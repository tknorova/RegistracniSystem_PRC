#include <stdio.h>
#include <string.h>

#define SIZE 30

struct Uzivatel {
    char krestniJmeno[30];
    char prijmeni[30];
    char email[50];
};

struct Uzivatel uzivatelé[SIZE];
int pocet;

void pridaniUzivatele() {
    if (pocet >= SIZE) {
        printf("Uz jste zadal/a maximalni pocet uzivatelu (30), nelze pridat dalsi. Pokud chcete pridat nove, musite odebrat a nebo upravit kod ;) \n");
        return;
    }

    printf("Jake je krestni jmeno uzivatele?: ");
    scanf("%s", uzivatelé[pocet].krestniJmeno);
    printf("Jake je prijmeni uzivatele?: ");
    scanf("%s", uzivatelé[pocet].prijmeni);
    printf("Jaky je email uzivatele? ");
    scanf("%s", uzivatelé[pocet].email);

    pocet++;
    printf("Uzivatel je nyni zaregistrovany.\n");
}

void vypsaniUzivatele() {

        printf("Seznam uživatelů:\n");
        for (int i = 0; i < pocet; i++) {
            printf("%d. %s %s (%s)\n", i + 1, uzivatelé[i].krestniJmeno, uzivatelé[i].prijmeni, uzivatelé[i].email);
        }
    }


void odebraniUzivatele() {
    char krestniJmeno[30];
    printf("Napis krestni jmeno uzivatele, abychom ho mohli smazat: ");
    scanf("%s", krestniJmeno);

    int nalezen = 0;
    for (int i = 0; i < pocet; i++) {
        if (strcmp(uzivatelé[i].krestniJmeno, krestniJmeno) == 0) {
            nalezen = 1;
            for (int j = i; j < pocet - 1; j++) {
                uzivatelé[j] = uzivatelé[j + 1];
            }
            pocet--;
            printf("Uzivatel s jmenem %s byl odebran.\n", krestniJmeno);
            break;
        }
    }

    if (!nalezen) {
        printf("Uživatel s jmenem %s nebyl nalezen.\n", krestniJmeno);
    }
}

int main() {
    int volba;

    do {
        printf("NAPIS CISLO TOHO ROZHODNUTI, KTERE CHCES UDELAT! \n 1) Chci pridat uzivatele \n 2) Chci odebrat uzivatele \n 3) Chci vypsat vsechny uzivatele \n 4) Ukonci me :( \n TVOJE ODPOVED: ");
        scanf("%d", &volba);

        switch (volba) {
            case 1:
                pridaniUzivatele();
                break;
            case 2:
                odebraniUzivatele();
                break;
            case 3:
                vypsaniUzivatele();
                break;
            case 4:
                printf("Ukoncuji se ;( \n");
                break;
            default:
                printf("Neco jsi asi napsal/a spatne.\n");
        }
    } while (volba != 4);

    return 0;
}
