#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <fmod.h>

#include "jeux.h"


void jouer(SDL_Surface *ecran)
{
    SDL_Surface *P = NULL, *PF = NULL, *PG = NULL, *PD = NULL, *PDr = NULL, *PFG = NULL, *PFDr = NULL, *PDG = NULL, *PDDr = NULL;
    //Anmiations
    SDL_Surface *PDpd = NULL, *PDpg = NULL;
    SDL_Rect Po;

    Po.x = 500;
    Po.y = 300;

    PF = IMG_Load("Surfaces/personnage/perso_face.png");
    PD = IMG_Load("Surfaces/personnage/perso_dos.png");
    PG = IMG_Load("Surfaces/personnage/perso_gauche.png");
    PDr = IMG_Load("Surfaces/personnage/perso_droite.png");
    PDG = IMG_Load("Surfaces/personnage/perso_dos_gauche.png");
    PDDr = IMG_Load("Surfaces/personnage/perso_dos_droite.png");
    PFG = IMG_Load("Surfaces/personnage/perso_face_gauche.png");
    PFDr = IMG_Load("Surfaces/personnage/perso_face_droite.png");
    //Anmiations
    PDpd = IMG_Load("Surfaces/personnage/perso_dos_pied_droit.png");


    P = PF;

    int continuer = 1;
    int tempsPrecedent = 0, tempsActuel = 0;
    int orientation=0;
    int mouvement = 0;


    SDL_Event event;
    SDL_EnableKeyRepeat(100,0);

    ecran = SDL_SetVideoMode(1340 , 670, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    while(continuer)
    {
        while(SDL_PollEvent(&event)); //boucle event de jeux
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0; //arreter le jeux si on clique sur la croix rouge en mode fenetré
            break;

            case SDL_KEYDOWN:

                    switch(event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            continuer = 0;
                        break;
                        case SDLK_UP:
                            Po.y--;
                            P=PD;
                            mouvement = 1;
                            orientation = 1;
                        break;
                        case SDLK_DOWN:
                            Po.y++;
                            P=PF;
                        break;
                        case SDLK_LEFT:
                            Po.x--;
                            P=PG;
                        break;
                        case SDLK_RIGHT:
                            Po.x++;
                            P=PDr;
                        break;
                        default:
                        break;
                    }
        }
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));

        while(mouvement==1)
        {
            tempsActuel = SDL_GetTicks();
            while(tempsActuel-tempsPrecedent<1000)
            {

                tempsPrecedent = tempsActuel;
            }
            mouvement=0;

        }
        SDL_BlitSurface(P, NULL, ecran, &Po);
        SDL_Flip(ecran);
    }
/*
    SDL_FreeSurface(P);
    SDL_FreeSurface(PF);
    SDL_FreeSurface(PD);
    SDL_FreeSurface(PG);
    SDL_FreeSurface(PDr);
    SDL_FreeSurface(PDG);
    SDL_FreeSurface(PDDr);
    SDL_FreeSurface(PFG);
    SDL_FreeSurface(PFDr);
    SDL_FreeSurface(ecran);
*/
}
