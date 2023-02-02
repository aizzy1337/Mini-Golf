#pragma once

#include "inicjalizacja.h"
#include "kinematyka.h"

void poziom2(ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_DISPLAY* display, ALLEGRO_MOUSE_STATE& mysz, ALLEGRO_TIMER* timer, ALLEGRO_FONT* czcionka, ALLEGRO_EVENT& zdarzenie1, ALLEGRO_FONT* czcionka2, ALLEGRO_SAMPLE* odbicie, ALLEGRO_SAMPLE* uderzenie) {

    ALLEGRO_BITMAP* pilka = al_load_bitmap("resources/pilka_lvl_2.png");
    must_init(pilka, "Pilka_2");
    ALLEGRO_BITMAP* tlo = al_load_bitmap("resources/map_level_2.png");
    must_init(tlo, "tlo_lvl_2");
    ALLEGRO_BITMAP* traf_back = al_load_bitmap("resources/trafienie_back.png");
    must_init(traf_back, "traf_back");

    // Zmienna do zakonczenia petli
    int koniec = 0;

    //zmienne do zliczania dotkniec
    int licznik_help = 0;
    int licznik = 0;
    int czas = 10;

    int time = 0;

    x = 340;
    y = 540;
    dx = 0;
    dy = 0;
    a = 0;
    b = 0;
    f = 0;
    skala = 1;

    al_rest(0.5);

    clock_t start = clock();

    // Glowna petla programu
    while (!koniec) {


        // Jezeli wystapi zdarzenie to --> zdarzenie
        al_wait_for_event(queue, &zdarzenie1);

        switch (zdarzenie1.type) {

        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            koniec = 1;
            poziom = -1;
            break;

        case ALLEGRO_EVENT_TIMER:

            // Wyswietlania tla
            al_draw_bitmap(tlo, 0, 0, 0);

            // Ruch myszka
            al_get_mouse_state(&mysz);

            if (mysz.buttons & 1) {

                dx = mysz.x;
                dy = mysz.y;
                f = sqrt(pow(dx - x, 2) + pow(dy - y, 2)) / 10;
                if (f > 30) { f = 30; };
                a = (y - dy) / (x - dx);
                b = y - (a * x);

                rysuj_kropki();

                //zmienna do zliczania dotkniec
                licznik_help++;

            }

            //if do zliczania dotkniec

            if (!(mysz.buttons & 1) && licznik_help > 0)
            {
                al_play_sample(uderzenie, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);

                licznik++;
                licznik_help = 0;

            }

            // przeszkody

            przeszkody_lvl_2(odbicie);

            // kolizje

            kolizcje(odbicie);

            //ruch pilki

            if (!(mysz.buttons & 1) && licznik > 0) {

                ruch_pilki();

            }

            //trafienie

            trafienie(pilka, czcionka, koniec, tlo, traf_back, czcionka2, licznik, time);

            dotkniecia[1] = licznik;
            czasy[1] = time;

            // Wyswieylanie pilki

            al_draw_scaled_bitmap(pilka, 0, 0, ball_weight, ball_height, x - 20, y - 20, ball_weight * skala, ball_height * skala, 0);

            // Odswiezenie
            al_flip_display();
            break;

        default: break;

        }

        clock_t end = clock();
        time = int(end - start) / CLOCKS_PER_SEC;

    }


    

    al_destroy_bitmap(pilka);
    al_destroy_bitmap(tlo);
    al_destroy_bitmap(traf_back);

}