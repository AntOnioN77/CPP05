#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include "Intern.hpp"
#include <time.h>
#include <stdlib.h>

int main(void)
{
    Intern someRandomIntern;
	AForm* rrf;

	srand(time(NULL));
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf)
	{
		std::cout << *rrf;
		delete rrf;
	}
	AForm* scf;
	scf = someRandomIntern.makeForm("shrubbery creation", "Home");
	if (scf)
	{
		std::cout << *scf;
		delete scf;
	}
	AForm* ppf;
	ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
	if (ppf)
	{
		std::cout << *ppf;
		delete ppf;
	}
	AForm* nonExistentForm;
	nonExistentForm = someRandomIntern.makeForm("non-existent form", "Target");
	if (nonExistentForm)
		delete nonExistentForm;

	return 0;
}