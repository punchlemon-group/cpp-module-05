#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
  std::cout << "=== Exercise 01: Form Tests ===" << std::endl;

  std::cout << std::endl << "--- Test 1: Form creation ---" << std::endl;
  try {
    Form form1("Tax Form", 50, 25);
    std::cout << form1 << std::endl;

    Form form2("Secret Document", 1, 1);
    std::cout << form2 << std::endl;
  } catch (const std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl << "--- Test 2: Form with invalid grades ---" << std::endl;
  try {
    Form invalidForm("Invalid", 0, 25); // Should throw exception
  } catch (const std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  try {
    Form invalidForm2("Invalid2", 25, 151); // Should throw exception
  } catch (const std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl << "--- Test 3: Successful form signing ---" << std::endl;
  try {
    Bureaucrat highRank("Boss", 1);
    Form easyForm("Easy Form", 50, 25);

    std::cout << "Before signing: " << easyForm << std::endl;
    highRank.signForm(easyForm);
    std::cout << "After signing: " << easyForm << std::endl;
  } catch (const std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl << "--- Test 4: Failed form signing (insufficient grade) ---" << std::endl;
  try {
    Bureaucrat lowRank("Intern", 100);
    Form difficultForm("Top Secret", 10, 5);

    std::cout << "Before signing attempt: " << difficultForm << std::endl;
    lowRank.signForm(difficultForm);
    std::cout << "After signing attempt: " << difficultForm << std::endl;
  } catch (const std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl << "--- Test 5: Multiple bureaucrats, multiple forms ---" << std::endl;
  try {
    Bureaucrat ceo("CEO", 1);
    Bureaucrat manager("Manager", 25);
    Bureaucrat employee("Employee", 75);

    Form form1("Budget Report", 50, 30);
    Form form2("Executive Order", 5, 1);
    Form form3("Employee Handbook", 100, 75);

    std::cout << std::endl << "CEO attempts to sign forms:" << std::endl;
    ceo.signForm(form1);
    ceo.signForm(form2);
    ceo.signForm(form3);

    std::cout << std::endl << "Manager attempts to sign forms:" << std::endl;
    manager.signForm(form1); // Already signed
    manager.signForm(form2); // Should fail

    std::cout << std::endl << "Employee attempts to sign forms:" << std::endl;
    employee.signForm(form3); // Should work

  } catch (const std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  return 0;
}
