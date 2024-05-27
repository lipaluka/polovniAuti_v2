#define _CRT_SECURE_NO_WARNINGS
#include"header.h"

int usporediKilometrazuUzlazno(const void* a, const void* b) {
	return ((AUTO*)a)->kilometraza - ((AUTO*)b)->kilometraza;
}
void sortirajKilometrazaUzlazno(AUTO* mobil, int broj) {
	qsort(mobil, broj, sizeof(AUTO), usporediKilometrazuUzlazno);
}

int usporediKilometrazuSilazno(const void* a, const void* b) {
	return ((AUTO*)b)->kilometraza - ((AUTO*)a)->kilometraza;
}
void sortirajKilometrazuSilazno(AUTO* mobil, int broj) {
	qsort(mobil, broj, sizeof(AUTO), usporediKilometrazuSilazno);
}

int usporediGodisteUzlazno(const void* a, const void* b) {
	return ((AUTO*)a)->godiste - ((AUTO*)b)->godiste;
}
void sortirajGodisteUzlazno(AUTO* mobil, int broj) {
	qsort(mobil, broj, sizeof(AUTO), usporediGodisteUzlazno);
}

int usporediGodisteSilazno(const void* a, const void* b) {
	return ((AUTO*)b)->godiste - ((AUTO*)a)->godiste;
}
void sortirajGodisteSilazno(AUTO* mobil, int broj) {
	qsort(mobil, broj, sizeof(AUTO), usporediGodisteSilazno);
}

int usporediCijenuUzlazno(const void* a, const void* b) {
	return ((AUTO*)a)->cijena - ((AUTO*)b)->cijena;
}
void sortirajCijenuUzlazno(AUTO* mobil, int broj) {
	qsort(mobil, broj, sizeof(AUTO), usporediCijenuUzlazno);
}

int usporediCijenuSilazno(const void* a, const void* b) {
	return ((AUTO*)b)->cijena - ((AUTO*)a)->cijena;
}
void sortirajCijenuSilazno(AUTO* mobil, int broj) {
	qsort(mobil, broj, sizeof(AUTO), usporediCijenuSilazno);
}