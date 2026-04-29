#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm():
AForm("RobotomyRequestForm", 72, 45),
target("No_target") 
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
AForm("RobotomyRequestForm", 72, 45),
target(target) 
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):
AForm(other),
target(other.getTarget())
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.getTarget();
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void RobotomyRequestForm::action() const
{
	std::cout << "tsssk...\n"; 
	sleep(1);
	std::cout << "clunk!\n";
	sleep(1);
	std::cout << "chas, tsssk." <<std::endl;
	sleep(1);
	srand(time(NULL));  // <ctime>
	if (rand() % 2)
		std::cout << getTarget() << " has been robotomized!!" <<std::endl;
	else
		std::cout << "Robotomy failed. (:C)" <<std::endl;
}

bool RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getGradeToExecute())
	{
		throw GradeTooLowException();
		return false;
	}
	action();
	return true;
}

std::string RobotomyRequestForm::getTarget() const
{
	return target;
}