#include "includes/Bureaucrat.hpp"
#include "includes/Form.hpp"

Form::Form(std::string name, int gradeSign, int gradeExec) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {
    std::cout << BLUE << "Constructor form created for " << name << RESET << std::endl;
    if (gradeSign < 1 || gradeExec < 1)
        throw Form::GradeTooHighException();
    else if (gradeSign > 150 || gradeExec > 150)
        throw Form::GradeTooLowException();
}

Form::Form( Form const & src ) : _name(src._name), _signed(src._signed), _gradeSign(src._gradeSign), _gradeExec(src._gradeExec) {}

Form::~Form( void ) {}

Form&  Form::operator=( Form const & src ) {
    if (this != &src)
        this->_signed = src._signed;
    return *this;
}

std::string const   Form::getName( void ) const {
    return this->_name;
}

bool                Form::getSigned( void ) const {
    return this->_signed;
}

int                 Form::getGradeSign( void ) const {
    return this->_gradeSign;
}

int                 Form::getGradeExec( void ) const {
    return this->_gradeExec;
}

void                Form::beSigned(const Bureaucrat & b ) {
    if (b.getGrade() > this->_gradeSign)
        throw Form::GradeTooLowException();
    else
        this->_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& Form) {
    os << BLUE << Form.getName() << ": form grade " << Form.getGradeSign() << ", form grade exec " << Form.getGradeExec() << RESET << std::endl;
    return os;
}

