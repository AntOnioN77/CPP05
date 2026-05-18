#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <ostream>

// Inicialización por defecto válida.
AForm::AForm() :
name("nameless_form"),
signature(false),
gradeToSign(150),
gradeToExecute(150)
{}

// Inicialización explícita con comprobación de límites.
AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) :
name(name),
signature(false),
gradeToSign(gradeToSign),
gradeToExecute(gradeToExecute)
{
if (gradeToSign > 150 || gradeToExecute > 150)
throw AForm::GradeTooLowException();
if (gradeToSign < 1 || gradeToExecute < 1)
throw AForm::GradeTooHighException();
}

// Copia fiel del estado.
AForm::AForm(const AForm &other) :
name(other.getName()),
signature(other.getSignature()),
gradeToSign(other.getGradeToSign()),
gradeToExecute(other.getGradeToExecute())
{}

// Solo signature es asignable (resto const).
AForm &AForm::operator=(const AForm &other)
{
if (this != &other)
signature = other.getSignature();
return *this;
}

AForm::~AForm()
{}

const std::string &AForm::getName() const
{
return name;
}

bool AForm::getSignature() const
{
return signature;
}

int AForm::getGradeToSign() const
{
return gradeToSign;
}

int AForm::getGradeToExecute() const
{
return gradeToExecute;
}

// Firma validando grado del firmante.
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
if (bureaucrat.getGrade() > gradeToSign)
throw GradeTooLowException();
signature = true;
}

const char* AForm::GradeTooLowException::what() const throw()
{
return "A GradeTooLowException occurred";
}

const char* AForm::GradeTooHighException::what() const throw()
{
return "A GradeTooHighException occurred";
}

const char* AForm::NotSignedException::what() const throw()
{
return "A NotSignedException occurred";
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
os << "AForm name: " << form.getName()
<< ". Grade to sign: " << form.getGradeToSign()
<< ". Grade to execute: " << form.getGradeToExecute();
if (form.getSignature())
os << ". Signed." << std::endl;
else
os << ". No signed." << std::endl;
return os;
}

// Plantilla común de ejecución: firmado + grado + acción concreta.
void AForm::execute(Bureaucrat const &executor) const
{
if (!signature)
throw NotSignedException();
if (executor.getGrade() > gradeToExecute)
throw GradeTooLowException();
action();
}
