#include "Fwoosh.hpp"
#include "ATarget.hpp"

Fwoosh::Fwoosh(void) : ASpell("Fwoosh", "fwooshed") {}

Fwoosh::~Fwoosh(void) {}

ASpell *Fwoosh::clone(void) const
{
    return new Fwoosh();
}