#include "includes/Base.hpp"

/* generate return a pointer to the instance randomly */

Base* generate() {
    int random = std::rand() % 3;
	switch (random) {
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			return (NULL);
	}
}

/*
	- use of dynamic_cast to convert pointer Base* to the derived class A, B or C
	- if the original pointer is a derived class then it print the type

*/

void identify(Base * p) {
    if (dynamic_cast<A *>(p))
        std::cout << BOLDGREEN << "Pointer is A (" << p << ")" << RESET << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << BOLDYELLOW << "Pointer is B (" << p << ")" << RESET << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << BOLDBLUE << "Pointer is C (" << p << ")" << RESET << std::endl;
    else
        std::cout << BOLDWHITE << "Unknown pointer (" << p << ")" << RESET << std::endl;
}

/*
	- same thing but i use a ref and use a different way (try catch)
	- use of dynamic_cast to convert pointer Base* to the derived class A, B or C
	- if the original pointer is a derived class then it print the type

*/

void identify(Base &p) {
    // A
    try {
        A &result = dynamic_cast<A &>(p);
        std::cout << BOLDGREEN << "Pointer is A (" << &result << ")" << RESET << std::endl;
        return;
    } catch (std::exception const &bc) {
		std::cout << "Error: " << bc.what() << std::endl;
		    // B
		try {
			B &result = dynamic_cast<B &>(p);
			std::cout << BOLDYELLOW << "Pointer is B (" << &result << ")" << RESET << std::endl;
			return;
		} catch (std::exception const &bc) {
			std::cout << "Error: " << bc.what() << std::endl;
			   // C
			try {
				C &result = dynamic_cast<C &>(p);
				std::cout << BOLDBLUE << "Pointer is C (" << &result << ")" << RESET << std::endl;
				return;
			} catch (std::exception const &bc) {
				std::cout << "Error: " << bc.what() << std::endl;
			}
		}
    }

	std::cout << BOLDWHITE << "Pointer is unknown" << RESET  << std::endl;
}

int main () {

		// std::cout << BOLDMAGENTA << "\n 🔨 🔨  ========== CONSTRUCTOR ========== 🔨 🔨 \n" <<  RESET << std::endl;

		// std::cout << BOLDMAGENTA << "\n 💻💻 ========== EVENTS ========== 💻💻 \n" <<  RESET << std::endl;


		// std::cout << BOLDMAGENTA << "\n 🧨🧨 ========== DELETE ========== 🧨🧨 \n" <<  RESET << std::endl;

		// std::cout << BOLDMAGENTA << "\n 💥💥 ========== DESTRUCTOR ========== 💥💥 \n" <<  RESET << std::endl;

    std::srand(time(NULL));
    for (int i = 0; i < 6; i++) {
        // Base *base = NULL;
		Base *base = generate();
        //std::cout << std::endl;

        identify(base);
        std::cout << std::endl;
		//Base &ref = *base;
        identify(*base);

        delete base;
        std::cout << "__________________________________\n"
                  << std::endl;
    }



    return (0);
}
