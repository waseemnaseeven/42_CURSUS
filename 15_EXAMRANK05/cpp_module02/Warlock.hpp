#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"

#include <map>

class Warlock {

    public:
        Warlock(const std::string& name, const std::string& title);
        ~Warlock();
        Warlock(const Warlock& src);

    Warlock& operator=(const Warlock& src);
    
    const std::string& getName() const;
    const std::string& getTitle() const;
    void  setTitle(const std::string& title);
    void  introduce() const;
    void learnSpell(ASpell *spell);
    void forgetSpell(std::string const spellName);
    void launchSpell(std::string const spellName, ATarget &target);

    private:
        std::string _name;
        std::string _title;
        std::map < std::string, ASpell * > _spells;
};

#endif