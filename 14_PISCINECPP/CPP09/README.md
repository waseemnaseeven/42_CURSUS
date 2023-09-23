## CPP09

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
