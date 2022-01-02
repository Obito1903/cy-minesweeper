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
#include <time.h>

/**
 *  @fn void placeBombes (plateauDemineur *plateau, int i_nbMines)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 31 Dec 2021 14:32
 *
 *  @brief Place les mines sur le plateau de jeu
 *
 *  @param[in out] plateau : Plateau de jeu
 *  @param[in] i_nbMines : Nombre de mines à placer
 *
 */
void placeBombes(plateauDemineur *plateau, int i_nbMines);

/**
 *  @fn void placeNombres (plateauDemineur *plateau)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 01 Jan 2022 18:53
 *
 *  @brief Calcule les nombres de cases adjacentes contenant une bombes à chaque case du plateau
 *
 *  @param[in out] plateau : Plateau de jeu
 *
 */
void placeNombres(plateauDemineur *plateau);

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

/**
 *  @fn void decouvreCase(plateauDemineur *plateau, int posX, int posY)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 01 Jan 2022 23:53
 *
 *  @brief
 *
 *  @param[in out] plateau : Plateau de jeu
 *  @param[in] posX : Position en X de la case à découvrir
 *  @param[in] posY : Position en Y de la case à découvrir
 *
 */
void decouvreCase(plateauDemineur *plateau, int posX, int posY);

/**
 *  @fn int deplaceDurseur (plateauDemineur *plateau, int posX, int posY)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sun 02 Jan 2022 00:37
 *
 *  @brief Deplace le curseur du plateau en s'assurant que la case est accessible
 *
 *  @param[in out] plateau : le plateau du jeu
 *  @param[in] posX : la nouvelle position en X du curseur
 *  @param[in] posY : la nouvelle position en Y du curseur
 *  @return FALSE si la case est inaccessible, TRUE sinon
 *
 */
int deplaceDurseur(plateauDemineur *plateau, int posX, int posY);

/**
 *  @fn int validePosDrapeaux (plateauDemineur *plateau)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sun 02 Jan 2022 00:58
 *
 *  @brief Verifie que tous les drapeaux son bien au dessus d'une bombe
 *
 *  @param[in] plateau : Plateau de jeu
 *  @return TRUE si tous les drapeaux sont au dessus d'une bombe, FALSE sinon
 *
 */
int validePosDrapeaux(plateauDemineur *plateau);

/**
 *  @fn void aGagne (plateauDemineur *plateau)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sun 02 Jan 2022 00:50
 *
 *  @brief Determine si le joueur a gagné
 *
 *  @param[in out] plateau : Plateau du jeu
 */
void aGagne(plateauDemineur *plateau);

#endif // __LOGICDEMINEUR_H__
