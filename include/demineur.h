/** @file demineur.h
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 21 Dec 2021 18:28
 *
 *  @brief Fonction et structures globales du programme
 *
 */

#ifndef __DEMINEUR_H__
/**
 *  @def __DEMINEUR_H__
 *  Constante permettant de savoirs si le fichier à déjà été chargé.
 */
#define __DEMINEUR_H__

#include <ncurses.h>
#include <stddef.h>

/**
 * @enum contenuCase
 * @brief Enumération des différents contenus possibles d'une case
 */
typedef enum
{
	/*! La case contient une bombe */
	BOMBE = -1,
	/*! La case n'a pas de bombe */
	VIDE = 0,
	/*! La case contient un nombre (Nombre de bombe autour de cette case) */
	NB1 = 1,
	NB2 = 2,
	NB3 = 3,
	NB4 = 4,
	NB5 = 5,
	NB6 = 6,
	NB7 = 7,
	NB8 = 8
} contenuCase;

extern const cchar_t contenuCaseChar[10];
#define CONTENU_CASE_CHAR(CONTENU) contenuCaseChar[(int)CONTENU + 1]

/**
 * @enum etatCase
 * Etat d'une case
 */
typedef enum
{
	/*! Case marquée */
	DRAPEAU = -1,
	/*! Case caché */
	CACHE = 0,
	/*! Case découverte */
	DECOUVERTE = 1
} etatCase;

extern const cchar_t etatCaseChar[3];
#define ETAT_CASE_CHAR(CONTENU) etatCaseChar[CONTENU + 1]

/**
 * @struct casePlateau
 * Structure représentant une case du plateau de jeu
 */
typedef struct
{
	/*! Contenu de la case */
	contenuCase contenu;
	/*! Etat de la case */
	etatCase etat;
} casePlateau;

/**
 * @struct plateauDemineur
 * @brief Strucure contenant les informations du plateau de jeu
 *
 * @details Les plateaux sont representé de la maniere suivante:
 * ~~~~~~~~~~~~~~~~~~~~~{.c}
 * plateauDemineur.contenu[colonne][ligne]
 * ~~~~~~~~~~~~~~~~~~~~~
 * Les coordonnées commencent dans le coin en haut à gauche du plateau:
 *
 * |y/x| 0 | 1 | 2 | 3 |
 * |:-:|:-:|:-:|:-:|:-:|
 * | 0 |   |   |   |   |
 * | 1 |   |   |   |   |
 * | 2 |   |   |   |   |
 * | 3 |   |   |   |   |
 *
 *
 */
typedef struct
{
	/*! Tableau contenant les bombes et le nombre de bombe autour de chaque case
	 * @details Ce tableau sert à stocké l'emplacement de toutes les bombes ainsi
	 * que le nombre de bombe autour de chaque cases qui sera calculé lors de
	 * l'initialisation du plateau
	 */
	casePlateau **cases;
	/*! Nombre de ligne du plateau */
	int nbLignes;
	/*! Nombre de colonne du plateau */
	int nbColonnes;
	int nbMines;
} plateauDemineur;

#endif // __DEMINEUR_H__
