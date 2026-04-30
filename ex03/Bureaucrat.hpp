#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <stdexcept>
# include <string>
# include "AForm.hpp"

class Form;

class Bureaucrat {
private:
	// Atributos
	const std::string name;
	int grade;

public:
	// Constructores
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	// Destructor
	~Bureaucrat();
	// Sobrecarga del operador de asignación
	Bureaucrat &operator=(const Bureaucrat &other);
	// Getters
	const std::string &getName() const;
	int getGrade() const;
	// Setters
	void upGrade();
	void downGrade();
	//otros
	bool signForm(AForm &form);
	bool executeForm(AForm const & form) const;

class GradeTooHighException : public std::exception{
	const char* what() const throw();
};
class GradeTooLowException : public std::exception{
	const char* what() const throw();
};

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif