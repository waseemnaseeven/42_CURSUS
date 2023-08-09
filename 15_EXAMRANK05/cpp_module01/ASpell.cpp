#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell(std::string name, std::string effects) : _name(name), _effects(effects) {}

ASpell::~ASpell() {
    std::cout << this->_name << ": ";
    std::cout << "My job here is done!" << std::endl;
}

ASpell::ASpell(const ASpell& src) : _name(src._name), _effects(src._effects) {

}

ASpell& ASpell::operator=(const ASpell& src) {
    _name = src._name;
    _effects = src._effects;
    return (*this);
}

std::string ASpell::getName() const {
    return _name;
}

std::string ASpell::getEffects() const {
    return _effects;
}

void ASpell::launch(const ATarget& target) const {
    target.getHitBySpell(*this);
}
