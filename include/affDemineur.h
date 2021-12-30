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

#include <ncurses.h>
#include <locale.h>
#include "demineur.h"
#include "samLib.h"

#define ERREUR_SET_LOCALE	-22
#define ERREUR_INIT_COULEUR 23

extern const cchar_t contenuCaseChar[10];
#define CONTENU_CASE_CHAR(CONTENU) contenuCaseChar[(int)CONTENU + 1]

/**
 * @enum couleurContenu
 * Enumeration des couleurs pour le contenu des cases
 */
typedef enum
{
	/*!  */
	COULEUR_BOMBE = 10,
	COULEUR_VIDE,
	COULEUR_NB1,
	COULEUR_NB2,
	COULEUR_NB3,
	COULEUR_NB4,
	COULEUR_NB5,
	COULEUR_NB6,
	COULEUR_NB7,
	COULEUR_NB8,
	COULEUR_DRAPEAU,
	COULEUR_CACHE,

} couleurDemineur;

extern const cchar_t etatCaseChar[3];
#define ETAT_CASE_CHAR(CONTENU) etatCaseChar[CONTENU + 1]

/**
 *  @fn void initAffichage (void)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Thu 30 Dec 2021 00:10
 *
 *  @brief Initialise l'affichage et prepare le terminal pour ncurses
 *
 */
void initAffichage(void);

/**
 *  @fn void initCouleurs (void)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Thu 30 Dec 2021 02:24
 *
 *  @brief Initialise l'affichage en couleur
 *
 */
void initCouleurs(void);

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

/**
 *  @fn void updateFenetrePlateau (WINDOW *winPlateau, plateauDemineur *plateau)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 22 Dec 2021 20:42
 *
 *  @brief Met à jour la fenêtre du plateau de jeu
 *
 *  @param[in out] winPlateau : Fenêtre du plateau de jeu
 *  @param[in] plateau : Plateau de jeu
 *
 */
void updateFenetrePlateau(WINDOW *winPlateau, plateauDemineur *plateau);

#endif // __AFFDEMINEUR_H__
