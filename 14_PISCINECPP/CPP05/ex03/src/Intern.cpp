#include "includes/Intern.hpp"

Intern::Intern() {
    std::cout << YELLOW << "Constructor Intern called for " << RESET << std::endl;
}

Intern::~Intern() {}

//Intern::Intern(Intern const &src) : AForm("", 0, 0)
//{
//    std::cout << YELLOW << "Intern copy constructor called" << RESET << std::endl;
//    *this = src;
//}

//Intern &Intern::operator=(Intern const &src) {
//    (void) src;
//    return *this;
//}

AForm *Intern::makePardon(std::string const &target) {
    return (new PresidentialPardonForm(target));
}

AForm *Intern::makeRobotomy(std::string const &target) {
    return (new RobotomyRequestForm(target));
}

AForm *Intern::makeShrubbery(std::string const &target) {
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(std::string form, std::string target) {

    std::string formTypes[3] = {"pardon", "robotomy", "shrubbery"};

    AForm *(Intern::*actions[3])(std::string const &) = {
        &Intern::makePardon,  &Intern::makeRobotomy, &Intern::makeShrubbery
    };

    for (size_t i = 0; i < 3; i++) {
    	if (formTypes[i].length() == form.length()) {
			if (formTypes[i] == form) {
				AForm *form = (this->*(actions[i]))(target);
            	return form;
			}
        }
    }
    return NULL;
}
