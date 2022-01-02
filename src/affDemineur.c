/** @file affDemineur.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 21 Dec 2021 18:30
 *
 *  @brief
 *
 */

#include "affDemineur.h"

const cchar_t contenuCaseChar[10] = {
	(cchar_t){.attr = 0, .chars = {L'💣'}, .ext_color = COULEUR_BOMBE},
	(cchar_t){.attr = 0, .chars = {L' '}, .ext_color = COLOR_WHITE},
	(cchar_t){.attr = 0, .chars = {L'1'}, .ext_color = COULEUR_NB1},
	(cchar_t){.attr = 0, .chars = {L'2'}, .ext_color = COULEUR_NB2},
	(cchar_t){.attr = 0, .chars = {L'3'}, .ext_color = COULEUR_NB3},
	(cchar_t){.attr = 0, .chars = {L'4'}, .ext_color = COULEUR_NB4},
	(cchar_t){.attr = 0, .chars = {L'5'}, .ext_color = COULEUR_NB5},
	(cchar_t){.attr = 0, .chars = {L'6'}, .ext_color = COULEUR_NB6},
	(cchar_t){.attr = 0, .chars = {L'7'}, .ext_color = COULEUR_NB7},
	(cchar_t){.attr = 0, .chars = {L'8'}, .ext_color = COULEUR_NB8},
};
const cchar_t etatCaseChar[3] = {(cchar_t){.attr = A_NORMAL, .chars = {L'⚑'}, .ext_color = COULEUR_DRAPEAU},
								 (cchar_t){.attr = A_NORMAL, .chars = {L'~'}, .ext_color = COULEUR_CACHE},
								 (cchar_t){.attr = A_NORMAL, .chars = {L' '}, .ext_color = COLOR_WHITE}};

void initAffichage(void)
{
	initscr();

	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	CHECK_PRINT_ERR(setlocale(LC_CTYPE, "") == NULL, ERREUR_SET_LOCALE, "Impossible de changer le format des caractères.");
	CHECK_PRINT_ERR(has_colors() == FALSE, ERREUR_INIT_COULEUR, "Le terminal ne supporte pas les couleurs.");
	if (has_colors() == TRUE) {
		initCouleurs();
	}
}

void initCouleurs(void)
{
	int error = OK;
	start_color();
	error = init_color(COULEUR_BOMBE, 800, 0, 0);
	error = init_color(COULEUR_VIDE, 0, 0, 0);
	error = init_color(COULEUR_NB1, 423, 1000, 113);
	error = init_color(COULEUR_NB2, 298, 917, 380);
	error = init_color(COULEUR_NB3, 188, 854, 612);
	error = init_color(COULEUR_NB4, 78, 788, 839);
	error = init_color(COULEUR_NB5, 180, 607, 820);
	error = init_color(COULEUR_NB6, 458, 400, 541);
	error = init_color(COULEUR_NB7, 760, 176, 239);
	error = init_color(COULEUR_NB8, 1000, 0, 0);
	error = init_color(COULEUR_DRAPEAU, 1000, 1000, 1000);
	error = init_color(COULEUR_CACHE, 1000, 1000, 1000);
	error = init_color(COULEUR_CURSEUR, 500, 500, 1000);

	CHECK_PRINT_ERR(error == ERR, ERREUR_INIT_COULEUR, "Impossible d'initialiser une ou plusieurs couleurs.");
	error = OK;

	error = init_pair(COULEUR_NB1, COULEUR_NB1, 0);
	error = init_pair(COULEUR_NB2, COULEUR_NB2, 0);
	error = init_pair(COULEUR_NB3, COULEUR_NB3, 0);
	error = init_pair(COULEUR_NB4, COULEUR_NB4, 0);
	error = init_pair(COULEUR_NB5, COULEUR_NB5, 0);
	error = init_pair(COULEUR_NB6, COULEUR_NB6, 0);
	error = init_pair(COULEUR_NB7, COULEUR_NB7, 0);
	error = init_pair(COULEUR_NB8, COULEUR_NB8, 0);
	error = init_pair(COULEUR_BOMBE, COULEUR_BOMBE, 0);
	error = init_pair(COULEUR_VIDE, COULEUR_VIDE, 0);
	error = init_pair(COULEUR_DRAPEAU, COULEUR_DRAPEAU, 0);
	error = init_pair(COULEUR_CACHE, COULEUR_CACHE, 0);
	error = init_pair(COULEUR_CURSEUR, COULEUR_CURSEUR, 0);

	CHECK_PRINT_ERR(error == ERR, ERREUR_INIT_COULEUR, "Impossible d'initialiser une ou plusieurs paires de couleurs.");
}

WINDOW *creeWinPlateau(plateauDemineur *plateau, int i_x, int i_y)
{
	WINDOW *winPlateau; // Variable de retour
	CHECK_PRINT_ERR(((plateau->nbLignes + 2) > LINES) || (((plateau->nbColonnes * 2) + 3) > COLS), ERREUR_TAILLE_PLATEAU , "Le plateau est plus grand que la fenetre.");
	winPlateau = newwin(plateau->nbLignes + 2, (plateau->nbColonnes * 2) + 3, i_y, i_x);
	box(winPlateau, 0, 0);
	keypad(winPlateau, TRUE);
	wrefresh(winPlateau);
	return (winPlateau);
}

void detruitWinPlateau(WINDOW *winPlateau)
{
	wborder(winPlateau, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wrefresh(winPlateau);
	delwin(winPlateau);
}

void updateFenetrePlateau(WINDOW *winPlateau, plateauDemineur *plateau)
{

	wmove(winPlateau, 1, 2);

	int iter_Colonne;
	for (iter_Colonne = 0; iter_Colonne < plateau->nbColonnes; iter_Colonne++) {
		int iter_Ligne;
		for (iter_Ligne = 0; iter_Ligne < plateau->nbLignes; iter_Ligne++) {
			if ((plateau->posCurseur.x == iter_Colonne) && (plateau->posCurseur.y == iter_Ligne) &&
				(plateau->posCurseur.affiche == TRUE)) {
				mvwadd_wch(winPlateau, iter_Ligne + 1, (iter_Colonne * 2) + 2, &CURSEUR);
			} else if ((plateau->cases[iter_Colonne][iter_Ligne].etat == DECOUVERTE) || (plateau->xRay == TRUE)) {
				mvwadd_wch(winPlateau, iter_Ligne + 1, (iter_Colonne * 2) + 2,
						   &CONTENU_CASE_CHAR(plateau->cases[iter_Colonne][iter_Ligne].contenu));
			} else {
				mvwadd_wch(winPlateau, iter_Ligne + 1, (iter_Colonne * 2) + 2,
						   &ETAT_CASE_CHAR(plateau->cases[iter_Colonne][iter_Ligne].etat));
			}
		}
	}
	mvprintw(((LINES + plateau->nbLignes) / 2) + 2, (COLS - (plateau->nbColonnes * 2)) / 2, "Mines : %d/%d | Mode : %c ",
			 plateau->nbDrapeaux, plateau->nbMines, CHAR_MODE_DRAPEAU(plateau->posCurseur.mode));

	wrefresh(winPlateau);
}

void demarreJeux(int nbLignes, int nbColonnes, int nbMines)
{
	initAffichage();

	plateauDemineur *plateau = initPlateauDemineur(nbLignes, nbColonnes, nbMines);
	int				 starty	 = (LINES - plateau->nbLignes) / 2;		   /* Calculating for a center placement */
	int				 startx	 = (COLS - (plateau->nbColonnes * 2)) / 2; /* of the window		*/
	int				 ch;
	plateau->xRay = FALSE;
	MEVENT event;
	printw("Espace/Clique Souris pour découvrir, Flèches pour déplacer");
	refresh();
	WINDOW *my_win = creeWinPlateau(plateau, startx, starty);

	updateFenetrePlateau(my_win, plateau);
	mousemask(ALL_MOUSE_EVENTS, NULL);
	while (plateau->etat == 0) {
		ch = getch();
		switch (ch) {
			case KEY_UP:
				deplaceDurseur(plateau, plateau->posCurseur.x, plateau->posCurseur.y - 1);
				plateau->posCurseur.affiche = TRUE;
				break;
			case KEY_DOWN:
				deplaceDurseur(plateau, plateau->posCurseur.x, plateau->posCurseur.y + 1);
				plateau->posCurseur.affiche = TRUE;
				break;
			case KEY_LEFT:
				deplaceDurseur(plateau, plateau->posCurseur.x - 1, plateau->posCurseur.y);
				plateau->posCurseur.affiche = TRUE;
				break;
			case KEY_RIGHT:
				deplaceDurseur(plateau, plateau->posCurseur.x + 1, plateau->posCurseur.y);
				plateau->posCurseur.affiche = TRUE;
				break;
			case ' ':
				decouvreCase(plateau, plateau->posCurseur.x, plateau->posCurseur.y);
				plateau->posCurseur.affiche = FALSE;
				break;
			case 'd':
				if (plateau->posCurseur.mode == MODE_DECOUVRE) {
					plateau->posCurseur.mode = MODE_DRAPEAU;
				} else {
					plateau->posCurseur.mode = MODE_DECOUVRE;
				}
				printw("%d", plateau->posCurseur.mode);
				break;
			case KEY_MOUSE:
				if (getmouse(&event) == OK) {
					if (event.bstate & BUTTON1_CLICKED) {
						if (deplaceDurseur(plateau, (event.x - startx) / 2 - 1, event.y - starty - 1)) {
							plateau->posCurseur.affiche = FALSE;
							decouvreCase(plateau, plateau->posCurseur.x, plateau->posCurseur.y);
						}
					} else if (event.bstate & BUTTON2_CLICKED) {
						if (deplaceDurseur(plateau, (event.x - startx) / 2 - 1, event.y - starty - 1)) {
							plateau->posCurseur.affiche = FALSE;
							plateau->posCurseur.mode	= MODE_DRAPEAU;
							decouvreCase(plateau, plateau->posCurseur.x, plateau->posCurseur.y);
							plateau->posCurseur.mode = MODE_DECOUVRE;
						}
					}
				}
				break;
			default:
				break;
		}
		aGagne(plateau);
		updateFenetrePlateau(my_win, plateau);
	}
	freePlateauDemineur(plateau);
	printw("Partie terminé!");
	getch();
	endwin();
}
