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

	plateauDemineur *plateau = initPlateauDemineur(4, 4, 10);
	int				 starty	 = (LINES - plateau->nbLignes) / 2;	 /* Calculating for a center placement */
	int				 startx	 = (COLS - plateau->nbColonnes) / 2; /* of the window		*/
	int				 ch;
	plateau->cases[0][0].etat	 = DRAPEAU;
	plateau->cases[1][0].etat	 = DECOUVERTE;
	plateau->cases[1][0].contenu = BOMBE;
	plateau->cases[2][0].etat	 = DECOUVERTE;
	plateau->cases[2][0].contenu = NB1;
	plateau->cases[3][0].etat	 = DECOUVERTE;
	plateau->cases[0][1].contenu = VIDE;

	printw("Press F1 to exit");
	refresh();
	WINDOW *my_win = creeWinPlateau(plateau, startx, starty);

	updateFenetrePlateau(my_win, plateau);
	getchar();

	endwin();
	return (0);
}
