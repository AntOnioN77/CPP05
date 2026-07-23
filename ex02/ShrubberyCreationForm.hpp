#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <string>

// Formulario que crea un archivo con un dibujo ASCII de arbusto.
class ShrubberyCreationForm : public AForm {
private:
// Prefijo del archivo de salida (<target>_shrubbery).
std::string target;

public:
ShrubberyCreationForm();
ShrubberyCreationForm(const std::string &target);
ShrubberyCreationForm(const ShrubberyCreationForm &other);
~ShrubberyCreationForm();
ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

// Acción de escritura en disco.
void action() const;
std::string getTarget() const;
};

#endif
