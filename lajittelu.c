#include <stdio.h>
#include <string.h>
#include <malloc.h>


/* Lajittelu-funktio */
int *lajittelu1 (int *A, int n) {
    /* C-kielessa taytyy aloittaa 0:sta */
    for (int i=0;i<n-1;i++) {
        for (int j=n-1;j>i;j--) {
            if (A[j-1] > A[j]) {
                int temp = A[j-1];
                A[j-1] = A[j];
                A[j] = temp;
            }
        }
    }
    return A;
}

int main (void) {
    /*Luodaan taulukko ja maaritetaan koko*/
    int taulukon_koko = 7;
    int kokonaislukutaulukko[7] = {5,20,6,3000,-643432,1,-6};
    /*Tulostetaan vanha taulukko*/
    for (int i=0 ; i<taulukon_koko;i++) {
        printf("VANHA %d\n", kokonaislukutaulukko[i]);
    }
    /*Kutsutaan lajittelu-funktio*/
    printf("***LAJITTELU***\n");
    int *kokonaislukutaulukko1 = lajittelu1(kokonaislukutaulukko, taulukon_koko);
    
    /*Tulostetaan uusi taulukko*/
    for (int j=0 ; j<taulukon_koko;j++) {
        printf("UUSI %d\n", kokonaislukutaulukko1[j]);
    }
    
}