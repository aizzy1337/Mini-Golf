#pragma once

#include "inicjalizacja.h"
#include "kinematyka.h"



void podsumowanie1(ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_DISPLAY* display, ALLEGRO_MOUSE_STATE& mysz, ALLEGRO_TIMER* timer, ALLEGRO_FONT* czcionka3, ALLEGRO_EVENT& zdarzenie1, ALLEGRO_FONT* czcionka2, ALLEGRO_SAMPLE* odbicie, ALLEGRO_SAMPLE* uderzenie, int dotkniecia[3], int czasy[3])
{
	ALLEGRO_BITMAP* tlo = al_load_bitmap("resources/PODSUMOWANIE.png");
	ALLEGRO_BITMAP* wyjscie = al_load_bitmap("resources/button_wyjscie.png");
	must_init(wyjscie, "wyjscie");
	must_init(tlo, "PODSUMOWANIE");
	int koniec = 0;
	while (!koniec)
	{
		al_wait_for_event(queue, &zdarzenie1);

			// Wyswietlania tla
			al_draw_bitmap(tlo, 0, 0, 0);
			// Wyswietlanie wynikow
			al_draw_textf(czcionka3, al_map_rgb(240, 130, 20), 900, 425, 0, " HOLE IN %i  TIME %is",dotkniecia[0],czasy[0]);
			al_draw_textf(czcionka3, al_map_rgb(240, 130, 20), 900, 625, 0, " HOLE IN %i  TIME %is", dotkniecia[1], czasy[1]);
			al_draw_textf(czcionka3, al_map_rgb(240, 130, 20), 900, 825, 0, " HOLE IN %i  TIME %is", dotkniecia[2], czasy[2]);
			// Wyswietlanie wyjscia do ustawien
			al_draw_bitmap(wyjscie, 1300, 950, 0);

			al_get_mouse_state(&mysz);

			if (mysz.buttons & 1)
			{
				if (mysz.x >= 1300 && mysz.x <= 1900 && mysz.y >= 950 && mysz.y <= 1050)
				{
					 poziom = 0;
					 // zresetowanie butelek
					 wys_but_1 = 1;
					 wys_but_2 = 1;
					 wys_but_3 = 1;
					 wys_but_4 = 1;
					 // reset sily
					 f = 0;
					 f_max = 3;
				}
			}
			// Odswiezenie
			al_flip_display();
			break;

			


		
		}
	al_destroy_bitmap(tlo);
	al_destroy_bitmap(wyjscie);
		
	}

