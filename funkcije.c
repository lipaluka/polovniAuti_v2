#define _CRT_SECURE_NO_WARNINGS
#include"header.h"

int krajPrograma() {
	int kraj;
	char unos[3];
	printf("Jeste li sigurni da zelite izaci?\n");
	scanf("%2s", unos);

	if (strcmp(unos, "da") == 0 || strcmp(unos, "DA") == 0 || strcmp(unos, "Da") == 0) {
		kraj = 0;
	}
	else if (strcmp(unos, "ne") == 0 || strcmp(unos, "NE") == 0 || strcmp(unos, "Ne") == 0) {
		kraj = 1;
	}
	else {
		printf("Trebate unijeti da ili ne!!");
		return krajPrograma();
	}
	return kraj;
}

void scanAuto(AUTO** mobil, int* broj) {
	FILE* auti = fopen("auti.txt", "r");
	if (auti == NULL) {
		perror("Greska pri otvaranju datoteke");
		return;
	}

	AUTO temp;
	*broj = 0;
	while (fscanf(auti, "%d\n%19s\n%19s\n%14s\n%9s\n%14s\n%14s\n%d\n%d\n%d\n%d\n",
		&temp.id, temp.marka, temp.model, temp.karoserija, temp.pogon,
		temp.motor, temp.boja, &temp.konji, &temp.newtonm, &temp.kilometraza, &temp.godiste) == 11) {
		(*broj)++;
	}
	rewind(auti);

	*mobil = (AUTO*)malloc(*broj * sizeof(AUTO));
	for (int i = 0; i < *broj; i++) {
		fscanf(auti, "%d\n%19s\n%19s\n%14s\n%9s\n%14s\n%14s\n%d\n%d\n%d\n%d\n",
			&(*mobil)[i].id, (*mobil)[i].marka, (*mobil)[i].model,
			(*mobil)[i].karoserija, (*mobil)[i].pogon, (*mobil)[i].motor,
			(*mobil)[i].boja, &(*mobil)[i].konji, &(*mobil)[i].newtonm,
			&(*mobil)[i].kilometraza, &(*mobil)[i].godiste);
	}

	fclose(auti);
}

void printAuto(const AUTO* mobil, int broj) {
	for (int i = 0; i < broj; i++) {
		printf("ID: %d\nMarka: %s\nModel: %s\nKaroserija: %s\nPogon: %s\nMotor: %s\nBoja: %s\nKonji: %d\nNewtonmetri: %d\nKilometraza: %d\nGodiste: %d\n\n",
			mobil[i].id, mobil[i].marka, mobil[i].model, mobil[i].karoserija,
			mobil[i].pogon, mobil[i].motor, mobil[i].boja, mobil[i].konji,
			mobil[i].newtonm, mobil[i].kilometraza, mobil[i].godiste);
	}
}
