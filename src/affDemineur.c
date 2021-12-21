/** @file affDemineur.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 21 Dec 2021 18:30
 *
 *  @brief
 *
 */

#include "affDemineur.h"

WINDOW *creeWinPlateau(plateauDemineur *plateau, int i_x, int i_y)
{
	WINDOW *winPlateau; // Variable de retour

	winPlateau = newwin(plateau->nbLignes + 2, plateau->nbColonnes + 2, i_y, i_x);
	box(winPlateau, 0, 0);

	mvwhline(winPlateau, 2, 0, ACS_HLINE, plateau->nbColonnes + 2);

	wrefresh(winPlateau);
	return (winPlateau);
}

void detruitWinPlateau(WINDOW *winPlateau)
{
	wborder(winPlateau, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wrefresh(winPlateau);
	delwin(winPlateau);
}
