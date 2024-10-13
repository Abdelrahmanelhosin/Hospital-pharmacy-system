#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char tc[12];
    char ad[50];
    int yas;
    char hastalik[50];
} Hasta;

typedef struct {
    char tc[12];
    int id;
} HastaId;

// Hasta ekleme
void hastaEkle(Hasta *hastalar, HastaId *hastaIdler, int *hastaSayisi) {
    if (*hastaSayisi >= MAX_SIZE) {
        printf("Maksimum hasta sayisina ulasildi.\n");
        return;
    }
    printf("Hasta TC: ");
    scanf("%s", hastalar[*hastaSayisi].tc);
    printf("Hasta Ad: ");
    scanf("%s", hastalar[*hastaSayisi].ad);
    printf("Hasta Yas: ");
    scanf("%d", &hastalar[*hastaSayisi].yas);
    printf("Hasta Hastalik: ");
    scanf("%s", hastalar[*hastaSayisi].hastalik);
    strcpy(hastaIdler[*hastaSayisi].tc, hastalar[*hastaSayisi].tc);
    hastaIdler[*hastaSayisi].id = *hastaSayisi;
    *hastaSayisi += 1;
    printf("Hasta basariyla eklendi.\n");
}

// Hasta silme
void hastaSil(Hasta *hastalar, HastaId *hastaIdler, int *hastaSayisi) {
    char tc[12];
    printf("Silinecek Hasta TC: ");
    scanf("%s", tc);
    int i;
    int found = 0;
    for (i = 0; i < *hastaSayisi; i++) {
        if (strcmp(hastalar[i].tc, tc) == 0) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (; i < *hastaSayisi - 1; i++) {
            strcpy(hastalar[i].tc, hastalar[i + 1].tc);
            strcpy(hastalar[i].ad, hastalar[i + 1].ad);
            hastalar[i].yas = hastalar[i + 1].yas;
            strcpy(hastalar[i].hastalik, hastalar[i + 1].hastalik);
        }
        *hastaSayisi -= 1;
        printf("Hasta basariyla silindi.\n");
    } else {
        printf("Hasta bulunamadi.\n");
    }
}

// Hasta düzenleme
void hastaDuzenle(Hasta *hastalar, int hastaSayisi) {
    char tc[12];
    printf("Düzenlenecek Hasta TC: ");
    scanf("%s", tc);
    int i;
    int found = 0;
    for (i = 0; i < hastaSayisi; i++) {
        if (strcmp(hastalar[i].tc, tc) == 0) {
            found = 1;
            break;
        }
    }
    if (found) {
        printf("Hasta Ad: ");
        scanf("%s", hastalar[i].ad);
        printf("Hasta Yas: ");
        scanf("%d", &hastalar[i].yas);
        printf("Hasta Hastalik: ");
        scanf("%s", hastalar[i].hastalik);
        printf("Hasta bilgileri basariyla güncellendi.\n");
    } else {
        printf("Hasta bulunamadi.\n");
    }
}

// Hasta listeleme
void hastaListele(Hasta *hastalar, int hastaSayisi) {
    printf("Hasta Listesi:\n");
    for (int i = 0; i < hastaSayisi; i++) {
        printf("ID: %d, TC: %s, Ad: %s, Yas: %d, Hastalik: %s\n",
               i, hastalar[i].tc, hastalar[i].ad, hastalar[i].yas,
               hastalar[i].hastalik);
    }
}

int main() {
    Hasta hastalar[MAX_SIZE];
    HastaId hastaIdler[MAX_SIZE];
    int hastaSayisi = 0;
    int secim;
    while (1) {
        printf("\n1- Hasta Ekle\n");
        printf("2- Hasta Sil\n");
        printf("3- Hasta Duzenle\n");
        printf("4- Hasta Listele\n");
        printf("0- Cikis\n");
        printf("Secim: ");
        scanf("%d", &secim);
        switch (secim) {
            case 1:
                hastaEkle(hastalar, hastaIdler, &hastaSayisi);
                break;
            case 2:
                hastaSil(hastalar, hastaIdler, &hastaSayisi);
                break;
            case 3:
                hastaDuzenle(hastalar, hastaSayisi);
                break;
            case 4:
                hastaListele(hastalar, hastaSayisi);
                break;
            case 0:
                printf("Programdan cikiliyor...\n");
                exit(0);
            default:
                printf("Gecersiz secim.\n");
                break;
        }
    }
    return 0;
}
