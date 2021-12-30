/** @file logicDemineur.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 22 Dec 2021 20:21
 *
 *  @brief Implémentation de la logique du demineur
 *
 */

#include <logicDemineur.h>

plateauDemineur *initPlateauDemineur(int i_nbLignes, int i_nbColonnes, int i_nbMines)
{
	plateauDemineur *plateau; // Variable de retour
	int				 i_iteColonne;
	int				 i_iterLigne;

	plateau				= (plateauDemineur *)malloc(sizeof(plateauDemineur));
	plateau->nbLignes	= i_nbLignes;
	plateau->nbColonnes = i_nbColonnes;
	plateau->nbMines	= i_nbMines;

	plateau->cases = (casePlateau **)malloc(sizeof(casePlateau *) * i_nbColonnes);
	CHECK_PRINT_ERR(plateau->cases == NULL, ERREUR_ALLOCATION_MEMOIRE, "Erreur d'allocation mémoire");

	for (i_iteColonne = 0; i_iteColonne < i_nbColonnes; i_iteColonne++) {
		plateau->cases[i_iteColonne] = (casePlateau *)malloc(sizeof(casePlateau) * i_nbLignes);
		CHECK_PRINT_ERR(plateau->cases[i_iteColonne] == NULL, ERREUR_ALLOCATION_MEMOIRE, "Erreur d'allocation mémoire");

		for (i_iterLigne = 0; i_iterLigne < i_nbLignes; i_iterLigne++) {
			plateau->cases[i_iteColonne][i_iterLigne].contenu = VIDE;
		}
	}

	return (plateau);
}

void freePlateauDemineur(plateauDemineur *plateau)
{
	int i_iteColonne;
	for (i_iteColonne = 0; i_iteColonne < plateau->nbColonnes; i_iteColonne++) {
		free(plateau->cases[i_iteColonne]);
	}
	free(plateau->cases);
	free(plateau);
}
