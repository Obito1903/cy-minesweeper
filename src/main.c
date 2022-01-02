/** @file main.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 18 Dec 2021 19:50
 *
 *  @brief Module maindu TP9
 *
 */

#include <affDemineur.h>
#include <logicDemineur.h>

/**
 *
 *  @fn int main (int argc, char const *argv[])
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 18 Dec 2021 19:50
 *
 *  @brief Fonction Principale
 *
 *  @param[in] argc Nombre d'arguments
 *  @param[in] *argv[] Tableau d'arguments
 *  @return EXIT_SUCCESS : le programme doit se terminer normalement
 *
 */
int main(int argc, char const *argv[])
{
	initAffichage();

	plateauDemineur *plateau = initPlateauDemineur(10, 20, 10);
	int				 starty	 = (LINES - plateau->nbLignes) / 2;		   /* Calculating for a center placement */
	int				 startx	 = (COLS - (plateau->nbColonnes * 2)) / 2; /* of the window		*/
	int				 ch;
	plateau->xRay = FALSE;
	MEVENT event;
	printw("Espace/Clique Souris pour découvrir, Flèches pour déplacer");
	refresh();
	WINDOW *my_win = creeWinPlateau(plateau, startx, starty);

	updateFenetrePlateau(my_win, plateau);
	mousemask(ALL_MOUSE_EVENTS, NULL);
	while (plateau->etat == 0) {
		ch = getch();
		switch (ch) {
			case KEY_UP:
				deplaceDurseur(plateau, plateau->posCurseur.x, plateau->posCurseur.y - 1);
				plateau->posCurseur.affiche = TRUE;
				break;
			case KEY_DOWN:
				deplaceDurseur(plateau, plateau->posCurseur.x, plateau->posCurseur.y + 1);
				plateau->posCurseur.affiche = TRUE;
				break;
			case KEY_LEFT:
				deplaceDurseur(plateau, plateau->posCurseur.x - 1, plateau->posCurseur.y);
				plateau->posCurseur.affiche = TRUE;
				break;
			case KEY_RIGHT:
				deplaceDurseur(plateau, plateau->posCurseur.x + 1, plateau->posCurseur.y);
				plateau->posCurseur.affiche = TRUE;
				break;
			case ' ':
				decouvreCase(plateau, plateau->posCurseur.x, plateau->posCurseur.y);
				plateau->posCurseur.affiche = FALSE;
				break;
			case KEY_MOUSE:
				if (getmouse(&event) == OK) {
					if (event.bstate & BUTTON1_CLICKED) {
						if (deplaceDurseur(plateau, (event.x - startx) / 2 - 1, event.y - starty - 1)) {
							plateau->posCurseur.affiche = FALSE;
							decouvreCase(plateau, plateau->posCurseur.x, plateau->posCurseur.y);
							refresh();
						}
					}
				}
				break;
			default:
				break;
		}
		aGagne(plateau);
		updateFenetrePlateau(my_win, plateau);
	}
	printw("Partie terminé!");
	getch();
	endwin();
	return (0);
}
