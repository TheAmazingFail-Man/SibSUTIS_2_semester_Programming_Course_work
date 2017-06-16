#include <stdio.h>
#include "functions.h"
#ifndef GRAPHICS_H
#define GRAPHICS_H

int checking(char *mode);
void group(char *a, int next, int *b);
void screen_01(team_information data[], int *r, int *gst, int *fsnt, int wt, int f[2], int sf[4], int qf[8], int fst[16], int g[4][16], int **g_g, int s);
void screen_011(team_information data[], int *r, int *gst, int *fsnt, int wt, int f[2], int sf[4], int qf[8], int fst[16], int g[4][16], int **g_g, int s);
void screen_02(team_information data[], int *r, int *gst, int *fsnt, int wt, int f[2], int sf[4], int qf[8], int fst[16], int g[4][16], int **g_g, int s);
void screen_03(team_information data[], int *r, int *gst, int *fsnt, int wt, int f[2], int sf[4], int qf[8], int fst[16], int g[4][16], int **g_g, int s);
void screen_04(team_information data[], int *r, int *gst, int *fsnt, int wt, int f[2], int sf[4], int qf[8], int fst[16], int g[4][16], int **g_g, int s);
void screen_05(team_information data[], int *r, int *gst, int *fsnt, int wt, int f[2], int sf[4], int qf[8], int fst[16], int g[4][16], int **g_g, int s);
void screen_06(team_information data[], int *r, int *gst, int *fsnt, int wt, int f[2], int sf[4], int qf[8], int fst[16], int g[4][16], int **g_g, int s);
void screen_07(team_information data[], int *r, int *gst, int *fsnt, int wt, int f[2], int sf[4], int qf[8], int fst[16], int g[4][16], int **g_g, int s);
void screen_08(team_information data[], int *r, int *gst, int *fsnt, int wt, int f[2], int sf[4], int qf[8], int fst[16], int g[4][16], int **g_g, int s);
void screen_062(team_information data[], int f[2], int g[4][16], int i);
void screen_061(team_information data[], int sf[4], int g[4][16], int f[2], int i);
void screen_052(team_information data[], int sf[4], int g[4][16], int i);
void screen_051(team_information data[], int qf[8], int sf[4], int g[4][16], int i);
void screen_081(team_information data[], int fst[16], int g[4][16], int i);
void screen_071(team_information data[], int i, int *gst);
void screen_031(int x, int *i);
void screen_032(team_information data[], int **g_g, int i);

#endif
