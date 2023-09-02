#include "includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm(target, 72, 45), _target(target) {
    std::cout << YELLOW << "Constructor RobotomyRequestForm called for " << target << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src._target, 25, 5), _target(src._target)
{
    std::cout << YELLOW << "RobotomyRequestForm copy constructor called" << RESET << std::endl;
    *this = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src) { 
    (void) src;
    return *this; 
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    AForm::execute(executor);
    formAction();
}

void RobotomyRequestForm::formAction() const {

    bool isSuccessful = rand() % 2 == 0;

    std::cout << "Brrrrrrrr... " << std::endl;

    if (isSuccessful == true)
        std::cout << this->_target << " has been robotomized successfully 50% of the time" << std::endl;
    else
        std::cout << "Robotomy failed for " << this->_target << std::endl;
}