/** @file logicDemineur.h
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 22 Dec 2021 20:20
 *
 *  @brief Logique du demineur
 *
 */

#ifndef __LOGICDEMINEUR_H__
/**
 *  @def \_\_LOGICDEMINEUR_H\_\_
 *  Constante permettant de savoirs si le fichier à déjà été chargé.
 */
#define __LOGICDEMINEUR_H__

#include <demineur.h>
#include <samLib.h>

/**
 *  @fn plateauDemineur* initPlateauDemineur (int i_nbLignes, int i_nbColonnes, int i_nbMines)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 22 Dec 2021 20:22
 *
 *  @brief Initialise le plateau de jeu
 *
 *  @param[in] i_nbLignes : Nombre de lignes du plateau
 *  @param[in] i_nbColonnes : Nombre de colonnes du plateau
 *  @param[in] i_nbMines : Nombre de mines du plateau
 *  @return Un pointeur vers le plateau de jeu initialisé
 *
 */
plateauDemineur *initPlateauDemineur(int i_nbLignes, int i_nbColonnes, int i_nbMines);

/**
 *  @fn void freePlateauDemineur (plateauDemineur *plateau)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 22 Dec 2021 20:43
 *
 *  @brief Libère l'espace mémoire alloué pour le plateau de jeu
 *
 *  @param[in] plateau : Plateau de jeu
 *
 */
void freePlateauDemineur(plateauDemineur *plateau);

#endif // __LOGICDEMINEUR_H__
