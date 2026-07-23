#include "Bureaucrat.hpp"

int main(void)
{
// Cada bloque valida un requisito explícito del enunciado de ex00.
// TEST 1: flujo nominal con grados válidos y uso de operator<<
std::cout << "TEST 1 (no errores) \n";
try
{
std::cout << "CREANDO --> Bureaucrat Bowser(Bowser, 1);" << std::endl;
Bureaucrat Bowser("Bowser", 1);
std::cout << "CREANDO --> Bureaucrat Goomba(Goomba, 150);" << std::endl;
Bureaucrat Goomba("Goomba", 150);
Goomba.upGrade();
std::cout << "provando operador <<: " << Goomba;
}
catch (std::exception &e)
{
std::cout << "Excepcion capturada! " << e.what() << std::endl;
}

// TEST 2: construcción inválida por grado superior al límite alto (0)
std::cout << "TEST 2 (error GradeTooHighException en SuperBowser) \n";
try
{
std::cout << "CREANDO --> Bureaucrat SuperBowser(superBowser, 1);" << std::endl;
Bureaucrat SuperBowser("SuperBowser", 0);
}
catch (std::exception &e)
{
std::cout << "Excepcion capturada! " << e.what() << std::endl;
}

// TEST 3: construcción inválida por grado inferior al límite bajo (151)
std::cout << "TEST 3 (error GradeTooLowException en MiniGoomba) \n";
try
{
std::cout << "CREANDO --> Bureaucrat MiniGoomba(MiniGoomba, 151);" << std::endl;
Bureaucrat MiniGoomba("MiniGoomba", 151);
}
catch (std::exception &e)
{
std::cout << "Excepcion capturada! " << e.what() << std::endl;
}

// TEST 4: descenso fuera de rango desde 150 -> 151
// Requisito: al salir del rango [1, 150] debe lanzarse excepción.
std::cout << "TEST 4 (error GradeTooLowException en Goomba) \n";
try
{
std::cout << "CREANDO --> Bureaucrat Goomba(Goomba, 150);" << std::endl;
Bureaucrat Goomba("Goomba", 150);
std::cout << "HACIENDO --> Goomba.downGrade();" << std::endl;
Goomba.downGrade();
}
catch(const std::exception& e)
{
std::cerr << e.what() << '\n';
}

// TEST 5: ascenso fuera de rango desde 1 -> 0
// Requisito: grade 1 es el máximo, no se puede incrementar más.
std::cout << "TEST 5 (error GradeTooHighException en Bowser) \n";
try
{
std::cout << "CREANDO --> Bureaucrat Bowser(Bowser, 1);" << std::endl;
Bureaucrat Bowser("Bowser", 1);
std::cout << "HACIENDO --> Bowser.upGrade();" << std::endl;
Bowser.upGrade();
}
catch(const std::exception& e)
{
std::cerr << e.what() << '\n';
}
return 0;
}
