#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title) : 
    _name(name),
    _title(title)
{
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << this->_name << ": My job here is done!" << std::endl;
    std::map<std::string, ASpell *>::iterator it_begin = this->Spell_Book.begin();
    std::map<std::string, ASpell *>::iterator it_end = this->Spell_Book.end();
    while (it_begin != it_end)
    {
        delete it_begin->second;
        ++it_begin;
    }
    this->Spell_Book.clear();
}

Warlock::Warlock(const Warlock& src) {*this = src;}

Warlock& Warlock::operator=(const Warlock& src)
{
    this->_name = src._name;
    this->_title = src._title;
    this->Spell_Book = src.Spell_Book;
    return *this;
}

const std::string& Warlock::getName() const {return this->_name;}

const std::string& Warlock::getTitle() const {return this->_title;}

void Warlock::setTitle(const std::string& title) {this->_title = title;}

void Warlock::introduce() const 
{
    std::cout << this->getName() << ": I am " << this->getName() << ", " << this->getTitle() << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell)
{
    if (spell)
        Spell_Book[spell->getName()] = spell->clone();
}

void Warlock::forgetSpell(const std::string& spellName)
{
    std::map<std::string, ASpell*>::iterator it = Spell_Book.find(spellName);
    std::map<std::string, ASpell*>::iterator ite = Spell_Book.end();
    if (it != ite)
    {
        delete it->second;
        Spell_Book.erase(it);
    }
}

void Warlock::launchSpell(const std::string& spellName, ATarget& target) {
    std::map<std::string, ASpell*>::iterator it = Spell_Book.find(spellName);
    if (it != Spell_Book.end()) {
        it->second->launch(target);
    }
}