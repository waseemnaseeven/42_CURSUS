#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
    std::cout << GREEN << "Constructor called for " << _name << RESET << std::endl;
    if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade) {
    std::cout << GREEN << "Copy constructor called for " << _name << RESET << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &src)
        this->_grade = src._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << RED << "Destructor called for " << _name << RESET << std::endl;
}

const std::string& Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::incrementGrade() {
    if (_grade > 1)
        _grade--;
    else
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade() {
    if (_grade < 150)
        _grade++;
    else
        throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(AForm& form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << GREEN  << "Bureaucrat " << _name << " signed " << form.getName() << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << GREEN << "Bureaucrat " << _name << " cannot sign " << form.getName() << " because " << e.what() << RESET << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const& form) const
{
    try
    {
        form.execute(*this);
        std::cout << GREEN  << "Bureaucrat " << _name << " executed " << form.getName() << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << GREEN << "Bureaucrat " << _name << " couldn't execute " << form.getName() << " because " << e.what() << RESET << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low\n";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << GREEN << bureaucrat.getName() << ": bureaucrat grade " << bureaucrat.getGrade() << RESET << std::endl;
    return os;
}