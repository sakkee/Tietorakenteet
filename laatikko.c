#include <stdio.h>
/*Laatikko-funktio*/
float * laatikot(float a[], float l[], int n) {
    int i, j;
    
    for (i=0;i<n;i++) {
        j=0;
        while (a[i]+l[j]>1) j=j+1;
        l[j] = l[j]+a[i];
    }
    return l;
}

/*Suurimmasta pienimpaan lajittelu -funtkio*/
float *lajittelu1 (float A[], int n) {
    for (int i=0;i<n-1;i++) {
        for (int j=n-1;j>i;j--) {
            if (A[j-1] < A[j]) {
                float temp = A[j-1];
                A[j-1] = A[j];
                A[j] = temp;
            }
        }
    }
    return A;
}
int main(void) {
    float a[] = {0.3, 0.1, 0.4, 0.1, 0.5, 0.9, 0.2, 0.6, 0.5, 0.3, 0.5, 0.8, 0.9, 0.7, 0.9};
    int n = sizeof(a)/sizeof(float);
    
    /*Apumuuttujat*/
    float *b, *c, *d;
    float l[] = {0,0,0,0,0,0,0,0,0};
    float e[] = {0,0,0,0,0,0,0,0,0};
    int j=0;
   
    /*Tulostetaan vanha lista*/
    printf("VANHA LISTA: ");
    for (int i=0;i<n;i++) {
        printf(" %.1f", a[i]);
    }
    
    /*Jarjestellaan laatikoihin ja tulostetaan uusi lista*/
    b = laatikot(a,l,n);
    printf("\nLAATIKOT:");
    while (b[j] != 0) {
        printf(" %.1f", b[j]);
        j = j+1;
    }
    j=0;
    
    /*Lajitellaan suurimmasta pienimpaan ja tulostetaan se*/
    c = lajittelu1(a,n);
    printf("\nJARJESTELTY LISTA:");
    for (int i=0;i<n;i++) {
        printf(" %.1f", a[i]);
    }
    
    /*Jarjestellaan uusi lista laatikoihin ja tulostetaan se*/
    d = laatikot(c,e,n);
    printf("\nMUUNNELLUT LAATIKOT:");
    while (d[j] != 0) {
        printf(" %.1f", d[j]);
        j = j+1;
    }
    printf("\n");
}