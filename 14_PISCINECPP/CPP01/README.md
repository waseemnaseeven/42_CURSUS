## CPP01

### ALLOCATION MEMOIRE
	Par défaut, le constructeur et le destructeur servent a instancier sur un emplacement mémoire un objet lié a ma classe, pour un nouvel objet on utilise new :
		Class Student
		{
			private:
				std::string _login;
			public:
				Student(std::string login) : _login(login)
				{
					std::cout << "Student " << this->_login << " is born" << std::endl;
				}
				~Student()
				{
					std::cout << "Student " << this->_login << " died" << std::endl;
				}
		};
		int main
		{
			Student stack = Student("Was"); // allocation statique
			Student* heap = new Student("Alicia"); // allocation dynamique

			delete heap; // destruction du nouvel objet (heap is destroyed)

			return (0); // destruction de l'objet standard (stack is destroyed)
		}

	- New
		Fonction new qui permet d'allouer dynamiquement de la mémoire
		Si plusieurs objet doivent être alloués alors : new Objet[n_objet];

		opérateur de placement new(adresse) Type(constructor_argmuments s'il y a)
		il est utilisé pour appelé explicitement le constructeur d'un objet dans un emplacement mémoire spécifique.
	- Delete
		delete objet;
		Si plusieurs : delete [] objet;

### POINTEURS SUR FONCTIONS MEMBRES
	pointeurs qui pveuent être utilisés pour appeler des fonctions membres d'une classe. Offrent une flexibilité supplémentaire en permettant d'accéder et d'appeler des fonctions membres à l'aide d'un pointeur plutôt qu'en utilisant directement l'objet de ma classe.

	Déclaration d'un pointeur de f° membre :
		void	(MyClass::*ptr)(constructor_arg);
	Initialisation du pointeur avec la fonction membre MyFunction:
		ptr = &MyClass::myFunction;
	Creation d'un objet (ou instance) de la class MyClass:
		MyClass obj;
	Appel de la fonction membre à l'aide du pointeur:
		(obj.*ptr)(42)

### TYPEDEF
	on creer un alias (avec typedef) pour definir un new name pour un type existant.
		ex : typedef void (Harl::*FunctionPtr)() const; pour un pointeur de fonction sans paramètre et sans type de retour
			- typedef : mot clé pour définir un alias de type
			- void : on connait
			- Harl::* : un pointeur de fonction membre de la classe Harl
			- FunctionPtr : nom de l'alias de type, on vapouvoir déclarer des variables de ce type.


### REFERENCES
	C'est un alias ou une autre appelation vers un objet existant.
	C'est un pointeur constant, tjrs déréférencé et qui n'est jamais NULL;
	Intérêt : ça complète les pointeurs, ca ne les remplace pas!

	declaration d'une reference :
		Type& nomReference = objet;
	- Type : Le type de l'objet auquel la référence est liée.
	- nomReference : Le nom de la référence.
	- objet : L'objet existant auquel la référence est liée.

	Exemple:
		int	nb_balls = 42;
		int* balls_ptr = &nb_balls;
		int& balls_ref = nb_balls; // une reference sur un int, c'est un pointeur constant donc elle pointera tjrs sur la même chose

		nb_balls = 42;
		balls_ptr = 42;
		balls_ref = 42;

	- Différence entre pointeurs et références:

		- Un pointeur est une variable qui contient l'adresse mémoire d'un autre objet. il permet d'accéder et de manipuler l'objet en utilisant cette adresse. Pour accéder à la valeur pointée ca serait:
			int x = 10;
			int* ptr = &x;  // Pointeur ptr pointe vers l'adresse de x
			int value = *ptr;  // Accès à la valeur pointée par ptr (valeur de x)

		Les pointeurs peuvent être réassignés pointer vers d'autres objets ou être NULL, alors que les références NON!

		- Une référence est utilisée pour manipuler l'objet de la même manière que s'il s'agissait de la variable elle-même.

### SWITCH INSTRUCTION
	Remplace une forêt de if...
