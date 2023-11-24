#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget() {}

ATarget::ATarget(const std::string& type) :
    _type(type) {}

ATarget::~ATarget() {}

ATarget::ATarget(const ATarget& src) {*this = src;}

ATarget& ATarget::operator=(const ATarget& src)
{
    this->_type = src._type;
    return *this;
}

const std::string &ATarget::getType() const 
{
    return this->_type;
}

void ATarget::getHitBySpell(const ASpell& spell) const
{
    std::cout << this->getType() << " has been " <<  spell.getEffects() << std::endl;
}