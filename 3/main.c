#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include <sys/time.h>
//include "functions.h"

typedef struct {
	char name[50];
	int wins;
	int draws;
	int loses;
	int scored;
	int missed;
	int points;
} commanddata;

int one_match(commanddata *data[], int **teams, int oneteam, int twoteam)
{
	srand(time(NULL));
	
	int winnerteam, goalsoneteam = 0, goalstwoteam = 0, goalsdraw = 0, result;
	
	int victoryoneteam = teams[oneteam - 1][twoteam * 2 - 2];
	int draw = teams[oneteam - 1][twoteam * 2 - 1];
	int victorytwoteam = teams[twoteam - 1][oneteam * 2 - 2];
	
	int winner = rand() % (victoryoneteam + draw + victorytwoteam) + 1;
	
	printf("\n\n\n%d %d %d\n", victoryoneteam, draw, victorytwoteam);
	
//	system("pause");
	
	if (winner > 0 && winner <= victoryoneteam) {
		result = 1;
		winner = victoryoneteam;
		winnerteam = oneteam;
		printf("1\n");
	} else if (winner > victoryoneteam && winner <= victoryoneteam + draw) {
		result = 2;
		winner = draw;
		winnerteam = 99;
		printf("2\n");
	} else if (winner > victoryoneteam + draw && winner <= victoryoneteam + draw + victorytwoteam) {
		result = 3;
		winner = victorytwoteam;
		winnerteam = twoteam;
		printf("3\n");
	}
	
	if (winner <= 100 && winner > 90) {
		if (result == 1) {
			goalsoneteam = rand() % 14 + 1;
			goalstwoteam = rand () % (goalsoneteam - 1);			
		} else if (result == 2) {
			goalsdraw = rand() % 1;	
		} else if (result == 3) {
			goalstwoteam = rand() % 14 + 1;
			goalsoneteam = rand () % (goalstwoteam - 1);
		}
	} else if (winner <= 90 && winner > 80) {
		if (result == 1) {
			goalsoneteam = rand() % 12 + 1;
			goalstwoteam = rand () % (goalsoneteam - 1);
		} else if (result == 2) {
			goalsdraw = rand() % 2;
		} else if (result == 3) {
			goalstwoteam = rand() % 12 + 1;
			goalsoneteam = rand () % (goalstwoteam - 1);
		}
	} else if (winner <= 80 && winner > 70) {
		if (result == 1) {
			goalsoneteam = rand() % 9 + 1;
			goalstwoteam = rand () % (goalsoneteam - 1);
		} else if (result == 2) {
			goalsdraw = rand() % 3;
		} else if (result == 3) {
			goalstwoteam = rand() % 9 + 1;
			goalsoneteam = rand () % (goalstwoteam - 1);
		}
	} else if (winner <= 70 && winner > 60) {
		if (result == 1) {
			goalsoneteam = rand() % 7 + 1;
			goalstwoteam = rand () % (goalsoneteam - 1);
		} else if (result == 2) {
			goalsdraw = rand() % 4;
		} else if (result == 3) {
			goalstwoteam = rand() % 7 + 1;
			goalsoneteam = rand () % (goalstwoteam - 1);
		}
	} else if (winner <= 60 && winner > 50) {
		if (result == 1) {
			goalsoneteam = rand() % 6 + 1;
			goalstwoteam = rand () % (goalsoneteam - 1);
		} else if (result == 2) {
			goalsdraw = rand() % 5;
		} else if (result == 3) {
			goalstwoteam = rand() % 6 + 1;
			goalsoneteam = rand () % (goalstwoteam - 1);
		}
	} else if (winner <= 50 && winner > 40) {
		if (result == 1) {
			goalsoneteam = rand() % 5 + 1;
			goalstwoteam = rand () % (goalsoneteam - 1);
		} else if (result == 2) {
			goalsdraw = rand() % 5;
		} else if (result == 3) {
			goalstwoteam = rand() % 5 + 1;
			goalsoneteam = rand () % (goalstwoteam - 1);
		}
	} else if (winner <= 40 && winner > 30) {
		if (result == 1) {
			goalsoneteam = rand() % 4 + 1;
			goalstwoteam = rand () % (goalsoneteam - 1);
		} else if (result == 2) {
			goalsdraw = rand() % 5;
		} else if (result == 3) {
			goalstwoteam = rand() % 4 + 1;
			goalsoneteam = rand () % (goalstwoteam - 1);
		}
	} else if (winner <= 30 && winner > 20) {
		if (result == 1) {
			goalsoneteam = rand() % 3 + 1;
			goalstwoteam = rand () % (goalsoneteam - 1);
		} else if (result == 2) {
			goalsdraw = rand() % 5;
		} else if (result == 3) {
			goalstwoteam = rand() % 3+ 1;
			goalsoneteam = rand () % (goalstwoteam - 1);
		}
	} else if (winner <= 20 && winner > 10) {
		if (result == 1) {
			goalsoneteam = rand() % 2 + 1;
			goalstwoteam = rand () % (goalsoneteam - 1);
		} else if (result == 2) {
			goalsdraw = rand() % 5;
		} else if (result == 3) {
			goalstwoteam = rand() % 2 + 1;
			goalsoneteam = rand () % (goalstwoteam - 1);
		}
	} else if (winner <= 10 && winner > 0) {
		if (result == 1) {
			goalsoneteam = 1;
			goalstwoteam = 0;
		} else if (result == 2) {
			goalsdraw = rand() % 5;
		} else if (result == 3) {
			goalstwoteam = 1;
			goalsoneteam = 0;
		}
	}
	
	printf("lol\n");
	
	if (result == 1) {
		data[oneteam - 1]->scored += goalsoneteam;
		data[twoteam - 1]->missed += goalsoneteam;
		data[oneteam - 1]->missed += goalstwoteam;
		data[twoteam - 1]->scored += goalstwoteam;
		data[oneteam - 1]->points += 3;
		data[oneteam - 1]->wins += 1;
		data[twoteam - 1]->loses += 1;
	} else if (result == 2) {
		data[oneteam - 1]->scored += goalsdraw;
		data[oneteam - 1]->missed += goalsdraw;
		data[twoteam - 1]->scored += goalsdraw;
		data[twoteam - 1]->missed += goalsdraw;
		data[oneteam - 1]->points += 1;
		data[twoteam - 1]->points += 1;
		data[oneteam - 1]->draws += 1;
		data[twoteam - 1]->draws += 1;
	} else if (result == 3) {
		data[oneteam - 1]->scored += goalsoneteam;
		data[twoteam - 1]->missed += goalsoneteam;
		data[oneteam - 1]->missed += goalstwoteam;
		data[twoteam - 1]->scored += goalstwoteam;
		data[twoteam - 1]->points += 3;
		data[twoteam - 1]->wins += 1;
		data[oneteam - 1]->loses += 1;
	}
	printf("\nname %d %d\nscored %d %d\nmissed %d %d\ndraws %d %d\npoints %d %d\nwins %d %d\nloses %d %d\n", oneteam, twoteam, data[oneteam - 1]->scored, data[twoteam - 1]->scored, data[oneteam - 1]->missed, data[twoteam - 1]->missed, data[oneteam - 1]->draws, data[twoteam - 1]->draws, data[oneteam - 1]->points, data[twoteam - 1]->points, data[oneteam - 1]->wins, data[twoteam - 1]->wins, data[oneteam - 1]->loses, data[twoteam - 1]->loses);
	printf("%d %d			%d %d\n\n", goalsoneteam, goalstwoteam, goalsdraw, goalsdraw);
	
		printf("\nlol\n");
	
	FILE *matchhistory = fopen("matchhistory.txt", "a");
	
		printf("\n%d %d %d %d %d\n", oneteam, goalsoneteam, goalsdraw, goalstwoteam, twoteam);
	
	if (result == 1) {
		fprintf(matchhistory, "%d %d %d %d\n", oneteam, goalsoneteam, goalstwoteam, twoteam);
	} else if (result == 2) {
		fprintf(matchhistory, "%d %d %d %d\n", oneteam, goalsdraw, goalsdraw, twoteam);
	} else if (result == 3) {
		fprintf(matchhistory, "%d %d %d %d\n", oneteam, goalsoneteam, goalstwoteam, twoteam);
	}
	
	fclose(matchhistory);
	
	return winnerteam;
}

void final_stage(commanddata data[], int **teams, int *finalstagenumberteams)
{
	srand(time(NULL));
	
	int answer, i, j, z, temp, number, winnerteam, oneteam, twoteam;
	int *final = (int*)malloc(2 * sizeof(int));
	int *semifinal = (int*)malloc(4 * sizeof(int));
	int *quarterfinals = (int*)malloc(8 * sizeof(int));
	int *finalstageteams = (int*)malloc(16 * sizeof(int));
	int *auxiliary_array = (int*)malloc(16 * sizeof(int));
	
	printf("Final stage 1(random) or 2(vybor): ");
	scanf("%d", &answer);
	while (answer != 1 && answer != 2) {
		printf("Error\n");
		scanf("%d", &answer);
	}
	
	if (answer == 1) {
		for (i = 0; i < 16; i++) {
			number = rand() % (16 - i);
			finalstageteams[i] = finalstagenumberteams[number];
			for (j = number; j < 15; j++) {
				temp = finalstagenumberteams[j];
				finalstagenumberteams[j] = finalstagenumberteams[j + 1];
				finalstagenumberteams[j + 1] = temp;
			}
		}
	} else if (answer == 2) {
/*		j = 1;
		for (i = 0; i < 16; i++) {
			if (i == 0 || i % 4 == 0) {
				printf("	%d gruppa\n", j++);
				z = 1;
			}
			printf("Enter %d element: ", z++);
			scanf("%d", &number);
			while (number < 1 || number > 32) {
				printf("\nError number, repeat number: ");
				scanf("%d", &number);
			}
			while (auxiliary_array[number - 1] == 1) {
				printf("Error\n");
				printf("\nEnter %d element: ", i + 1);
				scanf("%d", &number);
				while (number < 1 || number > 32) {
					printf("\nError number, repeat number: ");
					scanf("%d", &number);
				}
			}
		finalstageteams[i] = number;
		auxiliary_array[number - 1] = 1;
		}
*/	}
	
	for (z = 0; z < 4; z++) {
		j = 0;
		if (z == 0) {
			for (i = 0; i < 15; i += 2) {
				oneteam = finalstageteams[i];
				twoteam = finalstageteams[i + 1];
				quarterfinals[j++] = one_match(&data, teams, oneteam, twoteam);
			}
		} else if (z == 1) {
			for (i = 0; i < 7; i += 2) {
				oneteam = quarterfinals[i];
				twoteam = quarterfinals[i + 1];
				semifinal[j++] = one_match(&data, teams, oneteam, twoteam);
			}
		} else if (z == 2) {
			for (i = 0; i < 3; i += 2) {
				oneteam = semifinal[i];
				twoteam = semifinal[i + 1];
				final[j++] = one_match(&data, teams, oneteam, twoteam);
			}
		} else if (z == 3) {
			winnerteam = one_match(&data, teams, final[0], final[1]);
		}
	}
}

void group_stage(commanddata data[], int **teams)
{
	srand(time(NULL));
	
	int answer, i, j, z, number, temp, pawn;
	
	int *groupstagenumberteams = (int*)malloc(32 * sizeof(int));
	int *groupstageteams = (int*)malloc(32 * sizeof(int));
	int *finalstagenumberteams = (int*)malloc(16 * sizeof(int));
	int *auxiliary_array = (int*)malloc(16 * sizeof(int));
	
	for (i = 0; i < 32; i++) {
		groupstagenumberteams[i] = i + 1;
		groupstageteams[i] = 0;
		auxiliary_array[i] = 0;
	}
	
	printf("Group stage 1(random) or 2(sam sebe rezhiser): ");
	scanf("%d", &answer);
	while (answer != 1 && answer != 2) {
		printf("Error\n");
		scanf("%d", &answer);
	}
	
	if (answer == 1) { //randomnoe raspredelenie na gruppy
		for (i = 0; i < 32; i++) {
			number = rand() % (32 - i);
			groupstageteams[i] = groupstagenumberteams[number];
			for (j = number; j < 31; j++) {
				temp = groupstagenumberteams[j];
				groupstagenumberteams[j] = groupstagenumberteams[j + 1];
				groupstagenumberteams[j + 1] = temp;
			}
		}
	} else if (answer == 2) { //samostoyatel'noe raspredelenie na gruppy
		j = 1;
		for (i = 0; i < 32; i++) {
			if (i == 0 || i % 4 == 0) {
				printf("	%d gruppa\n", j++);
				z = 1;
			}
			printf("Enter %d element: ", z++);
			scanf("%d", &number);
			while (number < 1 || number > 32) {
				printf("\nError number, repeat number: ");
				scanf("%d", &number);
			}
			while (auxiliary_array[number - 1] == 1) {
				printf("Error\n");
				printf("\nEnter %d element: ", i + 1);
				scanf("%d", &number);
				while (number < 1 || number > 32) {
					printf("\nError number, repeat number: ");
					scanf("%d", &number);
				}
			}
		groupstageteams[i] = number;
		auxiliary_array[number - 1] = 1;
		}
	}
	
	printf("\nGROUPSTAGETEAMS ");
	
	for (i = 0; i < 32; i++) {
		printf("%d ", groupstageteams[i]);
	}
	
	for (i = 0; i < 32; i += 4) {
		pawn = one_match(&data, teams, groupstageteams[i], groupstageteams[i + 2]);
		
		printf("\nlol\n");
		
		pawn = one_match(&data, teams, groupstageteams[i + 1], groupstageteams[i + 3]);
		pawn = one_match(&data, teams, groupstageteams[i], groupstageteams[i + 1]);
		pawn = one_match(&data, teams, groupstageteams[i + 3], groupstageteams[i + 2]);
		pawn = one_match(&data, teams, groupstageteams[i + 3], groupstageteams[i]);
		pawn = one_match(&data, teams, groupstageteams[i + 2], groupstageteams[i + 1]);
	}
	
	for (z = 0; z <= 28; z += 4) {
		for (j = 0; j < 3; j++) {
			for (i = 0 + z; i < 3 + z; i++) {
				if (data[groupstageteams[i] - 1].points < data[groupstageteams[i + 1] - 1].points) {
					temp = groupstageteams[i];
					groupstageteams[i] = groupstageteams[i + 1];
					groupstageteams[i + 1] = temp;
				}
			}
		}
	}
	
	printf("\nGROUPSTAGETEAMS ");
	
	for (i = 0; i < 32; i++) {
		printf("%d ", groupstageteams[i]);
	}
	
	j = 0;
	for (i = 0; i < 32; i += 4) {
		finalstagenumberteams[j++] = groupstageteams[i];
		finalstagenumberteams[j++] = groupstageteams[i + 1];
	}
	
	printf("\n");
	
	for (i = 0; i < 16; i++) {
		printf("%d ", finalstagenumberteams[i]);
	}
	
	final_stage(data, teams, finalstagenumberteams);
}

int main(void)
{
	FILE *matchhistory = fopen("matchhistory.txt", "w");
	fclose(matchhistory);
	
	setlocale(LC_ALL, "Rus");
	
	commanddata data[32];
	
	int answer,  i = 0, j, oneteam, twoteam, winnerteam;
	
	for (i = 0; i < 32; i++) {
		data[i].wins = 0;
		data[i].draws = 0;
		data[i].loses = 0;
		data[i].scored = 0;
		data[i].missed = 0;
		data[i].points = 0;
	}
	
	int  **teams = (int**)calloc(2048, sizeof(int*));
	for (i = 0; i < 2048; i++) {
		teams[i] = (int*)calloc(2048, sizeof(int));
    }
    
	FILE *probability = fopen("data.txt", "r");
	for (i = 0; i < 32; i++) {
		for (j = 0; j < 64; j++) {
			fscanf(probability, "%d", &teams[i][j]);
		}
	}
	fclose(probability);
	
	FILE *commandnames = fopen("teams.txt", "r");
	for (i = 0; !feof(commandnames); i++) {
		fgets(data[i].name, 50, commandnames);
	}
	fclose(commandnames);
	
	printf("play(1) or help(2)(error) or exit(3): ");
	
	scanf("%d", &answer);
	while (answer != 1 && answer != 2 && answer != 3) {
		printf("Error\n");
		scanf("%d", &answer);
	}
	
	if (answer == 1) {
		
		printf("liga(1) or one match(2): ");
		
		scanf("%d", &answer);
		while (answer != 1 && answer != 2) {
			printf("Error\n");
			scanf("%d", &answer);
		}
		
		if (answer == 1) {
			group_stage(data, teams);
			
			return 0;
		} else if (answer == 2) {
			
			printf("one team and two team: ");
			
			scanf("%d", &oneteam);
			while (oneteam < 1 || oneteam > 32) {
				printf("Error\n");
				scanf("%d", &oneteam);
			}
			scanf("%d", &twoteam);
			while (twoteam < 1 || twoteam > 32 || twoteam == oneteam) {
				printf("Error\n");
				scanf("%d", &twoteam);
			}
//			winnerteam = one_match(&data, teams, 32, 64, oneteam, twoteam);
			
			return 0;
		}
		
	} else if (answer == 2) {
		
	} else if (answer == 3) {
		
		return 0;
	}
	
//	system("pause");
	
	return 0;
}
