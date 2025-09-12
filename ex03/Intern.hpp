#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
  private:
    typedef AForm* (Intern::*FormCreator)(const std::string& target) const;

    struct FormInfo {
      std::string name;
      FormCreator creator;
    };

    static const FormInfo _formTypes[3];

    AForm* createShrubberyForm(const std::string& target) const;
    AForm* createRobotomyForm(const std::string& target) const;
    AForm* createPresidentialForm(const std::string& target) const;

  public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(const std::string& formName, const std::string& target) const;

    class FormNotFoundException : public std::exception {
      public:
        virtual const char* what() const throw();
    };
};

#endif
