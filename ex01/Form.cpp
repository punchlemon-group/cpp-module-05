#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default Form"), _isSigned(false), _gradeToSign(_lowestGrade), _gradeToExecute(_lowestGrade) {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
  if (gradeToSign < _highestGrade || gradeToExecute < _highestGrade) {
    throw Form::GradeTooHighException();
  }
  if (gradeToSign > _lowestGrade || gradeToExecute > _lowestGrade) {
    throw Form::GradeTooLowException();
  }
}

Form::Form(const Form& other)
    : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

Form& Form::operator=(const Form& other) {
  if (this != &other) {
    this->_isSigned = other._isSigned;
    // Note: const members (_name, _gradeToSign, _gradeToExecute) cannot be reassigned
  }
  return *this;
}

Form::~Form() {}

std::string Form::getName() const {
  return this->_name;
}

bool Form::getIsSigned() const {
  return this->_isSigned;
}

int Form::getGradeToSign() const {
  return this->_gradeToSign;
}

int Form::getGradeToExecute() const {
  return this->_gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
  if (bureaucrat.getGrade() > this->_gradeToSign) {
    throw Form::GradeTooLowException();
  }
  this->_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
  return "Form grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
  return "Form grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
  os << "Form " << form.getName()
     << ", sign grade " << form.getGradeToSign()
     << ", execute grade " << form.getGradeToExecute()
     << ", " << (form.getIsSigned() ? "signed" : "not signed") << ".";
  return os;
}
