#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <fmod.h>

#include "jeux.h"


int main(int argc, char *argv[])
{
    freopen("CON", "w", stdout); //commandes pour afficher dans la console
    freopen("CON", "r", stdin);
    freopen("CON", "w", stderr);


    SDL_Surface *ecran = NULL;

    SDL_Event event;
    int continuerMain = 1;

    SDL_Init(SDL_INIT_EVERYTHING); //initialisation de la SDL

    //SDL_WM_SetIcon(SDL_LoadBMP("icone.bmp"), NULL);  // chargement de l'icone de fenêtre


    ecran = SDL_SetVideoMode(1340 , 670, 32, SDL_HWSURFACE | SDL_DOUBLEBUF); //Chargement de la fenetre et ses options

    SDL_WM_SetCaption("zombie project", NULL); //changement du nom de la fenêtre

     /*while (continuerMain) //boucle principale
    {
        SDL_WaitEvent(&event); //boucle event de main.c
            switch(event.type)
            {
                case SDL_QUIT:
                    continuerMain = 0;
                    break;

                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {
                    case SDLK_ESCAPE:
                        continuerMain = 0;
                        break;
                    case SDLK_UP:
                        jouer(ecran);  //lancer le jeu
                        break;
                    default:
                        break;
                    }
            }

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        SDL_Flip(ecran);
    }*/
     while (continuerMain) //boucle principale
    {
        SDL_WaitEvent(&event); //boucle event de main.c
        switch(event.type)
        {
            case SDL_QUIT:
                continuerMain = 0;
                break;

            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        continuerMain = 0;
                        break;
                    case SDLK_UP:
                        jouer(ecran);  //lancer le jeu
                        break;

                    default:
                        break;
                }
        }

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        SDL_Flip(ecran);
    }
    SDL_Quit();

    return 0;
}

