#include "fmod.hpp" // para utilizar el wrapper C++
#include "fmod_errors.h" // para manejo de errores
#include <time.h>
#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace FMOD;

// para salidas de error
void ERRCHECK(FMOD_RESULT result) {
    if (result != FMOD_OK) {
        std::cout << FMOD_ErrorString(result) << std::endl;
        // printf("FMOD error %d - %s", result, FMOD_ErrorString(result));
        exit(-1);
    }
}

FMOD_RESULT ej1(System* system) {
    Sound* sound1;
    FMOD_RESULT result = system->createSound(
        "../Assets/Battle.wav",   // path al archivo de sonido
        FMOD_LOOP_NORMAL,   // valores (por defecto en este caso: sin loop, 2D)
        0,              // informacion adicional (nada en este caso)
        &sound1);       // handle al buffer de sonido
    ERRCHECK(result);

    Channel* channel1;
    result = system->playSound(
        sound1,         // buffer que se "engancha" a ese canal
        0,              // grupo de canales, 0 sin agrupar (agrupado en el master)
        false,          // arranca sin "pause" (se reproduce directamente)
        &channel1);      // devuelve el canal que asigna
    ERRCHECK(result);

    //============================================

    Sound* sound2;
    result = system->createSound(
        "../Assets/Battle.wav",   // path al archivo de sonido
        FMOD_LOOP_NORMAL,   // valores (por defecto en este caso: sin loop, 2D)
        0,              // informacion adicional (nada en este caso)
        &sound2);       // handle al buffer de sonido
    ERRCHECK(result);

    Channel* channel2;
    result = system->playSound(
        sound2,         // buffer que se "engancha" a ese canal
        0,              // grupo de canales, 0 sin agrupar (agrupado en el master)
        false,          // arranca sin "pause" (se reproduce directamente)
        &channel2);      // devuelve el canal que asigna
    ERRCHECK(result);

    //============================================

    Sound* sound3;
    result = system->createSound(
        "../Assets/Battle.wav",   // path al archivo de sonido
        FMOD_LOOP_NORMAL,   // valores (por defecto en este caso: sin loop, 2D)
        0,              // informacion adicional (nada en este caso)
        &sound3);       // handle al buffer de sonido
    ERRCHECK(result);

    Channel* channel3;
    result = system->playSound(
        sound3,         // buffer que se "engancha" a ese canal
        0,              // grupo de canales, 0 sin agrupar (agrupado en el master)
        false,          // arranca sin "pause" (se reproduce directamente)
        &channel3);      // devuelve el canal que asigna
    ERRCHECK(result);

    //============================================

    result = channel1->setVolume(0.7f);
}

int main() {
    System* system;
    FMOD_RESULT result;
    result = System_Create(&system); // Creamos el objeto system
    ERRCHECK(result);

    // 128 canales (numero maximo que podremos utilizar simultaneamente)
    result = system->init(128, FMOD_INIT_NORMAL, 0); // Inicializacion de FMOD
    ERRCHECK(result);

    //============================================

    result = ej1(system);

    //BUCLE PRINCIPAL
	bool exit = false;
	while (!exit) {

		if (_kbhit()) { //INPUT

			int key = _getch();
			if (key == 'q') exit = true;
		}
		result = system->update();
	}

    result = system->release();
    ERRCHECK(result);
}



//float doppler = 1.0f, rolloff = 1.0f;
//system->set3DSettings(doppler, 1.0, rolloff);

//FMOD_VECTOR
//    listenerPos = { 0,0,0 }, // posicion del listener
//    listenerVel = { 0,0,0 }, // velocidad del listener
//    up = { 0,1,0 }, // vector up: hacia la ``coronilla''
//    at = { 1,0,0 }; // vector at: hacia donde mira
//    // colocamos listener
//system->set3DListenerAttributes(0, &listenerPos, &listenerVel, &up, &at);

//Sound* sound1;
//result = system->createSound(
//    "battle.mp3", // path al archivo de sonido
//    FMOD_3D, // valores (por defecto en este caso: sin loop, 2D)
//    0, // informacion adicional (nada en este caso)
//    &sound1);

//Channel* channel;
//result = system->playSound(
//    sound1, // buffer que se "engancha" a ese canal
//    0, // grupo de canales, 0 sin agrupar (agrupado en el master)
//    false, // arranca sin "pause" (se reproduce directamente)
//    &channel); // devuelve el canal que asigna
//    // el sonido ya se esta reproduciendo

//FMOD_VECTOR
//    pos = { 0,0,1 }, // posicion
//    vel = { 0,0,0 }; // velocidad

//channel->set3DAttributes(&pos, &vel);

//result = channel->setVolume(0.1f); 


//while (true) {
//    result = system->update();
//}
