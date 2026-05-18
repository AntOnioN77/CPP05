#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h>

int main(void)
{
// TEST 1: flujo nominal de firma + ejecución de indulto presidencial.
Bureaucrat Zaphod("Zaphod", 5);
Bureaucrat empleado("Empleado", 25);
Bureaucrat subcontratado("Subcontratado", 26);
PresidentialPardonForm perdon("Arthur");

empleado.signForm(perdon);
Zaphod.executeForm(perdon);
std::cout << "[TEST 1 COMPLETADO] Verifica los mensajes" << std::endl;

// TEST 2: firma/ejecución con grados insuficientes.
PresidentialPardonForm otroPerdon("NPC");
subcontratado.signForm(otroPerdon);
empleado.signForm(otroPerdon);
empleado.executeForm(otroPerdon);
std::cout << "[TEST 2 COMPLETADO] Verifica los mensajes" << std::endl;

// TEST 3: robotomy con semilla aleatoria y doble intento de ejecución.
srand(time(NULL));
Bureaucrat aprendiz("Aprendiz", 46);
RobotomyRequestForm robotomy("human3987324");
aprendiz.signForm(robotomy);
aprendiz.executeForm(robotomy);
empleado.executeForm(robotomy);
std::cout << "[TEST 3 COMPLETADO] Verifica los mensajes" << std::endl;

// TEST 4: creación de archivo shrubbery con grado correcto.
Bureaucrat Labrador("Labrador", 137);
ShrubberyCreationForm romero("Romero");
Labrador.signForm(romero);
Labrador.executeForm(romero);
std::cout << "[TEST 4 COMPLETADO] Verifica los mensajes" << std::endl;

// TEST 5: intento de ejecución fallida por grado insuficiente.
Bureaucrat aprendiz2("Aprendiz2", 138);
ShrubberyCreationForm matojo("Matojo");
aprendiz2.signForm(matojo);
aprendiz2.executeForm(matojo);
std::cout << "[TEST 5 COMPLETADO] Verifica los mensajes" << std::endl;

return 0;
}
