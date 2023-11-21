#pragma once 

#include "Warlock.hpp"

class ATarget;

class ASpell {
    protected:
        std::string _name;
        std::string _effects;

    public:
        ASpell();
        ASpell(const std::string& name, const std::string& effects);
        virtual ~ASpell();
    
    ASpell(const ASpell& src);
    ASpell& operator=(const ASpell& src);

    const std::string getName() const;
    const std::string getEffects() const;

    virtual ASpell* clone() const = 0;

    void launch(const ATarget& target) const;

};
