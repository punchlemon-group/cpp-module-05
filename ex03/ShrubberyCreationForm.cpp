#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
  if (this != &other) {
    AForm::operator=(other);
    this->_target = other._target;
  }
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const {
  std::string filename = this->_target + "_shrubbery";
  std::ofstream file(filename.c_str());

  if (!file.is_open()) {
    throw std::runtime_error("Could not create file");
  }

  file << "       _-_" << std::endl;
  file << "    /~~   ~~\\" << std::endl;
  file << " /~~         ~~\\" << std::endl;
  file << "{               }" << std::endl;
  file << " \\  _-     -_  /" << std::endl;
  file << "   ~  \\\\ //  ~" << std::endl;
  file << "_- -   | | _- _" << std::endl;
  file << "  _ -  | |   -_" << std::endl;
  file << "      // \\\\" << std::endl;
  file << std::endl;

  file << "      /\\  /\\" << std::endl;
  file << "     /  \\/  \\" << std::endl;
  file << "    /        \\" << std::endl;
  file << "   /  ^    ^  \\" << std::endl;
  file << "  /            \\" << std::endl;
  file << " /______________\\" << std::endl;
  file << "       ||||" << std::endl;
  file << "       ||||" << std::endl;

  file.close();
}
