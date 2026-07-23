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
// El intern funciona como fábrica central de formularios.
// Cada caso verifica que makeForm devuelva el tipo correcto por nombre.
Intern someRandomIntern;
AForm* rrf;

// Semilla para acciones aleatorias de robotomy.
srand(time(NULL));

// Caso 1: creación de robotomy request.
rrf = someRandomIntern.makeForm("robotomy request", "Bender");
if (rrf)
{
std::cout << *rrf;
delete rrf;
}

// Caso 2: creación de shrubbery creation.
AForm* scf;
scf = someRandomIntern.makeForm("shrubbery creation", "Home");
if (scf)
{
std::cout << *scf;
delete scf;
}

// Caso 3: creación de presidential pardon.
AForm* ppf;
ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
if (ppf)
{
std::cout << *ppf;
delete ppf;
}

// Caso 4: nombre inexistente, debe devolver NULL.
// Requisito: ante nombre inválido debe informar error y no crear formulario.
AForm* nonExistentForm;
nonExistentForm = someRandomIntern.makeForm("non-existent form", "Target");
if (nonExistentForm)
delete nonExistentForm;

return 0;
}
