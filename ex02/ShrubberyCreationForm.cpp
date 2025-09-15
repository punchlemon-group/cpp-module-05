#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", kSignGrade, kExecGrade), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", kSignGrade, kExecGrade), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
  if (this != &other) {
    this->AForm::operator=(other);
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

  // ANSI color codes
  const char* YELLOW = "\033[1;33m";
  const char* RED    = "\033[1;31m";
  const char* GREEN  = "\033[1;32m";
  const char* RESET  = "\033[0m";

  file << GREEN;
  file << "    " << YELLOW << "*" << GREEN << std::endl;
  file << "   /.\\" << std::endl;
  file << "  /" << RED << "o" << GREEN << "..\\" << std::endl;
  file << "  /.." << RED << "o" << GREEN << "\\" << std::endl;
  file << " /." << RED << "o" << GREEN << ".." << RED << "o" << GREEN << "\\" << std::endl;
  file << " /..." << RED << "o" << GREEN << ".\\" << std::endl;
  file << "/.." << RED << "o" << GREEN << "....\\" << std::endl;
  file << "^^^[_]^^^" << RESET << std::endl;

  file.close();
}
