/** @file demineur.h
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Tue 21 Dec 2021 18:28
 *
 *  @brief Fonction et structures globales du programme
 *
 */

#include <demineur.h>

const cchar_t contenuCaseChar[10] = {
	(cchar_t){.attr = A_NORMAL, .chars = {L'💣'}, .ext_color = COLOR_PAIR(BOMBE)},
	(cchar_t){.attr = A_NORMAL, .chars = {L' '}, .ext_color = COLOR_WHITE},
	(cchar_t){.attr = A_NORMAL, .chars = {L'1'}, .ext_color = NB1},
	(cchar_t){.attr = A_NORMAL, .chars = {L'2'}, .ext_color = COLOR_BLUE},
	(cchar_t){.attr = A_NORMAL, .chars = {L'3'}, .ext_color = COLOR_GREEN},
	(cchar_t){.attr = A_NORMAL, .chars = {L'4'}, .ext_color = COLOR_YELLOW},
	(cchar_t){.attr = A_NORMAL, .chars = {L'5'}, .ext_color = COLOR_YELLOW},
	(cchar_t){.attr = A_NORMAL, .chars = {L'6'}, .ext_color = COLOR_MAGENTA},
	(cchar_t){.attr = A_NORMAL, .chars = {L'7'}, .ext_color = COLOR_RED},
	(cchar_t){.attr = A_NORMAL, .chars = {L'8'}, .ext_color = COLOR_RED},
};
const cchar_t etatCaseChar[3] = {(cchar_t){.attr = A_NORMAL, .chars = {L'⚑'}, .ext_color = NB1},
								 (cchar_t){.attr = A_NORMAL, .chars = {L'~'}, .ext_color = COLOR_WHITE},
								 (cchar_t){.attr = A_NORMAL, .chars = {L' '}, .ext_color = COLOR_WHITE}};
