#pragma once 

#include <string>
#include <iostream>

class Warlock {

    private:
        std::string _name;
        std::string _title;
    
    public:
        Warlock(const std::string& name, const std::string& title);
        ~Warlock();
    Warlock(const Warlock& src);
    Warlock& operator=(const Warlock& src);
    
    const std::string& getName() const;
    const std::string& getTitle() const;
    void  setTitle(const std::string& title);
    void  introduce() const;

};
