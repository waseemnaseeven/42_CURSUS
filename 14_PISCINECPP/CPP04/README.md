## CPP04

### POLYMORPHISME
	- choses ayant plusieurs formes
	- On aimerait appeler la bonne version d'une méthode, pour cela on va utiliser le mot clé "virtual"

### CLASSE ABSTRAITE

En C++, une classe abstraite est une classe qui ne peut pas être instanciée directement, c'est-à-dire qu'on ne peut pas créer d'objets à partir de cette classe. Elle est conçue pour servir de base à d'autres classes dérivées qui implémentent ses fonctions abstraites. Une fonction abstraite est une fonction membre déclarée dans une classe abstraite mais qui n'a pas de définition (pas de corps) dans cette classe. Les sous-classes dérivées de la classe abstraite doivent fournir des implémentations pour ces fonctions abstraites.

La principale utilité des classes abstraites réside dans la définition d'une interface commune pour un groupe de classes dérivées. Cela permet de garantir qu'un certain ensemble de fonctions ou de comportements spécifiques seront présents dans toutes les classes dérivées, `mais chaque classe dérivée peut implémenter ces fonctions de manière différente selon ses besoins.`

En ce qui concerne les fonctions membres virtuelles, elles sont utilisées pour réaliser le polymorphisme dans le C++. Lorsqu'une fonction membre est déclarée comme virtuelle dans une classe de base, les classes dérivées peuvent fournir leur propre implémentation de cette fonction. `Lorsque vous appelez une fonction virtuelle à travers un pointeur ou une référence à la classe de base, l'appel sera résolu à la fonction appropriée dans la classe dérivée, en fonction du type réel de l'objet.`

L'utilisation de fonctions membres virtuelles est cruciale pour obtenir le comportement polymorphique souhaité, notamment lorsque vous utilisez des pointeurs ou des références polymorphiques pour manipuler des objets de différentes sous-classes via un pointeur ou une référence à la classe de base. Cela permet d'implémenter des relations d'héritage plus flexibles et dynamiques, et c'est un élément clé du principe d'encapsulation et d'abstraction en programmation orientée objet.

En résumé, les classes abstraites et les fonctions membres virtuelles sont des concepts importants en C++ pour définir des interfaces communes et pour réaliser le polymorphisme, permettant ainsi une meilleure organisation et réutilisation du code.

### PLUS DE DETAILS

Un destructeur virtuel :

- Garantit la destruction correcte des sous-objets, si vous travaillez avec une hiérarchie de classes et que vous déclarez un destructeur virtuel dans la classe de base, cela garantit que le destructeur des sous-objets (objets des classes dérivées) sera également appelé. Cela permet de libérer correctement les ressources et de gérer les opérations de nettoyage spécifiques à chaque sous-classe.
- Polymorphisme lors de la destruction : Lorsque vous détruisez un objet à travers un pointeur de la classe de base, le destructeur virtuel assure que le destructeur approprié de la sous-classe est appelé. Cela implique que la liaison dynamique est utilisée pour déterminer quel destructeur doit être appelé en fonction du type réel de l'objet.

```cpp
class Animal {
public:
    virtual ~Animal() { }
};

class Dog : public Animal {
public:
    ~Dog() { }
};

class Cat : public Animal {
public:
    ~Cat() { }
};

int main() {
    Animal* ptr = new Dog;
    delete ptr; // Le destructeur virtuel assure que ~Dog() est appelé

    ptr = new Cat;
    delete ptr; // Le destructeur virtuel assure que ~Cat() est appelé

    return 0;
}

```

Fonction virtuelle classique:
Une fonction virtuelle classique est une fonction définie dans la classe de base, mais cette définition peut être redéfinie dans les classes dérivées. Lorsqu'une classe dérivée redéfinit une fonction virtuelle de la classe de base, elle fournit sa propre implémentation, mais elle peut toujours appeler la version de la classe de base à l'aide de la syntaxe ClasseBase::nomFonction().

```cpp
class Animal {
public:
    virtual void makeSound() const {
        std::cout << "Animal sound" << std::endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() const {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() const {
        std::cout << "Meow!" << std::endl;
    }
};
```
Fonction virtuelle pure:
Une fonction virtuelle pure est une fonction déclarée dans la classe de base, mais elle n'a pas d'implémentation. Elle est marquée avec = 0 à la fin de la déclaration. Une classe qui contient au moins une fonction virtuelle pure devient automatiquement une classe abstraite, ce qui signifie qu'elle ne peut pas être instanciée directement.

Les classes dérivées sont obligées de fournir une implémentation pour les fonctions virtuelles pures de la classe de base. Si une classe dérivée ne fournit pas d'implémentation pour une fonction virtuelle pure, elle devient également abstraite.

```cpp
class AAnimal {
public:
    virtual void makeSound() const = 0; // Fonction virtuelle pure
};

class Dog : public AAnimal {
public:
    void makeSound() const {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public AAnimal {
public:
    void makeSound() const {
        std::cout << "Meow!" << std::endl;
    }
};

```

### AUTRES
	- Makefile
		$^ = spécifies toutes les dépendances
		$< = spécifie la dépendance du fichier source
