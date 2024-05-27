#define _CRT_SECURE_NO_WARNINGS

#include"header.h"

enum IzborKorisnik {
	PREGLED = 1,
	PRETRAGA,
	KMU,
	KMS,
	GODU,
	GODS,
	CIJU,
	CIJS,
	KAROSERIJA,
	KUPOVINA,
	IZLAZ
};


void izborKorisnik() {
	int izbor;
	printf("!Korisnicki Izbornik!\n");
	printf("[1] Pregled svih automobila\n");
	printf("[2] Pretrazivanje automobila\n");
	printf("[3] Sortiranje automobila (kilometraza - UZLAZNO)\n");
	printf("[4] Sortiranje automobila (kilometraza - SILAZNO)\n");
	printf("[5] Sortiranje automobila (godiste - UZLAZNO)\n");
	printf("[6] Sortiranje automobila (godiste - SILAZNO)\n");
	printf("[7] Sortiranje automobila (cijena - UZLAZNO)\n");
	printf("[8] Sortiranje automobila (cijena - SILAZNO)\n");
	printf("[9] Pretraga automobila po obliku karoserije\n");
	printf("[10] Kupovina automobila\n");
	printf("[11] Izlaz iz programa\n");
	printf("/////////////////////////////////\n");
	printf("Unesite vas izbor: ");
	scanf("%d", &izbor);
	if (strcmp(izbor, "pregled") == 0)
		izbor = PREGLED;
	
	FILE* auti = NULL;
	AUTO* mobil = NULL;
	int broj;
	char karoserija[15];

	switch (izbor) {
	case PREGLED:
		auti = fopen("auti.txt", "r");
		if (auti == NULL) {
			perror("Greska pri otvaranju datoteke");
			break;
		}
		pregledAutomobila();
		fclose(auti);
		break;
	case 2:
		auti = fopen("auti.txt", "r");
		if (auti == NULL) {
			perror("Greska pri otvaranju datoteke");
			break;
		}
		pretraziAute();
		fclose(auti);
		break;
	case 3:
		scanAuto(&mobil, &broj);
		printf("Automobili sortirani po kilometrazi (UZLAZNO)\n");
		sortirajKilometrazaUzlazno(mobil, broj);
		printAuto(mobil, broj);
		free(mobil);
		break;
	case 4:
		scanAuto(&mobil, &broj);
		printf("Automobili sortirani po kilometrazi (SILAZNO)\n");
		sortirajKilometrazuSilazno(mobil, broj);
		printAuto(mobil, broj);
		free(mobil);
		break;
	case 5:
		scanAuto(&mobil, &broj);
		printf("Automobili sortirani po godistu (UZLAZNO)\n");
		sortirajGodisteUzlazno(mobil, broj);
		printAuto(mobil, broj);
		free(mobil);
		break;
	case 6:
		scanAuto(&mobil, &broj);
		printf("Automobili sortirani po godistu (SILAZNO)\n");
		sortirajGodisteSilazno(mobil, broj);
		printAuto(mobil, broj);
		free(mobil);
		break;
	case 7:
		scanAuto(&mobil, &broj);
		printf("Automobili sortirani po cijeni (UZLAZNO)\n");
		sortirajCijenuUzlazno(mobil, broj);
		printAuto(mobil, broj);
		free(mobil);
		break;
	case 8:
		scanAuto(&mobil, &broj);
		printf("Automobili sortirani po cijeni (SILAZNO)\n");
		sortirajCijenuSilazno(mobil, broj);
		printAuto(mobil, broj);
		free(mobil);
		break;
	case 9:
		scanAuto(&mobil, &broj);
		printf("Unesi karoseriju koju zelis pretraziti: ");
		scanf("%14s", karoserija);
		printf("Svi automobili tipa: %s\n", karoserija);
		pretragaPoKaroseriji(mobil, broj, karoserija);
		free(mobil);
		break;
	case 10:
		kupovinaAutomobila();
		break;
	case 11:
		if (krajPrograma() == 0) {
			printf("Kraj programa, stisnite bilo koju tipku\n");
			getchar(); 
			getchar(); 
			exit(0); 
		}
		else {
			printf("Za povratak na pocetni izbornik pritisnite bilo koju tipku\n");
			getchar(); 
			getchar(); 
			return; 
		}
	default:
		printf("Krivi broj unesen!\n");
		return; 
	}
	exit(0);
}