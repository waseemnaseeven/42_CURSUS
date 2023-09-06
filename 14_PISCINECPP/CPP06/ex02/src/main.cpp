#include "includes/Base.hpp"

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

void identify(Base * p) {
    if (dynamic_cast<A *>(p))
        std::cout << GREEN << "Pointer is A (" << p << ")" << RESET << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << YELLOW << "Pointer is B (" << p << ")" << RESET << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << BLUE << "Pointer is C (" << p << ")" << RESET << std::endl;
    else
        std::cout << BOLDWHITE << "Unknown pointer (" << p << ")" << RESET << std::endl;
}

void identify(Base &p) {
    // A
    try {
        A &result = dynamic_cast<A &>(p);
        std::cout << GREEN << "Pointer is A (" << &result << ")" << RESET << std::endl;
        return;
    } catch (...) {
    }

    // B
    try {
        B &result = dynamic_cast<B &>(p);
        std::cout << YELLOW << "Pointer is B (" << &result << ")" << RESET << std::endl;
        return;
    } catch (...) {
    }

    // C
    try {
        C &result = dynamic_cast<C &>(p);
        std::cout << BLUE << "Pointer is C (" << &result << ")" << RESET << std::endl;
        return;
    } catch (...) {
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
        std::cout << std::endl;

        identify(base);
        std::cout << std::endl;
		Base &ref = *base;
        identify(&ref);

        delete base;
        std::cout << "__________________________________\n"
                  << std::endl;
    }



    return (0);
}
