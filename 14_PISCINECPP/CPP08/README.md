## CPP08

### TEMPLATED CONTAINERS

- `STL` : Standard Template Library, and the basic element is the `vector`
- There is different types of containers :
    - Les conteneurs séquences :  vector  ,  deque  ,  list  ,  stack  ,  queue  ,  priority_queue
    - Les conteneurs associatifs :  set  ,  multiset  ,  map  ,  multimap

- We can use `size()` it return the size of a vector, a list or a map.
- We can use `empty()`, `clear()`, `swap()`

![Screenshot](img/containers.png) // aller chercher l'image sur OCR

- vector
    - on accède aux éléments via les crochets comme pour les tableaux statiques
    - on ajoute des éléments à la fin via la méthode push_back()

- deque
    - double ended queue, ce qui donne en français, "queue à deux bouts".
    - on peut push_back et push_front

- stack
    - container qui n'autorise l'accès qu'au dernier élément ajouté
    - Structure LIFO

- queue
    - Structure FIFO

Les tables associatives sont des structures de données qui autorisent l'emploi de n'importe quel type comme index.

On dit qu'une map est une table associative permettant de stocker des paires clé-valeur. Vous pouvez donc créer un conteneur où les indices sont des string  , par exemple.

- map
    -


Performance : image!


### ITERATORS

Les itérateurs sont des objets ressemblant aux pointeurs, qui vont nous permettre de parcourir les conteneurs.

L'intérêt de ces objets est qu'on les utilise de la même manière quel que soit le conteneur ! Pas besoin de faire de distinction entre les vector  , les map ou les list

Les foncteurs, quant à eux, sont des objets que l'on utilise comme fonction. Nous allons alors pouvoir appliquer ces fonctions à tous les éléments d'un conteneur, par exemple.



- list
    -


### ALGORITHMS





