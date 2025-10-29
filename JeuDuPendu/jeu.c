#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void affiche_pendu(int nombre_erreurs) {
	printf(" +---+\n");
	printf(" |   |\n");
	switch (nombre_erreurs) {
		case 0 : 
			printf("     |\n");
			printf("     |\n");
			printf("     |\n");
			break;
		case 1:
			printf(" O   |\n");
			printf("     |\n");
			printf("     |\n");
			break;
		case 2:
			printf(" O   |\n");
			printf(" |   |\n");
			printf("     |\n");
			break;
		case 3:
			printf(" O   |\n");
			printf(" |\  |\n");
			printf("     |\n");
			break;
		case 4:
			printf(" O   |\n");
			printf("/|\  |\n");
			printf("     |\n");
			break;
		case 5:
			printf(" O   |\n");
			printf("/|\  |\n");
			printf("  \  |\n");
			break;
		case 6:
			printf(" O   |\n");
			printf("/|\  |\n");
			printf("/ \  |\n");
			break;
	}
	printf("     |\n");
	printf("========\n");
}

void affiche_mot() {

}

int main() {
	char mot_a_trouver[6] = {};
	for (int i = 0; i < 6; i++) {
		mot_a_trouver[i] /* A compléter pour comparer */
	}

	return 0;
}