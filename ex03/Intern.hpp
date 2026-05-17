#ifndef INTERN_HPP
# define INTERN_HPP
# include <string>
# include "AForm.hpp"

struct name_form{
	std::string type;
	AForm *(*function)(const std::string &);
};

class Intern {
private:
	
	static AForm *NewRobotomyForm(const std::string &target);
	static AForm *NewShrubberyForm(const std::string &target);
	static AForm *NewPardonForm(const std::string &target);

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