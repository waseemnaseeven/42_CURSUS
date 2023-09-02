#ifndef INTERN_HPP
# define INTERN_HPP

#include "includes/AForm.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"

class Bureaucrat;

class Intern {
    public:
        Intern();
        ~Intern();
        Intern(const Intern &src);
        Intern &operator=(const Intern &src);
        AForm *makeForm(std::string form, std::string target);

        AForm *makePardon(std::string const &target);
        AForm *makeRobotomy(std::string const &target);
        AForm *makeShrubbery(std::string const &target);

};

#endif
