#include "Warlock.hpp"

int main()
{
    Warlock Richard("Richard", "The Magnificient");
    
    // std::cout << "My name is: " << Richard.getName() << std::endl;
    // std::cout << "My title is: " << Richard.getTitle() << std::endl;

    Richard.introduce();
    Richard.setTitle("The Brutal");
    Richard.introduce();
    Warlock Mongole("Xavier", "Le Mongole");
    Mongole.introduce();
    Mongole = Richard;
    Mongole.introduce();
    
    return (0);
}