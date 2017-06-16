#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphics.h"
#include "functions.h"

int checking(char *mode)
{
	if(mode[0] == '1' || mode[0] == '2' || mode[0] == '3' || mode[0] == '4' || mode[0] == '5' || mode[0] == '6' || mode[0] == '7' || mode[0] == '8' || mode[0] == '9' || mode[0] == '0')
		return 1;
	else
		return 0;
	return 0;
}

void group(char *a, int next, int *b)
{
	int i;
	char *mas;
        mas = (char*)malloc(8 * sizeof(char));
        mas[0] = 'A';
        for(i = 1; i < 8; i++)
                mas[i] = mas[0] + i;
	*a = mas[next-1];
	if(next == 1)
		*b = 0;
	else if(next == 2)
		*b = 4;
	else if(next == 3)
		*b = 8;
	else if(next == 4)
		*b = 12;
	else if(next == 5)
		*b = 16;
	else if(next == 6)
		*b = 20;
	else if(next == 7)
		*b = 24;
	else if(next == 8)
		*b = 28;
}

void screen_062(team_information data[], int f[2], int g[4][16], int i)
{
	int j = 0, k = 0;
	char *vmas;
        vmas = (char*)malloc(100 * sizeof(char));
        vmas[0] = ' ';
        k = 1;
        while(k < 11)
        {
                vmas[k] = ' ';
                k++;
        }
        vmas[k] = '*';
        vmas[k+1] = ' ';
        k = 13;
        while(data[f[i] - 1].name[j] != '\n')
        {
                vmas[k] = data[f[i] - 1].name[j];
                k++;
                j++;
        }
        k = k - 1;
        while(k < 35)
        {
                vmas[k] = ' ';
                k++;
        }
        vmas[k] = '*';
        vmas[k+1] = ' ';
        vmas[k+2] = g[3][i] + '0';
        vmas[k+3] = ' ';
        vmas[k+4] = ':';
        vmas[k+5] = ' ';
        vmas[k+6] = g[3][i+1] + '0';
        vmas[k+7] = ' ';
        vmas[k+8] = '*';
	vmas[k+9] = ' ';
        k = 45;
        j = 0;
        while(data[f[i+1] - 1].name[j] != '\n')
        {
                vmas[k] = data[f[i+1] - 1].name[j];
                k++;
                j++;
        }
        k = k - 1;
        while(k < 68)
        {
                vmas[k] = ' ';
                k++;
        }
        vmas[k] = '*';
        printf("%s\n", vmas);

}

void screen_061(team_information data[], int sf[4], int g[4][16], int f[2], int i)
{
	int j = 0, k = 0;
	char *vmas;
	vmas = (char*)malloc(100 * sizeof(char));
	vmas[0] = ' ';
	k = 1;
	while(k < 11)
	{
		vmas[k] = ' ';
		k++;
	}
	vmas[k] = '*';
	vmas[k+1] = ' ';
	k = 13;
	while(data[sf[i] - 1].name[j] != '\n')
	{
		vmas[k] = data[sf[i] - 1].name[j];
		k++;
		j++;
	}
	k = k - 1;
	while(k < 35)
	{
		vmas[k] = ' ';
		k++;
	}
	vmas[k] = '*';
	vmas[k+1] = ' ';
	vmas[k+2] = g[2][i] + '0';
	vmas[k+3] = ' ';
	vmas[k+4] = ':';
	vmas[k+5] = ' ';
	vmas[k+6] = g[2][i+1] + '0';
	vmas[k+7] = ' ';
	vmas[k+8] = '*';
	vmas[k+9] = ' ';
	k = 45;
	j = 0;
	while(data[sf[i+1] - 1].name[j] != '\n')
	{
		vmas[k] = data[sf[i+1] - 1].name[j];
		k++;
		j++;
	}
	k = k - 1;
	while(k < 68)
	{
		vmas[k] = ' ';
		k++;
	}
	vmas[k] = '*';
	printf("%s\n", vmas);
}

void screen_06(team_information data[], int *r, int *gst, int *fsnt, int wt, int f[2], int sf[4], int qf[8], int fst[16], int g[4][16], int **g_g, int s)
{
	int i = 0, q, j;
	char *mode;
	mode = (char*)malloc(100 * sizeof(char));
        system("clear");
        printf("                                                                               \n");
        printf("             ******************************************************            \n");
        printf("            *      Результаты 1/2 финала Чемпионата Мира 2018      *           \n");
        printf(" ***********                                                        ***********\n\n");
	printf("           **********************************************************          \n");
	screen_061(data,sf,g,f,i);
	printf("           **********************************************************          \n\n");
	printf("           **********************************************************          \n");
	i = 2;
	screen_061(data,sf,g,f,i);
	printf("           **********************************************************          \n\n");
	printf("           **********************************************************          \n");
	printf("           *                                                        *          \n");
	printf("           *          Финальный матч Чемпионата Мира 2018!          *          \n");
	printf("           *                                                        *          \n");
	printf("           **********************************************************          \n");
	i = 0;
	screen_062(data,f,g,i);
	printf("           **********************************************************          \n");
	printf("           ЧЕМПИОНОМ МИРА СТАНОВИТСЯ КОМАНДА ");
	if(g[3][0] > g[3][1])
		q = 0;
	else
		q = 1;
	j = 0;
	while(data[f[q] - 1].name[j] != '\n')
	{
		printf("%c", data[f[q] - 1].name[j]);
		j++;
	}
	printf("\n");
	printf("           С ПОБЕДОЙ!\n");
	printf(" [Нажмите любую клавишу для выхода из программы]: ");
	scanf("%s", mode);
}

void screen_052(team_information data[], int sf[4], int g[4][16], int i)
{
	int j = 0, k = 0;
	char *vmas;
	vmas = (char*)malloc(100 * sizeof(char));
	while(k < 39)
	{
		vmas[k] = ' ';
		k++;
	}
	vmas[39] = '*';
	vmas[40] = '*';
	vmas[41] = '*';
	vmas[42] = ' ';
	k = 43;
	while(data[sf[i] - 1].name[j] != '\n')
	{
		vmas[k] = data[sf[i] - 1]. name[j];
		j++;
		k++;
	}
	k = k - 1;
	while(k < 55)
	{
		vmas[k] = ' ';
		k++;
	}
	vmas[k] = '*';
	vmas[k+1] = ' ';
	vmas[k+2] = g[2][i] + '0';
	vmas[k+3] = ':';
	vmas[k+4] = g[2][i+1] + '0';
	vmas[k+5] = ' ';
	vmas[k+6] = '*';
	vmas[k+7] = ' ';
	k = 63;
	j = 0;
	while(data[sf[i+1] - 1].name[j] != '\n')
	{
		vmas[k] = data[sf[i+1] - 1].name[j];
		k++;
		j++;
	}
	k = k - 1;
	while(k < 77)
	{
		vmas[k] = ' ';
		k++;
	}
	vmas[k] = '*';
	printf("%s\n", vmas);
}

void screen_051(team_information data[], int qf[8], int sf[4], int g[4][16], int i)
{
	int j = 0, k = 0;
	char *vmas;
	vmas = (char*)malloc(100 * sizeof(char));
	vmas[0] = ' ';
	vmas[1] = '*';
	vmas[2] = ' ';
	k = 3;
	while(data[qf[i] - 1].name[j] != '\n')
	{
		vmas[k] = data[qf[i] - 1].name[j];
		k++;
		j++;
	}
	k = k - 1;
	while(k < 15)
	{
		vmas[k] = ' ';
		k++;
	}
	vmas[k] = '*';
	vmas[k+1] = ' ';
	vmas[k+2] = g[1][i] + '0';
	vmas[k+3] = ':';
	vmas[k+4] = g[1][i+1] + '0';
	vmas[k+5] = ' ';
	vmas[k+6] = '*';
	vmas[k+7] = ' ';
	k = 23;
	j = 0;
	while(data[qf[i + 1] - 1].name[j] != '\n')
	{
		vmas[k] = data[qf[i + 1] - 1].name[j];
		k++;
		j++;
	}
	k = k - 1;
	while(k < 37)
	{
		vmas[k] = ' ';
		k++;
	}
	vmas[k] = '*';
	vmas[k+1] = '*';
	vmas[k+2] = '*';
	printf("%s\n", vmas);
}

void screen_05(team_information data[], int *r, int *gst, int *fsnt, int wt, int f[2], int sf[4], int qf[8], int fst[16], int g[4][16], int **g_g, int s)
{
	int next = 1, i = 0, q = 0;
	char *mode;
        mode = (char*)malloc(100 * sizeof(char));
        while(next != 9 && next != 0)
{
	i = 0;
	system("clear");
	printf("\n");
	printf(" *****************************************************************************  \n");
        printf("  *                                                                         *   \n");
        printf("   *                      PLAY-OFF ЧЕМПИОНАТА МИРА 2018                    *    \n");
        printf("  *                                                                         *   \n");
        printf(" *****************************************************************************  \n");
	printf("                (1/4)                                   (1/2)                   \n");
	printf(" *************************************                                          \n");
	screen_051(data,qf,sf,g,i);
	printf(" ************************************* * *************************************  \n");
	screen_052(data,sf,g,i);
	printf(" ************************************* * *************************************  \n");
	i = 2;
	screen_051(data,qf,sf,g,i);
	printf(" *************************************                                          \n");
	printf("                                                                                \n");
	printf(" *************************************                                          \n");
	i = 4;
	q = 2;
	screen_051(data,qf,sf,g,i);
	printf(" ************************************* * *************************************  \n");
	screen_052(data,sf,g,q);
	printf(" ************************************* * *************************************  \n");
	i = 6;
	screen_051(data,qf,sf,g,i);
	printf(" *************************************                                          \n");
	printf(" [Хотите сыграть финальную стадию? Нажмите - 9 | Меню - 0]: ");
	scanf("%s", mode);
	if(mode[1] == '\0')
        {
                if(checking(mode) == 1)
                {
                       next = mode[0] - '0';
                }
        }

}
	if(next == 0)
                screen_01(data, &*r, gst, fsnt, wt, f, sf, qf, fst, g, g_g, s);
	else if(next == 9)
		screen_06(data, &*r, gst, fsnt, wt, f, sf, qf, fst, g, g_g, s);
}

void screen_04(team_information data[], int *r, int *gst, int *fsnt, int wt, int f[2], int sf[4], int qf[8], int fst[16], int g[4][16], int **g_g, int s)
{
	int next = 1, i = 0;
	char *mode;
	mode = (char*)malloc(100 * sizeof(char));
	while(next != 9 && next != 0)
{
	i = 0;
	system("clear");
        printf("                                                                               \n\n");
        printf("             ******************************************************            \n");
        printf("            *      Список команд, отобранных в результате 1/8      *           \n");
        printf(" ***********                                                        ***********\n\t\t%d. ", i + 1);
	for(i = 0; i < 8; i++)
	{
		printf("%s", data[qf[i] - 1].name);
		printf("           **********************************************************          \n\t\t");
		if(i + 2 != 9)
			printf("%d. ", i + 2);
	}
	printf("\n");
	printf(" [Чтобы перейти к четверть-финальной стадии - нажмите 9 | Меню - 0]: ");
	scanf("%s", mode);
	if(mode[1] == '\0')
        {
	        if(checking(mode) == 1)
        	{
	               next = mode[0] - '0';
		}
	}
}
	if(next == 0)
		screen_01(data, &*r, gst, fsnt, wt, f, sf, qf, fst, g, g_g, s);
	else if(next == 9)
		screen_05(data, &*r, gst, fsnt, wt, f, sf, qf, fst, g, g_g, s);
}

void screen_081(team_information data[], int fst[16], int g[4][16], int i)
{
	int j = 0, k = 0;
        char *vmas;
        vmas = (char*)malloc(100 * sizeof(char));
	while(k < 11)
	{
		vmas[k] = ' ';
		k++;
	}
	vmas[k] = '*';
	vmas[k+1] = ' ';
	k = 13;
	while(data[fst[i] - 1].name[j] != '\n')
	{
		vmas[k] = data[fst[i] - 1].name[j];
		k++;
		j++;
	}
	k = k - 1;
	while(k < 36)
	{
		vmas[k] = ' ';
		k++;
	}
	vmas[k] = '*';
	vmas[k+1] = ' ';
	vmas[k+2] = g[0][i] + '0';
	vmas[k+3] = ' ';
	vmas[k+4] = ':';
	vmas[k+5] = ' ';
	vmas[k+6] = g[0][i+1] + '0';
	vmas[k+7] = ' ';
	vmas[k+8] = '*';
	vmas[k+9] = ' ';
	k = 46;
	j = 0;
	while(data[fst[i+1] - 1].name[j] != '\n')
        {
                vmas[k] = data[fst[i+1] - 1].name[j];
                k++;
                j++;
        }
        k = k - 1;
        while(k < 68)
        {
                vmas[k] = ' ';
                k++;
        }
        vmas[k] = '*';
	printf("%s\n", vmas);
}

void screen_08(team_information data[], int *r, int *gst, int *fsnt, int wt, int f[2], int sf[4], int qf[8], int fst[16], int g[4][16], int **g_g, int s)
{
	int next = 1, i = 0;
        char *mode;
        mode = (char*)malloc(100 * sizeof(char));
        while(next != 9 && next != 0)
{
	i = 0;
        system("clear");
        printf("                                                                               \n\n");
        printf("             ******************************************************            \n");
        printf("            *         Игры, проведённые в этапе 1/8 финала         *           \n");
        printf(" ***********                                                        ***********\n");
	printf("           **********************************************************          \n");
        for(i = 0; i < 16; i+=2)
        {
                screen_081(data,fst,g,i);
                printf("           **********************************************************          \n");
	}
	printf(" [Для того, чтобы продолжить - нажмите 9 / Выход в меню - 0]: ");
        scanf("%s", mode);
	if(mode[1] == '\0')
                if(checking(mode) == 1)
                        next = mode[0] - '0';
}
        if(mode[0] == '9' && mode[1] == '\0')
                screen_04(data, &*r, gst, fsnt, wt, f, sf, qf, fst, g, g_g, s);
	else if(mode[0] == '0' && mode[1] == '\0')
                screen_01(data, &*r, gst, fsnt, wt, f, sf, qf, fst, g, g_g, s);
}

void screen_071(team_information data[], int i, int *gst)
{
	int x, j = 0, k = 3;
        char *varr;
        varr = (char*)malloc(200 * sizeof(char));
        varr[0] = ' ';
        varr[1] = '*';
	varr[2] = ' ';
        while(data[gst[i] - 1].name[j] != '\n')
        {
                varr[k] = data[gst[i] - 1].name[j];
                j++;
                k++;
        }
        k = k - 1;
	while(k < 26)
	{
		varr[k] = ' ';
		k++;
	}
	varr[k] = '*';
	varr[k+1] = ' ';
	varr[k+2] = data[gst[i] - 1].wins + '0';
	k = 29;
	while(k < 35)
	{
		varr[k] = ' ';
		k++;
	}
	varr[k] = '*';
	k = 36;
	varr[k] = ' ';
	varr[k+1] = data[gst[i] - 1].loses + '0';
	k = 38;
	while(k < 44)
	{
		varr[k] = ' ';
		k++;
	}
	varr[k] = '*';
	varr[k+1] = ' ';
	varr[k+2] = data[gst[i] - 1].draws + '0';
	k = 47;
	while(k < 53)
	{
		varr[k] = ' ';
		k++;
	}
	varr[k] = '*';
	varr[k+1] = ' ';
	k = 55;
	if(data[gst[i] - 1].scored < 10)
	{
		varr[k] = data[gst[i] - 1].scored + '0';
		varr[56] = ' ';
	}
	else
	{
		x = data[gst[i] - 1].scored;
		if(x > 9)
		{
			varr[k] = x / 10 + '0';
			varr[k+1] = x % 10 + '0';
		}
	}
	varr[57] = '/';
	varr[58] = ' ';
	k = 59;
	x = data[gst[i] - 1].missed;
	if(x < 10)
	{
		varr[k] = x + '0';
		varr[k+1] = ' ';
	}
	else
	{
		varr[k] = x / 10 + '0';
		varr[k+1] = x % 10 + '0';
	}
	k = 61;
	while(k < 62)
	{
		varr[k] = ' ';
		k++;
	}
	varr[k] = '*';
	varr[k+1] = ' ';
	varr[k+2] = data[gst[i] - 1].points + '0';
	k = 65;
	while(k < 71)
	{
		varr[k] = ' ';
		k++;
	}
	varr[k] = '*';
	printf("%s\n", varr);
}

void screen_031(int x, int *i)
{
	printf(" *****************************************************************            \n");
	printf(" *  'A'  *  'B'  *  'C'  *  'D'  *  'E'  *  'F'  *  'G'  *  'H'  *            \n");
	if(x == 1)
	{
		printf(" *       *********************************************************            \n");
        	printf(" *********                                                                    \n");
		*i = 0;
	}
	else if(x == 2)
	{
		printf(" *********       *************************************************            \n");
        	printf("         *********                                                            \n");
		*i = 6;
	}
	else if(x == 3)
        {
                printf(" *****************       *****************************************            \n");
                printf("                 *********                                                    \n");
		*i = 12;
	}
	else if(x == 4)
        {
                printf(" *************************       *********************************            \n");
                printf("                         *********                                            \n");
		*i = 18;
	}
	else if(x == 5)
        {
                printf(" *********************************       *************************            \n");
                printf("                                 *********                                    \n");
		*i = 24;
	}
	else if(x == 6)
        {
                printf(" *****************************************       *****************            \n");
                printf("                                         *********                            \n");
		*i = 30;
	}
	else if(x == 7)
        {
                printf(" *************************************************       *********            \n");
                printf("                                                 *********                    \n");
		*i = 36;
	}
	else if(x == 8)
        {
                printf(" *********************************************************       *            \n");
                printf("                                                         *********            \n");
		*i = 42;
	}
}

void screen_07(team_information data[], int *r, int *gst, int *fsnt, int wt, int f[2], int sf[4], int qf[8], int fst[16], int g[4][16], int **g_g, int s)
{
	int next = 1, i = 0, q;
        char *mode;
        mode = (char*)malloc(100 * sizeof(char));
        while(next != 0 && next != 9)
{
        system("clear");
	printf(" **************************************************************************** \n");
	printf(" * ПРОМЕЖУТОЧНАЯ СТАТИСТИКА СБОРНЫХ В ОТБОРОЧНОМ ЭТАПЕ                      * \n");
	printf(" **************************************************************************** \n");
        screen_031(next,&i);
	i = (next - 1) * 4;
        printf(" ***********************************************************************      \n");
        printf(" *                        *        *        *        *        *        *      \n");
        printf(" *    НАЗВАНИЕ СБОРНОЙ    * ВЫИГР. * ПОРАЖ. * НИЧЬИХ *  З/ПМ  * И.ОЧКИ *      \n");
        printf(" *                        *        *        *        *        *        *      \n");
        printf(" ***********************************************************************      \n");
	for(q = i; q < i + 4; q++)
{
	screen_071(data,q,gst);
        printf(" ***********************************************************************      \n");
}
	printf("\n Подсказка: Для смены группы нажмите 1-8 / Продолжить - 9 / Меню - 0          \n");
	printf(" [Выберите интересующий вас пункт]: ");
	scanf("%s", mode);
	if(mode[1] == '\0')
                if(checking(mode) == 1)
                        next = mode[0] - '0';
}
	if(mode[0] == '9' && mode[1] == '\0')
		screen_08(data, &*r, gst, fsnt, wt, f, sf, qf, fst, g, g_g, s);
	else if(mode[0] == '0' && mode[1] == '\0')
		screen_01(data, &*r, gst, fsnt, wt, f, sf, qf, fst, g, g_g, s);
}

void screen_032(team_information data[], int **g_g, int i)
{
	int x, j = 0, k = 3;
	char *varr;
	varr = (char*)malloc(200 * sizeof(char));
	varr[0] = ' ';
	varr[1] = '*';
	varr[2] = ' ';
	while(data[g_g[i][0] - 1].name[j] != '\n')
	{
		varr[k] = data[g_g[i][0] - 1].name[j];
		j++;
		k++;
	}
	k = k - 1;
	while(k < 29)
	{
		varr[k] = ' ';
		k++;
	}
	varr[29] = ' ';
	varr[30] = '*';
	varr[31] = ' ';
	k = 32;
	for(x = k; x < 37; x++)
	{
		varr[k] = ' ';
		k++;
	}
	varr[37] = g_g[i][1] + '0';
	varr[38] = ':';
	varr[39] = g_g[i][2] + '0';
	k = 40;
	for(x = k; x < 45; x++)
	{
		varr[k] = ' ';
		k++;
	}
	varr[k] = '*';
	varr[k+1] = ' ';
	k = 48;
	j = 0;
	while(data[g_g[i][3] - 1].name[j] != '\n')
	{
		varr[k] = data[g_g[i][3] - 1].name[j];
		j++;
		k++;
	}
	j = j - 1;
	k = k - 1;
	while(j < 29)
	{
		varr[k] = ' ';
		j++;
		k++;
	}
	varr[k] = '*';
	varr[k+1] = '\n';
	for(x = 0; x < k+2; x++)
		printf("%c", varr[x]);

}

void screen_03(team_information data[], int *r, int *gst, int *fsnt, int wt, int f[2], int sf[4], int qf[8], int fst[16], int g[4][16], int **g_g, int s)
{
        int next = 1, i = 0, q;
	char *mode;
	mode = (char*)malloc(100 * sizeof(char));
	while(next != 0 && next != 9)
{
        system("clear");
        screen_031(next,&i);
        printf(" **************************************************************************** \n");
        printf(" *                                                                          * \n");
        printf(" *                     Список игр в отборочном турнире                      * \n");
        printf(" *                                                                          * \n");
        printf(" **************************************************************************** \n");
	for(q = i; q < i + 6; q++)
	{
		screen_032(data,g_g,q);
		printf(" **************************************************************************** \n");
	}
        printf(" (Для просмотра других групп - нажмите 1-8) | Продолжить - 9 | Меню - 0       \n [Выберите интересующий вас пункт] : ");
        scanf("%s", mode);
	if(mode[1] == '\0')
		if(checking(mode) == 1)
			next = mode[0] - '0';
}
        if(next == 0)
                screen_01(data, &*r, gst, fsnt, wt, f, sf, qf, fst, g, g_g, s);
	else if(next == 9)
		screen_07(data, &*r, gst, fsnt, wt, f, sf, qf, fst, g, g_g, s);
}

void screen_02(team_information data[], int *r, int *gst, int *fsnt, int wt, int f[2], int sf[4], int qf[8], int fst[16], int g[4][16], int **g_g, int s)
{
	int next = 1, b;
	char a, *mode;
	mode = (char*)malloc(100 * sizeof(char));
	while(next != 0 && next != 9)
{
	group(&a,next,&b);
	system("clear");
	printf("\n");
        printf(" ******************************************************************************\n");
        printf(" *                                                                            *\n");
        printf(" *              Список отборочных групп на основе подбора команд              *\n");
        printf(" *                                                                            *\n");
        printf(" ******************************************************************************\n");
        printf("                                                                               \n");
	printf("                         ***************************                           \n");
	printf("                        *         GROUP '%c'         *                          \n", a);
	printf(" ***********************                             **************************\n\t\t\t");
	printf("%s", data[(gst[b]) - 1].name);
	printf("                       *******************************                         \n\t\t\t");
	printf("%s", data[(gst[b+1]) - 1].name);
	printf("                       *******************************                         \n\t\t\t");
	printf("%s", data[(gst[b+2]) - 1].name);
	printf("                       *******************************                         \n\t\t\t");
	printf("%s", data[(gst[b+3]) - 1].name);
	printf(" ***********************                             **************************\n");
	printf("                        *                           *                          \n");
	printf("                         ***************************                           \n\n");
	printf(" Нажмите 1-8 для просмотра других групп | Сыграть матчи - 9 | Выйти в меню - 0 \n [Выберите интересующий вас пункт] : ");
	scanf("%s", mode);
	if(mode[1] == '\0')
		if(checking(mode) == 1)
			next = mode[0] - '0';
}
	if(next == 0)
		screen_01(data, &*r, gst, fsnt, wt, f, sf, qf, fst, g, g_g, s);
	else if(next == 9)
		screen_03(data, &*r, gst, fsnt, wt, f, sf, qf, fst, g, g_g, s);
}

void screen_011(team_information data[], int *r, int *gst, int *fsnt, int wt, int f[2], int sf[4], int qf[8], int fst[16], int g[4][16], int **g_g, int s)
{
	int next = 1;
	char *mode;
	mode = (char*)malloc(100 * sizeof(char));
        while(next != 0)
{
	system("clear");
        printf("\n");
        printf(" ****************************************************************************** \n");
        printf("  *                                                                          *  \n");
        printf("   *                GENERATOR OF A TOURNAMENT GRID (v.1.1) 2017             *   \n");
        printf("  *                                                                          *  \n");
        printf(" ****************************************************************************** \n");
	printf(" *                                                                            * \n");
	printf(" *                       Помощь и справочные материалы                        * \n");
	printf(" *  Данная программа представляет собой модель проведения чемпионата мира,    * \n");
	printf(" *  основанная на алгоритмах, разработанных нашей командой.                   * \n");
	printf(" *  Благодаря применению реальных вероятностей на победу той или иной         * \n");
	printf(" *  команды, итоги матчей максимально приближены к настоящим исходам.         * \n");
	printf(" *                                                                            * \n");
	printf(" ****************************************************************************** \n");
	printf(" *                                                                            * \n");
	printf(" *  Для того, чтобы выбрать тот или иной пункт программы, нажмите необходимую * \n");
	printf(" *  клавишу, указанную в подсказке, после чего подтвердите клавишей 'Enter'.  * \n");
	printf(" *                                                                            * \n");
	printf(" *  Авторы: Артур Сергеев (дизайн), Александр Чедуров (алгоритм)              * \n");
	printf("  *         Илья Меньшиков (тестирование + поиск вероятностей)               *  \n");
	printf("   *                                                                        *   \n");
	printf("    ************************************************************************    \n");
	printf(" [Выйти в меню - нажмите 0]: ");
	scanf("%s", mode);
	if(mode[1] == '\0')
                if(checking(mode) == 1)
                        next = mode[0] - '0';
}
	if(next == 0)
		screen_01(data, &*r, gst, fsnt, wt, f, sf, qf, fst, g, g_g, s);
}

void screen_01(team_information data[], int *r, int *gst, int *fsnt, int wt, int f[2], int sf[4], int qf[8], int fst[16], int g[4][16], int **g_g, int s)
{
	int next = 0;
        char *mode;
        mode = (char*)malloc(100 * sizeof(char));
        while(next != 1 && next != 2 && next != 3 && next != 9)
{
	system("clear");
	printf("\n");
	printf(" ****************************************************************************** \n");
	printf("  *                                                                          *  \n");
	printf("   *                GENERATOR OF A TOURNAMENT GRID (v.1.1) 2017             *   \n");
	printf("  *                                                                          *  \n");
	printf(" ****************************************************************************** \n");
	printf(" *                                                                            * \n");
	printf(" *                             Добро пожаловать!                              * \n");
	printf(" *                                                                            * \n");
	printf("  *        Выберите один из пунктов меню для того, чтобы начать работу:      *  \n");
	printf("   *                                                                        *   \n");
	printf("   **************************************************************************   \n");
	printf("   *                                                                        *   \n");
	if(s == 0)
		printf("   *       > НАЧАТЬ ОТБОРОЧНЫЙ ТУРНИР                     (нажмите '1')     *   \n");
	else if(s == 1)
		printf("   *       > ПРОДОЛЖИТЬ (нажмите '1' | начать новую игру - нажмите '9')     *   \n");
	printf("   *                                                                        *   \n");
	printf("   **************************************************************************   \n");
	printf("   *                                                                        *   \n");
	printf("   *       > ПОМОЩЬ И СПРАВОЧНЫЕ МАТЕРИАЛЫ                (нажмите '2')     *   \n");
	printf("   *                                                                        *   \n");
	printf("   **************************************************************************   \n");
	printf("   *                                                                        *   \n");
	printf("   *       > ВЫЙТИ ИЗ ПРОГРАММЫ                           (нажмите '3')     *   \n");
	printf("   *                                                                        *   \n");
	printf("   **************************************************************************   \n");
	printf(" [Выберите интересующий вас пункт] : ");
	scanf("%s", mode);
        if(mode[1] == '\0')
                if(checking(mode) == 1)
                        next = mode[0] - '0';
}
        if(next == 1)
	{
		s = 1;
                screen_02(data, &*r, gst, fsnt, wt, f, sf, qf, fst, g, g_g, s);
	}
	else if(next == 2)
		screen_011(data, &*r, gst, fsnt, wt, f, sf, qf, fst, g, g_g, s);
	else if(next == 3)
		exit(1);
	else if(next == 9)
		*r = 1;
/*
	while((mode[0] != 1 + '0' || mode[1] != '\0') && mode[0] != 3 + '0' && mode[0] != 9 + '0' && mode[0] != 2 + '0')
	{
		screen_01(data, &*r, gst, fsnt, wt, f, sf, qf, fst, g, g_g, s);
	}
	if(mode[0] == 1 + '0' && mode[1] == '\0')
	{
		s = 1;
		screen_02(data, &*r, gst, fsnt, wt, f, sf, qf, fst, g, g_g, s);
	}
	else if(mode[0] == 3 + '0' && mode[1] == '\0')
		exit(1);
	else if(mode[0] == 9 + '0' && mode[1] == '\0')
		*r = 1;
	else if(mode[0] == 2 + '0' && mode[1] == '\0')
	{
		screen_011(data, &*r, gst, fsnt, wt, f, sf, qf, fst, g, g_g, s);
	}
*/
}
