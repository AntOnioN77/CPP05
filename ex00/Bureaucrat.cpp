#include "Bureaucrat.hpp"

// ==========================
// Constructores y destructor
// ==========================

// Estado por defecto válido.
Bureaucrat::Bureaucrat() :
name("nameless_gray_man"),
grade(150)
{}

// Construcción explícita con validación de invariantes.
Bureaucrat::Bureaucrat(const std::string &name, int grade) :
name(name),
grade(grade)
{
if (grade > 150)
throw Bureaucrat::GradeTooLowException();
if (grade < 1)
throw Bureaucrat::GradeTooHighException();
}

// Copia completa del estado observable.
Bureaucrat::Bureaucrat(const Bureaucrat &other) :
name(other.getName()),
grade(other.getGrade())
{}

// No hay recursos dinámicos propios que liberar.
Bureaucrat::~Bureaucrat()
{}

// =============================
// Operador de asignación y API
// =============================

// El nombre es const: solo puede copiarse el grado.
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
if (this != &other)
grade = other.getGrade();
return *this;
}

// Devuelve referencia constante al nombre interno.
const std::string& Bureaucrat::getName() const
{
return name;
}

// Devuelve el grado actual.
int Bureaucrat::getGrade() const
{
return grade;
}

// Ascender equivale a disminuir el número de grado.
void Bureaucrat::upGrade()
{
if (grade <= 1)
throw Bureaucrat::GradeTooHighException();
grade--;
}

// Descender equivale a incrementar el número de grado.
void Bureaucrat::downGrade()
{
if (grade >= 150)
throw Bureaucrat::GradeTooLowException();
grade++;
}

// ====================
// Mensajes de errores
// ====================

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
return "A GradeTooLowException occurred";
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
return "A GradeTooHighException occurred";
}

// Formato de depuración requerido por los tests.
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
return os;
}
