
#include "Bureaucrat.hpp"

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
	std::cout << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return os;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
	}
	catch (std::exception &e)
	{
		std::cout << name << " couldn’t sign " << form.getName()
			<< " because " << e.what();

	}
	std::cout << name << " signed " << form.getName();
}