#pragma once

#include "inicjalizacja.h"

// Funkcja odpowiadajaca za ruch pilki
void ruch_pilki() {

    if (dx - x > 0 && dy - y > 0) {

        if (fabs(dx - x) / fabs(dy - y) < 1) {
            y -= f;
            x = (y - b) / a;
            f -= f * 0.075;
            if (f < 0) { f = 0; };
        }
        else {
            x -= f;
            y = a * (x)+b;
            f -= f * 0.075;
            if (f < 0) { f = 0; };
        }
    }
    else if (dx - x > 0 && dy - y < 0) {

        if (fabs(dx - x) / fabs(dy - y) < 1) {
            y += f;
            x = (y - b) / a;
            f -= f * 0.075;
            if (f < 0) { f = 0; };
        }
        else {
            x -= f;
            y = a * (x)+b;
            f -= f * 0.075;
            if (f < 0) { f = 0; };
        }
    }
    else if (dx - x < 0 && dy - y < 0) {

        if (fabs(dx - x) / fabs(dy - y) < 1) {
            y += f;
            x = (y - b) / a;
            f -= f * 0.075;
            if (f < 0) { f = 0; };
        }
        else {
            x += f;
            y = a * (x)+b;
            f -= f * 0.075;
            if (f < 0) { f = 0; };
        }

    }
    else if (dx - x < 0 && dy - y > 0) {

        if (fabs(dx - x) / fabs(dy - y) < 1) {
            y -= f;
            x = (y - b) / a;
            f -= f * 0.075;
            if (f < 0) { f = 0; };
        }
        else {
            x += f;
            y = a * (x)+b;
            f -= f * 0.075;
            if (f < 0) { f = 0; };
        }

    }

}

// Funkcja odpowiadaj¹ca za kolizje
void kolizcje(ALLEGRO_SAMPLE* odbicie) {

    if (x <= 320) {
        //lewy bok
        dx = (x - dx);
        a = (y - dy) / (x - dx);
        b = y - (a * x);

        al_play_sample(odbicie, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
    }
    else if (x >= 1600) {
        //prawy bok
        dx = x + (x - dx);
        a = (y - dy) / (x - dx);
        b = y - (a * x);

        al_play_sample(odbicie, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
    }
    else if (y <= 180) {
        //góra
        dy = y + (y - dy);
        a = (y - dy) / (x - dx);
        b = y - (a * x);

        al_play_sample(odbicie, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
    }
    else if (y >= 900) {
        //dó³
        dy = y + (y - dy);
        a = (y - dy) / (x - dx);
        b = y - (a * x);

        al_play_sample(odbicie, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
    }

}

// Wskaznik uderzenia
void rysuj_kropki() {

    al_draw_filled_circle(x + (0.005 * f) * (x - dx), y + (0.005 * f) * (y - dy), 3.2 + (0.0025 * f), al_map_rgb(0, 0, 0));
    al_draw_filled_circle(x + (0.005 * f) * (x - dx), y + (0.005 * f) * (y - dy), 2.5 + (0.0025 * f), al_map_rgb(0 + (12.75 * 2 * f), 0, 255 - (12.75 * 2 * f)));

    al_draw_filled_circle(x + (0.01 * f) * (x - dx), y + (0.01 * f) * (y - dy), 3.2 + (0.005 * f), al_map_rgb(0, 0, 0));
    al_draw_filled_circle(x + (0.01 * f) * (x - dx), y + (0.01 * f) * (y - dy), 2.6 + (0.005 * f), al_map_rgb(0 + (12.75 * 2 * f), 0, 255 - (12.75 * 2 * f)));

    al_draw_filled_circle(x + (0.015 * f) * (x - dx), y + (0.015 * f) * (y - dy), 3.2 + (0.075 * f), al_map_rgb(0, 0, 0));
    al_draw_filled_circle(x + (0.015 * f) * (x - dx), y + (0.015 * f) * (y - dy), 2.7 + (0.075 * f), al_map_rgb(0 + (12.75 * 2 * f), 0, 255 - (12.75 * 2 * f)));

    al_draw_filled_circle(x + (0.02 * f) * (x - dx), y + (0.02 * f) * (y - dy), 3.2 + (0.1 * f), al_map_rgb(0, 0, 0));
    al_draw_filled_circle(x + (0.02 * f) * (x - dx), y + (0.02 * f) * (y - dy), 2.8 + (0.1 * f), al_map_rgb(0 + (12.75 * 2 * f), 0, 255 - (12.75 * 2 * f)));

    al_draw_filled_circle(x + (0.025 * f) * (x - dx), y + (0.025 * f) * (y - dy), 3.2 + (0.125 * f), al_map_rgb(0, 0, 0));
    al_draw_filled_circle(x + (0.025 * f) * (x - dx), y + (0.025 * f) * (y - dy), 2.9 + (0.125 * f), al_map_rgb(0 + (12.75 * 2 * f), 0, 255 - (12.75 * 2 * f)));

}

// Animacja trafienie
void trafienie(ALLEGRO_BITMAP* pilka, ALLEGRO_FONT* czcionka, int& koniec, ALLEGRO_BITMAP* tlo_lvl, ALLEGRO_BITMAP* traf_back, ALLEGRO_FONT* czcionka2, int& licznik, int& time) {

    if (x > 1490 && x < 1510 && y > 530 && y < 550) {

        while (skala > 0.0000001) {

            al_draw_scaled_bitmap(pilka, 0, 0, ball_weight, ball_height, x - 20, y - 20, ball_weight * skala, ball_height * skala, 0);
            skala -= 0.1;
            f = 0;

        }

        int czas = 5;

        while (czas) {

            al_draw_bitmap(tlo_lvl, 0, 0, 0);
            al_draw_bitmap(traf_back, 0, 0, 0);
            al_draw_textf(czcionka, al_map_rgb(240, 130, 20), 400, 300, 0, "HOLE IN %i ", licznik);
            al_draw_textf(czcionka2, al_map_rgb(240, 230, 20), 425, 700, 0, "NEXT LEVEL IN... %i", czas);
            al_draw_textf(czcionka2, al_map_rgb(240, 130, 20), 675, 550, 0, "TIME : %is", time);

            al_flip_display();

            al_rest(1);
            czas--;

            al_flip_display();
        }

        if (poziom < 4) {
            poziom++;
        }
        else {
            poziom = 0;
        }
        koniec = 1;

    }

}

// Funkcja odpowiadaj¹ca za przeszkody poziom 1
void przeszkody_lvl_1(ALLEGRO_SAMPLE* odbicie) {

    if ((x >= 600 && y >= 420 && y <= 660 && x <= 639) || (x >= 1240 && y >= 420 && y <= 660 && x <= 1289) || (x >= 920 && y >= 180 && y <= 420 && x <= 959) || (x >= 920 && y >= 650 && y <= 900 && x <= 959)) {
        // prawy bok
        dx = x + (x - dx);
        a = (y - dy) / (x - dx);
        b = y - (a * x);

        al_play_sample(odbicie, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
    }
    else if ((x >= 641 && y >= 420 && y <= 660 && x <= 680) || (x >= 1281 && y >= 420 && y <= 660 && x <= 1320) || (x >= 961 && y >= 180 && y <= 420 && x <= 1000) || (x >= 961 && y >= 650 && y <= 900 && x <= 1000)) {
        //lewy bok
        dx = (x - dx);
        a = (y - dy) / (x - dx);
        b = y - (a * x);

        al_play_sample(odbicie, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
    }
    else if ((x >= 601 && y >= 660 && y <= 670 && x <= 679) || (x >= 1241 && y >= 660 && y <= 670 && x <= 1319) || (x >= 921 && y >= 420 && y <= 430 && x <= 999)) {
        //góra
        dy = y + (y - dy);
        a = (y - dy) / (x - dx);
        b = y - (a * x);

        al_play_sample(odbicie, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
    }
    else if ((x >= 601 && y >= 410 && y <= 420 && x <= 679) || (x >= 1241 && y >= 410 && y <= 420 && x <= 1319) || (x >= 921 && y >= 640 && y <= 650 && x <= 999)) {
        //dó³
        dy = y + (y - dy);
        a = (y - dy) / (x - dx);
        b = y - (a * x);

        al_play_sample(odbicie, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
    }
    
}

// Funkcja odpowiadaj¹ca za przeszkody poziom 2
void przeszkody_lvl_2(ALLEGRO_SAMPLE* odbicie) {

    if ((x >= 720 && x <= 749) || (x >= 1140 && x <= 1169)) {
        // prawy bok
        dx = x + (x - dx);
        a = (y - dy) / (x - dx);
        b = y - (a * x);

        al_play_sample(odbicie, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
    }
    else if ((x <= 780 && x >= 750) || (x <= 1200 && x >= 1170)) {
        //lewy bok
        dx = (x - dx);
        a = (y - dy) / (x - dx);
        b = y - (a * x);

        al_play_sample(odbicie, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
    }

    // trafienia do dolkow

    if (x >= 650 && x <= 670 && y >= 270 && y <= 290) {

        f = 30;

    }
    else if (x >= 650 && x <= 670 && y >= 530 && y <= 550) {

        f = 0;
        x -= 200;
        y -= 200;

    }
    else if (x >= 650 && x <= 670 && y >= 770 && y <= 790) {

        f = 0;
        x = 840;
        y = 540;
        dx = 840;
        dy = 540;
        a = (y - dy) / (x - dx);
        b = y - (a * x);
        std::cout << 1;

    }
    else if (x >= 1070 && x <= 1090 && y >= 270 && y <= 290) {

        f = 0;
        x = 1240;
        y = 540;
        dx = 1240;
        dy = 540;
        a = (y - dy) / (x - dx);
        b = y - (a * x);
        std::cout << 1;

    }
    else if (x >= 1070 && x <= 1090 && y >= 530 && y <= 550) {

        f = 0;
        x = 340;
        y = 540;
        dx = 340;
        dy = 540;
        a = (y - dy) / (x - dx);
        b = y - (a * x);
        std::cout << 1;

    }
    else if (x >= 1070 && x <= 1090 && y >= 770 && y <= 790) {

        f = 30;

    }
    else if (x >= 1490 && x <= 1510 && y >= 270 && y <= 290) {

        f = 0;
        x = 340;
        y = 540;
        dx = 340;
        dy = 540;
        a = (y - dy) / (x - dx);
        b = y - (a * x);
        std::cout << 1;

    }
    else if (x >= 1490 && x <= 1510 && y >= 770 && y <= 790) {

        f = 0;
        x = 340;
        y = 540;
        dx = 340;
        dy = 540;
        a = (y - dy) / (x - dx);
        b = y - (a * x);
        std::cout << 1;

    }

}

// Funckja odpowiadaj¹ca za przeszkody poziom 3
void przeszkody_lvl_3(ALLEGRO_SAMPLE* picie) {

    if (x >= 400 && x <= 510 && y >= 300 && y <= 410) {

        if (wys_but_1 == 1) al_play_sample(picie, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);

        f_max = 8;
        
        wys_but_1 = 0;

    }
    else if (x >= 1200 && x <= 1310 && y >= 700 && y <= 810) {

        if (wys_but_2 == 1) al_play_sample(picie, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);

        f_max = 10;
        
        wys_but_2 = 0;

    }
    else if (x >= 900 && x <= 1010 && y >= 500 && y <= 610) {

        if (wys_but_3 == 1) al_play_sample(picie, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
        
        wys_but_3 = 0;

    }
    else if (x >= 500 && x <= 610 && y >= 700 && y <= 810) {

        if(wys_but_4 == 1) al_play_sample(picie, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
        
        f_max = 100;

        wys_but_4 = 0;

    }

}






