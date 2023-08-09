#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <iostream>

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

    private:
        std::string _name;
        std::string _title;
};

#endif