#pragma once

#include <iostream>

#include "ASpell.hpp"

class Fwoosh : public ASpell
{
public:
    Fwoosh(void);
    ~Fwoosh(void);
    virtual ASpell *clone(void) const;

};
