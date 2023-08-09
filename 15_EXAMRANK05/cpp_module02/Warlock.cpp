#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title) : _name(name), _title(title)
{
    std::cout << this->_name << ": ";
    std::cout << "This looks like another boring day." << std::endl;
}

Warlock::~Warlock(){
    std::cout << this->_name << ": ";
    std::cout << "My job here is done!" << std::endl;
}

Warlock::Warlock(const Warlock& src) : _name(src._name), _title(src._title) {

}

Warlock& Warlock::operator=(const Warlock& src) {
    _name = src._name;
    _title = src._title;
    return (*this);
}

const std::string& Warlock::getName() const {
    return _name;
}

const std::string& Warlock::getTitle() const {
    return _title;
}

void    Warlock::setTitle(const std::string& title) {
    this->_title = title;
}

void    Warlock::introduce() const {
    std::cout << this->_name << ": ";
    std::cout << "I am " << this->_name << ", " << this->_title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell)
{
	if (spell)
		_spells[spell->getName()] = spell;
}

void Warlock::forgetSpell(std::string SpellName)
{
	if (_spells.find(SpellName) != _spells.end())
		_spells.erase(_spells.find(SpellName));
}

void Warlock::launchSpell(std::string SpellName, ATarget & target)
{
	if (_spells.find(SpellName) != _spells.end())
		_spells[SpellName]->launch(target);
}