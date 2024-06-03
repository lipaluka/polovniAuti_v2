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
		fscanf(auti, "%d", &mobil.cijena);

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
		printf("Cijena: %d(EUR)\n", mobil.cijena);
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
			fscanf(auti, "%d", &mobil.cijena);
			fgetc(auti);

			if (mobil.id == id) {
				found = 1;
				printf("Automobil pronadjen:\n");
				printf("ID: %d\nMarka: %s\nModel: %s\nKaroserija: %s\nPogon: %s\nMotor: %s\nBoja: %s\nKonji: %d\nNewtonm: %d\nKilometraza: %d\nGodiste: %d\nCijena: %d(EUR)\n",
					mobil.id, mobil.marka, mobil.model, mobil.karoserija, mobil.pogon,
					mobil.motor, mobil.boja, mobil.konji, mobil.newtonm, mobil.kilometraza, mobil.godiste, mobil.cijena);
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
			fscanf(auti, "%d", &mobil.cijena);
			fgetc(auti);

			if (strcmp(mobil.marka, marka) == 0) {
				found = 1;
				printf("Automobil pronadjen:\n");
				printf("ID: %d\nMarka: %s\nModel: %s\nKaroserija: %s\nPogon: %s\nMotor: %s\nBoja: %s\nKonji: %d\nNewtonm: %d\nKilometraza: %d\nGodiste: %d\nCijena: %d(EUR)\n",
					mobil.id, mobil.marka, mobil.model, mobil.karoserija, mobil.pogon,
					mobil.motor, mobil.boja, mobil.konji, mobil.newtonm, mobil.kilometraza, mobil.godiste, mobil.cijena);
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
			printf("ID: %d\nMarka: %s\nModel: %s\nKaroserija: %s\nPogon: %s\nMotor: %s\nBoja: %s\nKonji: %d\nNewtonm: %d\nKilometraza: %d\nGodiste: %d\nCijena: %d(EUR)\n\n",
				mobil[i].id, mobil[i].marka, mobil[i].model, mobil[i].karoserija,
				mobil[i].pogon, mobil[i].motor, mobil[i].boja, mobil[i].konji,
				mobil[i].newtonm, mobil[i].kilometraza, mobil[i].godiste, mobil[i].cijena);
			found = 1;
		}
	}
	if (!found) {
		printf("Nema automobila sa karoserijom: %s\n", karoserija);
	}
}

void kupovinaAutomobila() {
	extern int var;
	AUTO* mobil;
	int broj;

	scanAuto(&mobil, &broj);
	pretraziAute(mobil, broj);

	printf("Unesi ID automobila koji zelite kupiti: ");
	int kupovinaID;
	scanf("%d", &kupovinaID);
	getchar();

	int found = 0;
	AUTO kupljenAuto;
	FILE* auti = fopen("auti.txt", "r");
	FILE* temp = fopen("temp.txt", "w");

	if (auti == NULL || temp == NULL) {
		perror("Greska pri otvaranju datoteke");
		free(mobil);
		return;
	}

	while (fscanf(auti, "%d\n%19s\n%19s\n%14s\n%9s\n%14s\n%14s\n%d\n%d\n%d\n%d\n%d\n",
		&kupljenAuto.id, kupljenAuto.marka, kupljenAuto.model, kupljenAuto.karoserija,
		kupljenAuto.pogon, kupljenAuto.motor, kupljenAuto.boja, &kupljenAuto.konji,
		&kupljenAuto.newtonm, &kupljenAuto.kilometraza, &kupljenAuto.godiste, &kupljenAuto.cijena) == var) {

		if (kupljenAuto.id == kupovinaID) {
			found = 1;
			printf("Jeste li sigurni da zelite kupiti automobil (ID %d)? (da/ne): ", kupovinaID);
			char potvrda[3];
			scanf("%2s", potvrda);

			if (strcmp(potvrda, "da") == 0) {
				printf("Automobil sa ID %d je kupljen.\n", kupovinaID);
				continue;
			}
		}

		fprintf(temp, "%d\n%19s\n%19s\n%14s\n%9s\n%14s\n%14s\n%d\n%d\n%d\n%d\n%d\n",
			kupljenAuto.id, kupljenAuto.marka, kupljenAuto.model, kupljenAuto.karoserija,
			kupljenAuto.pogon, kupljenAuto.motor, kupljenAuto.boja, kupljenAuto.konji,
			kupljenAuto.newtonm, kupljenAuto.kilometraza, kupljenAuto.godiste, kupljenAuto.cijena);

		
		if (found && kupljenAuto.id != kupovinaID) {
			kupljenAuto.id--; 
			fprintf(temp, "%d\n%19s\n%19s\n%14s\n%9s\n%14s\n%14s\n%d\n%d\n%d\n%d\n%d\n",
				kupljenAuto.id, kupljenAuto.marka, kupljenAuto.model, kupljenAuto.karoserija,
				kupljenAuto.pogon, kupljenAuto.motor, kupljenAuto.boja, kupljenAuto.konji,
				kupljenAuto.newtonm, kupljenAuto.kilometraza, kupljenAuto.godiste, kupljenAuto.cijena);
		}
	}

	fclose(auti);
	fclose(temp);

	if (found) {
		remove("auti.txt");
		rename("temp.txt", "auti.txt");
	}
	else {
		remove("temp.txt");
		printf("Automobil sa ID %d nije pronadjen.\n", kupovinaID);
	}

	free(mobil);
}



