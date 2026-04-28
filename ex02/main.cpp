#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(void)
{
    // Test 1: Ejecución exitosa de PresidentialPardonForm
    Bureaucrat jefe("Jefe", 1);
    PresidentialPardonForm perdon("Juan Perez");

    jefe.signForm(perdon);
    jefe.executeForm(perdon);
    std::cout << "[TEST 1 COMPLETADO] Verifica los mensajes de Bureaucrat::executeForm." << std::endl;

    // Test 2: Ejecución fallida por grado insuficiente
    Bureaucrat empleado("Empleado", 50);
    PresidentialPardonForm otroPerdon("Maria Lopez");

    empleado.signForm(otroPerdon);
    empleado.executeForm(otroPerdon);
    std::cout << "[TEST 2 COMPLETADO] Verifica los mensajes de Bureaucrat::executeForm." << std::endl;

    return 0;
}
