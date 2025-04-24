#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char ad[30];
    char soyad[30];
    int notu;
} Ogrenci;

int main() {
    FILE *dosya;
    Ogrenci o;
    int i, adet = 3;

    // 1) Yazma modu: ��renci kay�tlar�n� dosyaya ekleme
    dosya = fopen("ogrenciler.txt", "w");
    if (!dosya) {
        perror("Dosya acilamad�");
        return 1;
    }

    printf("=== Ogrenci Bilgisi Yazma (fprintf) ===\n");
    for (i = 0; i < adet; i++) {
        printf("%d. �grencinin adi soyadi notu: ", i+1);
        scanf("%29s %29s %d", o.ad, o.soyad, &o.notu);
        fprintf(dosya, "%s %s %d\n", o.ad, o.soyad, o.notu);
    }
    fclose(dosya);

    // 2) fgets / fputs ile t�m dosyay� sat�r sat�r okuma
    dosya = fopen("ogrenciler.txt", "r");
    if (!dosya) {
        perror("Dosya acilamadi");
        return 1;
    }
    char satir[100];
    printf("\n=== fgets / fputs ile Okuma ===\n");
    while (fgets(satir, sizeof(satir), dosya)) {
        fputs(satir, stdout);
    }
    rewind(dosya);

    // 3) fscanf ile formatl� okuma
    printf("\n=== fscanf ile Formatli Okuma ===\n");
    while (fscanf(dosya, "%29s %29s %d", o.ad, o.soyad, &o.notu) == 3) {
        printf("Ad: %s, Soyad: %s, Not: %d\n", o.ad, o.soyad, o.notu);
    }
    fclose(dosya);

    return 0;
}
