#include <iostream>

using namespace std;

template <typename T>
void swap(T *a, T *b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T> T min(T a, T b)
{
	return (a < b) ? a : b;
}

template <typename T> T max(T a, T b)
{
	return (a > b) ? a : b;
}

template <typename T> T random(T a)
{
	a = std::rand() % 4;
	return a;
}

template <class T> void bubbleSort(T a[], int n)
{
	for (int i = 0; i < n -1; i++){
		for (int j = n - 1; i < j; j--) {
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
		}
	}
}

int main()
{
    int a[5] = { 10, 50, 30, 40, 20 };
    int n = sizeof(a) / sizeof(a[0]);
	std::srand(time(NULL));
	int rand = 0;

    // calls template function
    bubbleSort<int>(a, n);
	cout << "Random int: " << random<int>(rand) << std::endl;


    cout << " Sorted array : ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
