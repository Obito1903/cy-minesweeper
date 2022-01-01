/** @file samLib.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Mon 22 Nov 2021 15:31
 *
 *  @brief Bibliotheque de fonctions utile pour mes projets
 *
 */

#include "samLib.h"

struct winsize ws_getTerminalesize(void)
{
	struct winsize retour; // Variable de retour
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &retour);
	return (retour);
}

void clearBuffer(void)
{
	int c;
	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}

int checkPrintErr(const int condition, const int err_type, const char *err_name, const char *message)
{
	if (condition) {
		if (err_type <= 0) {
			fprintf(stderr, "ERREUR (%s : %d) : %s \n", err_name, err_type, message);
			exit(err_type);
		} else {
			printf("WARNING (%s : %d) : %s \n", err_name, err_type, message);
			return err_type;
		}
	}
	return 0;
}

int saisieEntierFatal(void)
{
	int	 n; // Variable de retour
	int	 i_resScanf = 0;
	char s_overflow[100];
	sprintf(s_overflow, "Saisie incorrecte, Entier trop grand, il doit etre compris entre %d et %d", INT_MIN, INT_MAX);

	i_resScanf = scanf("%d", &n);
	CHECK_PRINT_ERR(errno == ERANGE, ERREUR_SAISIE_FATAL, s_overflow);
	CHECK_PRINT_ERR(i_resScanf != 1 || getchar() != '\n', ERREUR_SAISIE_FATAL, "Saisie incorrect, un entier est attendu !");
	return (n);
}

int saisieEntier(void)
{
	int	 n			= 0; // Variable de retour
	int	 i_resScanf = 1;
	char s_overflow[100];
	int	 i_bufferVide;
	sprintf(s_overflow, "Saisie incorrecte, Entier trop grand, il doit etre compris entre %d et %d", INT_MIN, INT_MAX);
	do {
		i_resScanf	 = scanf("%d", &n);
		i_bufferVide = getchar() != '\n';
	} while (CHECK_PRINT_ERR(errno == ERANGE, ERREUR_SAISIE, s_overflow) ||
			 CHECK_PRINT_ERR(i_bufferVide || i_resScanf != 1, ERREUR_SAISIE,
							 "Saisie incorrect, un entier est attendu !\nVeuillez reessayer:"));
	return (n);
}

////////////////////////////////////////////
//                  MATH
////////////////////////////////////////////

float f_rand_entre(float min, float max)
{
	CHECK_PRINT_ERR(min > max, ERREUR_PARAM, "min doit etre inferieur a max");
	return ((((float)rand() / (float)RAND_MAX) * (max + abs(min))) - abs(min));
}

int i_rand_entre(int min, int max)
{
	CHECK_PRINT_ERR(min > max, ERREUR_PARAM, "min doit etre inferieur a max");
	return ((rand() % (max + 1 - min)) + min);
}

////////////////////////////////////////////
//                  Tableaux
////////////////////////////////////////////

////////////////////////////////////////////
//                      Tableaux 1D
////////////////////////////////////////////

#if defined(FEATURES_ALL) || defined(FEATURES_STRING)

void allocString(char **str_chaine, unsigned int ui_taille)
{
	*str_chaine = (char *)malloc(sizeof(char) * ui_taille);
	CHECK_PRINT_ERR(*str_chaine == NULL, ERREUR_ALLOCATION_MEMOIRE, "Imposible d'allouer la memoire demandée");
}

#endif // __STRING__

////////////////////////////////////////////
//                      Tableaux 1D Entiers
////////////////////////////////////////////

#if defined(FEATURES_ALL) || defined(FEATURES_TAB1D_INT)

void pi_allocTab1D(int **pi_tab, unsigned int ui_taille)
{
	*pi_tab = (int *)malloc(sizeof(int) * ui_taille);
	CHECK_PRINT_ERR(*pi_tab == NULL, ERREUR_ALLOCATION_MEMOIRE, "Imposible d'allouer la memoire demandée");
}

void pi_initTab1D(int *pi_tab, unsigned int ui_taille, int i_initVal)
{
	int i;
	for (i = 0; i < ui_taille; i++) {
		pi_tab[i] = i_initVal;
	}
}

void pitab1d_creeTab(i_tab1D *pitab1d_tab, unsigned int ui_taille, int i_initVal)
{
	pi_allocTab1D(&(pitab1d_tab->data), ui_taille);
	pi_initTab1D(pitab1d_tab->data, ui_taille, i_initVal);
	pitab1d_tab->taille = ui_taille;
}

void pitab1d_afficheTab(i_tab1D *pitab1d_tab)
{
	int i;
	for (i = 0; i < pitab1d_tab->taille; i++) {
		printf("| %d ", pitab1d_tab->data[i]);
	}
	printf("|\n");
}

void pitab1d_echangeVal(i_tab1D *pitab1d_tab, unsigned int ui_indice1, unsigned int ui_indice2)
{
	CHECK_PRINT_ERR(ui_indice1 >= pitab1d_tab->taille || ui_indice1 < 0, ERREUR_PARAM,
					"ui_indice1 doit etre compris entre 0 et pitab1d_tab->taille - 1");
	CHECK_PRINT_ERR(ui_indice2 >= pitab1d_tab->taille || ui_indice2 < 0, ERREUR_PARAM,
					"ui_indice1 doit etre compris entre 0 et pitab1d_tab->taille - 1");

	int i_tmp = pitab1d_tab->data[ui_indice1];

	pitab1d_tab->data[ui_indice1] = pitab1d_tab->data[ui_indice2];
	pitab1d_tab->data[ui_indice2] = i_tmp;
}

void pitab1d_rempliTabRandom(i_tab1D *pitab1d_tab, int i_min, int i_max)
{
	int i;
	for (i = 0; i < pitab1d_tab->taille; i++) {
		pitab1d_tab->data[i] = i_rand_entre(i_min, i_max);
	}
}

void pitab1d_melangeTab(i_tab1D *pitab1d_tab)
{
	int i;
	for (i = 0; i < pitab1d_tab->taille; i++) {
		pitab1d_echangeVal(pitab1d_tab, i, i_rand_entre(0, pitab1d_tab->taille - 1));
	}
}

void pitab1d_free(i_tab1D *pitab1d_tab)
{
	free(pitab1d_tab->data);
}

	#if defined(TEST_SAMLIB_TAB1D)

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	i_tab1D tab1d;
	pitab1d_creeTab(&tab1d, 50, 0);
	int int_i;
	for (int_i = 0; int_i < 50; int_i++) {
		tab1d.data[int_i] = int_i;
	}
	printf("Tableau avant mélange :\n");
	pitab1d_afficheTab(&tab1d);
	pitab1d_melangeTab(&tab1d);
	printf("Tableau après mélange :\n");
	pitab1d_afficheTab(&tab1d);
	return (0);
}

	#endif

#endif // __TAB1D_INT__
