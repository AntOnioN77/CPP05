#include "Bureaucrat.hpp"

int main(void)
{
//TEST 1
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

//TEST 2
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

//TEST 3
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

//TEST 4
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

//TEST 5
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