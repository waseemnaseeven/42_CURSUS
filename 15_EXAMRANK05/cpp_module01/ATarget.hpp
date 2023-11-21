#pragma once

#include "Warlock.hpp"

class ASpell;

class ATarget {
    protected:
        std::string _type;

    public:
        ATarget();
        ATarget(const std::string& type);
        virtual ~ATarget();
    
    ATarget(const ATarget& src);
    ATarget& operator=(const ATarget& src);

    const std::string getType() const;

    void getHitBySpell(const ASpell& spell) const;

    virtual ATarget* clone() const = 0;

};
