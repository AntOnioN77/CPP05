#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <string>

// Formulario que concede un indulto simbólico.
class PresidentialPardonForm : public AForm {
private:
// Destinatario del indulto.
std::string target;

public:
// Forma canónica ortodoxa.
PresidentialPardonForm();
PresidentialPardonForm(const std::string &target);
PresidentialPardonForm(const PresidentialPardonForm &other);
~PresidentialPardonForm();
PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

// Implementación de la acción concreta.
void action() const;
// Getter del objetivo.
std::string getTarget() const;
};

#endif
