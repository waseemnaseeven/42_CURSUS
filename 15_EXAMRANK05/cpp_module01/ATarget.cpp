#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget(const std::string& type) : _type(type) {}

ATarget::~ATarget(){
    std::cout << "My job here is done!" << std::endl;
}

ATarget::ATarget(const ATarget& src) : _type(src._type) {

}

ATarget& ATarget::operator=(const ATarget& src) {
    _type = src._type;
    return (*this);
}

const std::string& ATarget::getType() const {
    return _type;
}

void ATarget::getHitBySpell(const ASpell& spell) const {
    std::cout << getType() << " has been " << spell.getEffects() << "!" << std::endl;
}