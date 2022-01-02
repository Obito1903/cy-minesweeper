/** @file main.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 18 Dec 2021 19:50
 *
 *  @brief Module maindu TP9
 *
 */

#include <affDemineur.h>
#include <string.h>

/**
 *  @fn void afficheAide (void)
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Thu 09 Dec 2021 12:34
 *
 *  @brief Affiche l'aide d'une fonction
 */
void afficheAide(void)
{
	printf("Aide du TP9 - Demineur - Rodrigues Samuel\n"
		   "Utilisation: TP9 [options]\n"
		   "	Les options sont:\n"
		   "	-H <Hauteur du plateau>\n"
		   "	-L <Longueur du plateau>\n"
		   "	-M <Nombre de mines>\n");
}

/**
 *
 *  @fn int main (int argc, char const *argv[])
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 18 Dec 2021 19:50
 *
 *  @brief Fonction Principale
 *
 *  @param[in] argc Nombre d'arguments
 *  @param[in] *argv[] Tableau d'arguments
 *  @return EXIT_SUCCESS : le programme doit se terminer normalement
 *
 */
int main(int argc, char const *argv[])
{
	int iter_arg   = 1;
	int nbLignes   = 10;
	int nbColonnes = 20;
	int nbMines	   = 10;
	while (iter_arg < argc) {
		printf("%s\n", argv[iter_arg]);
		if ((strcmp(argv[iter_arg], "-H") == 0) && (argc > iter_arg + 1)) {
			nbLignes = atoi(argv[iter_arg + 1]);
			iter_arg += 1;
		} else if ((strcmp(argv[iter_arg], "-L") == 0) && (argc > iter_arg + 1)) {
			nbColonnes = atoi(argv[iter_arg + 1]);
			iter_arg += 1;
		} else if ((strcmp(argv[iter_arg], "-M") == 0) && (argc > iter_arg + 1)) {
			nbMines = atoi(argv[iter_arg + 1]);
			iter_arg += 1;
		} else if (strcmp(argv[iter_arg], "-h") == 0) {
			afficheAide();
		} else {
			CHECK_PRINT_ERR(1, ERREUR_ARGUMENTS,
							"L'option specifier n'existe pas."
							"\nUtiliser l'option -h pour afficher l'aide");
		}
		iter_arg++;
	}

	demarreJeux(nbLignes, nbColonnes, nbMines);
	return (0);
}
