#ifndef AFORM_HPP
# define AFORM_HPP
# include <string>
# include <ostream>
# include <exception>

class Bureaucrat;

class AForm{
	private:
	const std::string name;
	bool signature;
	const int gradeToSign;
	const int gradeToExecute;

//ortodox canonical form
	public:
	AForm();
	AForm(const std::string &name, int gradeToSign, int gradeToExecute);
	AForm(const AForm &other);
	virtual ~AForm();
	AForm &operator=(const AForm &other);

//getters
	const std::string &getName() const;
	bool getSignature() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

//otros
	void beSigned(const Bureaucrat &bureaucrat);
	void execute(Bureaucrat const &executor) const;
	virtual void action() const = 0 ;

//excepciones
	class GradeTooHighException : public std::exception{
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception{
		const char* what() const throw();
	};
	//Nueva
	class NotSignedException : public std::exception{
		const char* what() const throw();
	};


};

std::ostream& operator<<(std::ostream& os, const AForm& Aform);

#endif