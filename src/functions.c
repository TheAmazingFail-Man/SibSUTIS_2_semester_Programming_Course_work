#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "graphics.h"

int check_data(int oneteam, int twoteam)
{
	int victoryoneteam, victorytwoteam, n = 0, pawn;
	
	if (oneteam == twoteam) {
		
		return 0;
	}
	
	FILE *test = fopen("data.txt", "r");
	for (n = 0; !feof(test); n++) {
		fscanf(test, "%d", &pawn);
		if (n == 64 * (oneteam - 1) + 2 * (twoteam - 1)) {
			victoryoneteam = pawn;
		} else if (n  == 64 * (twoteam - 1) + 2 * (oneteam - 1)) {
			victorytwoteam = pawn;
		}
	}
	fclose(test);
	
	if (victoryoneteam + victorytwoteam == 100) {
		
		return 0;
	} else {
		
		return -1;
	}
}

int final_one_match(int oneteam, int twoteam)
{
	int n = 0, error, pawn, victoryoneteam, victorytwoteam, goals_one_team = 0, goals_two_team = 0, max_goals_one_team, max_goals_two_team;
	
	error = check_data(oneteam, twoteam);
	if (error == -1) {
//		return 0;
	}
	
	FILE *probability = fopen("data.txt", "r");
	for (n = 0; !feof(probability); n++) {
		fscanf(probability, "%d", &pawn);
		if (n == 64 * (oneteam - 1) + 2 * (twoteam - 1)) {
			victoryoneteam = pawn;
		} else if (n  == 64 * (twoteam - 1) + 2 * (oneteam - 1)) {
			victorytwoteam = pawn;
		}
	}
	fclose(probability);
	
	max_goals_one_team = victoryoneteam / 10;
	if (victoryoneteam % 10 != 0) {
		max_goals_one_team++;
	}
	max_goals_two_team = victorytwoteam / 10;
	if (victorytwoteam % 10 != 0) {
		max_goals_two_team++;
	}
	
	while (goals_one_team == goals_two_team) {
		goals_one_team = rand() % max_goals_one_team;
		goals_two_team = rand() % max_goals_two_team;
	}
	
	FILE *goalshistory = fopen("goalshistory.txt", "a");
	
	fprintf(goalshistory, "%d %d\n", goals_one_team, goals_two_team);
	
	fclose(goalshistory);
	
	
	if (goals_one_team > goals_two_team) {
		
		return oneteam;
	} else if (goals_one_team == goals_two_team) {
		
		return -1;
	} else if (goals_one_team < goals_two_team) {
		
		return twoteam;
	}
	
	return 0;
}

int one_match(int oneteam, int twoteam, team_information *data)
{
	int winnerteam, result, n = 0, error, pawn, victoryoneteam, victorytwoteam, goals_one_team, goals_two_team, max_goals_one_team, max_goals_two_team;
	
	error = check_data(oneteam, twoteam);
	if (error == -1) {
		
//		return 0;
	}
	
	FILE *probability = fopen("data.txt", "r");
	for (n = 0; !feof(probability); n++) {
		fscanf(probability, "%d", &pawn);
		if (n == 64 * (oneteam - 1) + 2 * (twoteam - 1)) {
			victoryoneteam = pawn;
		} else if (n  == 64 * (twoteam - 1) + 2 * (oneteam - 1)) {
			victorytwoteam = pawn;
		}
	}
	fclose(probability);
	
	max_goals_one_team = victoryoneteam / 10;
	if (victoryoneteam % 10 != 0) {
		max_goals_one_team++;
	}
	max_goals_two_team = victorytwoteam / 10;
	if (victorytwoteam % 10 != 0) {
		max_goals_two_team++;
	}
	
	goals_one_team = rand() % max_goals_one_team;
	goals_two_team = rand() % max_goals_two_team;
	
	if (goals_one_team > goals_two_team) {
		winnerteam = oneteam;
		result = 1;
	} else if (goals_one_team == goals_two_team) {
		winnerteam = 99;
		result = 2;
	} else if (goals_one_team < goals_two_team) {
		winnerteam = twoteam;
		result = 3;
	}
	
	if (result == 1) {
		data[oneteam - 1].scored += goals_one_team;
		data[twoteam - 1].missed += goals_one_team;
		data[oneteam - 1].missed += goals_two_team;
		data[twoteam - 1].scored += goals_two_team;
		data[oneteam - 1].points += 3;
		data[oneteam - 1].wins += 1;
		data[twoteam - 1].loses += 1;
	} else if (result == 2) {
		data[oneteam - 1].scored += goals_one_team;
		data[twoteam - 1].missed += goals_one_team;
		data[oneteam - 1].missed += goals_two_team;
		data[twoteam - 1].scored += goals_two_team;
		data[oneteam - 1].points += 1;
		data[twoteam - 1].points += 1;
		data[oneteam - 1].draws += 1;
		data[twoteam - 1].draws += 1;
	} else if (result == 3) {
		data[oneteam - 1].scored += goals_one_team;
		data[twoteam - 1].missed += goals_one_team;
		data[oneteam - 1].missed += goals_two_team;
		data[twoteam - 1].scored += goals_two_team;
		data[twoteam - 1].points += 3;
		data[twoteam - 1].wins += 1;
		data[oneteam - 1].loses += 1;
	}

	FILE *matchhistory = fopen("matchhistory.txt", "a");
	
	fprintf(matchhistory, "%d %d %d %d\n", oneteam, goals_one_team, goals_two_team, twoteam);
	
	fclose(matchhistory);
		
	if (goals_one_team > goals_two_team) {
		
		return oneteam;
	} else if (goals_one_team == goals_two_team) {
		
		return 99;
	} else if (goals_one_team < goals_two_team) {
		
		return twoteam;
	}
	winnerteam = winnerteam + 1;
	winnerteam = winnerteam - 1;
	return 0;
}

void final_stage(team_information data[], int *restart, int *groupstageteams, int *finalstagenumberteams, int **goals_group)
{
	int i, j, z, x, y, temp, number;
	int winnerteam, final[2], semifinal[4], quarterfinals[8], finalstageteams[16], goals[4][16];
	
	for (i = 0; i < 16; i++) {
		number = rand() % (16 - i);
		finalstageteams[i] = finalstagenumberteams[number];
		for (j = number; j < 15; j++) {
			temp = finalstagenumberteams[j];
			finalstagenumberteams[j] = finalstagenumberteams[j + 1];
			finalstagenumberteams[j + 1] = temp;
		}
	}
	
	for (x = 0; x < 4; x++) {
		for (y = 0; y < 16; y++) {
		    goals[x][y] = 0;
		}
	}
	
	for (z = 0; z < 4; z++) {
		FILE *re_goalshistory = fopen("goalshistory.txt", "w");
		fclose(re_goalshistory);
		
		j = 0;
		if (z == 0) {
			for (i = 0; i < 15; i += 2) {
				quarterfinals[j] = final_one_match(finalstageteams[i], finalstageteams[i + 1]);
				
				j++;
			}
			
			FILE *write_goals_quarter = fopen("goalshistory.txt", "r");
			for (y = 0; !feof(write_goals_quarter); y++) {
			    fscanf(write_goals_quarter, "%d", &goals[0][y]);
			}
			fclose(write_goals_quarter);
		} else if (z == 1) {
			for (i = 0; i < 7; i += 2) {
				semifinal[j] = final_one_match(quarterfinals[i], quarterfinals[i + 1]);
				
				j++;
			}
			
			FILE *write_goals_semifinal = fopen("goalshistory.txt", "r");
			for (y = 0; !feof(write_goals_semifinal); y++) {
			    fscanf(write_goals_semifinal, "%d", &goals[1][y]);
			}
			fclose(write_goals_semifinal);
		} else if (z == 2) {
			final[0] = final_one_match(semifinal[0], semifinal[1]);
			final[1] = final_one_match(semifinal[2], semifinal[3]);
			
			FILE *write_goals_final = fopen("goalshistory.txt", "r");
			for (y = 0; !feof(write_goals_final); y++) {
			    fscanf(write_goals_final, "%d", &goals[2][y]);
			}
			fclose(write_goals_final);
		} else if (z == 3) {
			winnerteam = final_one_match(final[0], final[1]);
			
			FILE *write_goals_win = fopen("goalshistory.txt", "r");
			for (y = 0; !feof(write_goals_win); y++) {
			    fscanf(write_goals_win, "%d", &goals[3][y]);
			}
			fclose(write_goals_win);
		}
	}
	int s = 0;
	screen_01(data, restart, groupstageteams, finalstagenumberteams, winnerteam, final, semifinal, quarterfinals, finalstageteams, goals, goals_group, s);
}

void group_stage(team_information data[], int *restart)
{
	int i, j, z, number, temp;
	int groupstagenumberteams[32], groupstageteams[32], finalstagenumberteams[16];
	int **goals_group;
	goals_group = (int**)malloc(48 * sizeof(int*));
	for(i = 0; i < 48; i++)
		goals_group[i] = (int*)malloc(4 * sizeof(int));
	for (i = 0; i < 32; i++) {
		groupstagenumberteams[i] = i + 1;
		groupstageteams[i] = 0;
	}

	for (i = 0; i < 32; i++) {
		number = rand() % (32 - i);
		groupstageteams[i] = groupstagenumberteams[number];
		for (j = number; j < 31; j++) {
			temp = groupstagenumberteams[j];
			groupstagenumberteams[j] = groupstagenumberteams[j + 1];
			groupstagenumberteams[j + 1] = temp;
		}
	}

	for (i = 0; i < 32; i += 4) {
		one_match(groupstageteams[i], groupstageteams[i + 2], data);
		one_match(groupstageteams[i + 1], groupstageteams[i + 3], data);
		one_match(groupstageteams[i], groupstageteams[i + 1], data);
		one_match(groupstageteams[i + 3], groupstageteams[i + 2], data);
		one_match(groupstageteams[i + 3], groupstageteams[i], data);
		one_match(groupstageteams[i + 2], groupstageteams[i + 1], data);
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
	
	j = 0;
	for (i = 0; i < 32; i += 4) {
		finalstagenumberteams[j++] = groupstageteams[i];
		finalstagenumberteams[j++] = groupstageteams[i + 1];
	}
	
	for (i = 0; i < 48; i++) {
		for (j = 0; j < 4; j++) {
			goals_group[i][j] = 0;
		}
	}
	
	FILE *matchhistory_groupstage = fopen("matchhistory.txt", "r");
	for (i = 0; i < 48; i++) {
		for (j = 0; j < 4; j++) {
			fscanf(matchhistory_groupstage, "%d", &goals_group[i][j]);
		}
	}
	fclose(matchhistory_groupstage);

	final_stage(data, restart, groupstageteams, finalstagenumberteams, goals_group);
}
