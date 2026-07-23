#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <ostream>
# include <exception>

class Bureaucrat;

// Clase abstracta base para formularios ejecutables.
class AForm {
private:
// Identificador inmutable del formulario.
const std::string name;
// Marca de firmado previo a ejecución.
bool signature;
// Grado requerido para firmar.
const int gradeToSign;
// Grado requerido para ejecutar.
const int gradeToExecute;

public:
// Forma canónica ortodoxa.
AForm();
AForm(const std::string &name, int gradeToSign, int gradeToExecute);
AForm(const AForm &other);
virtual ~AForm();
AForm &operator=(const AForm &other);

// Getters.
const std::string &getName() const;
bool getSignature() const;
int getGradeToSign() const;
int getGradeToExecute() const;

// Operaciones comunes.
void beSigned(const Bureaucrat &bureaucrat);
void execute(Bureaucrat const &executor) const;

// Punto de extensión obligatorio para formularios concretos.
virtual void action() const = 0;

// Excepciones de validación y estado.
class GradeTooHighException : public std::exception {
const char* what() const throw();
};
class GradeTooLowException : public std::exception {
const char* what() const throw();
};
class NotSignedException : public std::exception {
const char* what() const throw();
};
};

std::ostream& operator<<(std::ostream& os, const AForm& Aform);

#endif
