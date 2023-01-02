#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int av1 = atoi(argv[1]);
	int av2 = atoi(argv[2]);

	if (argc == 3)
	{
		if (av1 > 0 && av2 > 0)
		{
			while (av1 != av2)
			{
				if (av1 > av2)
					av1 -= av2;
				else
					av2 -= av1;
			}
			printf("%d", av1);
		}
	}
	printf("\n");
	return (0);
}