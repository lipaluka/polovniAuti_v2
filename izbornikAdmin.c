#define _CRT_SECURE_NO_WARNINGS
#include"header.h"

int adminPrijava(ADMIN* admin) {
	ADMIN prijava;
	printf("Unesi korisnicko ime: ");
	scanf("%49s", prijava.ime);
	printf("Unesi lozinku: ");
	scanf("%49s", prijava.lozinka);

	if (strcmp(prijava.ime, admin->ime) == 0 && strcmp(prijava.lozinka, admin->lozinka) == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int izborAdmin() {
	srand((unsigned)time(NULL));
	size_t pokusaji = 0;
	ADMIN admin = { "Luka2502", "123321" };

	while (adminPrijava(&admin) == 0 && pokusaji < 3) {
		pokusaji++;
		printf("Pogresno ime ili lozinka, pokusajte ponovno!!\n");
		if (pokusaji == 3) {
			printf("Iskoristili ste sve pokusaje, pokusajte ponovno kasnije\n");
			return 1;
		}
	}

	if (pokusaji < 3) {
		printf("Uspjesna prijava, dobrodosao %s\n", admin.ime);
	}

	int izbor;
	printf("ADMINISTRATORSKI IZBORNIK\n");
	printf("[1] Dodavanje Automobila\n");
	printf("[2] Brisanje Automobila\n");
	printf("[3] Uredjivanje Automobila\n");
	printf("[4] Izlaz iz Programa\n");
	printf("Unesite vas izbor: ");
	scanf("%d", &izbor);

	FILE* auti = NULL;
	AUTO mobil;

	switch (izbor) {
	case 1:
		dodajAuto();
		break;
	case 2:
		obrisiAuto();
		break;
	case 3:
		urediAuto();
		break;
	case 4:
		if (krajPrograma() == 0) {
			printf("Kraj programa, stisnite bilo koju tipku\n");
			getchar(); 
			getchar(); 
			exit(0);
		}
		else {
			printf("Za povratak u pocetni izbornik pritisnite bilo koju tipku.");
			getchar(); 
			return 0; 
		}
	default:
		printf("Nepostojeci izbor!\n");
		break;
	}

	exit(0);
	return 0;
}