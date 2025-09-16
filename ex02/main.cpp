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

    // Intern attempts to sign (should fail)
    std::cout << "Intern attempts to sign ShrubberyCreationForm:" << std::endl;
    try {
      intern.signForm(shrub);
    } catch (const std::exception& e) {
      std::cout << "Exception: " << e.what() << std::endl;
    }
    // Manager attempts to sign (should succeed)
    std::cout << "Manager attempts to sign ShrubberyCreationForm:" << std::endl;
    try {
      manager.signForm(shrub);
    } catch (const std::exception& e) {
      std::cout << "Exception: " << e.what() << std::endl;
    }
    // Intern attempts to execute (should fail)
    std::cout << "Intern attempts to execute ShrubberyCreationForm:" << std::endl;
    try {
      intern.executeForm(shrub);
    } catch (const std::exception& e) {
      std::cout << "Exception: " << e.what() << std::endl;
    }
    // Manager attempts to execute (should succeed)
    std::cout << "Manager attempts to execute ShrubberyCreationForm:" << std::endl;
    try {
      manager.executeForm(shrub);
    } catch (const std::exception& e) {
      std::cout << "Exception: " << e.what() << std::endl;
    }
  } catch (const std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl << "--- Test 2: RobotomyRequestForm ---" << std::endl;
  try {
    RobotomyRequestForm robotomy("Bender");
    std::cout << robotomy << std::endl;

    // Manager signs (should succeed)
    std::cout << "Manager attempts to sign RobotomyRequestForm:" << std::endl;
    try {
      manager.signForm(robotomy);
    } catch (const std::exception& e) {
      std::cout << "Exception: " << e.what() << std::endl;
    }
    // Manager executes (should succeed, random result)
    std::cout << "Manager attempts to execute RobotomyRequestForm (3 times):" << std::endl;
    for (int i = 0; i < 3; i++) {
      try {
        manager.executeForm(robotomy);
      } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
      }
    }
  } catch (const std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl << "--- Test 3: PresidentialPardonForm ---" << std::endl;
  try {
    PresidentialPardonForm pardon("Arthur Dent");
    std::cout << pardon << std::endl;

    // Director signs (should succeed)
    std::cout << "Director attempts to sign PresidentialPardonForm:" << std::endl;
    try {
      director.signForm(pardon);
    } catch (const std::exception& e) {
      std::cout << "Exception: " << e.what() << std::endl;
    }
    // Director executes (should fail)
    std::cout << "Director attempts to execute PresidentialPardonForm:" << std::endl;
    try {
      director.executeForm(pardon);
    } catch (const std::exception& e) {
      std::cout << "Exception: " << e.what() << std::endl;
    }
    // President executes (should succeed)
    std::cout << "President attempts to execute PresidentialPardonForm:" << std::endl;
    try {
      president.executeForm(pardon);
    } catch (const std::exception& e) {
      std::cout << "Exception: " << e.what() << std::endl;
    }
  } catch (const std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl << "--- Test 4: Form not signed error ---" << std::endl;
  try {
    ShrubberyCreationForm unsignedForm("garden");
    std::cout << unsignedForm << std::endl;
    std::cout << "President attempts to execute unsigned ShrubberyCreationForm:" << std::endl;
    try {
      president.executeForm(unsignedForm);
    } catch (const std::exception& e) {
      std::cout << "Exception: " << e.what() << std::endl;
    }
  } catch (const std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  std::cout << std::endl << "--- Test 5: Insufficient grade for signing ---" << std::endl;
  try {
    PresidentialPardonForm highLevel("Ford Prefect");
    std::cout << highLevel << std::endl;
    std::cout << "Intern attempts to sign PresidentialPardonForm:" << std::endl;
    try {
      intern.signForm(highLevel);
    } catch (const std::exception& e) {
      std::cout << "Exception: " << e.what() << std::endl;
    }
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
