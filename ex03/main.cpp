#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
  std::cout << "=== Exercise 03: Intern Factory Tests ===" << std::endl;

  // Create bureaucrats for testing
  Bureaucrat president("President", 1);
  Bureaucrat manager("Manager", 50);

  std::cout << std::endl << "--- Test 1: Valid form creation ---" << std::endl;
  try {
    Intern someRandomIntern;
    AForm* rrf;

    // Test robotomy request
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    std::cout << *rrf << std::endl;

    president.signForm(*rrf);
    president.executeForm(*rrf);

    delete rrf;
    std::cout << std::endl;

    // Test shrubbery creation
    AForm* scf = someRandomIntern.makeForm("shrubbery creation", "garden");
    std::cout << *scf << std::endl;

    manager.signForm(*scf);
    manager.executeForm(*scf);

    delete scf;
    std::cout << std::endl;

    // Test presidential pardon
    AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
    std::cout << *ppf << std::endl;

    president.signForm(*ppf);
    president.executeForm(*ppf);

    delete ppf;

  } catch (const std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl << "--- Test 2: Case insensitive form names ---" << std::endl;
  try {
    Intern intern;

    AForm* form1 = intern.makeForm("ROBOTOMY REQUEST", "Marvin");
    std::cout << *form1 << std::endl;
    delete form1;

    AForm* form2 = intern.makeForm("Shrubbery Creation", "park");
    std::cout << *form2 << std::endl;
    delete form2;

    AForm* form3 = intern.makeForm("Presidential Pardon", "Zaphod");
    std::cout << *form3 << std::endl;
    delete form3;

  } catch (const std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl << "--- Test 3: Invalid form names ---" << std::endl;
  try {
    Intern intern;

    std::cout << "Trying to create non-existent form:" << std::endl;
    AForm* invalidForm = intern.makeForm("coffee making", "office");
    delete invalidForm; // This won't be reached

  } catch (const std::exception& e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  try {
    Intern intern;

    std::cout << std::endl << "Trying another invalid form:" << std::endl;
    AForm* anotherInvalid = intern.makeForm("tax evasion", "someone");
    delete anotherInvalid; // This won't be reached

  } catch (const std::exception& e) {
    std::cout << "Exception caught: " << e.what() << std::endl;
  }

  std::cout << std::endl << "--- Test 4: Multiple interns ---" << std::endl;
  try {
    Intern intern1;
    Intern intern2;
    Intern intern3;

    AForm* forms[3];
    forms[0] = intern1.makeForm("shrubbery creation", "intern1_garden");
    forms[1] = intern2.makeForm("robotomy request", "intern2_target");
    forms[2] = intern3.makeForm("presidential pardon", "intern3_victim");

    for (int i = 0; i < 3; ++i) {
      std::cout << *forms[i] << std::endl;
      president.signForm(*forms[i]);
      president.executeForm(*forms[i]);
      delete forms[i];
      std::cout << std::endl;
    }

  } catch (const std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl << "--- Test 5: Copy and assignment ---" << std::endl;
  try {
    Intern originalIntern;

    // Test copy constructor
    Intern copyIntern(originalIntern);
    AForm* form1 = copyIntern.makeForm("robotomy request", "copy_test");
    std::cout << *form1 << std::endl;
    delete form1;

    // Test assignment operator
    Intern assignIntern;
    assignIntern = originalIntern;
    AForm* form2 = assignIntern.makeForm("shrubbery creation", "assign_test");
    std::cout << *form2 << std::endl;
    delete form2;

  } catch (const std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl << "=== Tests completed ===" << std::endl;
  return 0;
}
