#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <ostream>

//ortodox canonical form
AForm::AForm():
name("nameless_form"),
signature(false),
gradeToSign(150),
gradeToExecute(150)
{}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute):
name(name),
signature(false),
gradeToSign(gradeToSign),
gradeToExecute(gradeToExecute)
{
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm &other):
name(other.getName()),
signature(other.getSignature()),
gradeToSign(other.getGradeToSign()),
gradeToExecute(other.getGradeToExecute())
{}

// Este operador apenas tiene sentido, teniendo en cuenta que
//los atributos name, gradeToSign y gradeToExecute son constantes,
//lo incluimos para respetar la ortodox canonical Aform. 
AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		signature = other.getSignature();
	}
	return *this;
}

// Destructor
AForm::~AForm()
{}

//getters
const std::string &AForm::getName() const
{
	return name;
}

bool AForm::getSignature() const
{
	return signature;
}

int AForm::getGradeToSign() const
{
	return gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

//otros
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	signature = true;
}

//sobreescribiendo el what() de std::exception par su heredera GradeTooLowException
const char* AForm::GradeTooLowException::what() const throw()
{
	return "A GradeTooLowException occurred";
}

//sobreescribiendo el what() de std::exception par su heredera GradeTooHighException
const char* AForm::GradeTooHighException::what() const throw()
{
	return "A GradeTooHighException occurred";
}

const char* AForm::NotSignedException::what() const throw()
{
	return "A NotSignedException occurred";
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "AForm name: " << form.getName()
		<< ". Grade to sign: " << form.getGradeToSign()
		<< ". Grade to execute: " << form.getGradeToExecute();
	if (form.getSignature())
		os << ". Signed." << std::endl;
	else
		os << ". No signed." << std::endl;

	return os;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!signature)
		throw NotSignedException();
	if (executor.getGrade() > gradeToExecute)
		throw GradeTooLowException();
	action();
}

