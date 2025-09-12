#include "Intern.hpp"
#include <cctype>

// Static member initialization
const Intern::FormInfo Intern::_formTypes[3] = {
  {"shrubbery creation", &Intern::createShrubberyForm},
  {"robotomy request", &Intern::createRobotomyForm},
  {"presidential pardon", &Intern::createPresidentialForm}
};

Intern::Intern() {}

Intern::Intern(const Intern& other) {
  (void)other; // Suppress unused parameter warning
}

Intern& Intern::operator=(const Intern& other) {
  (void)other; // Suppress unused parameter warning
  return *this;
}

Intern::~Intern() {}

AForm* Intern::createShrubberyForm(const std::string& target) const {
  return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target) const {
  return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(const std::string& target) const {
  return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
  // Convert form name to lowercase for case-insensitive comparison
  std::string lowerFormName = formName;
  for (size_t i = 0; i < lowerFormName.length(); ++i) {
    lowerFormName[i] = std::tolower(lowerFormName[i]);
  }

  // Search for the form type
  for (int i = 0; i < 3; ++i) {
    if (lowerFormName == _formTypes[i].name) {
      std::cout << "Intern creates " << formName << std::endl;
      return (this->*_formTypes[i].creator)(target);
    }
  }

  // Form not found
  std::cout << "Error: Form \"" << formName << "\" does not exist!" << std::endl;
  throw Intern::FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw() {
  return "Form not found!";
}
