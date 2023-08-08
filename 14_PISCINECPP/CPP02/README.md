## CPP02

### POLYMORPHISM AD-HOC
	surcharge de fonction
	permet de définir plusieurs fonctions ayant le meme nom mais ayant des paramètres différents

### SURCHARGE D'OPERATEUR
	Une technique qui permet de realiser des opérations mathématiques intelligentes entre mes objets.

	- Operateur de comparaison:
		bool operator==(Objet const& a, Objet const& b)
			const& car on ne veut pas que a et b peuvent être modifiables

	- surcharge de l'operateur de sortie : ostream c'est un flux de sortie, permet de controler comment objet est affiche lorsqu'il est utilise avec l'operateur '<<'
		std::ostream & operator<<(std::ostream & o, Fixed const & other) {
  			o << other.toFloat();
   			return o;
   		}



### FORME CANONIQUE
	Utilisé pour la gestion des ressources.
	On s'assure qu'une classe a un seul constructeur et destructeur par défaut, un destructeur et un constructeur de copie, et un
	operateur d'assignation.

	- Constructeur de copie : comme son nom l'indique creer un nouvel objet en utilisant un objet existant. Le constructeur de copie utilise l;operateur d'assignation par copie pour effectuer la copie des valeurs de l'objet 'other'. Lorsque le constructeur de copie est appele, il cree une copie exacte de l'objet 'other' et l'affecte a l'objet en cours de construction.

	- Operateur d'assignation : une assignation comme 'obj1 = obj2' entrainera l'appel de cette fonction. Le but est de copier les valeurs d'un bjet dans un autre objet et affecter ses valeurs a l'objet this.
