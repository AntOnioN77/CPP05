#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm():
AForm("PresidentialPardonForm", 25, 5),
target("No_target") 
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):
AForm("PresidentialPardonForm", 25, 5),
target(target) 
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):
AForm(other),
target(other.getTarget())
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.getTarget();
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void PresidentialPardonForm::action() const
{
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
	return target;
}
