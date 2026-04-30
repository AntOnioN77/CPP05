#include "Intern.hpp"
#include <iostream>
#include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

// Constructores
Intern::Intern()
{}

Intern::Intern(const Intern &other)
{
	(void)other;
}

// Destructor
Intern::~Intern()
{}

// Operador de asignación
Intern& Intern::operator=(const Intern &other)
{
	(void)other;
	// if (this != &other){} No hay atributos que copiar.
	return *this;
}

AForm *Intern::DinamicRobotomyForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::DinamicShrubberyForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::DinamicPardonForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}


AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
		const name_form pile_forms[3] = {
		{"robotomy request", DinamicRobotomyForm},
		{"shrubbery creation", DinamicShrubberyForm},
		{"presidential pardon", DinamicPardonForm}
	};
	AForm * form;
	int i;
	for (i = 0; i < 3 && pile_forms[i].type != formName; i++) {}
	if (i == 3)
	{
		std::cout << "Form " << formName << " does not exist" << std::endl;
		return NULL;
	}
	else
	{
		form = pile_forms[i].function(target);	
	}
	return form;
}
