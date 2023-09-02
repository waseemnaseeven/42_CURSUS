#ifndef ROBOTOMY_HPP
# define ROBOTOMY_HPP

#include "includes/AForm.hpp"
#include <cstdlib>

class Bureaucrat;

class RobotomyRequestForm : virtual public AForm {

    public:
        RobotomyRequestForm(const std::string &target);
        virtual ~RobotomyRequestForm();

        RobotomyRequestForm(RobotomyRequestForm const &src);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &src);

        virtual void execute(Bureaucrat const & executor) const;
    private:
        const std::string _target;
        void formAction() const;
};

#endif
