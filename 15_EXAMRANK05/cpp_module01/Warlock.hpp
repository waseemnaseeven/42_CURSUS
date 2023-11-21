#pragma once

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include "ASpell.hpp"
#include "ATarget.hpp"

class ASpell;

class Warlock {
    private:
        std::string _name;
        std::string _title;
        std::map<std::string, ASpell*> Spell_Book;

    public:
        Warlock(const std::string& name, const std::string& title);
        ~Warlock();
    
    Warlock(const Warlock& src);
    Warlock& operator=(const Warlock& src);

    const std::string& getName() const;
    const std::string& getTitle() const;
    void setTitle(const std::string& title);
    void introduce() const;

    void learnSpell(ASpell* spell);
    void forgetSpell(const std::string& spellName);
    void launchSpell(const std::string& spellName, ATarget& target);

};
