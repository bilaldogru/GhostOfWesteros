#include "OyunIcerigi.h"
#include <stdlib.h>
#define Ortala "                                                            " // 60 Bosluk

void gorev_ekle(GorevKuyruk *kuyruk, int id, char* bas, char* acik, char* gerek, int altin, int xp, int stat)
{
    GorevNode *yeni_gorev = (GorevNode*)malloc(sizeof(GorevNode));
    yeni_gorev->id = id;
    strcpy(yeni_gorev->baslik, bas);
    strcpy(yeni_gorev->aciklama, acik);
    strcpy(yeni_gorev->gereksinim, gerek);
    yeni_gorev->odul_altin = altin;
    yeni_gorev->odul_xp = xp;
    yeni_gorev->odul_stat = stat;
    yeni_gorev->sonraki = NULL;

    if (kuyruk->son == NULL) 
    {
        kuyruk->bas = kuyruk->son = yeni_gorev;
    }
    else 
    {
        kuyruk->son->sonraki = yeni_gorev;
        kuyruk->son = yeni_gorev;
    }
}

void gorev_kuyrugunu_baslat(Karakter *oyuncu)
{
    oyuncu->gorevler = (GorevKuyruk*)malloc(sizeof(GorevKuyruk));
    oyuncu->gorevler->bas = NULL;
    oyuncu->gorevler->son = NULL;

    gorev_ekle(oyuncu->gorevler, 1, "Baslangic", "Westeros zorlu bir yer. Guclenmelisin.", "Seviye 2 Ol", 50, 20, 1);
    gorev_ekle(oyuncu->gorevler, 2, "Ticaret", "Para her kapiyi acar. Biraz birikim yap.", "500 Altina Sahip Ol", 100, 30, 2);
    gorev_ekle(oyuncu->gorevler, 3, "Kas Gucu", "Kilicini daha sert savurmalisin.", "Gucun 10 veya uzeri olsun", 150, 40, 2);
    gorev_ekle(oyuncu->gorevler, 4, "Sifa", "Hayatta kalmak onemli. Saglam dur.", "Canin 100 (Full) Olsun", 200, 50, 3);

    gorev_ekle(oyuncu->gorevler, 5, "Zindan Kesfi", "Karanliktan korkma. Derine in.", "Cevikligin 20 uzeri olsun", 400, 100, 5);
    gorev_ekle(oyuncu->gorevler, 6, "Zenginlik", "Krallara layik bir hazine biriktir.", "2000 Altina Sahip Ol", 500, 150, 5);
    gorev_ekle(oyuncu->gorevler, 7, "Usta Savasci", "Artik bir cirak degilsin.", "Seviye 10 Ol", 600, 200, 5);

    gorev_ekle(oyuncu->gorevler, 8, "Ejderha Gucu", "Valyria celigini hak et.", "Gucun 20 uzeri olsun", 1000, 500, 10);
    gorev_ekle(oyuncu->gorevler, 9, "Milyoner", "Westeros'un en zengini ol.", "5000 Altina Sahip Ol", 2000, 1000, 10);
    gorev_ekle(oyuncu->gorevler, 10, "Efsane", "Ismin tarihe kazinacak.", "Seviye 20 Ol", 5000, 5000, 50);
}

int gorev_tamamla(Karakter *oyuncu)
{
    if (oyuncu->gorevler->bas == NULL) return -1; 

    GorevNode *aktif_gorev = oyuncu->gorevler->bas;
    int tamamlandi = 0;

    switch(aktif_gorev->id)
    {
        case 1: if (oyuncu->seviye >= 2) tamamlandi = 1; break;
        case 2: if (oyuncu->para >= 500) tamamlandi = 1; break;
        case 3: if (oyuncu->guc >= 10) tamamlandi = 1; break;
        case 4: if (oyuncu->can >= 100) tamamlandi = 1; break;
        case 5: if (oyuncu->ceviklik >= 20) tamamlandi = 1; break;
        case 6: if (oyuncu->para >= 2000) tamamlandi = 1; break;
        case 7: if (oyuncu->seviye >= 5) tamamlandi = 1; break;
        case 8: if (oyuncu->guc >= 50) tamamlandi = 1; break;
        case 9: if (oyuncu->para >= 5000) tamamlandi = 1; break;
        case 10: if (oyuncu->seviye >= 10) tamamlandi = 1; break;
    }

    if (tamamlandi)
    {
        printf("\n" Ortala ">>> TEBRIKLER! GOREV BASARIYLA TAMAMLANDI! <<<\n");
        printf(Ortala ">>> Oduller: %d Altin, %d XP, +%d Guc <<<\n", 
               aktif_gorev->odul_altin, aktif_gorev->odul_xp, aktif_gorev->odul_stat);
        
        para_ayarlamasi3(&(oyuncu->para), &(aktif_gorev->odul_altin));
        deger_arttir("XP", &(oyuncu->xp), aktif_gorev->odul_xp);
        deger_arttir("GUC", &(oyuncu->guc), aktif_gorev->odul_stat);

        GorevNode *silinecek = oyuncu->gorevler->bas;
        oyuncu->gorevler->bas = oyuncu->gorevler->bas->sonraki;
        
        if (oyuncu->gorevler->bas == NULL) oyuncu->gorevler->son = NULL;
        
        free(silinecek);
        sleep(2);
        return 1;
    }
    else
    {
        printf("\n" Ortala ">>> Henuz gorev sartlarini saglamiyorsun! <<<\n");
        sleep(1);
        return 0;
    }
}

void menu_gorevler(Karakter *oyuncu)
{
    if (oyuncu->gorevler == NULL) 
    {
        gorev_kuyrugunu_baslat(oyuncu);
    }

    while(1)
    {
        ekrani_temizle();
        sabit_durum_cubugu_yazdir(oyuncu);
        
        printf(Ortala "\t\t\t\t      _________________\n");
        printf(Ortala "\t\t\t\t     / \\               \\\n");
        printf(Ortala "\t\t\t\t    |   |  GOREVLER     |\n");
        printf(Ortala "\t\t\t\t     \\_ |               |\n");
        printf(Ortala "\t\t\t\t        |   PANOSU      |\n");
        printf(Ortala "\t\t\t\t        |               |\n");
        printf(Ortala "\t\t\t\t        |   _________   |\n");
        printf(Ortala "\t\t\t\t        |  /         \\  |\n");
        printf(Ortala "\t\t\t\t        | |           | |\n");
        printf(Ortala "\t\t\t\t        \\_|___________|_/\n\n");

        if (oyuncu->gorevler->bas == NULL)
        {
            printf(Ortala "\t\t\t>>> TUM GOREVLERI BITIRDIN EFSANE! <<<\n\n");
            printf(Ortala "\t\t\t [0] Geri Don\n");
            sayiKontrol("\nSecim: ");
            return;
        }

        GorevNode *aktif = oyuncu->gorevler->bas;
        
        printf(Ortala "\t\t\t>>> AKTIF GOREV: %s <<<\n", aktif->baslik);
        printf(Ortala "\t\t\t--------------------------------------------------\n");
        printf(Ortala "\t\t\tACIKLAMA   : %s\n", aktif->aciklama);
        printf(Ortala "\t\t\tGEREKSINIM : %s\n", aktif->gereksinim);
        printf(Ortala "\t\t\tODUL       : %d Altin | %d XP | +%d Stat\n", aktif->odul_altin, aktif->odul_xp, aktif->odul_stat);
        printf(Ortala "\t\t\t--------------------------------------------------\n");
        
        if (aktif->sonraki != NULL)
        {
            printf("\n" Ortala "\t\t\tSiradaki Gorev: ??? (Kilitli)\n");
            printf(Ortala "\t\t\tKalan Toplam Gorev: Bir suru...\n");
        }

        printf("\n\n" Ortala "\t\t\t [1] GOREVI TAMAMLA (Kontrol Et)\n");
        printf(Ortala "\t\t\t [0] GERI DON\n");

        int secim = sayiKontrol("\nSeciminiz: ");
        
        if (secim == 0) return;
        else if (secim == 1)
        {
            gorev_tamamla(oyuncu);
        }
    }
}