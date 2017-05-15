#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));
	
	int num, i, b[10], c[10];
	
	for (i = 0; i < 10; i++) {
		b[i] = 0;
		c[i] = 0;
	}
	
	for (i = 0; i < 10; i++) {
		printf("Enter %d element: ", i + 1);
		scanf("%d", &num);
		while (num < 1 || num > 10) {
			printf("\nError number, repeat number: ");
			scanf("%d", &num);
		}
		while (b[num - 1] == 1) {
			printf("Error\n");
			printf("\nEnter %d element: ", i + 1);
			scanf("%d", &num);
			while (num < 1 || num > 10) {
				printf("\nError number, repeat number: ");
				scanf("%d", &num);
			}
		}
		c[i] = num;
		b[num - 1] = 1;
	}
	
	for (i = 0; i < 10; i++) {
		printf("%d ", c[i]);
	}
	
	return 0;
}
