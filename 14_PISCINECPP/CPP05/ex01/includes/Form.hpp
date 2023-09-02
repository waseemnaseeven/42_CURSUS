#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

    public:
        Form( std::string name, int gradeSign, int gradeExec );
        Form( Form const & src );
        virtual ~Form( void );

        Form &  operator=( Form const & rhs );

        std::string const   getName( void ) const;
        bool                getSigned( void ) const;
        int                 getGradeSign( void ) const;
        int                 getGradeExec( void ) const;

        void                beSigned( const Bureaucrat & b );
        
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
    
    private:
        std::string const   _name;
        bool                _signed;
        int const           _gradeSign;
        int const           _gradeExec;
};

std::ostream& operator<<(std::ostream& os, const Form& Form);

# endif