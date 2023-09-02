#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"

AForm::AForm(std::string name, int gradeSign, int gradeExec) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {
    std::cout << BLUE << "Constructor AForm created for " << name << RESET << std::endl;
    if (gradeSign < 1 || gradeExec < 1)
        throw AForm::GradeTooHighException();
    else if (gradeSign > 150 || gradeExec > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm( AForm const & src ) : _name(src._name), _signed(src._signed), _gradeSign(src._gradeSign), _gradeExec(src._gradeExec) {}

AForm::~AForm( void ) {}

AForm&  AForm::operator=( AForm const & src ) {
    if (this != &src)
        this->_signed = src._signed;
    return *this;
}

std::string const   AForm::getName( void ) const {
    return this->_name;
}

bool                AForm::getSigned( void ) const {
    return this->_signed;
}

int                 AForm::getGradeSign( void ) const {
    return this->_gradeSign;
}

int                 AForm::getGradeExec( void ) const {
    return this->_gradeExec;
}

void                AForm::beSigned(const Bureaucrat & b ) {
    if (b.getGrade() > this->_gradeSign)
        throw AForm::GradeTooLowException();
    else
        this->_signed = true;
}

void                AForm::execute(Bureaucrat const & executor) const {
    if (!this->_signed)
        throw AForm::NotSignedException();
    if (executor.getGrade() > this->_gradeExec)
        throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& AForm) {
    os << BLUE << AForm.getName() << ": AForm grade " << AForm.getGradeSign() << ", AForm grade exec " << AForm.getGradeExec() << RESET << std::endl;
    return os;
}
