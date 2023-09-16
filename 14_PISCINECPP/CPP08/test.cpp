#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> tab(5,4); //Un tableau contenant 5 entiers dont la valeur est 4
    tab.pop_back();      //On supprime la dernière case du tableau.
    tab.push_back(6);    //On ajoute un 6 à la fin du tableau.

    for(int i(0); i<tab.size(); ++i) //On utilise size() pour connaître le nombre d'éléments dans le vector
        cout << tab[i] << endl;      //On utilise les crochets [] pour accéder  aux éléments

    return 0;
}
