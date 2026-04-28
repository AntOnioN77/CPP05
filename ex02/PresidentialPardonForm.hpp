#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"
# include <string>

class PresidentialPardonForm : public AForm  {
	private:
	std::string target;

	public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

	void action() const;
	bool execute(Bureaucrat const & executor) const;
	std::string getTarget() const;

};

#endif