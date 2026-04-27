
#include "Bureaucrat.hpp"
#include <ostream>

//Constructores

Bureaucrat::Bureaucrat():
name("nameless_gray_man"),
grade(150)
{}

Bureaucrat::Bureaucrat(const std::string &name, int grade):
name(name),
grade(grade) 
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();

}

Bureaucrat::Bureaucrat(const Bureaucrat &other):
name(other.getName()),
grade(other.getGrade())
{};

// Destructor
Bureaucrat::~Bureaucrat()
{};

//Operador de asignación
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		grade = other.getGrade();

	}
	return *this;
}

// Getters
const std::string& Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

// Setters
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

//sobreescribiendo el what() de std::exception par su heredera GradeTooLowException
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "A GradeTooLowException occurred";
}

//sobreescribiendo el what() de std::exception par su heredera GradeTooHighException
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "A GradeTooHighException occurred";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return os;
}

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


const void AForm::execute(Bureaucrat const &executor);

