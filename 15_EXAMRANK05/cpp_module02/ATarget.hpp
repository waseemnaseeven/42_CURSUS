#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <string>
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget {

    public:
        ATarget(const std::string& type);
        virtual ~ATarget();
        ATarget(const ATarget& src);

    ATarget& operator=(const ATarget& src);
    
    const std::string& getType() const;
    virtual ATarget* clone() const = 0;
    virtual void getHitBySpell(const ASpell& spell) const;

    protected:
        std::string _type;
};

#endif