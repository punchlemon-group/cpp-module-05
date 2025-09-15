#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", kSignGrade, kExecGrade), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", kSignGrade, kExecGrade), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
  if (this != &other) {
    this->AForm::operator=(other);
    this->_target = other._target;
  }
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeAction() const {
  std::cout << "* DRILLING NOISES *" << std::endl;
  std::cout << "BZZZZZZT! WHIRRRRR! CLANK CLANK!" << std::endl;

  // Initialize random seed if not already done
  static bool seeded = false;
  if (!seeded) {
    std::srand(std::time(NULL));
    seeded = true;
  }

  if (std::rand() % 2) {
    std::cout << this->_target << " has been robotomized successfully!" << std::endl;
  } else {
    std::cout << "Robotomy of " << this->_target << " failed!" << std::endl;
  }
}
