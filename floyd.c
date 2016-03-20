#include <stdio.h>

int main (void) {
    /* Maaritetaan alkioiden lukumaara ja lista*/
    int n=5;
    int d[10][10];
    /*Laitetaan jokaisen listan alkion oletusarvoksi 999, jotta tarpeeksi iso*/
    for (int y=0;y<n+1;y++) {
        for (int x=0;x<n+1;x++) {
            d[y][x]=999;
        }
    }
    /*Maaritetaan annetut alkiot*/
    d[0][1] = 4;
    d[1][0] = 4;
    d[0][4] = 5;
    d[4][0] = 5;
    d[1][2] = 6;
    d[2][1] = 6;
    d[2][3] = 1;
    d[3][2] = 1;
    d[3][4] = 2;
    d[4][3] = 2;
    d[2][5] = 2;
    d[5][2] = 2;
    d[1][5] = 1;
    d[5][1] = 1;
    /*Tulostetaan aloituslista*/
    printf("ALOITUSLISTA\n");
    for (int y=0;y<n+1;y++) {
        for (int x=0;x<n+1;x++) {
            printf("%d ", d[y][x]);
            
        }
        printf("\n");
    }
    /*Algoritmi*/
    for (int k=0;k<n+1;k++) {
        for (int i=0;i<n+1;i++) {
            for (int j=0;j<n+1;j++) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    
                }
            }
        }
        /*Tulostetaan jokaisen k:n arvolla kyseinen lista*/
        printf("\nKUN k=%d\n", k);
        for (int y=0;y<n+1;y++) {
            for (int x=0;x<n+1;x++) {
                printf("%d ", d[y][x]);
                
            }
            printf("\n");
        }
    }
    /*Tulostetaan valmis lista*/
    printf("\nUUSI\n");
    for (int y=0;y<n+1;y++) {
        for (int x=0;x<n+1;x++) {
            printf("%d ", d[y][x]);
            
        }
        printf("\n");
    }
    
    return 1;
    
}