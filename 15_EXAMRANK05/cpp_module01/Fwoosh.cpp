#include "Fwoosh.hpp"

Fwoosh::Fwoosh()
{
    _name = "Fwoosh";
    _effects = "fwooshed";
}

Fwoosh::~Fwoosh() {}

ASpell* Fwoosh::clone() const 
{
    return new Fwoosh(*this);
}

