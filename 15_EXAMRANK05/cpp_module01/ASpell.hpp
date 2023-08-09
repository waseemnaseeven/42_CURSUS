#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <string>
#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell {

    public:
        ASpell(std::string name, std::string effects);
        virtual ~ASpell();
        ASpell(const ASpell& src);

    ASpell& operator=(const ASpell& src);
    virtual ASpell* clone() const = 0;
    
    std::string getName() const;
    std::string getEffects() const;
    void launch(const ATarget& target) const;

    protected:
        std::string _name;
        std::string _effects;
};

#endif