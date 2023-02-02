#pragma once

#include "menu.h"
#include "ustawienia.h"
#include "level_1.h"
#include "level_2.h"
#include "level_3.h"
#include "podsumowanie.h"

void rozpocznij_gre() {

    // Inicjalizacja biblioteki Allegro
    must_init(al_init(), "Allegro");

    // Kolejka zdarzen
    ALLEGRO_EVENT_QUEUE* queue = NULL;
    queue = al_create_event_queue();
    must_init(queue, "Kolejka zdarzen");

    // Inicjalizacja ekranu
    ALLEGRO_DISPLAY* display = NULL;
    display = al_create_display(display_weight, display_height);
    must_init(display, "Ekran");

    // Ekran jako zrodlo zdarzen
    al_register_event_source(queue, al_get_display_event_source(display));

    // Inicjalizacja myszki
    al_install_mouse();
    ALLEGRO_MOUSE_STATE mysz;

    // Inicjalizacja timera, 30 klatek na sekunde
    ALLEGRO_TIMER* timer = NULL;
    timer = al_create_timer(1.0 / 30);
    must_init(timer, "Timer");

    // Timer jako zrodlo zdarzen
    al_register_event_source(queue, al_get_timer_event_source(timer));

    // Inicjowanie czcionek
    must_init(al_init_font_addon(), "Czcionka");
    must_init(al_init_ttf_addon(), "Czcionka ttf");
    ALLEGRO_FONT* czcionka = NULL;
    czcionka = al_load_font("resources/czcionka.ttf", 200, 0);
    ALLEGRO_FONT* czcionka2 = NULL;
    czcionka2 = al_load_font("resources/czcionka.ttf", 100, 0);
    ALLEGRO_FONT* czcionka3 = al_load_font("resources/czcionka.ttf", 50, 0);
    must_init(czcionka, "Czcionka");
    must_init(czcionka2, "Czcionka");
    must_init(czcionka3, "Czcionka");

    // Inicjowanie ksztaltow
    must_init(al_init_primitives_addon(), "Ksztalty");

    // Ustawianie kursora
    al_init_image_addon();
    ALLEGRO_BITMAP* kursor1 = al_load_bitmap("resources/kursor1.png");
    ALLEGRO_BITMAP* kursor2 = al_load_bitmap("resources/kursor2.png");
    ALLEGRO_BITMAP* kursor3 = al_load_bitmap("resources/kursor3.png");
    must_init(kursor1, "kursor1");
    must_init(kursor2, "kursor2");
    must_init(kursor3, "kursor3");
    ALLEGRO_MOUSE_CURSOR* kursor_1 = al_create_mouse_cursor(kursor1, 0, 0);
    ALLEGRO_MOUSE_CURSOR* kursor_2 = al_create_mouse_cursor(kursor2, 0, 0);
    ALLEGRO_MOUSE_CURSOR* kursor_3 = al_create_mouse_cursor(kursor3, 0, 0);
    
    al_set_mouse_cursor(display, kursor_1);

    //Muzyczka
    ALLEGRO_SAMPLE* muzyka = NULL;
    ALLEGRO_SAMPLE_INSTANCE* muzykaInstance = NULL;

    ALLEGRO_SAMPLE* uderzenie = NULL;
    ALLEGRO_SAMPLE* odbicie = NULL;
    ALLEGRO_SAMPLE* picie = NULL;

    must_init(al_install_audio(), "Audio");
    must_init(al_init_acodec_addon(), "acodec");

    al_reserve_samples(10);

    muzyka = al_load_sample("resources/muzyka_lvl_1.ogg");
    muzykaInstance = al_create_sample_instance(muzyka);

    uderzenie = al_load_sample("resources/uderzenie.wav");
    odbicie = al_load_sample("resources/odbicie.wav");
    picie = al_load_sample("resources/picie.ogg");

    al_set_sample_instance_playmode(muzykaInstance, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(muzykaInstance, al_get_default_mixer());

    // Zdarzenie
    ALLEGRO_EVENT zdarzenie1;

    // Start timera
    al_start_timer(timer);

    // Start muzyki
    al_play_sample_instance(muzykaInstance);

    // ----- GLOWNA PETLA PROGRAMU ----- //

    while (poziom != -1) {

        switch (poziom) {
        case 0:
            rozpocznij_menu(mysz);
            break;
        case 9:
            rozpocznij_ustawienia(mysz,kursor1,kursor2,kursor3,kursor_1,kursor_2,kursor_3,czcionka3,display,muzykaInstance);
            break;
        case 1:
            poziom1(queue, display, mysz, timer, czcionka, zdarzenie1, czcionka2, odbicie, uderzenie);
            break;
        case 2:
            poziom2(queue, display, mysz, timer, czcionka, zdarzenie1, czcionka2, odbicie, uderzenie);
            break;
        case 3:
            poziom3(queue, display, mysz, timer, czcionka, zdarzenie1, czcionka2, odbicie, uderzenie, picie);
            break;
        case 4:
            podsumowanie1(queue, display, mysz, timer, czcionka3, zdarzenie1, czcionka3, odbicie, uderzenie, dotkniecia, czasy);
            break;
        }
        
    }

    // ----- KONIEC GLOWNA PETLA PROGRAMU ----- //

// Deinicjalizacja
    al_destroy_event_queue(queue);
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_font(czcionka);
    al_destroy_font(czcionka2);
    al_shutdown_image_addon();
    al_destroy_bitmap(kursor1);
    al_destroy_bitmap(kursor2);
    al_destroy_bitmap(kursor3);
    al_destroy_mouse_cursor(kursor_1);
    al_destroy_mouse_cursor(kursor_2);
    al_destroy_mouse_cursor(kursor_3);
    al_destroy_sample(muzyka);
    al_destroy_sample_instance(muzykaInstance);
    al_destroy_sample(odbicie);
    al_destroy_sample(uderzenie);
    al_destroy_sample(picie);

}
