#include "OyunIcerigi.h"
#define SAVE_FILE "game_save.txt"

void save_game(Karakter *oyuncu)
{
    FILE *file_ptr = fopen(SAVE_FILE, "w"); 
    
    if (file_ptr == NULL)
    {
        printf("\n\n*** HATA: Oyun kaydedilemedi! Dosya acilamadi! ***\n");
        sleep(2);
        return;
    }

    fprintf(file_ptr, "%s\n", oyuncu->kahramanin_adi);
    fprintf(file_ptr, "%s\n", oyuncu->kahramanin_calgisi);

    fprintf(file_ptr, "%d\n", oyuncu->seviye);
    fprintf(file_ptr, "%d\n", oyuncu->xp);
    fprintf(file_ptr, "%d\n", oyuncu->can);
    fprintf(file_ptr, "%d\n", oyuncu->tokluk);
    fprintf(file_ptr, "%d\n", oyuncu->uyku);
    fprintf(file_ptr, "%d\n", oyuncu->susuzluk);
    fprintf(file_ptr, "%d\n", oyuncu->mutluluk);
    fprintf(file_ptr, "%d\n", oyuncu->hijyen);
    fprintf(file_ptr, "%d\n", oyuncu->inanc);
    fprintf(file_ptr, "%d\n", oyuncu->para);

    fprintf(file_ptr, "%d\n", oyuncu->guc);
    fprintf(file_ptr, "%d\n", oyuncu->ceviklik);
    fprintf(file_ptr, "%d\n", oyuncu->dayaniklilik);
    fprintf(file_ptr, "%d\n", oyuncu->karizma);
    fprintf(file_ptr, "%d\n", oyuncu->toplayicilik);

    fprintf(file_ptr, "%d\n", oyuncu->yukseltme_miktari);
    
    fclose(file_ptr);

    printf("\n\n>>> Oyun basariyla kaydedildi!<<<\n");
    sleep(2);
}

int load_game(Karakter *oyuncu)
{
    FILE *file_ptr = fopen(SAVE_FILE, "r");

    if (file_ptr == NULL)
    {
        printf("Kayıtlı Oyun Bulunamadı...");
        return 0; 
    }

    if (fgets(oyuncu->kahramanin_adi, sizeof(oyuncu->kahramanin_adi), file_ptr) == NULL) 
    {
        fclose(file_ptr); return 0; 
    }

    oyuncu->kahramanin_adi[strcspn(oyuncu->kahramanin_adi, "\r\n")] = 0;

    if (fgets(oyuncu->kahramanin_calgisi, sizeof(oyuncu->kahramanin_calgisi), file_ptr) == NULL) 
    {
        fclose(file_ptr); return 0; 
    }
    oyuncu->kahramanin_calgisi[strcspn(oyuncu->kahramanin_calgisi, "\r\n")] = 0;

    int items_read = 0;

    items_read += fscanf(file_ptr, "%d\n", &oyuncu->seviye);
    items_read += fscanf(file_ptr, "%d\n", &oyuncu->xp);
    items_read += fscanf(file_ptr, "%d\n", &oyuncu->can);
    items_read += fscanf(file_ptr, "%d\n", &oyuncu->tokluk);
    items_read += fscanf(file_ptr, "%d\n", &oyuncu->uyku);
    items_read += fscanf(file_ptr, "%d\n", &oyuncu->susuzluk);
    items_read += fscanf(file_ptr, "%d\n", &oyuncu->mutluluk);
    items_read += fscanf(file_ptr, "%d\n", &oyuncu->hijyen);
    items_read += fscanf(file_ptr, "%d\n", &oyuncu->inanc);
    items_read += fscanf(file_ptr, "%d\n", &oyuncu->para);

    items_read += fscanf(file_ptr, "%d\n", &oyuncu->ceviklik);
    items_read += fscanf(file_ptr, "%d\n", &oyuncu->dayaniklilik);
    items_read += fscanf(file_ptr, "%d\n", &oyuncu->karizma);
    items_read += fscanf(file_ptr, "%d\n", &oyuncu->toplayicilik);

    items_read += fscanf(file_ptr, "%d\n", &oyuncu->yukseltme_miktari);
    
    fclose(file_ptr);

    return 1; 
}