#define _CRT_SECURE_NO_WARNINGS
#include"header.h"


void pregledAutomobila() {
	FILE* auti = fopen("auti.txt", "r");
	if (auti == NULL) {
		perror("Greska pri otvaranju datoteke");
		return;
	}

	AUTO mobil;
	while (fscanf(auti, "%d", &mobil.id) == 1) {

		fscanf(auti, "%19s", mobil.marka);
		fscanf(auti, "%19s", mobil.model);
		fscanf(auti, "%14s", mobil.karoserija);
		fscanf(auti, "%9s", mobil.pogon);
		fscanf(auti, "%14s", mobil.motor);
		fscanf(auti, "%14s", mobil.boja);
		fscanf(auti, "%d", &mobil.konji);
		fscanf(auti, "%d", &mobil.newtonm);
		fscanf(auti, "%d", &mobil.kilometraza);
		fscanf(auti, "%d", &mobil.godiste);

		printf("ID: %d\n", mobil.id);
		printf("Marka: %s\n", mobil.marka);
		printf("Model: %s\n", mobil.model);
		printf("Karoserija: %s\n", mobil.karoserija);
		printf("Pogon: %s\n", mobil.pogon);
		printf("Motor: %s\n", mobil.motor);
		printf("Boja: %s\n", mobil.boja);
		printf("Konjske snage: %d\n", mobil.konji);
		printf("Newton-metri: %d\n", mobil.newtonm);
		printf("Kilometraza: %d\n", mobil.kilometraza);
		printf("Godiste: %d\n", mobil.godiste);
		printf("---------------------------------\n");
	}

	fclose(auti);
}

void pretraziAute() {
	FILE* auti = fopen("auti.txt", "r");
	if (auti == NULL) {
		perror("Greska pri otvaranju datoteke");
		return;
	}

	printf("Izaberi kriterij pretrage:\n");
	printf("1. ID\n2. Marka\n");
	int izbor;
	scanf("%d", &izbor);
	getchar();

	AUTO mobil;
	int id;
	char marka[20];
	int found = 0;

	switch (izbor) {
	case 1:
		printf("Unesi ID automobila: ");
		scanf("%d", &id);
		while (fscanf(auti, "%d", &mobil.id) == 1) {
			fgetc(auti);
			fscanf(auti, "%19s", mobil.marka);
			fscanf(auti, "%19s", mobil.model);
			fscanf(auti, "%14s", mobil.karoserija);
			fscanf(auti, "%9s", mobil.pogon);
			fscanf(auti, "%14s", mobil.motor);
			fscanf(auti, "%14s", mobil.boja);
			fscanf(auti, "%d", &mobil.konji);
			fscanf(auti, "%d", &mobil.newtonm);
			fscanf(auti, "%d", &mobil.kilometraza);
			fscanf(auti, "%d", &mobil.godiste);
			fgetc(auti);

			if (mobil.id == id) {
				found = 1;
				printf("Automobil pronadjen:\n");
				printf("ID: %d\nMarka: %s\nModel: %s\nKaroserija: %s\nPogon: %s\nMotor: %s\nBoja: %s\nKonji: %d\nNewtonm: %d\nKilometraza: %d\nGodiste: %d\n",
					mobil.id, mobil.marka, mobil.model, mobil.karoserija, mobil.pogon,
					mobil.motor, mobil.boja, mobil.konji, mobil.newtonm, mobil.kilometraza, mobil.godiste);
				break;
			}
		}
		if (!found) {
			printf("Automobil (ID %d) nije pronadjen.\n", id);
		}
		break;

	case 2:
		printf("Unesi marku automobila: ");
		scanf("%19s", marka);
		while (fscanf(auti, "%d", &mobil.id) == 1) {
			fgetc(auti);
			fscanf(auti, "%19s", mobil.marka);
			fscanf(auti, "%19s", mobil.model);
			fscanf(auti, "%14s", mobil.karoserija);
			fscanf(auti, "%9s", mobil.pogon);
			fscanf(auti, "%14s", mobil.motor);
			fscanf(auti, "%14s", mobil.boja);
			fscanf(auti, "%d", &mobil.konji);
			fscanf(auti, "%d", &mobil.newtonm);
			fscanf(auti, "%d", &mobil.kilometraza);
			fscanf(auti, "%d", &mobil.godiste);
			fgetc(auti);

			if (strcmp(mobil.marka, marka) == 0) {
				found = 1;
				printf("Automobil pronadjen:\n");
				printf("ID: %d\nMarka: %s\nModel: %s\nKaroserija: %s\nPogon: %s\nMotor: %s\nBoja: %s\nKonji: %d\nNewtonm: %d\nKilometraza: %d\nGodiste: %d\n",
					mobil.id, mobil.marka, mobil.model, mobil.karoserija, mobil.pogon,
					mobil.motor, mobil.boja, mobil.konji, mobil.newtonm, mobil.kilometraza, mobil.godiste);
			}
		}
		if (!found) {
			printf("Automobili marke %s nisu pronadjeni.\n", marka);
		}
		break;

	default:
		printf("Nepostojeci izbor.\n");
		break;
	}

	fclose(auti);
}

void pretragaPoKaroseriji(AUTO* mobil, int broj, const char* karoserija) {
	int found = 0;
	for (int i = 0; i < broj; i++) {
		if (strcmp(mobil[i].karoserija, karoserija) == 0) {
			printf("ID: %d\nMarka: %s\nModel: %s\nKaroserija: %s\nPogon: %s\nMotor: %s\nBoja: %s\nKonji: %d\nNewtonm: %d\nKilometraza: %d\nGodiste: %d\n\n",
				mobil[i].id, mobil[i].marka, mobil[i].model, mobil[i].karoserija,
				mobil[i].pogon, mobil[i].motor, mobil[i].boja, mobil[i].konji,
				mobil[i].newtonm, mobil[i].kilometraza, mobil[i].godiste);
			found = 1;
		}
	}
	if (!found) {
		printf("Nema automobila sa karoserijom: %s\n", karoserija);
	}
}


