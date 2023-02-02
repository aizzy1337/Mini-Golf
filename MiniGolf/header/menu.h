#pragma once

#include "inicjalizacja.h"

void rozpocznij_menu(ALLEGRO_MOUSE_STATE& mysz) {


    ALLEGRO_BITMAP* start = al_load_bitmap("resources/button_start.png");
    must_init(start, "start");
    ALLEGRO_BITMAP* ustawienia = al_load_bitmap("resources/button_ust.png");
    must_init(ustawienia, "ustawienia");
    ALLEGRO_BITMAP* wyjscie = al_load_bitmap("resources/button_wyjscie.png");
    must_init(wyjscie, "wyjscie");
    ALLEGRO_BITMAP* tlo_menu = al_load_bitmap("resources/menu_back.png");
    must_init(tlo_menu, "tlo menu");

    al_draw_bitmap(tlo_menu, 0, 0, 0);
    al_draw_bitmap(start, 660, 540, 0);
    al_draw_bitmap(ustawienia, 660, 690, 0);
    al_draw_bitmap(wyjscie, 660, 840, 0);

    al_flip_display();

    al_get_mouse_state(&mysz);


    if (mysz.buttons & 1) {

        if (mysz.x >= 660 && mysz.x <= 1260 && mysz.y >= 540 && mysz.y <= 640) {
            
            poziom = 1;

        }
        else if (mysz.x >= 660 && mysz.x <= 1260 && mysz.y >= 690 && mysz.y <= 790) {

            poziom = 9;

        }
        else if (mysz.x >= 660 && mysz.x <= 1260 && mysz.y >= 840 && mysz.y <= 940) {

            poziom = -1;

        }

    }

    al_destroy_bitmap(start);
    al_destroy_bitmap(ustawienia);
    al_destroy_bitmap(wyjscie);
    al_destroy_bitmap(tlo_menu);

}