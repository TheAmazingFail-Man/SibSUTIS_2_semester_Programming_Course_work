#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <time.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

typedef struct {
	char name[50];
	int wins;
	int draws;
	int loses;
	int scored;
	int missed;
	int points;
} team_information;

int check_data(int oneteam, int twoteam);
int final_one_match(int oneteam, int twoteam);
int one_match(int oneteam, int twoteam, team_information *data);
void final_stage(team_information data[], int *restart, int *groupstageteams, int *finalstagenumberteams, int **goals_group);
void group_stage(team_information data[], int *restart);

#endif
