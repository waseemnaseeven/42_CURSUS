#include "includes/ShrubberyCreationForm.hpp"
#include "includes/AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm(target, 145, 137), _target(target) {
    std::cout << YELLOW << "Constructor ShrubberyCreationForm called for " << target << RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) :  AForm(src._target, 145, 137) , _target(src._target)
{
    std::cout << YELLOW << "ShrubberyCreationForm copy constructor called" << RESET << std::endl;
    *this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src) {
    //  if (this != &src)
    //     this->_target = src._target;
    (void) src;
    return *this; 
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    AForm::execute(executor);
    formAction();
}

void ShrubberyCreationForm::formAction() const {
    std::ofstream output((this->_target + "_shrubbery").c_str());

    if (!output.is_open())
        throw std::runtime_error("Unable to open file.");
    output <<        "                                                     .\n"
                     "                                          .         ;  \n"
                     "             .              .              ;%     ;;   \n"
                     "               ,           ,                :;%  %;   \n"
                     "                :         ;                   :;%;'     .,   \n"
                     "       ,.        %;     %;            ;        %;'    ,;\n"
                     "         ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
                     "          %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
                     "           ;%;      %;        ;%;        % ;%;  ,%;'\n"
                     "            `%;.     ;%;     %;'         `;%%;.%;'\n"
                     "             `:;%.    ;%%. %@;        %; ;@%;%'\n"
                     "                `:%;.  :;bd%;          %;@%;'\n"
                     "                  `@%:.  :;%.         ;@@%;'   \n"
                     "                    `@%.  `;@%.      ;@@%;         \n"
                     "                      `@%%. `@%%    ;@@%;        \n"
                     "                        ;@%. :@%%  %@@%;       \n"
                     "                          %@bd%%%bd%%:;     \n"
                     "                            #@%%%%%:;;\n"
                     "                            %@@%%%::;\n"
                     "                            %@@@%(o);  . '         \n"
                     "                            %@@@o%;:(.,'         \n"
                     "                        `.. %@@@o%::;         \n"
                     "                           `)@@@o%::;         \n"
                     "                            %@@(o)::;        \n"
                     "                           .%@@@@%::;         \n"
                     "                           ;%@@@@%::;.          \n"
                     "                          ;%@@@@%%:;;;. \n"
                     "                      ...;%@@@@@%%:;;;;,.. \n";
    output.close();
    std::cout << this->_target << " requested a tree" << std::endl;
}