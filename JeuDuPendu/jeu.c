#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ERROR 6

void affiche_pendu(int nombre_erreurs) {
	/*
	Affiche l'état actuel du pendu en fonction du nombre d'erreurs commises
	*/
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
			printf(" |\\  |\n");
			printf("     |\n");
			break;
		case 4:
			printf(" O   |\n");
			printf("/|\\  |\n");
			printf("     |\n");
			break;
		case 5:
			printf(" O   |\n");
			printf("/|\\  |\n");
			printf("  \\  |\n");
			break;
		case 6:
			printf(" O   |\n");
			printf("/|\\  |\n");
			printf("/ \\  |\n");
			break;
	}
	printf("     |\n");
	printf("========\n");
}

void affiche_mot(char mot[6]) {
	/*
	Affiche toutes les lettres d'un mot (en l'occurence les lettres du mot que l'on a trouvé)
	*/
	for (int i = 0; i < 6; i++) {
		printf("%c", mot[i]);
	}
	printf("\n");
}

bool mot_trouve(char mot[6]) {
	/*
	Indique si le mot complet a été trouvé
	*/
	for (int i = 0; i < 6; i++) {
		if (mot[i] == '_') {
			return false;
		}
	}
	return true;
}

int main() {
	/*
	Initialisation du nombre d'erreurs et du mot à trouver
	*/
	int nombre_erreurs = 0;
	bool trouve = false;
	char mot_a_trouver[6] = {'-','-','-','-','-','-'};
	printf("Entrez un mot a 6 lettres : ");
	for (int i = 0; i < 6; i++) {
		scanf(" %c",&mot_a_trouver[i]);
	}
	/*
	Nettoyage de la fenêtre
	*/
	system("cls");
	char a_afficher[6] = { '_','_','_','_','_','_' };
	char lettre_cherchee;


	/*
	Vérification de la lettre cherchée dans le mot à trouver tant que l'on a ni gagné ni perdu
	*/
	while (trouve == false && nombre_erreurs < MAX_ERROR){
		printf("Entrez un charactere a chercher : ");
		scanf(" %c", &lettre_cherchee);
		bool present = false;
		/*
		On vérifie la présence de la lettre à chaque position
		*/
		for (int i = 0; i < 6; i++) {
			if (lettre_cherchee == mot_a_trouver[i]) {
				a_afficher[i] = lettre_cherchee;
				present = true;
			}
		}
		if (present == false) {
			nombre_erreurs += 1;
		}
		/*
		Nettoyage de la fenêtre et affichage des informations mises à jour pour le joueur
		*/
		system("cls");
		affiche_mot(a_afficher);
		affiche_pendu(nombre_erreurs);
		trouve = mot_trouve(a_afficher);
	}


	/*
	Affichage du message de victoire ou de défaite et validation du mot de départ
	*/
	if (trouve == true) {
		printf("Felicitations ! ");
		
	}
	else {
		printf("Dommage ! ");
	}
	printf("Mon mot etait ");
	for (int i = 0; i < 6; i++) {
		printf("%c", mot_a_trouver[i]);
	}
	printf("\n");
	return 0;
}