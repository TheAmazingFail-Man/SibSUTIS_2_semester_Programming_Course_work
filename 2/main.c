#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));
	int num, temp, i, j, z, a[10], b[10];
	
	for (i = 0; i < 10; i++) {
		a[i] = i;
		b[i] = 0;
	}
	for (i = 0; i < 10; i++) {
		num = rand() % (10 - i);
		b[i] = a[num];
		for (j = num; j < 9; j++) {
			temp = a[j];
			a[j] = a[j + 1];
			a[j + 1] = temp;
		}
	}
	for (i = 0; i < 10; i++) {
		printf("%d ", b[i]);
	}
	printf("\n");
	
/////////////////////////////////////////////////	
	
	for (z = 0; z <= 5; z += 5) {
		for (j = 0; j < 4; j++) {
			for (i = 0 + z; i < 4 + z; i++) {
				if (b[i] < b[i + 1]) {
					temp = b[i];
					b[i] = b[i + 1];
					b[i + 1] = temp;
				}
			}
		}
	}
	
	for (i = 0; i < 10; i++) {
		printf("%d ", b[i]);
	}
	printf("\n");
	
	for (i = 0; i < 10; i += 5) {
		a[j++] = b[i];
		a[j++] = b[i + 1];
	}
	for (i = 0; i < 4; i++) {
		printf("%d ", a[i]);
	}
	
//	рандом массива odna16finala
	
	int final[2], polufinal[4], chetvert'finala[8], odna16finala ;
	
	for (z = 0; z < 4; z++) {
		j = 0;
		if (z = 0) {
			for (i = 0; i < 15; i += 2) {
				oneteam = odna16finala[i];
				сортировка, как в групповом этапе
				twoteam = odna16finala[i + 1];
				chetvert'finala[j++] = one_match(oneteam, twoteam);
			}
		} else if (z = 1) {
			for (i = 0; i < 7; i += 2) {
				oneteam = chetvert'finala[i];
				сортировка, как в групповом этапе
				twoteam = chetvert'finala[i + 1];
				polufinal[j++] = one_match(oneteam, twoteam);
			}
		} else if (z = 2) {
			for (i = 0; i < 3; i += 2) {
				oneteam = polufinal[i];
				сортировка, как в групповом этапе
				twoteam = polufinal[i + 1];
				final[j++] = one_match(oneteam, twoteam);
			}
		} else if (z = 3) {
			сортировка, как в групповом этапе
			winner = one_match(final[0], final[1]);
		}
	}
	
	return 0;
}