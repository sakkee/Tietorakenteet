#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#define FALSE (1==0)
#define TRUE (1==0)
/*Oletusalkio*/
struct luku {
    int numero;
    struct luku *vasen;
    struct luku *oikea;
};

/*Uusi alkio, voisi myos olla syotto-funktion sisalla*/
struct luku* uusiLuku(int numero) {
    struct luku* luku = (struct luku*)malloc(sizeof(struct luku));
    luku->numero = numero;
    luku->vasen = NULL;
    luku->oikea = NULL;
    return luku;
}

/*Hakufunktio*/
int haku(struct luku* luku, int kohde) {
    /* Ei loytynyt*/
    if (luku == NULL) {
        printf("EI LOYTYNYT!\n");
        return FALSE;
    }
    else {
        /*Tulostetaan jonoa*/
        if (kohde == luku->numero) {
            printf ("%d LOYTYI!\n", luku->numero);
        }
        else printf ("%d -> ", luku->numero);
        /*Loytyi oikea*/
        if (kohde == luku->numero) return TRUE;
        /*Jatketaan etsintaa*/
        else {
            if (kohde < luku->numero) return haku(luku->vasen, kohde);
            else return haku(luku->oikea, kohde);
        }
    }
}

/*Syotto-funktio*/
struct luku* syotto (int number, struct luku* luku, int numero) {
    if (luku==NULL) {
        /*Tulostellaan. Huom! 0 kaytto ei ole suositeltavaa saadakseen ensimmaisen alkion. Tehtava 1B */
        if (number == 0) {
            printf("Luotiin uusi hakupuu, jonka ainoa luku on %d\n", numero);
        }
        else if (numero <= number) {
            printf("Numero %d sijoitettiin luvun %d vasemmalle puolelle\n", numero, number);
        }
        else {
            printf("Numero %d sijoitettiin luvun %d oikealle puolelle\n", numero, number);
        }
        return uusiLuku(numero);
    }
    else {
        if (numero <= luku->numero) {
            luku->vasen = syotto(luku->numero,luku->vasen, numero);
        }
        else {
            luku->oikea = syotto(luku->numero,luku->oikea, numero);
        }
        return luku;
    }
}
/*Inorder*/
void inorder(struct luku *tmp) {
    if (tmp!=NULL) {
        inorder(tmp->vasen);
        printf("%d ", tmp->numero);
        inorder(tmp->oikea);
    }
}
int main(void)
{
    struct luku *puu;
    /*Syotetaan puuhun. tehtava 1A ja 1B */
    puu = syotto(0,puu,4);
    puu = syotto(0,puu,3);
    puu = syotto(0,puu,2);
    puu = syotto(0,puu,5);
    puu = syotto(0,puu,9);
    puu = syotto(0,puu,6);
    puu = syotto(0,puu,7);
    printf("\n");
    /*Etsitaan, tehtava 2*/
    printf("Etsitaan luku 6: ");
    haku(puu,6);
    printf("Etsitaan luku 11: ");
    haku(puu,11);
    printf("\n");
    /*Tulostetaan, tehtävä 3*/
    printf("Tulostetaan koko puu inorder-jarjestyksessa: ");
    inorder(puu);
    printf("\n");
    printf("Inorder-menetelmalla alkiot tulostuvat pienimmasta suurimpaan.\n");
    return 0;
}

