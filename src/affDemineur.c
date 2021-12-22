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

	winPlateau = newwin(plateau->nbLignes + 4, plateau->nbColonnes + 2, i_y, i_x);
	box(winPlateau, 0, 0);

	mvwhline(winPlateau, 2, 1, 0, plateau->nbColonnes);

	wrefresh(winPlateau);
	return (winPlateau);
}

void detruitWinPlateau(WINDOW *winPlateau)
{
	wborder(winPlateau, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wrefresh(winPlateau);
	delwin(winPlateau);
}

/**
 *  @fn void updateFenetrePlateau (WINDOW *winPlateau, plateauDemineur *plateau)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 22 Dec 2021 20:42
 *
 *  @brief
 *
 *  @param[in]
 *
 */
void updateFenetrePlateau(WINDOW *winPlateau, plateauDemineur *plateau)
{}
