#include <iostream>
#include "Bureaucrat.hpp"

int main() {
  std::cout << "--- Test 1: Valid Bureaucrat creation ---" << std::endl;
  try {
    Bureaucrat b1("Zapp", 1);
    std::cout << b1 << std::endl;

    std::cout << std::endl << "--- Test 2: Test grade increment/decrement ---" << std::endl;
    Bureaucrat b2("Leela", 50);
    std::cout << "Before: " << b2 << std::endl;
    b2.incrementGrade();
    std::cout << "After increment: " << b2 << std::endl;
    b2.decrementGrade();
    std::cout << "After decrement: " << b2 << std::endl;

    std::cout << std::endl << "--- Test 3: Exception test - Grade too high ---" << std::endl;
    Bureaucrat b3("Bender", 1);
    std::cout << b3 << std::endl;
    b3.incrementGrade(); // This should throw an exception
  } catch (std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  try {
    std::cout << std::endl << "--- Test 4: Exception test - Grade too low ---" << std::endl;
    Bureaucrat b4("Fry", 150);
    std::cout << b4 << std::endl;
    b4.decrementGrade(); // This should throw an exception
  } catch (std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  try {
    std::cout << std::endl << "--- Test 5: Invalid grade in constructor ---" << std::endl;
    Bureaucrat b5("Professor", 0); // This should throw an exception
  } catch (std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  try {
    Bureaucrat b6("Zoidberg", 151); // This should throw an exception
  } catch (std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  return 0;
}
