#include <stdio.h>
#include <stdlib.h>

int *dizileri_birlestir(int dizi_1[], int boyut_1, int dizi_2[], int boyut_2) {
    int *sonuc = (int *)calloc(boyut_1 + boyut_2, sizeof(int));
    int i, j = 0, k = 0;
    
    for (i = 0; i < boyut_1 + boyut_2; i++) {
        if (j < boyut_1 && (k >= boyut_2 || dizi_1[j] < dizi_2[k])) {
            sonuc[i] = dizi_1[j];
            j++;
        } else {
            sonuc[i] = dizi_2[k];
            k++;
        }
    }
    
    for (i = 1; i < boyut_1 + boyut_2; i++) {
        int key = sonuc[i];
        int j = i - 1;
        while (j >= 0 && sonuc[j] > key) {
            sonuc[j + 1] = sonuc[j];
            j = j - 1;
        }
        sonuc[j + 1] = key;
    }
    
    return sonuc;
}

int main() {
    int i;
    int liste_1[5] = {6, 12, 15, 18, 24};
    int liste_2[7] = {1, 5, 7, 11, 14, 16, 25};
    int *ptr;
    ptr = dizileri_birlestir(liste_1, 5, liste_2, 7);
    
    int toplam_boyut = 5 + 7;
    
    for (i = 0; i < toplam_boyut; i++) {
        printf("%d ", ptr[i]);
    }
    
    free(ptr); 
    
    return 0;
}
