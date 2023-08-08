## CPP03

### HERITAGE
	- Heriter d'une classe, c'est dire que "A est un B".  La classe dérivée hérite de toutes les caractéristiques (attributs et méthodes) de la classe de base et peut ajouter de nouvelles fonctionnalités ou modifier le comportement existant sans avoir à réécrire le code déjà présent dans la classe de base. Ex: Class Personnage ou Animal puis creer des classes derives comme chien et chat ou encore Guerrier ou Mage.

	- remplacer la portee private par la portee protected de la classe a laquelle on  souhaite heriter. Protected se situe entre public(le plus permissif) et private(le plus restrictif). Les elements qui suivent protected ne sont pas accessibles depuis l'exterieur sauf si c'est une classe fille.

	- Heritage en diamant: L'héritage en diamant (diamond inheritance en anglais) est un phénomène qui se produit lorsque vous avez une hiérarchie de classes où une classe dérive de deux classes distinctes, et deux classes dérivées de cette première classe héritent également des mêmes classes de base. Cela forme une forme de structure de diamant, d'où le nom.
  A
 / \
B   C
 \ /
  D
	- Virtual : L'héritage virtuel (des classes) est utilisé pour éviter le problème du diamant ou de l'ambiguïté des classes lorsque la même classe de base est héritée par plusieurs chemins dans la hiérarchie d'héritage. Une seule instance de OtherObject sera partagée entre ces classes dérivées, évitant ainsi la duplication des membres de OtherObject.
		Exemple: class Object : virtual public OtherObject
	- Fonction virtual :Lorsqu'une fonction est déclarée comme virtual dans une classe de base, toute classe dérivée peut fournir sa propre implémentation de cette fonction. Lorsqu'un objet est créé en tant que pointeur ou référence à la classe de base, et que cette référence ou ce pointeur est utilisé pour appeler une fonction virtuelle, le compilateur détermine à l'exécution quelle version de la fonction doit être appelée, en fonction du type réel de l'objet (l'objet dérivé).


	- Using: le mot-clé using peut être utilisé pour hériter publiquement toutes les fonctions membres d'une classe de base dans une classe dérivée. Cela est particulièrement utile pour inclure les fonctions membres d'une classe de base qui ne sont pas des constructeurs ou destructeurs.

