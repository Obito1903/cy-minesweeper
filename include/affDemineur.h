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
 * @def \_\_AFFDEMINEUR_H\_\_
 * Constante permettant de savoirs si le fichier à déjà été chargé.
 */
#define __AFFDEMINEUR_H__

#include <ncurses.h>
#include <locale.h>
#include "demineur.h"
#include "samLib.h"

/**
 * @def ERREUR_SET_LOCALE
 * Code d'erreur en case de problème lors de la définition de la locale.
 */
#define ERREUR_SET_LOCALE -22

/**
 * @def ERREUR_INIT_COULEUR
 *  Code d'erreur en cas de problème lors de l'initialisation des couleurs.
 */
#define ERREUR_INIT_COULEUR 23

/**
 * @brief Tableau contenant les caractères associés aux différents contenus d'une case
 */
extern const cchar_t contenuCaseChar[10];

/**
 * @def CONTENU_CASE_CHAR(CONTENU)
 * Macro permettant de récupérer le le caractères associé a une case en fonction de son contenu.
 */
#define CONTENU_CASE_CHAR(CONTENU) contenuCaseChar[(int)CONTENU + 1]

/**
 * @brief Tableau contenant les couleurs associés aux différents états d'une case
 *
 */
extern const cchar_t etatCaseChar[3];

/**
 * @def ETAT_CASE_CHAR(CONTENU)
 * Macro permettant de récupérer le le caractères associé a une case en fonction de son état.
 */
#define ETAT_CASE_CHAR(CONTENU) etatCaseChar[CONTENU + 1]

/**
 * @def CURSEUR
 * Caractère représentant le curseur.
 */
#define CURSEUR \
	(cchar_t) { .attr = A_BLINK, .chars = {L'⸰'}, .ext_color = COULEUR_CURSEUR }

/**
 * @enum couleurDemineur
 * Enumeration des couleurs pour le contenu des cases
 */
typedef enum
{
	/*! Couleurs d'une bombe */
	COULEUR_BOMBE = 10,
	/*! Couleurs d'une case vide */
	COULEUR_VIDE,
	/*! Couleurs d'une case entouré de bombe */
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
	COULEUR_CURSEUR

} couleurDemineur;

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
 *  @fn WINDOW *creeWinPlateau(plateauDemineur *plateau, int i_x, int i_y)
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
