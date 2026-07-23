#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() :
AForm("ShrubberyCreationForm", 145, 137),
target("No_target")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
AForm("ShrubberyCreationForm", 145, 137),
target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
AForm(other),
target(other.getTarget())
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
if (this != &other)
{
AForm::operator=(other);
target = other.getTarget();
}
return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

// Crea/reescribe el fichero target_shrubbery con arte ASCII.
void ShrubberyCreationForm::action() const
{
std::ofstream shrubbery((target + "_shrubbery").c_str(), std::ios::out);
shrubbery << "      |\n"
  << "     \\|/|/\n"
  << "   \\|\\|//|/\n"
  << "   \\|\\|/|/\n"
  << "     \\|//\n"
  << "     \\|/\n"
  << "     \\|/\n"
  << "      |\n"
  << "_\\|/__|_\\|/____\\|/_\n";
shrubbery.close();
}

std::string ShrubberyCreationForm::getTarget() const
{
return target;
}
