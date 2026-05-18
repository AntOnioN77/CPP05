#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

// Registro de tipo textual + función constructora correspondiente.
struct name_form {
std::string type;
AForm *(*function)(const std::string &);
};

// Fábrica de formularios concretos a partir de un nombre.
class Intern {
private:
// Constructores estáticos internos para cada tipo soportado.
static AForm *NewRobotomyForm(const std::string &target);
static AForm *NewShrubberyForm(const std::string &target);
static AForm *NewPardonForm(const std::string &target);

public:
// Forma canónica ortodoxa (sin estado interno real).
Intern();
Intern(const Intern &other);
~Intern();
Intern &operator=(const Intern &other);

// Crea el formulario solicitado o devuelve NULL si no existe.
AForm *makeForm(const std::string &formName, const std::string &target) const;
};

#endif
