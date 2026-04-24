
#include "Form.hpp"

//ortodox canonical form
Form::Form():
name("nameless_form"),
signature(false),
gradeToSign(150),
gradeToExecute(150)
{}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute):
name(name),
signature(false),
gradeToSign(gradeToSign),
gradeToExecute(gradeToExecute)
{
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
}

Form::Form(const Form &other):
name(other.getName()),
signature(other.getSignature()),
gradeToSign(other.getGradeToSign()),
gradeToExecute(other.getGradeToExecute())
{}

// Este operador apenas tiene sentido, teniendo en cuenta que
//los atributos name, gradeToSign y gradeToExecute son constantes,
//lo incluimos para respetar la ortodox canonical form. 
Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		signature = other.getSignature();
	}
	return *this;
}

// Destructor
Form::~Form()
{}

//getters
const std::string &Form::getName() const
{
	return name;
}

bool Form::getSignature() const
{
	return signature;
}

int Form::getGradeToSign() const
{
	return gradeToSign;
}

int Form::getGradeToExecute() const
{
	return gradeToExecute;
}

//otros
void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	signature = true;
}

//sobreescribiendo el what() de std::exception par su heredera GradeTooLowException
const char* Form::GradeTooLowException::what() const throw()
{
	return "A GradeTooLowException occurred";
}

//sobreescribiendo el what() de std::exception par su heredera GradeTooHighException
const char* Form::GradeTooHighException::what() const throw()
{
	return "A GradeTooHighException occurred";
}
