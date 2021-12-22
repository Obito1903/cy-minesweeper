/** @file logicDemineur.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 22 Dec 2021 20:21
 *
 *  @brief Implémentation de la logique du demineur
 *
 */

#include <logicDemineur.h>

/**
 *  @fn plateauDemineur* initPlateauDemineur (int i_nbLignes, int i_nbColonnes, int i_nbMines)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 22 Dec 2021 20:22
 *
 *  @brief
 *
 *  @param[in]
 *  @return
 *
 */
plateauDemineur *initPlateauDemineur(int i_nbLignes, int i_nbColonnes, int i_nbMines)
{
	plateauDemineur *plateau; // Variable de retour
	int				 i_iteColonne;
	int				 i_iterLigne;

	plateau				= (plateau *)malloc(sizeof(plateauDemineur));
	plateau->nbLignes	= i_nbLignes;
	plateau->nbColonnes = i_nbColonnes;
	plateau->nbMines	= i_nbMines;

	plateau->tabCases = (contenuCase **)malloc(sizeof(caseDemineur *) * i_nbColonnes);
	CHECK_PRINT_ERR(plateau->tabCases == NULL, ERREUR_ALLOCATION_MEMOIRE, "Erreur d'allocation mémoire");

	for (i_iteColonne = 0; i_iteColonne < i_nbColonnes; i_iteColonne++) {
		plateau->tabCases[i_iteColonne] = malloc(sizeof(caseDemineur) * i_nbLignes);
		CHECK_PRINT_ERR(plateau->tabCases[i_iteColonne] == NULL, ERREUR_ALLOCATION_MEMOIRE, "Erreur d'allocation mémoire");

		for (i_iterLigne = 0; i_iterLigne < i_nbLignes; i_iterLigne++) {
			plateau->tabCases[i_iteColonne][i_iterLigne].contenu = VIDE;
		}
	}

	return (plateau);
}

/**
 *  @fn void freePlateauDemineur (plateauDemineur *plateau)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 22 Dec 2021 20:43
 *
 *  @brief
 *
 *  @param[in]
 *
 */
void freePlateauDemineur(plateauDemineur *plateau)
{
	int i_iteColonne;
	for (i_iteColonne = depart; i_iteColonne < arrivée; i_iteColonne++) {
		free(plateau->tabCases[i_iteColonne]);
	}
	free(plateau->tabCases);
	free(plateau);
}
