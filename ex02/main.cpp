#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
  std::cout << "=== Exercise 02: Abstract Forms Tests ===" << std::endl;

  // Create bureaucrats with different grades
  std::cout << std::endl << "--- Creating Bureaucrats ---" << std::endl;
  Bureaucrat president("President", 1);
  Bureaucrat director("Director", 25);
  Bureaucrat manager("Manager", 50);
  Bureaucrat intern("Intern", 150);

  std::cout << president << std::endl;
  std::cout << director << std::endl;
  std::cout << manager << std::endl;
  std::cout << intern << std::endl;

  std::cout << std::endl << "--- Test 1: ShrubberyCreationForm ---" << std::endl;
  try {
    ShrubberyCreationForm shrub("home");
    std::cout << shrub << std::endl;

    // Intern can sign but not execute
    intern.signForm(shrub);
    intern.executeForm(shrub);

    // Manager can execute
    manager.executeForm(shrub);

  } catch (const std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl << "--- Test 2: RobotomyRequestForm ---" << std::endl;
  try {
    RobotomyRequestForm robotomy("Bender");
    std::cout << robotomy << std::endl;

    // Manager can sign
    manager.signForm(robotomy);

    // Try execution multiple times to see randomness
    for (int i = 0; i < 3; i++) {
      std::cout << std::endl << "Attempt " << (i + 1) << ":" << std::endl;
      manager.executeForm(robotomy);
    }

  } catch (const std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl << "--- Test 3: PresidentialPardonForm ---" << std::endl;
  try {
    PresidentialPardonForm pardon("Arthur Dent");
    std::cout << pardon << std::endl;

    // Director can sign
    director.signForm(pardon);

    // But cannot execute (needs grade 5 or better)
    director.executeForm(pardon);

    // President can execute
    president.executeForm(pardon);

  } catch (const std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }  std::cout << std::endl << "--- Test 4: Form not signed error ---" << std::endl;
  try {
    ShrubberyCreationForm unsignedForm("garden");
    std::cout << unsignedForm << std::endl;

    // Try to execute without signing
    president.executeForm(unsignedForm);

  } catch (const std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl << "--- Test 5: Insufficient grade for signing ---" << std::endl;
  try {
    PresidentialPardonForm highLevel("Ford Prefect");
    std::cout << highLevel << std::endl;

    // Intern cannot sign (needs grade 25 or better)
    intern.signForm(highLevel);

  } catch (const std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl << "--- Test 6: Complete workflow ---" << std::endl;
  try {
    std::cout << "Creating all three forms..." << std::endl;
    ShrubberyCreationForm shrub2("office");
    RobotomyRequestForm robotomy2("Marvin");
    PresidentialPardonForm pardon2("Zaphod");

    std::cout << std::endl << "President signs and executes all forms:" << std::endl;
    president.signForm(shrub2);
    president.executeForm(shrub2);

    president.signForm(robotomy2);
    president.executeForm(robotomy2);

    president.signForm(pardon2);
    president.executeForm(pardon2);

  } catch (const std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl << "=== Tests completed ===" << std::endl;
  return 0;
}
