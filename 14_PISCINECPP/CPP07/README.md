## CPP07

### TEMPLATES

- Templates is likes macros, but the difference is that the compiler does type-checking before template expansion.
- The simple idea is to pass the data type as a parameter so that we don’t need to write the same code for different data types.

![Screenshot](img/templates-cpp.jpg)

-

### OTHER THINGS

- Use of `sizeof(arr) / sizeof(arr[0])` instead of the writing the real value, to know the real size of an array. Ex:

```cpp
int main()
{
    int a[5] = { 10, 50, 30, 40, 20 };
    int n = sizeof(a) / sizeof(a[0]);
	//int n = 5;

    // calls template function
    bubbleSort<int>(a, n);

    cout << " Sorted array : ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
```
Cette approche garantit la `portabilite` du code. pcq la taille en octets d'un type de donnees peut varier en fonction de la machine. En utilisant les sizeof on s'assure que notre code fonctionnera correctement quelque soit la taille en octets de `int` sur la plateforme cible.

Cela indique clairement la taille du tableau en divisant la taille totale du tableau par la taille d'un de ses éléments.
