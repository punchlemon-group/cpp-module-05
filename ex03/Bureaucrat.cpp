#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(_lowestGrade) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
  if (grade < _highestGrade) {
    throw Bureaucrat::GradeTooHighException();
  }
  if (grade > _lowestGrade) {
    throw Bureaucrat::GradeTooLowException();
  }
  this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  if (this != &other) {
    this->_grade = other._grade;
  }
  return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {
  return this->_name;
}

int Bureaucrat::getGrade() const {
  return this->_grade;
}

void Bureaucrat::incrementGrade() {
  if (this->_grade - 1 < _highestGrade) {
    throw Bureaucrat::GradeTooHighException();
  }
  this->_grade--;
}

void Bureaucrat::decrementGrade() {
  if (this->_grade + 1 > _lowestGrade) {
    throw Bureaucrat::GradeTooLowException();
  }
  this->_grade++;
}

void Bureaucrat::signForm(AForm& form) {
  try {
    form.beSigned(*this);
    std::cout << this->_name << " signed " << form.getName() << std::endl;
  } catch (const std::exception& e) {
    std::cout << this->_name << " couldn't sign " << form.getName()
              << " because " << e.what() << "." << std::endl;
  }
}

void Bureaucrat::executeForm(const AForm& form) const {
  try {
    form.execute(*this);
    std::cout << this->_name << " executed " << form.getName() << std::endl;
  } catch (const std::exception& e) {
    std::cout << this->_name << " couldn't execute " << form.getName()
              << " because " << e.what() << "." << std::endl;
  }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
  return os;
}
