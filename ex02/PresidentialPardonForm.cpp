#ifndef PRESIDENTIALPARDONFORM_CPP
# define PRESIDENTIALPARDONFORM_CPP
# include "AForm.hpp"
# include <string>

class PresidentialPardonForm : private AForm  {
	private:
	std::string target;

	public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string &target);
	PresidentialPardonForm(const AForm &other);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=(const AForm &other);

	void action() const;
	bool executeForm(AForm const & form) const;

};

#endif