
#include <typeinfo>
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <cstdlib>

int main() {

	int a = 33;
	double b = 33.33;
	float c = 33.33f;
	char d = 'd';
	std::string e = "e";
	float f = (double)a;
	typedef int *g;
	g h = &a;


	std::cout << "type of a: " << typeid(a).name() << std::endl;
	std::cout << "type of b: " << typeid(b).name() << std::endl;
	std::cout << "type of c: " << typeid(c).name() << std::endl;
	std::cout << "type of d: " << typeid(d).name() << std::endl;
	std::cout << "type of e: " << typeid(e).name() << std::endl;
	std::cout << "type of f: " << typeid(f).name() << std::endl;
	std::cout << "type of g: " << typeid(NULL).name() << std::endl;
	std::cout << "type of h: " << typeid(h).name() << std::endl;
}
