/** @file samLib.h
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Mon 22 Nov 2021 15:32
 *
 *  @brief Bibliotheque de fonctions utile pour mes projets
 *
 */

#ifndef __SAMLIB_H__
/**
 *  @def \_\_SAMLIB_H\_\_
 *  Constante permettant de savoirs si le fichier à déjà été chargé.
 */
#define __SAMLIB_H__

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <sys/ioctl.h>
#include <unistd.h>

/**
 * @def ERREUR_SAISIE_FATAL
 * Code d'erreur pour une saisie incorect qui doit etre fatal
 */
#define ERREUR_SAISIE_FATAL -1

/**
 * @def ERREUR_SAISIE
 * Code d'erreur pour une saisie incorect
 */
#define ERREUR_SAISIE 1

/**
 * @brief ERREUR_PARAM
 * Code d'erreur pour un paramètre incorrect
 */
#define ERREUR_PARAM -2

/**
 * @brief ERREUR_ALLOCATION_MEMOIRE
 * Code d'erreur pour un paramètre incorrect
 */
#define ERREUR_ALLOCATION_MEMOIRE -10

/**
 * @brief ERREUR_ENV
 * Code d'erreur si la variable d'environnement n'est pas définie
 */
#define ERREUR_ENV -11

/**
 * @brief ERREUR_ALLOCATION_MEMOIRE
 * Code d'erreur pour un paramètre incorrect
 */
#define ERREUR_DEPASSEMENT_MEMOIRE -12

/**
 * @brief ERREUR_ARGUMENTS
 * Code d'erreur pour un paramètre incorrect
 */
#define ERREUR_ARGUMENTS -13

/**
 *  @fn winsize ws_getTerminalesize (void)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Mon 06 Dec 2021 16:48
 *
 *  @brief Recupère la taille de la fenetre de la console depuis le kernel linux
 *
 *  @return La structure contenant la taille du terminal
 *
 */
struct winsize ws_getTerminalesize(void);

/**
 *  @fn void clearBuffer (void)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 03 Dec 2021 00:14
 *
 *  @brief Vide le buffer d'entré
 *
 */
void clearBuffer(void);

/**
 *  @def CHECK_PRINT_ERR(CONDITION, ERR_TYPE, MESSAGE)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 03 Dec 2021 09:41
 *
 *  @brief Verifie la condition et affiche le message d'erreur si elle est vrai
 *
 *  @param[in] CONDITION : Condition à tester
 *  @param[in] ERR_TYPE  : Type d'erreur
 *  Si `err_type <= 0`  l'erreur est fatal et affichera le message d'erreur dans `stderr`.
 *  Sinon l'erreur est non fatal et affichera le message d'erreur dans `stdout`
 *  @param[in] MESSAGE   : Message d'erreur
 *
 *  @return 0 si la condition est fausse ou `ERR_TYPE` si la condition est non fatal
 *
 *  @details Cette MACRO a pour but d'afficher le nom de l'erreur en plus de sont id dans directement
 *  depuis le nom du define de l'erreur
 *
 */
#define CHECK_PRINT_ERR(CONDITION, ERR_TYPE, MESSAGE) checkPrintErr(CONDITION, ERR_TYPE, #ERR_TYPE, MESSAGE)

/**
 *  @fn int checkPrintErr (const int condition, const int err_type, const char *err_name, const char *message)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Mon 15 Nov 2021 16:53
 *
 *  @brief Verifie la condition et affiche le message d'erreur si elle est vrai
 *
 * @param[in] condition : La condition a tester pour l'erreur
 * @param[in] err_type  : Le type d'erreur.
 * Si `err_type <= 0`  l'erreur est fatal et affichera le message d'erreur dans `stderr`.
 * Sinon l'erreur est non fatal et affichera le message d'erreur dans `stdout`
 * @param[in] err_name  : Le nom de l'erreur
 * @param[in] message   : Le message d'erreur
 * @return 0 si la condition est fausse ou `err_type` si la condition est non fatal
 */
int checkPrintErr(const int condition, const int err_type, const char *err_name, const char *message);

/**
 *  @fn int saisieEntierFatal (void)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Mon 15 Nov 2021 16:53
 *
 *  @brief Lie un entier dans stdin et le retourne. Arrete le programme si l'entré n'est pas un entier
 *
 *  @return Retourne l'entier saisie
 *
 */
int saisieEntierFatal(void);

/**
 *  @fn int saisieEntier (void)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Mon 15 Nov 2021 16:53
 *
 *  @brief Lie un entier dans stdin et le retourne. Si l'entré est incorrecte, redemande de saisir un entier
 *
 *  @return Retourne l'entier saisie
 *
 */
int saisieEntier(void);

////////////////////////////////////////////
//                  MATH
////////////////////////////////////////////

/**
 *  @fn float f_rand_entre(float min, float max)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Mon 22 Nov 2021 13:12
 *
 *  @brief Génère un nombre aléatoire entre min et max
 *
 *  @param[in] min : La valeur minimale
 *  @param[in] max : La valeur maximale
 *  @return Retourne un nombre réel aléatoire entre min et max
 *
 */
float f_rand_entre(float min, float max);

/**
 *  @fn int i_rand_entre(int min, int max)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Mon 22 Nov 2021 13:12
 *
 *  @brief Génère un nombre entier aléatoire entre min et max
 *
 *  @param[in] min : La valeur minimale
 *  @param[in] max : La valeur maximale
 *  @return Retourne un nombre entier aléatoire entre min et max
 *
 */
int i_rand_entre(int min, int max);

////////////////////////////////////////////
//                  Tableaux
////////////////////////////////////////////

////////////////////////////////////////////
//                      Tableaux 1D
////////////////////////////////////////////

#if defined(FEATURES_ALL) || defined(FEATURES_STRING)

/**
 *  @fn void allocString(char **str_chaine, unsigned int ui_taille)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 03 Dec 2021 10:07
 *
 *  @brief Alloue l'espace memoire pour une chaine de caractère
 *
 *  @param[in out] str_chaine     : Pointeur vers la chaine à allouer
 *  @param[in]     ui_taille  : Taille du tableau a allouer
 *
 *  @remark Necessite d'aciver la fonctionalité FEATURES_STRING
 */
void allocString(char **str_chaine, unsigned int ui_taille);

#endif // __STRING__

////////////////////////////////////////////
//                      Tableaux 1D Entiers
////////////////////////////////////////////

/**
 * @brief Composants permettant de traiter les tableau dynamique d'entiers a une dimension
 *
 */
#if defined(FEATURES_ALL) || defined(FEATURES_TAB1D_INT)

/**
 * @struct i_tab1D
 *
 *  @remark Necessite d'aciver la fonctionalité FEATURES_TAB1D_INT
 */
typedef struct
{
	/*! Données du tableau */
	int *data;
	/*! Taille du tableau */
	unsigned int taille;
} i_tab1D;

/**
 *  @fn void pi_allocTab1D (int **pi_tab, unsigned int ui_taille)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 03 Dec 2021 10:07
 *
 *  @brief Alloue l'espace memoire pour un tableau d'entier à une dimension
 *
 *  @param[in out] pi_tab     : Pointeur vers le tableau a allouer
 *  @param[in]     ui_taille  : Taille du tableau a allouer
 *
 *  @remark Necessite d'aciver la fonctionalité FEATURES_TAB1D_INT
 */
void pi_allocTab1D(int **pi_tab, unsigned int ui_taille);

/**
 *  @fn void pi_initTab1D(int *pi_tab, unsigned int ui_taille, int i_initVal);
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 03 Dec 2021 09:57
 *
 *  @brief Initialise un tableau dynamique d'entier à la valeur `i_initVal`
 *
 *  @param[in out] pi_tab     : Le tableau a initialiser
 *  @param[in]     ui_taille  : taille du tableau a initialiser
 *  @param[in]     i_initVal  : Valeur d'initialisation du tableau
 *
 *  @remark Necessite d'aciver la fonctionalité FEATURES_TAB1D_INT
 */
void pi_initTab1D(int *pi_tab, unsigned int ui_taille, int i_initVal);

/**
 *  @fn void pitab1d_creeTab (i_tab1D *pitab1d_tab, unsigned int ui_taille, int i_initVal)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 03 Dec 2021 10:33
 *
 *  @brief Alloue et initialise une Structure `i_tab1D` a la valeur `i_initVal`
 *
 *  @param[in out] pitab1d_tab : Structure de tableau 1D a initialiséer
 *  @param[in]     ui_taille   : Taille du tableau à allouer
 *  @param[in]     i_initVal   : Valeur d'initialisation du tableau
 *
 *  @remark Necessite d'aciver la fonctionalité FEATURES_TAB1D_INT
 */
void pitab1d_creeTab(i_tab1D *pitab1d_tab, unsigned int ui_taille, int i_initVal);

/**
 *  @fn void pitab1d_afficheTab (i_tab1D *pitab1d_tab)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Fri 03 Dec 2021 10:44
 *
 *  @brief Affiche le tableau d'entier a une dimension
 *
 *  @param[in] pitab1d_tab : Tableau à afficher
 *
 *  @remark Necessite d'aciver la fonctionalité FEATURES_TAB1D_INT
 */
void pitab1d_afficheTab(i_tab1D *pitab1d_tab);

/**
 *  @fn void pitab1d_echangeVal(i_tab1D *pitab1d_tab, unsigned int ui_indice1, unsigned int ui_indice2)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Mon 06 Dec 2021 22:37
 *
 *  @brief Echange deux valeurs dans un tableau d'entier a une dimension
 *
 *  @param[in out] pitab1d_tab : Tableau d'entier a une dimension
 *  @param[in] ui_indice1 : Indice de la premiere valeur a echanger
 *  @param[in] ui_indice2 : Indice de la deuxieme valeur a echanger
 *
 *  @remark Necessite d'aciver la fonctionalité FEATURES_TAB1D_INT
 */
void pitab1d_echangeVal(i_tab1D *pitab1d_tab, unsigned int ui_indice1, unsigned int ui_indice2);

/**
 *  @fn void pitab1d_rempliTabRandom (i_tab1D *pitab1d_tab, int i_min, int i_max)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 07 Dec 2021 14:26
 *
 *  @brief Rempli un tableau d'entien aléatoir entre `min` et `max`
 *
 *  @param[in out] pitab1d_tab : Tableau a remplir
 *  @param[in]     i_min       : Valeur minimum des nombres aléatoire
 *  @param[in]     i_max       : Valeur maximum des nombres aléatoire
 *
 *  @remark Necessite d'aciver la fonctionalité FEATURES_TAB1D_INT
 */
void pitab1d_rempliTabRandom(i_tab1D *pitab1d_tab, int i_min, int i_max);

/**
 *  @fn void pitab1d_free (i_tab1D *pitab1d_tab)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 08 Dec 2021 17:10
 *
 *  @brief Libére l'espace memoire d'un tableau d'entier 1D
 *
 *  @param[in out] pitab1d_tab : le tableau a libérer
 *
 *  @remark Necessite d'aciver la fonctionalité FEATURES_TAB1D_INT
 */
void pitab1d_free(i_tab1D *pitab1d_tab);

#endif // __TAB1D_INT__

#endif // __SAMLIB_H__
