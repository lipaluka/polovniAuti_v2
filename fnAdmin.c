#define _CRT_SECURE_NO_WARNINGS
#include"header.h"




void dodajAuto() {
	FILE* auti = fopen("auti.txt", "r+");
	if (auti == NULL) {
		perror("Greska pri otvaranju datoteke");
		return;
	}

	AUTO mobil;
	int trenutniID;

	static int maxID = 0;
	while (fscanf(auti, "%d", &trenutniID) == 1) {
		maxID = trenutniID;

		char buffer[256];
		for (int i = 0; i < 12; i++) {
			fgets(buffer, sizeof(buffer), auti);
		}
	}

	mobil.id = maxID + 1;

	printf("\nUnesi marku: ");
	scanf("%19s", mobil.marka);
	for (int i = 0; mobil.marka[i] != '\0'; i++) {
		if (isspace(mobil.marka[i])) {
			printf("Neispravan unos! Marka ne smije sadržavati razmake.\n");
			fclose(auti);
			return;
		}
	}

	printf("\nUnesi model: ");
	scanf("%19s", mobil.model);
	for (int i = 0; mobil.model[i] != '\0'; i++) {
		if (isspace(mobil.model[i])) {
			printf("Neispravan unos! Model ne smije sadržavati razmake.\n");
			fclose(auti);
			return;
		}
	}

	printf("\nUnesi karoseriju: ");
	scanf("%14s", mobil.karoserija);
	for (int i = 0; mobil.karoserija[i] != '\0'; i++) {
		mobil.karoserija[i] = tolower(mobil.karoserija[i]);
	}
	if (strcmp(mobil.karoserija, "limuzina") != 0 && strcmp(mobil.karoserija, "hatchback") != 0 &&
		strcmp(mobil.karoserija, "coupe") != 0 && strcmp(mobil.karoserija, "kabrio") != 0 &&
		strcmp(mobil.karoserija, "suv") != 0 && strcmp(mobil.karoserija, "crossover") != 0 &&
		strcmp(mobil.karoserija, "hyper") != 0 && strcmp(mobil.karoserija, "monovolumen") != 0 &&
		strcmp(mobil.karoserija, "ostalo") != 0) {
		printf("Neispravan unos za karoseriju!\n");
		fclose(auti);
		return;
	}

	printf("\nUnesi pogon: ");
	scanf("%9s", mobil.pogon);
	for (int i = 0; mobil.pogon[i] != '\0'; i++) {
		mobil.pogon[i] = tolower(mobil.pogon[i]);
	}
	if (strcmp(mobil.pogon, "prednji") != 0 && strcmp(mobil.pogon, "zadnji") != 0 && strcmp(mobil.pogon, "4x4") != 0) {
		printf("Neispravan unos za pogon!\n");
		fclose(auti);
		return;
	}

	printf("\nUnesi motor: ");
	scanf("%14s", mobil.motor);

	printf("\nUnesi boju: ");
	scanf("%14s", mobil.boja);

	printf("\nUnesi broj konjskih snaga: ");
	scanf("%d", &mobil.konji);
	if (mobil.konji < 0 || mobil.konji > 4000) {
		printf("Neispravan unos! Provjerite unesene vrijednosti.\n");
		fclose(auti);
		return;
	}

	printf("\nUnesi broj njutn metara: ");
	scanf("%d", &mobil.newtonm);
	if (mobil.newtonm < 0 || mobil.newtonm > 4000) {
		printf("Neispravan unos! Provjerite unesene vrijednosti.\n");
		fclose(auti);
		return;
	}

	printf("\nUnesi kilometrazu: ");
	scanf("%d", &mobil.kilometraza);
	if (mobil.kilometraza < 0) {
		printf("Neispravan unos! Provjerite unesene vrijednosti.\n");
		fclose(auti);
		return;
	}

	printf("\nUnesi godiste: ");
	scanf("%d", &mobil.godiste);
	if (mobil.godiste < 1800 || mobil.godiste > 2025) {
		printf("Neispravan unos! Provjerite unesene vrijednosti.\n");
		fclose(auti);
		return;
	}

	printf("\nUnesi cijenu: ");
	scanf("%d", &mobil.cijena);
	if (mobil.cijena < 0) {
		printf("Neispravan unos! Provjerite unesene vrijednosti.\n");
		fclose(auti);
		return;
	}

	fseek(auti, 0, SEEK_END);
	fprintf(auti, "%d\n%19s\n%19s\n%14s\n%9s\n%14s\n%14s\n%d\n%d\n%d\n%d\n%d\n",
		mobil.id, mobil.marka, mobil.model, mobil.karoserija, mobil.pogon,
		mobil.motor, mobil.boja, mobil.konji, mobil.newtonm, mobil.kilometraza, mobil.godiste, mobil.cijena);

	fclose(auti);
}


void obrisiAuto() {
	printf("Unesi ID automobila za brisanje: ");
	int iddel;
	scanf("%d", &iddel);
	getchar();
	FILE* auti = fopen("auti.txt", "r+");
	if (auti == NULL) {
		perror("Greska pri otvaranju datoteke");
		return;
	}
	FILE* temp = fopen("temp.txt", "w");
	if (temp == NULL) {
		perror("Greska pri otvaranju temp datoteke");
		return 1;
	}

	auti = fopen("auti.txt", "r");
	if (auti == NULL) {
		perror("Greska pri otvaranju datoteke");
		fclose(temp);
		return 1;
	}

	int id;
	while (fscanf(auti, "%d", &id) == 1) {
		fgetc(auti);
		if (id == iddel) {

			char buffer[256];
			for (int i = 0; i < 10; i++) {
				fgets(buffer, sizeof(buffer), auti);
			}
			continue;
		}
		fprintf(temp, "%d\n", id);
		for (int i = 0; i < 10; i++) {
			char buffer[256];
			if (fgets(buffer, sizeof(buffer), auti)) {
				fputs(buffer, temp);
			}
		}
	}

	fclose(auti);
	fclose(temp);
	remove("auti.txt");
	rename("temp.txt", "auti.txt");

	printf("Automobil (ID %d) je obrisan.\n", iddel);
}

void urediAuto() {
	FILE* auti = fopen("auti.txt", "r");
	if (auti == NULL) {
		perror("Greska pri otvaranju datoteke");
		return;
	}

	FILE* temp = fopen("temp.txt", "w");
	if (temp == NULL) {
		perror("Greska pri otvaranju temp datoteke");
		fclose(auti);
		return;
	}

	printf("Unesi ID automobila za uredjivanje: ");
	int idedit;
	scanf("%d", &idedit);
	getchar();

	AUTO mobil;
	int id;
	int found = 0;

	while (fscanf(auti, "%d", &id) == 1) {
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

		if (id == idedit) {
			found = 1;
			printf("Izaberi polje za uredjivanje:\n");
			printf("1. Marka\n2. Model\n3. Karoserija\n4. Pogon\n5. Motor\n6. Boja\n7. Konji\n8. Newtonmetri\n9. Kilometraza\n10. Godiste\n11. Cijena\n");
			int izborPolja;
			scanf("%d", &izborPolja);
			getchar();

			switch (izborPolja) {
			case 1:
				do {
					printf("Unesi novu marku: ");
					scanf("%19s", mobil.marka);
					int valid = 1;
					for (int i = 0; mobil.marka[i] != '\0'; i++) {
						if (isspace(mobil.marka[i])) {
							printf("Neispravan unos! Marka ne smije sadržavati razmake.\n");
							valid = 0;
							break;
						}
					}
					if (valid) break;
				} while (1);
				break;
			case 2:
				do {
					printf("Unesi novi model: ");
					scanf("%19s", mobil.model);
					int valid = 1;
					for (int i = 0; mobil.model[i] != '\0'; i++) {
						if (isspace(mobil.model[i])) {
							printf("Neispravan unos! Model ne smije sadržavati razmake.\n");
							valid = 0;
							break;
						}
					}
					if (valid) break;
				} while (1);
				break;
			case 3:
				do {
					printf("Unesi novu karoseriju: ");
					scanf("%14s", mobil.karoserija);
					for (int i = 0; mobil.karoserija[i] != '\0'; i++) {
						mobil.karoserija[i] = tolower(mobil.karoserija[i]);
					}
					if (strcmp(mobil.karoserija, "limuzina") == 0 || strcmp(mobil.karoserija, "hatchback") == 0 ||
						strcmp(mobil.karoserija, "coupe") == 0 || strcmp(mobil.karoserija, "kabrio") == 0 ||
						strcmp(mobil.karoserija, "suv") == 0 || strcmp(mobil.karoserija, "crossover") == 0 ||
						strcmp(mobil.karoserija, "hyper") == 0 || strcmp(mobil.karoserija, "monovolumen") == 0 ||
						strcmp(mobil.karoserija, "ostalo") == 0) {
						break;
					}
					else {
						printf("Neispravan unos za karoseriju!\n");
					}
				} while (1);
				break;
			case 4:
				do {
					printf("Unesi novi pogon: ");
					scanf("%9s", mobil.pogon);
					for (int i = 0; mobil.pogon[i] != '\0'; i++) {
						mobil.pogon[i] = tolower(mobil.pogon[i]);
					}
					if (strcmp(mobil.pogon, "prednji") == 0 || strcmp(mobil.pogon, "zadnji") == 0 || strcmp(mobil.pogon, "4x4") == 0) {
						break;
					}
					else {
						printf("Neispravan unos za pogon!\n");
					}
				} while (1);
				break;
			case 5:
				printf("Unesi novi motor: ");
				scanf("%14s", mobil.motor);
				break;
			case 6:
				printf("Unesi novu boju: ");
				scanf("%14s", mobil.boja);
				break;
			case 7:
				do {
					printf("Unesi novi broj konjskih snaga: ");
					scanf("%d", &mobil.konji);
					if (mobil.konji >= 0 && mobil.konji <= 4000) break;
					printf("Neispravan unos! Provjerite unesene vrijednosti.\n");
				} while (1);
				break;
			case 8:
				do {
					printf("Unesi novi broj njutn metara: ");
					scanf("%d", &mobil.newtonm);
					if (mobil.newtonm >= 0 && mobil.newtonm <= 4000) break;
					printf("Neispravan unos! Provjerite unesene vrijednosti.\n");
				} while (1);
				break;
			case 9:
				do {
					printf("Unesi novu kilometrazu: ");
					scanf("%d", &mobil.kilometraza);
					if (mobil.kilometraza >= 0) break;
					printf("Neispravan unos! Provjerite unesene vrijednosti.\n");
				} while (1);
				break;
			case 10:
				do {
					printf("Unesi novo godiste: ");
					scanf("%d", &mobil.godiste);
					if (mobil.godiste >= 1800 && mobil.godiste <= 2025) break;
					printf("Neispravan unos! Provjerite unesene vrijednosti.\n");
				} while (1);
				break;
			case 11:
				do {
					printf("Unesi novu cijenu: ");
					scanf("%d", &mobil.cijena);
					if (mobil.cijena >= 0) break;
					printf("Neispravan unos! Provjerite unesene vrijednosti.\n");
				} while (1);
				break;
			default:
				printf("Nepostojeci izbor.\n");
				break;
			}
		}

		fprintf(temp, "%d\n%19s\n%19s\n%14s\n%9s\n%14s\n%14s\n%d\n%d\n%d\n%d\n%d\n",
			id, mobil.marka, mobil.model, mobil.karoserija, mobil.pogon,
			mobil.motor, mobil.boja, mobil.konji, mobil.newtonm, mobil.kilometraza, mobil.godiste, mobil.cijena);
	}

	fclose(auti);
	fclose(temp);

	if (found) {
		remove("auti.txt");
		rename("temp.txt", "auti.txt");
		printf("Automobil sa ID %d je uredjen.\n", idedit);
	}
	else {
		remove("temp.txt");
		printf("Automobil sa ID %d nije pronadjen.\n", idedit);
	}
}