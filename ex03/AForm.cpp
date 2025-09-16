#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default Form"), _isSigned(false), _gradeToSign(_lowestGrade), _gradeToExecute(_lowestGrade) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
  if (gradeToSign < _highestGrade || gradeToExecute < _highestGrade) {
    throw AForm::GradeTooHighException();
  }
  if (gradeToSign > _lowestGrade || gradeToExecute > _lowestGrade) {
    throw AForm::GradeTooLowException();
  }
}

AForm::AForm(const AForm& other)
    : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

AForm& AForm::operator=(const AForm& other) {
  if (this != &other) {
    this->_isSigned = other._isSigned;
    // Note: const members (_name, _gradeToSign, _gradeToExecute) cannot be reassigned
  }
  return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const {
  return this->_name;
}

bool AForm::getIsSigned() const {
  return this->_isSigned;
}

int AForm::getGradeToSign() const {
  return this->_gradeToSign;
}

int AForm::getGradeToExecute() const {
  return this->_gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
  if (bureaucrat.getGrade() > this->_gradeToSign) {
    throw AForm::GradeTooLowException();
  }
  this->_isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const {
  if (!this->_isSigned) {
    throw AForm::FormNotSignedException();
  }
  if (executor.getGrade() > this->_gradeToExecute) {
    throw AForm::GradeTooLowException();
  }
  this->executeAction();
}

const char* AForm::GradeTooHighException::what() const throw() {
  return "Form grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
  return "Form grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
  return "Form is not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
  os << "Form " << form.getName()
     << ", sign grade " << form.getGradeToSign()
     << ", execute grade " << form.getGradeToExecute()
     << ", " << (form.getIsSigned() ? "signed" : "not signed") << ".";
  return os;
}
