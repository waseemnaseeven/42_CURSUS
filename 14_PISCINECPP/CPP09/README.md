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

./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`

### FORDJOHNSON ALGORITHM

L'utilisation de l'algorithme de tri dépend de plusieurs facteurs, dont la taille de la séquence à trier. En ce qui concerne l'algorithme Ford-Johnson (ou le tri merge-insertion), il est courant de combiner l'insertion sort avec le tri fusion (merge sort) pour tirer parti des avantages de chaque algorithme en fonction de la taille des données.

La décision de basculer de l'insertion sort au tri fusion dépend souvent de la taille des sous-séquences à trier, car l'insertion sort est plus efficace pour de petites séquences, tandis que le tri fusion est plus adapté aux séquences plus grandes.
