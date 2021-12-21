/** @file affDemineur.h
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 21 Dec 2021 18:30
 *
 *  @brief Affichage du plateau de jeu
 *
 */

#ifndef __AFFDEMINEUR_H__
/**
 *  @def __AFFDEMINEUR_H__
 *  Constante permettant de savoirs si le fichier à déjà été chargé.
 */
#define __AFFDEMINEUR_H__

#include "demineur.h"
#include <ncurses.h>

/**
 *  @fn WINDOW* creeWinPlateau (plateauDemineur *plateau, int i_x,i_y)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 21 Dec 2021 19:22
 *
 *  @brief Créé la fenetre d'affichage du plateau de jeu
 *
 *  @param[in] plateau : Plateau de jeu
 *  @param[in] i_x : Emplacement du coin supérieur gauche du plateau en X
 *  @param[in] i_y : Emplacement du coin supérieur gauche du plateau en Y
 *  @return La fenêtre du plateau de jeu
 *
 */
WINDOW *creeWinPlateau(plateauDemineur *plateau, int i_x, int i_y);

/**
 *  @fn void detruitWinPlateau (WINDOW *winPlateau)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 21 Dec 2021 19:58
 *
 *  @brief Détruit la fenêtre du plateau de jeu
 *
 *  @param[in out] winPlateau : Fenêtre du plateau de jeu
 *
 */
void detruitWinPlateau(WINDOW *winPlateau);

#endif // __AFFDEMINEUR_H__
