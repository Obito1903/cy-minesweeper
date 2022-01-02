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

	plateau						= (plateauDemineur *)malloc(sizeof(plateauDemineur));
	plateau->nbLignes			= i_nbLignes;
	plateau->nbColonnes			= i_nbColonnes;
	plateau->nbMines			= i_nbMines;
	plateau->nbDrapeaux			= 0;
	plateau->xRay				= FALSE;
	plateau->etat				= 0;
	plateau->posCurseur.affiche = TRUE;
	plateau->posCurseur.x		= 1;
	plateau->posCurseur.y		= 2;
	plateau->posCurseur.mode	= 1;

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

void decouvreCase(plateauDemineur *plateau, int posX, int posY)
{
	int i_vectX;
	int i_vectY;
	if (plateau->posCurseur.mode == MODE_DRAPEAU) {
		if (plateau->cases[posX][posY].etat == CACHE) {
			plateau->cases[posX][posY].etat = DRAPEAU;
			plateau->nbDrapeaux++;
		} else if (plateau->cases[posX][posY].etat == DRAPEAU) {
			plateau->cases[posX][posY].etat = CACHE;
			plateau->nbDrapeaux--;
		}
	} else if ((plateau->cases[posX][posY].etat != DECOUVERTE)) {
		plateau->cases[posX][posY].etat = DECOUVERTE;
		if (plateau->cases[posX][posY].contenu == BOMBE) {
			plateau->etat = -1;
		} else if (plateau->cases[posX][posY].contenu == VIDE) {
			for (i_vectX = -1; i_vectX <= 1; i_vectX++) {
				for (i_vectY = -1; i_vectY <= 1; i_vectY++) {
					if ((posX + i_vectX >= 0) && (posX + i_vectX < plateau->nbColonnes) && (posY + i_vectY >= 0) &&
						(posY + i_vectY < plateau->nbLignes) && (i_vectX != 0 || i_vectY != 0)) {
						decouvreCase(plateau, posX + i_vectX, posY + i_vectY);
					}
				}
			}
		}
	}
}

int deplaceDurseur(plateauDemineur *plateau, int posX, int posY)
{
	int err; // Variable de retour

	if ((posX >= 0) && (posX < plateau->nbColonnes) && (posY >= 0) && (posY < plateau->nbLignes)) {
		plateau->posCurseur.x = posX;
		plateau->posCurseur.y = posY;
		err					  = TRUE;
	} else {
		err = FALSE;
	}

	return (err);
}

int validePosDrapeaux(plateauDemineur *plateau)
{
	int retour = TRUE; // Variable de retour

	int i_Colonne;
	int i_Lignes;
	for (i_Colonne = 0; i_Colonne < plateau->nbColonnes; i_Colonne++) {
		for (i_Lignes = 0; i_Lignes < plateau->nbLignes; i_Lignes++) {
			if ((plateau->cases[i_Colonne][i_Lignes].etat == DRAPEAU) &&
				(plateau->cases[i_Colonne][i_Lignes].contenu != BOMBE)) {
				retour = FALSE;
			}
		}
	}

	return (retour);
}

void aGagne(plateauDemineur *plateau)
{
	printw("|%d-%d", plateau->nbMines == plateau->nbDrapeaux, validePosDrapeaux(plateau) == TRUE);
	if ((plateau->nbMines == plateau->nbDrapeaux) && (validePosDrapeaux(plateau) == TRUE)) {
		plateau->etat = 1;
	}
}
