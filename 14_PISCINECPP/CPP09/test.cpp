#include <algorithm>
#include <vector>
#include <cstdlib> //pour rand()
#include <ctime>   //pour time()
#include <iostream>
#include <iterator>
#include <fstream>
#include <deque>
using namespace std;

class Generer
{
public:
    int operator()() const
    {
        return rand() % 10;  //On renvoie un nombre entre 0 et 9
    }
};

class Afficher
{
public:
    void operator()(int a) const
    {
        cout << a << endl;
    }
};

int main()
{
    srand(time(0));
    vector<int> tab(100, -1);
    generate(tab.begin(), tab.end(), Generer());  //On génère des nombres aléatoires
    sort(tab.begin(), tab.end());

    for_each(tab.begin(), tab.end(), Afficher());   //Et on affiche les éléments
    ostream_iterator<double> it(cout, "\n");
    *it = 3.14;
    ifstream fichier("/home/was/Desktop/CPP09/coucou.txt");
    istream_iterator<double> bou(fichier);

    istream_iterator<double> end;         //Le signal de fin

    while(bou != end)   //Tant qu'on n'a pas atteint la fin
    {
        cout << *bou << endl;  //On lbou
        ++bou;                 //Et on avance
    }

    // std::deque<int> arr(4,5);
    // arr.push_back(5);
    // arr.push_back(6);
    // sort()
    // for (int i(0); i < 10;++i)
    //     std::cout << arr[i] << std::endl;

    std::vector<string> planets = {"Earth", "Mercure", "Venus", "Saturne", "Uranus", "Neptune", "Pluton", "Jupiter"};
    for (string planet : planets)
        std::cout << planet << std::endl;
    return 0;
}
