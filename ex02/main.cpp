#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

int main(void)
{
    // Test 1: Ejecución exitosa de PresidentialPardonForm
    Bureaucrat Zaphod("Zaphod", 5);
    Bureaucrat empleado("Empleado", 25);
	Bureaucrat subcontratado("Subcontratado", 26);
    PresidentialPardonForm perdon("Arthur");

    empleado.signForm(perdon);
    Zaphod.executeForm(perdon);
    std::cout << "[TEST 1 COMPLETADO] Verifica los mensajes" << std::endl;

    // Test 2: Ejecución fallida por grado insuficiente
    PresidentialPardonForm otroPerdon("NPC");

	subcontratado.signForm(otroPerdon);
    empleado.signForm(otroPerdon);
    empleado.executeForm(otroPerdon);
    std::cout << "[TEST 2 COMPLETADO] Verifica los mensajes" << std::endl;

	Bureaucrat aprendiz("Aprendiz", 46);
	RobotomyRequestForm robotomy("human3987324");
	aprendiz.signForm(robotomy);
	aprendiz.executeForm(robotomy);
	empleado.executeForm(robotomy);
    std::cout << "[TEST 3 COMPLETADO] Verifica los mensajes" << std::endl;




    return 0;
}
