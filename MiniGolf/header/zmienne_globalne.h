#pragma once

// zmienna poziomow
int poziom = 0; // 0 - menu, 9 - ustawienia, 1 - poziom 1,

// wysokosc i szerkosc okna
int display_height = 1080;
int display_weight = 1920;

// pozycja pilki
double x = 0;
double y = 0;

// ruch pilki
double dx = 0;
double dy = 0;
double f = 0;
double skala = 1;
double a = 0;
double b = 0;

// poziom 3
int f_max = 3;
int wys_but_1 = 1;
int wys_but_2 = 1;
int wys_but_3 = 1;
int wys_but_4 = 1;
int zmiana = 60;


// wielkosc pilki
int ball_height = 40;
int ball_weight = 40;

// kursor
int wybrany = 1;

int dotkniecia[3];
int czasy[3];
