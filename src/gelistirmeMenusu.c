#include "OyunIcerigi.h"
#define Ortala "                                                            " // 60 Boşluk

void menu_gelistirme(Karakter *oyuncu)
{
    int gelistirme_secimi; 
    char buffer[100];

    menu_gecisi_bekleme_fonksiyonu("\nKarakter Gelistirme Islemi Baslatiliyor...", 1);

    while (1)
    {
        ekrani_temizle();
        sabit_durum_cubugu_yazdir(oyuncu);
        
        printf(Ortala"\t\t\t\t         (____)\n");
        printf(Ortala"\t\t\t\t         |    |\n");
        printf(Ortala"\t\t\t\t      .--|____|--.\n");
        printf(Ortala"\t\t\t\t     /   '----'   \\\n");
        printf(Ortala"\t\t\t\t    |    KADERINI  |\n");
        printf(Ortala"\t\t\t\t    |      DOV     |\n");
        printf(Ortala"\t\t\t\t    '--._______..--'\n");
        printf(Ortala"\t\t\t\t       |     |\n");
        printf(Ortala"\t\t\t\t      /       \\\n");
        printf(Ortala"\t\t\t\t     |_________|\n\n");
        printf(Ortala"\t\t\t\t   *** GELISTIRME MENUSU ***\n\n");

        printf(Ortala"\t\t\t\t   ??? NE YAPMAK ISTERSIN  ??? \n\n");
        printf(Ortala"\t\t [0] == > \tBASLANGIC NOKTASINA GERI DON...\t\t < == [0] \n");
        printf(Ortala"\t\t [1] == > \tTERFI AL... (Gerekli XP: 100)\t\t < == [1] \n");
        printf(Ortala"\t\t [2] == > \tBECERI YUKSELT... (Puan: %d)\t\t < == [2] \n", oyuncu->yukseltme_miktari);
        
        sprintf(buffer, "\n\nTercihin Nedir %s >> ", oyuncu->kahramanin_adi);
        gelistirme_secimi = sayiKontrol(buffer);

        if (gelistirme_secimi == 0)
        {
            printf("\n>>>>>>>> Baslangic Noktasina Geri Donuluyor...\n");
            sleep(1);
            return; 
        }
        else if (gelistirme_secimi == 1) 
        {
            if (oyuncu->xp >= 100)
            {
                oyuncu->xp -= 100;
                oyuncu->seviye++;
                oyuncu->yukseltme_miktari += 2; 
                
                printf("\n\n>>> TEBRIKLER! SEVIYE ATLADIN! <<<\n");
                printf("Yeni Seviye: %d\n", oyuncu->seviye);
                printf("Kazanilan Yukseltme Puani: +5\n");
                sleep(2);
            }
            else
            {
                printf("\n\nTerfi almak icin yeterli XP'niz yok. (Mevcut XP: %d / Gerekli: 100)\n", oyuncu->xp);
                sleep(2);
            }
        }
        else if (gelistirme_secimi == 2) 
        {
            while (1)
            {
                ekrani_temizle();
                sabit_durum_cubugu_yazdir(oyuncu);
                
                printf(Ortala"\t\t\t   *** BECERI YUKSELTME EKRANI ***\n\n");
                printf(Ortala"\t\t\t        MEVCUT YUKSELTME PUANI: %d\n\n", oyuncu->yukseltme_miktari);
                
                printf(Ortala"\t\t [0] == > \tGELISTIRME MENUSUNE DON... \t\t < == [0] \n");
                printf(Ortala"\t\t [1] == > \tGUC (+3) \t(Mevcut: %d) \t\t < == [1] \n", oyuncu->guc);
                printf(Ortala"\t\t [2] == > \tCEVIKLIK (+3) \t(Mevcut: %d) \t\t < == [2] \n", oyuncu->ceviklik);
                printf(Ortala"\t\t [3] == > \tDAYANIKLILIK (+3) \t(Mevcut: %d) \t < == [3] \n", oyuncu->dayaniklilik);
                printf(Ortala"\t\t [4] == > \tTOPLAYICILIK (+3) \t(Mevcut: %d) \t < == [4] \n", oyuncu->toplayicilik);

                int beceri_secimi = sayiKontrol("\nHangi beceriyi yukseltmek istiyorsun? >> ");

                if (beceri_secimi == 0)
                {
                    break; 
                }
                
                if (oyuncu->yukseltme_miktari <= 0)
                {
                    printf("\n!!! Yeterli yukselme puaniniz yok. Lutfen once Terfi Alin! !!!\n");
                    sleep(2);
                    continue;
                }

                if (beceri_secimi == 1)
                {
                    oyuncu->yukseltme_miktari--;
                    deger_arttir("GUC", &(oyuncu->guc), 3);
                    beceri_cubugu_gosterim_fonksiyonu("GUC", oyuncu->guc, 25, 0);
                    sleep(1);
                }
                else if (beceri_secimi == 2) 
                {
                    oyuncu->yukseltme_miktari--;
                    deger_arttir("CEVIKLIK", &(oyuncu->ceviklik), 3);
                    beceri_cubugu_gosterim_fonksiyonu("CEVIKLIK", oyuncu->ceviklik, 25, 0);
                    sleep(1);
                }
                else if (beceri_secimi == 3) 
                {
                    oyuncu->yukseltme_miktari--;
                    deger_arttir("DAYANIKLILIK", &(oyuncu->dayaniklilik), 3);
                    beceri_cubugu_gosterim_fonksiyonu("DAYANIKLILIK", oyuncu->dayaniklilik, 25, 0);
                    sleep(1);
                } 
                else if (beceri_secimi == 4)
                {
                    oyuncu->yukseltme_miktari--;
                    deger_arttir("TOPLAYICILIK", &(oyuncu->toplayicilik), 3);
                    beceri_cubugu_gosterim_fonksiyonu("TOPLAYICILIK", oyuncu->toplayicilik, 25, 0);
                    sleep(1);
                } 
                else 
                {
                    printf("\n!!! Hatali giris yaptiniz. Lutfen gecerli bir secim yapin. !!!\n");
                    sleep(1);
                }
            }
        }
        else
        {
            printf("\n!!! Hatali giris yaptiniz. Lutfen tekrar deneyin. !!!\n");
            sleep(1);
        }
    }
}