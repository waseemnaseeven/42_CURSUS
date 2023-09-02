#ifndef PRESIDENTIAL_HPP
# define PRESIDENTIAL_HPP

#include "includes/AForm.hpp"
#include <cstdlib>

class Bureaucrat;

class PresidentialPardonForm : virtual public AForm {

    public:
        PresidentialPardonForm(const std::string &target);
        virtual ~PresidentialPardonForm();

        PresidentialPardonForm(PresidentialPardonForm const &src);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &src);

        virtual void execute(Bureaucrat const & executor) const;
    private:
        const std::string _target;
        void formAction() const;
};

#endif
