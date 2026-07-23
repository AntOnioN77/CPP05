#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include <string>

// Clase principal del ejercicio 00.
// Representa un burócrata con nombre inmutable y grado acotado [1, 150].
class Bureaucrat {
private:
// Identidad fija del burócrata (no cambia tras construirse).
const std::string name;
// Nivel jerárquico: 1 es el más alto y 150 el más bajo.
int grade;

public:
// Constructor por defecto: crea un burócrata válido de rango mínimo.
Bureaucrat();
// Constructor parametrizado: valida que el grado esté dentro del rango permitido.
Bureaucrat(const std::string &name, int grade);
// Constructor de copia.
Bureaucrat(const Bureaucrat &other);
// Destructor.
~Bureaucrat();
// Copia únicamente los campos modificables (grade).
Bureaucrat &operator=(const Bureaucrat &other);

// Getters de solo lectura.
const std::string &getName() const;
int getGrade() const;

// Disminuye numéricamente el grado (sube de rango).
void upGrade();
// Aumenta numéricamente el grado (baja de rango).
void downGrade();

// Excepción lanzada al intentar pasar por encima de grado 1.
class GradeTooHighException : public std::exception {
const char *what() const throw();
};
// Excepción lanzada al intentar pasar por debajo de grado 150.
class GradeTooLowException : public std::exception {
const char *what() const throw();
};
};

// Salida legible de un Bureaucrat para trazas y pruebas.
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
