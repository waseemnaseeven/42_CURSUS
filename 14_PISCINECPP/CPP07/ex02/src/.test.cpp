#include "includes/Array.hpp"

int main() {

	std::cout << BOLDMAGENTA << "\n 🔨 🔨  ========== CONSTRUCTOR ========== 🔨 🔨 \n" <<  RESET << std::endl;
	int * a = new int();
	Array<unsigned int> p(6);

	std::cout << BOLDMAGENTA << "\n 💻💻 ========== EVENTS ========== 💻💻 \n" <<  RESET << std::endl;
	std::cout << BOLDGREEN << "Test from the subject: " << *a << std::endl;
	p.print();
	std::cout << BOLDYELLOW << "\n The size of my array is " <<  p.size() << RESET << std::endl;
	std::cout << BOLDMAGENTA << "\n 🧨🧨 ========== DELETE ========== 🧨🧨 \n" <<  RESET << std::endl;
	//delete p;
	std::cout << BOLDMAGENTA << "\n 💥💥 ========== DESTRUCTOR ========== 💥💥 \n" <<  RESET << std::endl;


	return (0);
}
