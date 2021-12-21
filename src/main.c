/** @file main.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Sat 18 Dec 2021 19:50
 *
 *  @brief Module maindu TP9
 *
 */

#include <affDemineur.h>

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
	initscr();

	cbreak();			  /* Line buffering disabled, Pass on
						   * everty thing to me 		*/
	keypad(stdscr, TRUE); /* I need that nifty F1 	*/

	plateauDemineur plateau;
	plateau.nbLignes   = 3;
	plateau.nbColonnes = 10;
	int starty		   = (LINES - plateau.nbLignes) / 2;  /* Calculating for a center placement */
	int startx		   = (COLS - plateau.nbColonnes) / 2; /* of the window		*/
	int ch;

	printw("Press F1 to exit");
	refresh();
	WINDOW *my_win = creeWinPlateau(&plateau, startx, starty);

	while ((ch = getch()) != KEY_F(1)) {
		switch (ch) {
			case KEY_LEFT:
				detruitWinPlateau(my_win);
				my_win = creeWinPlateau(&plateau, --startx, starty);
				break;
			case KEY_RIGHT:
				detruitWinPlateau(my_win);
				my_win = creeWinPlateau(&plateau, ++startx, starty);
				break;
			case KEY_UP:
				detruitWinPlateau(my_win);
				my_win = creeWinPlateau(&plateau, startx, --starty);
				break;
			case KEY_DOWN:
				detruitWinPlateau(my_win);
				my_win = creeWinPlateau(&plateau, startx, ++starty);
				break;
		}
	}

	endwin();
	return (0);
}
