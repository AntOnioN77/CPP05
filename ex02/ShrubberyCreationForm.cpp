#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm():
AForm("ShrubberyCreationForm", 145, 137),
target("No_target") 
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
AForm("ShrubberyCreationForm", 145, 137),
target(target) 
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):
AForm(other),
target(other.getTarget())
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.getTarget();
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::action() const
{
	// Implementación pendiente
}

bool ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getGradeToExecute())
	{
		throw GradeTooLowException();
		return false;
	}
	action();
	return true;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return target;
}