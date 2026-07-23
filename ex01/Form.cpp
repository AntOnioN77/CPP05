#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <ostream>

// Constructor por defecto en estado no firmado y máximos permisivos.
Form::Form() :
name("nameless_form"),
signature(false),
gradeToSign(150),
gradeToExecute(150)
{}

// Constructor principal con validación de límites.
Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) :
name(name),
signature(false),
gradeToSign(gradeToSign),
gradeToExecute(gradeToExecute)
{
if (gradeToSign > 150 || gradeToExecute > 150)
throw Form::GradeTooLowException();
if (gradeToSign < 1 || gradeToExecute < 1)
throw Form::GradeTooHighException();
}

// Copia de estado completo.
Form::Form(const Form &other) :
name(other.getName()),
signature(other.getSignature()),
gradeToSign(other.getGradeToSign()),
gradeToExecute(other.getGradeToExecute())
{}

// name/grade* son const; solo puede copiarse signature.
Form &Form::operator=(const Form &other)
{
if (this != &other)
signature = other.getSignature();
return *this;
}

Form::~Form()
{}

const std::string &Form::getName() const
{
return name;
}

bool Form::getSignature() const
{
return signature;
}

int Form::getGradeToSign() const
{
return gradeToSign;
}

int Form::getGradeToExecute() const
{
return gradeToExecute;
}

// Firma efectiva solo si el burócrata tiene grado suficiente.
void Form::beSigned(const Bureaucrat &bureaucrat)
{
if (bureaucrat.getGrade() > gradeToSign)
throw GradeTooLowException();
signature = true;
}

const char* Form::GradeTooLowException::what() const throw()
{
return "A GradeTooLowException occurred";
}

const char* Form::GradeTooHighException::what() const throw()
{
return "A GradeTooHighException occurred";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
os << "Form name: " << form.getName()
<< ". Grade to sign: " << form.getGradeToSign()
<< ". Grade to execute: " << form.getGradeToExecute();
if (form.getSignature())
os << ". Signed." << std::endl;
else
os << ". No signed." << std::endl;
return os;
}
