#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct asiakas {
char nimi[30];
int numero;
struct asiakas *seuraava;
struct asiakas *edellinen;
};

int main(void)
{
    struct asiakas *eka=NULL, *nyk=NULL, *vika=NULL, *uusi, tmp, *edellinen;
    int nro = 0;
    int valinta=0;

    /* kerataan asiakkaita "jonoon" */
    printf("Anna asiakkaita (Ctrl-D lopettaa): ");
    while (scanf("%s", tmp.nimi)!=EOF) {	/* Ctrl-D lopettaa silmukan */
        uusi = (struct asiakas*)malloc(sizeof(struct asiakas));
        strcpy(uusi->nimi, tmp.nimi);
        uusi->numero = ++nro;
        if (!eka) {
            eka=uusi;
            eka->edellinen=NULL;
        }
        else nyk->seuraava = uusi;
        uusi->seuraava=NULL;
        uusi->edellinen=nyk;
        nyk = uusi;
    } 
    /* tulostetaan nykyinen jono */
    nyk=eka;
    while (nyk) {
        printf("Asiakas %d %s\n", nyk->numero, nyk->nimi);
        nyk = nyk->seuraava;
    }
    /* kaannetaan jono */
    nyk=eka;
    while (nyk->seuraava) {
        nyk=nyk->seuraava;
    }
     vika = nyk;
    printf("KAANTEINEN JONO\n");
     while (vika) {
         printf("Asiakas %d %s\n",vika->numero,vika->nimi);
         vika = vika->edellinen;
     }
     while (1) {
        printf("VALITSE TOIMINTO\n");
        printf("1 Uusi asiakas\n");
        printf("2 Poista asiakas\n");
        printf("3 Lopeta\n");
        printf("Valitse: ");
        scanf("%d",&valinta);
        if (valinta==1) {
            printf("Anna uusi asiakas ja vuoronumero 1...%d: ", ++nro);
            scanf("%s %d",tmp.nimi, &tmp.numero);
            uusi = (struct asiakas*)malloc(sizeof(struct asiakas));
            strcpy(uusi->nimi, tmp.nimi);
            uusi->numero = tmp.numero;
            uusi->seuraava = NULL;
            uusi->edellinen=NULL;
            /* asetetaan uusi asiakas omalle paikalleen jonoon */
            nyk=eka;
            if (uusi->numero==1) {	/*ekaksi jonoon */
                eka = uusi;
                uusi->seuraava = nyk;
                nyk->edellinen=uusi;
            }
            else {
                while (nyk->seuraava && nyk->seuraava->numero < uusi->numero) 
                    nyk = nyk->seuraava;
                uusi->seuraava = nyk->seuraava;
                nyk->seuraava = uusi;
                uusi->edellinen = nyk;
            }
            /* kasvatetaan uuden asiakkaan taakse jaaneiden vuoronumeroa */
            nyk=uusi->seuraava;
            while (nyk) {
                nyk->numero = nyk->numero + 1;
                nyk = nyk->seuraava;
            }

            /* tulostetaan uusi jono */
            nyk=eka;
            while (nyk) {
                    printf("Asiakas %d %s\n", nyk->numero, nyk->nimi);
                    nyk = nyk->seuraava;
            }
            /* kaannetaan jono */
            nyk=eka;
            while (nyk->seuraava) {
                nyk=nyk->seuraava;
            }
             vika = nyk;
             printf("KAANTEINEN JONO\n");
             while (vika) {
                 printf("Asiakas %d %s\n",vika->numero,vika->nimi);
                 vika = vika->edellinen;
             }
        }
        else if (valinta==2) {
            /* joku poistuu jonosta */
            printf("Anna poistuvan asiakkaan nimi: ");
            scanf("%s", tmp.nimi);

            nyk = eka;
            while (nyk) {
                if (strcmp(tmp.nimi, nyk->nimi)==0) { /* tama poistetaan */
                    printf("%s poistuu paikalta %d\n", nyk->nimi, nyk->numero);
                    if (eka==nyk) eka=nyk->seuraava;
                    else edellinen->seuraava = nyk->seuraava;
                    uusi = nyk->seuraava;
                    if (uusi) uusi->edellinen = nyk->edellinen;
                    while (uusi) {
                        uusi->numero = uusi->numero-1;
                        uusi = uusi->seuraava;
                    }
                    free(nyk);
                    nro = nro-1;
                    break;
                }
                else {
                    edellinen = nyk;
                    nyk=nyk->seuraava;
                }
            }

            /* tulostetaan uusi jono */
            nyk=eka;
            while (nyk) {
                    printf("Asiakas %d %s\n", nyk->numero, nyk->nimi);
                    nyk = nyk->seuraava;
            }
            /* kaannetaan jono */
            nyk=eka;
            while (nyk->seuraava) {
                nyk=nyk->seuraava;
            }
             vika = nyk;
             printf("KAANTEINEN JONO\n");
             while (vika) {
                 printf("Asiakas %d %s\n",vika->numero,vika->nimi);
                 vika = vika->edellinen;
             }
        }
        else if (valinta==3) {
            printf("Lopetetaan\n");
            return 0;
        }
     }


    

    return 0;
}

