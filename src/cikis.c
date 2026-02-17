#include "OyunIcerigi.h"

int menu_cikis(Karakter *oyuncu)
{
    ekrani_temizle();
    menu_gecisi_bekleme_fonksiyonu("***** OYUNDAN CIKIS ISLEMI *****",1);
    printf("\n\n\t\t\t***** OYUNDAN CIKIS ISLEMI *****\n\n");

    int save_choice = sayiKontrol("Cikmadan once oyunu kaydetmek ister misiniz? (1: Evet, 0: Hayir): ");
    if (save_choice == 1) 
    {
        save_game(oyuncu);
    }

    while (1)
    {
        printf("\t\t ? Oyundan cikmak istedigine emin misin %s ? \n\n", oyuncu->kahramanin_adi);
        printf("\n\n\t\t\tOYUNDA KALMAK ISTIYORSAN  >> 0 <<\n");
        printf("\t\t\tOYUNDAN CIKMAK ISTIYORSAN >> 1 <<\n\n");

        int cikis = sayiKontrol("\n\nLutfen Yapmak Istedigin Islemi Sec : ");

        if (cikis == 0)
        {
            printf("\n\n\t\t%s oyunda kalmayi tercih ettin.\n\n\t\t\n", oyuncu->kahramanin_adi);
            menu_gecisi_bekleme_fonksiyonu("!!!...OYUNA GERI DONULUYOR...!!!",2);
            return 0; 
        }
        else if (cikis == 1)
        {
            printf("\n\n\t\t\t\t\t\t%s oyundan cikmayi tercih ettin.\n\n\t\t\t\t\t\tOYUNDAN CIKILIYOR....\n\n\n\n\n", oyuncu->kahramanin_adi);
            sleep(3);
            return 1; 
        }
        else
        {
            printf("YANLIS ISLEM SECILDI LUTFEN TEKRAR DENEYINIZ !!! ");
        }
    }
}