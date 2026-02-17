#include "OyunIcerigi.h"
#include <string.h> 

#define Ortala "                                                            " 

void hizali_cubuk_yazdir(char* etiket, int mevcut, int maks) {
    char bar[22];
    int doluluk = (mevcut * 10) / maks; 
    strcpy(bar,"\t\t\t\t\t\t[");
    for (int i = 0; i < 10; i++) {
        if (i < doluluk) strcat(bar, "■");
        else strcat(bar, " ");
    }
    strcat(bar, "]");

    printf(Ortala "%-16s >> %3d/%-3d %s\n", etiket, mevcut, maks, bar);
}

void menu_ozellikler(Karakter *oyuncu)
{
    menu_gecisi_bekleme_fonksiyonu("\nOzellikler ve Karakter Durumu Yukleniyor...", 1);

    while (1)
    {
        ekrani_temizle();
        sabit_durum_cubugu_yazdir(oyuncu); 
        

        printf(Ortala"\t\t\t\t      .'`~~~~~~~~~`'.     .'`~~~~~~~~~`'.\n");
        printf(Ortala"\t\t\t\t     /               \\   /               \\\n");
        printf(Ortala"\t\t\t\t    |                 | |                 |\n");
        printf(Ortala"\t\t\t\t    |    KARAKTER     | |      DURUM      |\n");
        printf(Ortala"\t\t\t\t    |      OZETI      | |     BILGISI     |\n");
        printf(Ortala"\t\t\t\t    |                 | |                 |\n");
        printf(Ortala"\t\t\t\t     \\               /   \\               /\n");
        printf(Ortala"\t\t\t\t      '.___________.'     '.___________.'\n");
        printf(Ortala"\t\t\t\t           |                     |\n");
        printf(Ortala"\t\t\t\t        .--|_____________________|--.\n");
        printf(Ortala"\t\t\t\t       (_____________________________)\n\n");


        printf(Ortala"\t\t\t\t   ***** TEMEL NITELIK DURUMLARI ***** \n\n");
        
        hizali_cubuk_yazdir("CAN", oyuncu->can, 100);
        hizali_cubuk_yazdir("ENERJI", oyuncu->uyku, 100);
        hizali_cubuk_yazdir("TOKLUK", oyuncu->tokluk, 100);
        hizali_cubuk_yazdir("SUSUZLUK", oyuncu->susuzluk, 100);
        hizali_cubuk_yazdir("MUTLULUK", oyuncu->mutluluk, 100);
        hizali_cubuk_yazdir("HIJYEN", oyuncu->hijyen, 100);
        hizali_cubuk_yazdir("INANC", oyuncu->inanc, 100);

        printf("\n");

        printf(Ortala"\t\t\t\t    ***** SAVAS VE YASAM BECERILERI ***** \n\n");
        

        hizali_cubuk_yazdir("GUC", oyuncu->guc, 25);
        hizali_cubuk_yazdir("CEVIKLIK", oyuncu->ceviklik, 25);
        hizali_cubuk_yazdir("DAYANIKLILIK", oyuncu->dayaniklilik, 25);
        hizali_cubuk_yazdir("KARIZMA", oyuncu->karizma, 25);
        hizali_cubuk_yazdir("TOPLAYICILIK", oyuncu->toplayicilik, 25);

        printf("\n");

        printf(Ortala"\t\t\t\t      ---------------------------------\n");
        printf(Ortala"\t\t\t\t         SEVIYE: %-2d  |  XP: %-4d\n", oyuncu->seviye, oyuncu->xp);
        printf(Ortala"\t\t\t\t      ---------------------------------\n");

        char buffer[100];
        printf("\n\n" Ortala "\t\t\t\t    Ana Menuye donmek icin [0] tuslayin \n");
        sprintf(buffer, Ortala "\t\t\t\t                   >> "); 
        int secim = sayiKontrol(buffer);
        
        if (secim == 0)
        {
            printf("\nAna menuye donuluyor...\n");
            sleep(1);
            return;
        }
        else
        {
            printf("\nHatali giris! Menude kaliniyor...\n");
            sleep(1);
        }
    }
}