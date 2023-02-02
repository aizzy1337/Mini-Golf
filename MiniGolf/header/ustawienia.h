#pragma once

#include "inicjalizacja.h"

void rysuj_kursory(ALLEGRO_BITMAP* kursor1, ALLEGRO_BITMAP* kursor2, ALLEGRO_BITMAP* kursor3, ALLEGRO_FONT* czcionka3) {

    switch (wybrany) {
    case 1:
        al_draw_filled_rectangle(38, 350, 294, 606, al_map_rgb(251, 132, 5));
        al_draw_filled_rectangle(332, 350, 588, 606, al_map_rgb(255, 250, 161));
        al_draw_filled_rectangle(626, 350, 882, 606, al_map_rgb(255, 250, 161));
        break;
    case 2:
        al_draw_filled_rectangle(38, 350, 294, 606, al_map_rgb(255, 250, 161));
        al_draw_filled_rectangle(332, 350, 588, 606, al_map_rgb(251, 132, 5));
        al_draw_filled_rectangle(626, 350, 882, 606, al_map_rgb(255, 250, 161));
        break;
    case 3:
        al_draw_filled_rectangle(38, 350, 294, 606, al_map_rgb(255, 250, 161));
        al_draw_filled_rectangle(332, 350, 588, 606, al_map_rgb(255, 250, 161));
        al_draw_filled_rectangle(626, 350, 882, 606, al_map_rgb(251, 132, 5));
        break;
    }

    al_draw_bitmap(kursor1, 38, 350, 0);
    al_draw_bitmap(kursor2, 332, 350, 0);
    al_draw_bitmap(kursor3, 626, 350, 0);

    al_draw_text(czcionka3, al_map_rgb(255, 244, 164), 70, 606, 0, "Kursor 1");
    al_draw_text(czcionka3, al_map_rgb(255, 244, 164), 354, 606, 0, "Kursor 2");
    al_draw_text(czcionka3, al_map_rgb(255, 244, 164), 644, 606, 0, "Kursor 3");
}

void rozpocznij_ustawienia(ALLEGRO_MOUSE_STATE& mysz, ALLEGRO_BITMAP* kursor1, ALLEGRO_BITMAP* kursor2, ALLEGRO_BITMAP* kursor3, ALLEGRO_MOUSE_CURSOR* kursor_1, ALLEGRO_MOUSE_CURSOR* kursor_2, ALLEGRO_MOUSE_CURSOR* kursor_3, ALLEGRO_FONT* czcionka3, ALLEGRO_DISPLAY* display, ALLEGRO_SAMPLE_INSTANCE* muzykaInstance) {

    al_play_sample_instance(muzykaInstance);

    ALLEGRO_BITMAP* wyjscie = al_load_bitmap("resources/button_wyjscie.png");
    must_init(wyjscie, "wyjscie");

    ALLEGRO_BITMAP* tlo_ustawienia = al_load_bitmap("resources/tlo_ustawienia.png");
    must_init(tlo_ustawienia, "tlo ustawienia");

    al_draw_bitmap(tlo_ustawienia, 0, 0, 0);

    rysuj_kursory(kursor1, kursor2, kursor3, czcionka3);

    al_draw_bitmap(wyjscie, 660, 780, 0);


    double volume = 1;
    double min_vol = 1140, max_vol = 1740;
    double suwak = 1740;

    while (true) {

        al_get_mouse_state(&mysz);

        al_draw_filled_rectangle(1100, 350, 1780, 450, al_map_rgb(251, 132, 5));
        al_draw_line(1140, 400, 1740, 400, al_map_rgb(13, 28, 32), 4);
        al_draw_filled_rectangle(suwak - 20, 370, suwak + 20, 430, al_map_rgb(244, 45, 0));

        if (mysz.buttons & 1) {

            if (mysz.x >= 38 && mysz.x <= 294 && mysz.y >= 350 && mysz.y < 606) {

                wybrany = 1;
                rysuj_kursory(kursor1, kursor2, kursor3, czcionka3);
                al_set_mouse_cursor(display, kursor_1);

            }
            else if (mysz.x >= 332 && mysz.x <= 588 && mysz.y >= 350 && mysz.y < 606) {

                wybrany = 2;
                rysuj_kursory(kursor1, kursor2, kursor3, czcionka3);
                al_set_mouse_cursor(display, kursor_2);

            }
            else if (mysz.x >= 626 && mysz.x <= 882 && mysz.y >= 350 && mysz.y < 606) {

                wybrany = 3;
                rysuj_kursory(kursor1, kursor2, kursor3, czcionka3);
                al_set_mouse_cursor(display, kursor_3);

            }
            else if (mysz.x >= 1140 && mysz.x <= 1740 && mysz.y >= 350 && mysz.y < 450) {

                if (mysz.x < 1140) {
                    suwak = 1140;
                }
                else if (mysz.x > 1740) {
                    suwak = 1740;
                }
                else {
                    suwak = mysz.x;
                }

                al_draw_filled_rectangle(suwak - 20, 370, suwak + 20, 430, al_map_rgb(244, 45, 0));

                al_set_sample_instance_gain(muzykaInstance, ((suwak - 1140) / 600));

            }
            else if (mysz.x >= 660 && mysz.x <= 1260 && mysz.y >= 780 && mysz.y < 880) {
                poziom = 0;
                return;
            }

        }


        al_flip_display();
    }

    al_destroy_bitmap(wyjscie);
    al_destroy_bitmap(tlo_ustawienia);

}