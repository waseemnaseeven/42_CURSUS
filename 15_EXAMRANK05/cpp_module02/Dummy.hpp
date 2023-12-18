#pragma once

#include "Warlock.hpp"
#include "ATarget.hpp"

class ATarget;

class Dummy : public ATarget {
    public:
        Dummy();
        virtual ~Dummy();
    
    virtual ATarget* clone() const;
};
