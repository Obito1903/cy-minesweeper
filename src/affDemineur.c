/** @file affDemineur.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 21 Dec 2021 18:30
 *
 *  @brief
 *
 */

#include "affDemineur.h"

void initAffichage(void)
{
	initscr();

	cbreak();			  /* Line buffering disabled, Pass on
						   * everty thing to me 		*/
	keypad(stdscr, TRUE); /* I need that nifty F1 	*/
	CHECK_PRINT_ERR(setlocale(LC_CTYPE, "") == NULL, ERREUR_SET_LOCALE, "Impossible de changer le format des caractères.");
	initCouleurs();
}

void initCouleurs(void)
{
	start_color();
	init_color(10, 500, 0, 500);

	init_pair(BOMBE, COLOR_YELLOW, COLOR_GREEN);
	init_pair(VIDE, COLOR_CYAN, COLOR_BLUE);
	init_pair(NB1, 10, COLOR_BLACK);
	init_pair(NB2, COLOR_RED, COLOR_MAGENTA);
}

WINDOW *creeWinPlateau(plateauDemineur *plateau, int i_x, int i_y)
{
	WINDOW *winPlateau; // Variable de retour

	winPlateau = newwin(plateau->nbLignes + 2, (plateau->nbColonnes * 2) + 3, i_y, i_x);
	box(winPlateau, 0, 0);

	wrefresh(winPlateau);
	return (winPlateau);
}

void detruitWinPlateau(WINDOW *winPlateau)
{
	wborder(winPlateau, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wrefresh(winPlateau);
	delwin(winPlateau);
}

void updateFenetrePlateau(WINDOW *winPlateau, plateauDemineur *plateau)
{

	wmove(winPlateau, 1, 2);
	// mvwadd_wch(winPlateau, 2, 2, WACS_BLOCK);

	int iter_Colonne;
	for (iter_Colonne = 0; iter_Colonne < plateau->nbColonnes; iter_Colonne++) {
		int iter_Ligne;
		for (iter_Ligne = 0; iter_Ligne < plateau->nbLignes; iter_Ligne++) {
			if (plateau->cases[iter_Colonne][iter_Ligne].etat == DECOUVERTE) {

				mvwadd_wch(winPlateau, iter_Ligne + 1, (iter_Colonne * 2) + 2,
						   &CONTENU_CASE_CHAR(plateau->cases[iter_Colonne][iter_Ligne].contenu));
			} else {
				mvwadd_wch(winPlateau, iter_Ligne + 1, (iter_Colonne * 2) + 2,
						   &ETAT_CASE_CHAR(plateau->cases[iter_Colonne][iter_Ligne].etat));
			}
		}
	}

	wrefresh(winPlateau);
}
