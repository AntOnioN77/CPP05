#include "Bureaucrat.hpp"
#include <ostream>

// Constructor por defecto con grado mínimo de privilegio.
Bureaucrat::Bureaucrat() :
name("nameless_gray_man"),
grade(150)
{}

// Constructor con validación de rango.
Bureaucrat::Bureaucrat(const std::string &name, int grade) :
name(name),
grade(grade)
{
if (grade > 150)
throw Bureaucrat::GradeTooLowException();
if (grade < 1)
throw Bureaucrat::GradeTooHighException();
}

// Copia literal del estado.
Bureaucrat::Bureaucrat(const Bureaucrat &other) :
name(other.getName()),
grade(other.getGrade())
{}

Bureaucrat::~Bureaucrat()
{}

// name es const; solo se asigna grade.
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
if (this != &other)
grade = other.getGrade();
return *this;
}

const std::string& Bureaucrat::getName() const
{
return name;
}

int Bureaucrat::getGrade() const
{
return grade;
}

void Bureaucrat::upGrade()
{
if (grade <= 1)
throw Bureaucrat::GradeTooHighException();
grade--;
}

void Bureaucrat::downGrade()
{
if (grade >= 150)
throw Bureaucrat::GradeTooLowException();
grade++;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
return "A GradeTooLowException occurred";
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
return "A GradeTooHighException occurred";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
return os;
}

// Intenta firmar y reporta resultado de forma uniforme.
bool Bureaucrat::signForm(AForm &form)
{
try
{
form.beSigned(*this);
std::cout << name << " signed " << form.getName() << std::endl;
}
catch (std::exception &e)
{
std::cout << name << " couldn’t sign " << form.getName()
<< " because " << e.what() << std::endl;
return false;
}
return true;
}

// Intenta ejecutar y centraliza el manejo de errores.
bool Bureaucrat::executeForm(AForm const & form) const
{
try
{
form.execute(*this);
std::cout << getName() << " executed " << form.getName() << std::endl;
}
catch(std::exception &e)
{
std::cout << getName() << " can’t execute " << form.getName()
<< " because " << e.what() << std::endl;
return false;
}
return true;
}
