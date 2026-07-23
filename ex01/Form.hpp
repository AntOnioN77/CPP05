#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <ostream>
# include <exception>

class Bureaucrat;

// Entidad firmable con requisitos de grado para firma y ejecución.
class Form {
private:
// Nombre del formulario (inmutable).
const std::string name;
// Estado de firmado.
bool signature;
// Grado mínimo requerido para firmar.
const int gradeToSign;
// Grado mínimo requerido para ejecutar.
const int gradeToExecute;

public:
// Forma canónica ortodoxa.
Form();
Form(const std::string &name, int gradeToSign, int gradeToExecute);
Form(const Form &other);
~Form();
Form &operator=(const Form &other);

// Consultas del estado interno.
const std::string &getName() const;
bool getSignature() const;
int getGradeToSign() const;
int getGradeToExecute() const;

// Intenta firmar el formulario con el burócrata recibido.
void beSigned(const Bureaucrat &bureaucrat);

// Excepciones de rango de grado.
class GradeTooHighException : public std::exception {
const char* what() const throw();
};
class GradeTooLowException : public std::exception {
const char* what() const throw();
};
};

// Impresión detallada del formulario.
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
