#ifndef FORM
# define FORM
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
	private:
	const std::string name;
	bool signature;
	const int gradeToSign;
	const int gradeToExecute;

	//ortodox canonical form
	public:
	Form();
	Form(const std::string &name, int gradeToSign, int gradeToExecute);
	Form(const Form &other);
	~Form();
	Form &operator=(const Form &other);

	//getters
	const std::string &getName() const;
	bool getSignature() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	//otros
	void beSigned(const Bureaucrat &bureaucrat);



	class GradeTooHighException : public std::exception{
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception{
		const char* what() const throw();
	};

};
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif