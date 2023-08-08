## CPP00

### COMPILATION
	g++ puis -std=c++98 (pour standard et versionnage)
	iostream = en tête standard pour gérer les entrées et sorties (flux)
	-Wshadow : warning pour les spot les variables fantomes
	-Wno-shadow : annule le warning

### NAMESSPACES
	- Mecanisme qui permet de regrouper des identificateurs (noms de variables, fonctions, classes, etc.) en un espace de noms distinct.
	Cela permet d'éviter les collisions de noms et de mieux organiser le code.

	- std:: = référence au namespace standard du C++ qui contient de nombreuses bibliotheques et fonctionnalités de bases.
	Il est même nécessaire de l'utiliser pour accéder aux identificateurs (fonctions, classes, objets) définis dans le namespace 'std'
	Ex = 'std::cout' fait référence a l'objet 'cout' utilisé pour l'affichage de la sortie standard.
	On va pouvoir différencier les namespaces de mon code et ceux du standard.

### OBJET : CLASSE ET INSTANCE
	- hpp = init une classe
	- cpp = définir une classe (la structure d'un objet) càd la déclaration de l'ensemble des entités qui composeront un objet.
	- une instance est un objet avec un comportement et un état tous deux définis par la classe.

	Une classe est constituée de variables, appelées attributs (variables membres) et de fonctions, appelées méthodes (fonctions membres)

	droit d'acces et encapsulation :
		- public = attribut ou la méthode peut être appelé depuis l'extérieur de l'objet (a savoir le main)
		- private = attribut ou la méthode ne peut pas être appelé depuis l'exterieur de l'objet. Par défaut, tous les éléments d'une classe sont private.

### CONSTRUCTEUR ET DESTRUCTEUR
	2 méthodes particulières :
		- constructeur = méthode appelé automatiquement à chaque fois que l'on crée un objet basé sur cette classe
		- destructeur = méthode appelé automatiquement lorsqu'un objet est détruit, par ex a la fin de la f° dans laquelle il a été déclaré ou, si l'objet a été alloué dynamiquement avec new, lors d'un delete.

	Role du constructeur :
		- initialiser les attributs. On appelle ca 'liste d'initialisation'
			ex :
				MyClass(int aVal, double bVal, const std::string& cVal)
        : a(aVal), b(bVal), c(cVal)
   		{
        	// Constructeur de la classe MyClass
        	// Utilise la liste d'initialisation pour initialiser les membres de la classe
   		}

### FONCTIONS MEMBRES
	Fonction qui fait partie de ma classe, il a un paramètre par défaut (meme s'il y a un void), qui sera tjr un pointeur sur l'instance courante.

### this = POINTEUR SUR L'INSTANCE COURANTE
	C'est un pointeur sur la structure (instance ici) comme data->var. Au sein du code d'une fonction membres, si on veut référence a notre instance courante, on va utiliser this.

### const
	rendre une variable constante, c'est ne pas pouvoir lui changer de valeur après l'avoir modifié au moins 1 fois. One ne peut plus faire d'"assignation. Après l'initialisation, on ne peut plus la changer.

	const après le paramètre de la fonction mais avant le ";" veut dire que que cette fonction ne modifiera jamais l'instance courante.

	Ma méthode est constante lorsque je ne modifie pas mes attributs, par exemple pour de l'affichage.
	A contrario lorsque je mets à jour mes attributs, alors ma méthode ne sera pas constante.

### static
	- static variable
		signifie que la variable n'existe qu'en un seul exemplaire, elle est globale à la classe en quelque sorte. Autrement, chaque objet du type de la classe dispose de sa propre copie. Variable globale interne à la classe.
