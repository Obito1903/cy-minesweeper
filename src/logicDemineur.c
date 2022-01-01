/** @file logicDemineur.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Wed 22 Dec 2021 20:21
 *
 *  @brief Implémentation de la logique du demineur
 *
 */

#include <logicDemineur.h>

void placeBombes(plateauDemineur *plateau, int i_nbMines)
{
	CHECK_PRINT_ERR(plateau->nbLignes * plateau->nbColonnes < i_nbMines, ERREUR_PARAM,
					"Le nombre de mines est supérieur au nombre de cases du plateau");
	srand(time(NULL));
	i_tab1D itab1d_casesdispo;
	pitab1d_creeTab(&itab1d_casesdispo, plateau->nbLignes * plateau->nbColonnes, 0);
	int i;
	for (i = 0; i < itab1d_casesdispo.taille; i++) {
		itab1d_casesdispo.data[i] = i;
	}
	pitab1d_melangeTab(&itab1d_casesdispo);

	for (i = 0; i < i_nbMines; i++) {
		int i_case								   = itab1d_casesdispo.data[i];
		int i_ligne								   = i_case / plateau->nbColonnes;
		int i_colonne							   = i_case % plateau->nbColonnes;
		plateau->cases[i_colonne][i_ligne].contenu = BOMBE;
	}
	pitab1d_free(&itab1d_casesdispo);
}

void placeNombres(plateauDemineur *plateau)
{
	int i_colonne;
	int i_ligne;
	int i_nbBombes;
	int i_vectX;
	int i_vectY;

	for (i_colonne = 0; i_colonne < plateau->nbColonnes; i_colonne++) {
		for (i_ligne = 0; i_ligne < plateau->nbLignes; i_ligne++) {
			if (plateau->cases[i_colonne][i_ligne].contenu != BOMBE) {
				i_nbBombes = 0;
				for (i_vectX = -1; i_vectX <= 1; i_vectX++) {
					for (i_vectY = -1; i_vectY <= 1; i_vectY++) {
						if ((i_colonne + i_vectX >= 0) && (i_colonne + i_vectX < plateau->nbColonnes) &&
							(i_ligne + i_vectY >= 0) && (i_ligne + i_vectY < plateau->nbLignes)) {
							if (plateau->cases[i_colonne + i_vectX][i_ligne + i_vectY].contenu == BOMBE) {
								i_nbBombes++;
							}
						}
					}
				}
				plateau->cases[i_colonne][i_ligne].contenu = i_nbBombes;
			}
		}
	}
}

plateauDemineur *initPlateauDemineur(int i_nbLignes, int i_nbColonnes, int i_nbMines)
{
	plateauDemineur *plateau; // Variable de retour
	int				 i_iteColonne;
	int				 i_iterLigne;

	plateau				= (plateauDemineur *)malloc(sizeof(plateauDemineur));
	plateau->nbLignes	= i_nbLignes;
	plateau->nbColonnes = i_nbColonnes;
	plateau->nbMines	= i_nbMines;
	plateau->nbDrapeaux = 0;
	plateau->xRay		= FALSE;

	plateau->cases = (casePlateau **)malloc(sizeof(casePlateau *) * i_nbColonnes);
	CHECK_PRINT_ERR(plateau->cases == NULL, ERREUR_ALLOCATION_MEMOIRE, "Erreur d'allocation mémoire");

	for (i_iteColonne = 0; i_iteColonne < i_nbColonnes; i_iteColonne++) {
		plateau->cases[i_iteColonne] = (casePlateau *)malloc(sizeof(casePlateau) * i_nbLignes);
		CHECK_PRINT_ERR(plateau->cases[i_iteColonne] == NULL, ERREUR_ALLOCATION_MEMOIRE, "Erreur d'allocation mémoire");

		for (i_iterLigne = 0; i_iterLigne < i_nbLignes; i_iterLigne++) {
			plateau->cases[i_iteColonne][i_iterLigne].contenu = VIDE;
		}
	}
	placeBombes(plateau, i_nbMines);
	placeNombres(plateau);
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
