#include "OyunIcerigi.h"
#include <ctype.h>
#include <time.h>
#include <windows.h> 

#define Ortala "                                                            "

void menu_kesif(Karakter *oyuncu)
{
    int westeros_secimi;
    char buffer[100];

    menu_gecisi_bekleme_fonksiyonu("\nWesteros Evrenini Kesfe Cikiliyor...", 1);

    while(1) 
    {
        ekrani_temizle();
        sabit_durum_cubugu_yazdir(oyuncu);

        if (oyuncu->can <= 0) return;

        printf(Ortala"\t\t\t\t           /\\\n");
        printf(Ortala"\t\t\t\t           |\n");
        printf(Ortala"\t\t\t\t      .----|----.\n");
        printf(Ortala"\t\t\t\t      /    |     \\\n");
        printf(Ortala"\t\t\t\t     |     N      |\n");
        printf(Ortala"\t\t\t\t<--W       +       E-->\n");
        printf(Ortala"\t\t\t\t     |     S      |\n");
        printf(Ortala"\t\t\t\t      \\    |     /\n");
        printf(Ortala"\t\t\t\t       '----|----'\n");
        printf(Ortala"\t\t\t\t            |\n");
        printf(Ortala"\t\t\t\t            \\/\n\n");
        printf(Ortala"\t\t\t\t *** WESTEROS DUNYASINI KESFET *** \n\n");

        printf(Ortala"\t   ??? Hangi Maceraya Atilmak Istersin, Savasci ??? \n\n");
        printf(Ortala"\t [0] == > \t        BASLANGIC NOKTASINA GERI DON...\t\t < == [0] \n");
        printf(Ortala"\t [1] == > \t        YAKIN YERLERI KESFE CIK (Ganimet/Haydut) < == [1] \n");
        printf(Ortala"\t [2] == > [ORTA]\tHARITADA ISTEDIGIN YERE ILERLE...\t < == [2] \n");
        printf(Ortala"\t [3] == > [ZOR]\t        SURU GEC VE KUZEYE DOGRU ILERLE ...\t < == [3] \n");
        printf(Ortala"\t [4] == > [BOSS]\tEJDERHA AVINA CIK...\t\t\t < == [4] \n\n");
        
        sprintf(buffer, "\n\nTercihin Nedir %s >> ", oyuncu->kahramanin_adi);
        westeros_secimi = sayiKontrol(buffer);

        if (westeros_secimi == 0)
        {
            printf("\nBaslangic Noktasina Geri Donuluyor...\n");
            sleep(1);
            return; 
        }
        else if (westeros_secimi == 1) 
        {
            printf("\n\nCevreyi arastiriyorsun...\n");
            sleep(2);
            int sans = rand() % 100;
            if (sans < 40) 
            {
                int bulunan_altin = rand() % 20 + 5;
                printf("\nSanslisin! Bir kese altin buldun (+%d Altin)\n", bulunan_altin);
                para_ayarlamasi3(&(oyuncu->para), &bulunan_altin);
                sleep(2);
            }
            else
            {
                savas(oyuncu, (rand() % 2 + 2), (rand() % 2 + 2), (rand() % 2), 35, "Basibozuk Haydut", 15, 10);
            }
        }
        else if (westeros_secimi == 2) 
        {
            while(1)
            {
                if (oyuncu->can <= 0) break;

                ekrani_temizle();
                sabit_durum_cubugu_yazdir(oyuncu);
                
                printf(Ortala"\t\t\t\t### HARITA BOLGESI (ORTA SEVIYE) ###\n\n");
                printf(Ortala"\t\t  [0] --> \tGeri Don...\t\t\t\t  <-- [0]\n");
                printf(Ortala"\t\t  [1] --> \tDoguya Git (Targaryen Askeri)...\t  <-- [1]\n");
                printf(Ortala"\t\t  [2] --> \tBatiya Git (Bos Arazi)...\t\t  <-- [2]\n");
                printf(Ortala"\t\t  [3] --> \tGuneye Git (Lannister Askeri)...\t  <-- [3]\n");

                int tutsak_secimi = sayiKontrol("\nHaritada Nereye Gidiyoruz? >> ");

                if (tutsak_secimi == 0) break;
                else if (tutsak_secimi == 1) 
                {
                    savas(oyuncu, (rand() % 3 + 4), (rand() % 3 + 3), (rand() % 3 + 2), 70, "Targaryen Askeri", 40, 25);
                }
                else if (tutsak_secimi == 2) 
                {
                    printf("\nBatiya gittin, ruzgardan baska bir sey yok...\n");
                    sleep(2);
                }
                else if (tutsak_secimi == 3) 
                {
                    savas(oyuncu, (rand() % 3 + 4), (rand() % 3 + 3), (rand() % 3 + 2), 70, "Lannister Askeri", 40, 25);
                }
                else
                {
                    printf("\nHatali secim!\n");
                    sleep(1);
                }
            }
        }
        else if (westeros_secimi == 3) 
        {
            while(1)
            {
                if (oyuncu->can <= 0) break;

                ekrani_temizle();
                sabit_durum_cubugu_yazdir(oyuncu);

                printf(Ortala"\t\t\t\t### SUR - KUZEY (ZOR SEVIYE) ###\n\n");
                printf(Ortala"  [0] --> \tGeri Don...\t\t\t\t <-- [0]\n");
                printf(Ortala"  [1] --> \tNocbetcileri Kontrol Et (Yabanil Avla)..\t  <-- [1]\n");
                printf(Ortala"  [2] --> \tDuvarin Otesine Göz At...\t\t\t  <-- [2]\n");

                int sur_secimi = sayiKontrol("\nSurda ne yapacaksin? >> ");
                
                if (sur_secimi == 0) break;
                else if (sur_secimi == 1) 
                { 
                    savas(oyuncu, (rand() % 3 + 7), (rand() % 3 + 5), (rand() % 3 + 4), 100, "Yabanil", 80, 45);
                }
                else if (sur_secimi == 2) 
                { 
                    printf("\nDuvarin otesine baktin... Soguk iliklerine isledi. (Tokluk -5)\n");
                    deger_azalt("TOKLUK", &(oyuncu->tokluk), 5);
                    sleep(2);
                }
                else
                {
                    printf("\nHatali secim!\n");
                    sleep(1);
                }
            }
        }
        else if (westeros_secimi == 4) 
        {
            while(1)
            {
                if (oyuncu->can <= 0) break;

                ekrani_temizle();
                sabit_durum_cubugu_yazdir(oyuncu);

                printf(Ortala"\t\t\t\t\t### EJDERHA AVI (BOSS) ###\n\n");
                printf(Ortala"\t\t  [0] --> \tGeri Don (Korkakca Kac)...\t\t  <-- [0]\n");
                printf(Ortala"\t\t  [1] --> \tEjderha Yuvasina Gir (Olumune Savas)..\t  <-- [1]\n");
                
                int ejderha_secimi = sayiKontrol("\nCesaretin var mi? >> ");
                
                if (ejderha_secimi == 0) break;
                else if (ejderha_secimi == 1)
                {
                    savas(oyuncu, (rand() % 5 + 15), (rand() % 5 + 10), (rand() % 5 + 12), 250, "Ejderha", 500, 300);
                }
                else
                {
                    printf("\nHatali secim!\n");
                    sleep(1);
                }
            }
        }
        else
        {
            printf("\nHatali giris yaptiniz. Lutfen tekrar deneyin.\n");
            sleep(1);
        }
    } 
}