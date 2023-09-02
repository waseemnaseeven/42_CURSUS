#ifndef SHRUBBERY_HPP
# define SHRUBBERY_HPP

#include "includes/AForm.hpp"
#include <fstream>

class Bureaucrat;

class ShrubberyCreationForm : virtual public AForm {

    public:
        ShrubberyCreationForm(const std::string &target);
        virtual ~ShrubberyCreationForm();
        ShrubberyCreationForm(ShrubberyCreationForm const &src);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);
        virtual void execute(Bureaucrat const & executor) const;
    private:
        void formAction() const;
        const std::string _target;
};

#endif
