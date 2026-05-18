#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include <string>
# include "Form.hpp"

class Form;

// Burócrata que puede firmar formularios según su grado.
class Bureaucrat {
private:
// Nombre inmutable del empleado.
const std::string name;
// Grado administrativo [1..150].
int grade;

public:
// Forma canónica ortodoxa.
Bureaucrat();
Bureaucrat(const std::string &name, int grade);
Bureaucrat(const Bureaucrat &other);
~Bureaucrat();
Bureaucrat &operator=(const Bureaucrat &other);

// Acceso de solo lectura al estado.
const std::string &getName() const;
int getGrade() const;

// Cambios de rango con validación de límites.
void upGrade();
void downGrade();

// Intenta firmar un formulario y reporta resultado por consola.
bool signForm(Form &form);

class GradeTooHighException : public std::exception {
const char* what() const throw();
};
class GradeTooLowException : public std::exception {
const char* what() const throw();
};
};

// Impresión amigable de un burócrata.
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
