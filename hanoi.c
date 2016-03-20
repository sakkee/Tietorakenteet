#include <stdio.h>

/* Hanoi-funktio, joka laskee samalla kierrosten maaran */
int Hanoi(int lkm, char Lahto, char Maali, char Apu, int kierros) {
    if (lkm>0){
        /*Nostetaan kierrosten maaraa 1:lla*/
        kierros++;
        kierros = Hanoi(lkm-1, Lahto, Apu, Maali,kierros);
        printf("Siirrä kiekko %d tornista %c torniin %c\n", lkm, Lahto, Maali);
        kierros = Hanoi(lkm-1, Apu, Maali, Lahto,kierros);
    }
    else {
        return kierros;
    }
}
int main(void) {
    int maara;
    printf("Anna siirrettavien renkaiden maara: ");
    scanf("%d", &maara);
    int kierros=0;
    kierros = Hanoi(maara, '1', '2', '3', kierros);
    printf("Tehtiin yhteensa %d kierrosta! \n", kierros);
}