## CPP05

### REPETITIONS




### EXCEPTIONS

Les exceptions sont un moyen de gérer efficacement les erreurs qui pourraient survenir dans notre programme.

Le principe général des exceptions est le suivant :

on crée des zones où l'ordinateur va essayer le code en sachant qu'une erreur peut survenir ;

si une erreur survient, on la signale en lançant un objet qui contient des informations sur l'erreur ;

à l'endroit où l'on souhaite gérer les erreurs survenues, on attrape l'objet et on gère l'erreur.

Les mot-clés du C++ qui correspondent à ces actions sont les suivants :

try{ ...}  ("essaie", en français) signale une portion de code où une erreur peut survenir ;

throw  ("lance", en français) signale l'erreur en lançant un objet ;

catch(...){...}  ("attrape", en français) introduit la portion de code qui récupère l'objet et gère l'erreur.

- TRY:
```cpp
// Du code sans risque.
try
{
   // Du code qui pourrait créer une erreur.
}
```
- THROW:

"throw"  permet de "lancer la bouteille à la mer". La syntaxe est la suivante : "throw expression"

On peut lancer n'importe quoi comme objet ; par exemple :

un int qui correspond au numéro de l'erreur ;

ou une string contenant le texte de l'erreur.

```cpp
throw 123;   // On lance l'entier 123, par exemple si l'erreur 123 est survenue

throw string("Erreur fatale. Contactez un administrateur"); // On peut lancer un string.

throw Personnage; // On peut tout à fait lancer une instance d'une classe.

throw 3.14 * 5.12; // Ou même le résultat d'un calcul
```

- CATCH:

catch permet de créer un bloc de gestion d'une exception survenue.

Il faut créer un bloc catch  par type d'objet lancé.

Chaque bloc try doit obligatoirement être suivi d'un bloc catch  . Inversement, tout bloc catch doit être précédé d'un bloc try ou d'un autre bloc catch  .

La syntaxe est la suivante : catch (type const& e){...}

On attrape les exceptions par référence constante, d'où la présence du &  (pas par valeur), pour :

éviter une copie ;

préserver le polymorphisme de l'objet reçu.

Souvenez-vous des ingrédients du polymorphisme : une référence ou un pointeur sont nécessaires. Comme l'objet lancé pourrait avoir des fonctions virtuelles, on l'attrape via une référence, de sorte que les deux ingrédients soient réunis.

```cpp
try
{
    // Le bloc sensible aux erreurs.
}
catch(int e) //On rattrape les entiers lancés (pour les entiers, une référence n'a pas de sens)
{
   //On gère l'erreur
}
catch(string const& e) //On rattrape les strings lancés
{
   // On gère l'erreur
}
catch(Personnage const& e) //On rattrape les personnages
{
   //On gère l'erreur
}
```

Ce qu'on utilise dans le cadre des exercices, c'est la classe exception, on derive cette classe, classe de base de toutes les exceptions lancees par la bibliotheque standard

```cpp
class exception
{
public:
    exception() throw(){ } //Constructeur.
    virtual  exception() throw(); //Destructeur.

    virtual const char* what() const throw(); //Renvoie une chaîne "à la C" contenant des infos sur l'erreur.
};

```
On peut egalement utiliser stdexcept pour premacher le travail.
