#include "includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm(target, 25, 5), _target(target) {
    std::cout << YELLOW << "Constructor PresidentialPardonForm called for " << target << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src._target, 25, 5), _target(src._target)
{
    std::cout << YELLOW << "PresidentialPardonForm copy constructor called" << RESET << std::endl;
    *this = src;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src) { 
    (void) src;
    return *this; 
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    AForm::execute(executor);
    formAction();
}

void PresidentialPardonForm::formAction() const {
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}