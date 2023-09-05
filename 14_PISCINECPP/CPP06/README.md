## CPP06

### CASTS

static_cast est un operateur de conversion qui permet de convertir un type de données en un autre.

```cpp
NouveauType resultat = static_cast<NouveauType>(valeur_a_convertir);
```

### SERIALIZE

Mecanisme qui converti un objet en sequence de bits qui peut etre stocke en memoire.

reinterpret_cast:
	- It is used to convert a pointer of some data type into a pointer of another data type, even if the data types before and after conversion are different.
	- It does not check if the pointer type and data pointed by the pointer is same or not.
