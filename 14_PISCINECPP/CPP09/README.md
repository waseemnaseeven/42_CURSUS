## CPP09

### EX00 : bitcoin exchange

1- Choose a Container: You can use a C++ std::map container to store Bitcoin prices over time, where the date will be the key, and the Bitcoin price will be the value. This allows for efficient date lookup.

2- Parse the Bitcoin Price Database (CSV): Read the provided Bitcoin price CSV file, parse it line by line, and store the data in the std::map container.

3- Parse the Input File: Read the input file specified as a command-line argument, parse it line by line to extract dates and values.

4- Look Up Bitcoin Prices: For each date in the input file, look up the corresponding Bitcoin price from the std::map container. If an exact match is not found, find the closest date that is lower (using std::map::lower_bound).

5- Calculate the Value: Multiply the Bitcoin price by the value from the input file.

6- Handle Errors: If there are errors in the input file (e.g., invalid date, non-positive value, etc.), display appropriate error messages.

7- Output Results: Display the date, value, and calculated result for valid input lines.

8- Use std::ifstream and std::ostream: Use std::ifstream to read from files and std::ostream to display the output. You can use the << operator for output.

9- Use std::getline and String Splitting: Use std::getline to read lines from the input files, and then split each line into date and value using string manipulation functions or regular expressions

### SUITE DU CPP08

A remplir dans le CPP08 (oubli de push)

suite des algorithm
- generate(tab.begin(), tab.end(), function)
	- ici on applique function aux éléments de la liste, function peut être une classe
	- par ex, +1 sur un tableau de int

- count()
	- par ex: int nombre = count(tab.begin(), tab.end(), 2);

```cpp
class Generer
{
public:
    int operator()() const
    {
        return rand() % 10;  //On renvoie un nombre entre 0 et 9
    }
};

int main()
{
    srand(time(0));

    vector<int> tab(100,-1); //Un tableau de 100 cases

    generate(tab.begin(), tab.end(), Generer());  //On génère les nombres aléatoires

    int const compteur = count(tab.begin(), tab.end(), 5); //Et on compte les occurrences du 5

    cout << "Il y a " << compteur << " elements valant 5." << endl;

    return 0;
}
```
- find()
	- example below:

```cpp
int main()
{
    deque<char> lettres;

    deque<char>::iterator trouve = find(lettres.begin(), lettres.end(), 'a');

    if(trouve == lettres.end())
        cout << "La lettre 'a' n'a pas ete trouvee" << endl;
    else
        cout << "La lettre 'a' a ete trouvee" << endl;

    return 0;
}
```

- min_element(), max_element()



### ITERATOR SUR LES FLUX

- `istream_iterator<type> it (fichier);`
- `ostream_iterator<type> it (cout, "\n");`
- copiez depuis un fichier vers un vector avec l'algorithme copy
- Gérez le problème de la taille des tableaux avec `back_insert_iterator<container_type<type> > it2(vectorArray)`

```cpp
// lignes permettant de trouver le minimum des valeurs dans un fichier
ifstream fichier("C:/Nanoc/data.txt");
cout << *min_element(istream_iterator<int>(fichier), istream_iterator<int>())<< endl;
```
### ITERATOR SUR LES STRING

```cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

class Convertir
{
public:
    char operator()(char c) const
    {
        return toupper(c);
    }
};

int main()
{
    string chaine("Salut les developpeurs !");
    transform(chaine.begin(), chaine.end(), chaine.begin(), Convertir());
    cout << chaine << endl;
    return 0;
}
```

### OTHER THINGS

- Pourquoi utilisons-nous la sortie d'erreur pour les messages d'erreur :
    - séparation des flux de sortie, différencier les messages
    - distinction visuelle
    - redirection aisée, vers un fichier par exemple
    - convention établie

- isstringstream:
    - std::istringstream is a convenient way to treat a string as a source of input data that you can easily read from.
    - while (iss >> token) { ... }: This while loop reads individual tokens (words or values) from the iss input stream. It continues reading until there are no more tokens in the rpnExpression string.
