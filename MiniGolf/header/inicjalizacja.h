#pragma once

// do³¹czanie bibliotek

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <time.h>
#include <windows.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include "zmienne_globalne.h"

// funkcja sprawdzajaca poprawnosc inicjalizacji
void must_init(bool test, const char* description)
{
    if (test) return;

    printf("Nie mozna uruchomic: %s\n", description);
    exit(1);
}






