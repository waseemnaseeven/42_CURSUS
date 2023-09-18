#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <utility>
#include <iostream>
#include <map>
#include "ex00/includes/Colors.hpp"


class Addition {
	public:
		int operator()(int a, int b) {
			return a+b;
		}
};

class CompareLongueur
{
public:
    bool operator()(const std::string& a, const std::string& b)
    {
        return a.length() < b.length();
    }
};

int main()
{
	std::cout << BOLDMAGENTA << "\n\t ********** VECTOR ********** \n" << RESET << std::endl;

	std::vector<int> tab(5,4); //Un tableau contenant 5 entiers dont la valeur est 4
    tab.pop_back();      //On supprime la dernière case du tableau.
    tab.push_back(6);    //On ajoute un 6 à la fin du tableau.

    for(int i(0); i<tab.size(); ++i) //On utilise size() pour connaître le nombre d'éléments dans le vector
        std::cout << tab[i] << std::endl;      //On utilise les crochets [] pour accéder  aux éléments

	std::cout << BOLDMAGENTA << "\n\t ********** DEQUE ********** \n" << RESET << std::endl;

    std::deque<int> d(4,5); //Une deque de 4 entiers valant 5

    d.push_front(2);   //On ajoute le nombre 2 au début
    d.push_back(8);    //Et le nombre 8 à la fin

    for(int i(0); i<d.size(); ++i)
        std::cout << d[i] << " " << std::endl;    //Affiche 2 5 5 5 5 8

	std::cout << BOLDMAGENTA << "\n\t ********** STACK ********** \n" << RESET << std::endl;

	std::stack<int> LIFO;
    LIFO.push(3);
    LIFO.push(4);
    LIFO.push(5);

    std::cout << LIFO.top() << std::endl;

    LIFO.pop();

    std::cout << LIFO.top() << std::endl;

	std::cout << BOLDMAGENTA << "\n\t ********** QUEUE ********** \n" << RESET << std::endl;

	std::queue<int> FIFO;

	FIFO.push(3);
	FIFO.push(4);
	FIFO.push(5);

	std::cout << FIFO.front() << std::endl;

	FIFO.pop();

	std::cout << FIFO.front() << std::endl;

	std::cout << BOLDMAGENTA << "\n\t ********** ITERATOR ********** \n" << RESET << std::endl;

	d.push_front(42);
	std::deque<int>::iterator it;

	for (it = d.begin(); it!=d.end(); ++it){
		std::cout << *it << std::endl;
	}

	std::vector<std::string> arr;

	arr.push_back("my homies");
	arr.push_back("my bro");

	arr.insert(arr.begin(), "Yo");

	for (std::vector<std::string>::iterator it = arr.begin(); it!=arr.end(); ++it) {
		std::cout << *it << std::endl;
	}

	arr.erase(arr.begin());

	for (std::vector<std::string>::iterator it = arr.begin(); it!=arr.end(); ++it) {
		std::cout << *it << std::endl;
	}


	std::cout << BOLDMAGENTA << "\n\t ********** LIST ********** \n" << RESET << std::endl;

	std::list<int> liste;       //Une liste d'entiers
    liste.push_back(5);    //On ajoute un entier dans la liste
    liste.push_back(8);    //Et un deuxième
    liste.push_back(7);    //Et encore un !
	liste.push_front(2);

	for(std::list<int>::iterator it = liste.begin(); it!=liste.end(); ++it) {
		std::cout << *it << std::endl;
	}

	std::cout << BOLDMAGENTA << "\n\t ********** MAP ********** \n" << RESET << std::endl;

	std::map<std::string, double> poids; //Une table qui associe le nom d'un animal à son poids

    //On ajoute les poids de quelques animaux
    poids["souris"] = 0.05;
    poids["tigre"] = 200;
    poids["chat"] = 3;
    poids["elephant"] = 10000;

	std::map<std::string, double>::iterator trouve = poids.find("chien");

	if (trouve == poids.end()) {
		std::cout << "Le poids du chien n'est pas dans la table" << std::endl;
	}
	else {
		std::cout << "le chien pese" << trouve->second << std::endl;
	}


    //Et on parcourt la table en affichant le nom et le poids
    for(std::map<std::string, double>::iterator it=poids.begin(); it!=poids.end(); ++it)
    {
        std::cout << it->first << " pese " << it->second << " kg." << std::endl;
    }

	std::cout << BOLDMAGENTA << "\n\t ********** FONCTEURS ********** \n" << RESET << std::endl;

	Addition foncteur;
	int a(2), b(3);
	std::cout << a << "+" << b << " = " << foncteur(a,b) << std::endl;

    return 0;
}
