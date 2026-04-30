#ifndef Intern_HPP
# define Intern_HPP
# include <string>
# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"

#include <string>

struct name_form{
	std::string type;
	AForm *(*function)(const std::string &);
};

class Intern {
private:
	
	static AForm *DinamicRobotomyForm(const std::string &target);
	static AForm *DinamicShrubberyForm(const std::string &target);
	static AForm *DinamicPardonForm(const std::string &target);

public:
	// Constructores
	Intern();
	Intern(const Intern &other);
	~Intern();
	Intern &operator=(const Intern &other);

	// Métodos
	AForm *makeForm(const std::string &formName, const std::string &target) const;
};

#endif