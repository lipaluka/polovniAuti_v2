#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<conio.h>
#include<ctype.h>
//5,8,12,13,14,19,20,22,24
#define VAR  12

typedef struct {
	int id;
	char marka[20];
	char model[20];
	char karoserija[15];
	char pogon[10];
	char motor[15];
	char boja[15];
	int konji;
	int newtonm;
	int kilometraza;
	int godiste;
	int cijena;
}AUTO;



typedef struct {
	char ime[20];
	char lozinka[20];
}ADMIN;

void izborGlavni();
int adminPrijava(admin);
int izborAdmin();
void izborKorisnik();
int krajPrograma();
void pregledAutomobila();
void dodajAuto();
void obrisiAuto();
void urediAuto();
void pretraziAute();
void scanAuto(AUTO** mobil, int* broj);
void printAuto(const AUTO* mobil, int broj);
int usporediKilometrazuUzlazno(const void* a, const void* b);
void sortirajKilometrazaUzlazno(AUTO* mobil, int broj);
int usporediKilometrazuSilazno(const void* a, const void* b);
void sortirajKilometrazuSilazno(AUTO* mobil, int broj);
int usporediGodisteUzlazno(const void* a, const void* b);
void sortirajGodisteUzlazno(AUTO* mobil, int broj);
int usporediGodisteSilazno(const void* a, const void* b);
void sortirajGodisteSilazno(AUTO* mobil, int broj);
int usporediCijenuUzlazno(const void* a, const void* b);
void sortirajCijenuUzlazno(AUTO* mobil, int broj);
int usporediCijenuSilazno(const void* a, const void* b);
void sortirajCijenuSilazno(AUTO* mobil, int broj);
void pretragaPoKaroseriji(AUTO* mobil, int broj, const char* karoserija);
void kupovinaAutomobila();