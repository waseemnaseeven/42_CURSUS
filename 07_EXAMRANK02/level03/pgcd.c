#include <stdio.h>
#include <stdlib.h>

int	pgcd(int nbr1, int nbr2)
{
	if (nbr2 != 0)
		return pgcd(nbr2, nbr1%nbr2);
	else
		return nbr1;
}

int main(int argc, char const *argv[])
{
	int n;
	if (argc == 3)
		printf("%d", n = pgcd(atoi(argv[1]), atoi(argv[2])));
	printf("\n");
}
