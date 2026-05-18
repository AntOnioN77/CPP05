#include "Bureaucrat.hpp"
#include <ostream>

// Constructor por defecto con estado válido mínimo.
Bureaucrat::Bureaucrat() :
name("nameless_gray_man"),
grade(150)
{}

// Construcción explícita validando el rango permitido.
Bureaucrat::Bureaucrat(const std::string &name, int grade) :
name(name),
grade(grade)
{
if (grade > 150)
throw Bureaucrat::GradeTooLowException();
if (grade < 1)
throw Bureaucrat::GradeTooHighException();
}

// Constructor de copia.
Bureaucrat::Bureaucrat(const Bureaucrat &other) :
name(other.getName()),
grade(other.getGrade())
{}

// Destructor trivial (sin recursos dinámicos).
Bureaucrat::~Bureaucrat()
{}

// Asignación: solo copia grade porque name es const.
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

// Subir de rango administrativo (número menor).
void Bureaucrat::upGrade()
{
if (grade <= 1)
throw Bureaucrat::GradeTooHighException();
grade--;
}

// Bajar de rango administrativo (número mayor).
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

// Envoltorio de firma con gestión de errores y mensaje uniforme.
bool Bureaucrat::signForm(Form &form)
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
