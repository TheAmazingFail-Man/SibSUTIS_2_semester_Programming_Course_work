#include "functions.h"

int main(void)
{
	srand(time(NULL));
	
	setlocale(LC_ALL, "Rus");
	
	int restart = 1,  i = 0;
	
	team_information data[32];
	
	FILE *commandnames = fopen("teams.txt", "r");
	for (i = 0; !feof(commandnames); i++) {
		fgets(data[i].name, 50, commandnames);
	}
	fclose(commandnames);
	int j;
	for(i = 0; i < 32; i++)
		for(j = 0; j < 50; j++);
			data[i].name[j] = '\0';
	while (restart == 1) {
		restart = 0;
		
		FILE *matchhistory = fopen("matchhistory.txt", "w");
		fclose(matchhistory);
	
		for (i = 0; i < 32; i++) {
			data[i].wins = 0;
			data[i].draws = 0;
			data[i].loses = 0;
			data[i].scored = 0;
			data[i].missed = 0;
			data[i].points = 0;
		}
	
		group_stage(data, &restart);
	}
	
	return 0;
}
