#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include <string>
# include "AForm.hpp"

class Form;

// Burócrata que interactúa con AForm: firma y ejecución.
class Bureaucrat {
private:
// Identidad fija.
const std::string name;
// Grado jerárquico permitido en [1..150].
int grade;

public:
// Forma canónica ortodoxa.
Bureaucrat();
Bureaucrat(const std::string &name, int grade);
Bureaucrat(const Bureaucrat &other);
~Bureaucrat();
Bureaucrat &operator=(const Bureaucrat &other);

// Getters.
const std::string &getName() const;
int getGrade() const;

// Modificadores de grado con control de límites.
void upGrade();
void downGrade();

// Firma un formulario; devuelve true si tuvo éxito.
bool signForm(AForm &form);
// Ejecuta un formulario; devuelve true si tuvo éxito.
bool executeForm(AForm const & form) const;

class GradeTooHighException : public std::exception {
const char* what() const throw();
};
class GradeTooLowException : public std::exception {
const char* what() const throw();
};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
