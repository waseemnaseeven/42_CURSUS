#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

    public:
        AForm( std::string name, int gradeSign, int gradeExec );
        AForm( AForm const & src );
        virtual ~AForm( void );

        AForm &  operator=( AForm const & rhs );

        std::string const   getName( void ) const;
        bool                getSigned( void ) const;
        int                 getGradeSign( void ) const;
        int                 getGradeExec( void ) const;

        void                beSigned( const Bureaucrat & b );
        virtual void execute(Bureaucrat const & executor) const = 0;
        
        class GradeTooHighException : public std::exception {
            public:
                virtual const char * what() const throw()
                {
                    return "Grade is too high\n";
                }
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char * what() const throw()
                {
                    return "Grade is too low\n";
                }
        };

        class NotSignedException : public std::exception {
            public:
                virtual const char * what() const throw()
                {
                    return "Form not signed\n";
                }
        };
    
    private:
        std::string const   _name;
        bool                _signed;
        int const           _gradeSign;
        int const           _gradeExec;
};

std::ostream& operator<<(std::ostream& os, const AForm& AForm);

# endif