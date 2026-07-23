#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <string>

// Formulario que intenta robotomizar un objetivo al 50%.
class RobotomyRequestForm : public AForm {
private:
// Objetivo de la robotomía.
std::string target;

public:
RobotomyRequestForm();
RobotomyRequestForm(const std::string &target);
RobotomyRequestForm(const RobotomyRequestForm &other);
~RobotomyRequestForm();
RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

// Efecto concreto del formulario.
void action() const;
std::string getTarget() const;
};

#endif
