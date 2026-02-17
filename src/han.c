#include "OyunIcerigi.h"
#define Ortala "                                                            " // 60 Boşluk

#include "OyunIcerigi.h"
#define Ortala "                                                            "

void menu_silahci(Karakter *oyuncu)
{
    Esya *silah_dukkani = NULL;
    dukkan_listesine_ekle(&silah_dukkani, 1, "Pasli Hancer", 50, 2, 1);
    dukkan_listesine_ekle(&silah_dukkani, 2, "Demir Kilic", 150, 5, 1);
    dukkan_listesine_ekle(&silah_dukkani, 3, "Savas Baltasi", 300, 10, 1);
    dukkan_listesine_ekle(&silah_dukkani, 4, "Sovalye Kilici", 600, 15, 1);
    dukkan_listesine_ekle(&silah_dukkani, 5, "Valyria Celigi", 2000, 30, 1);

    while(1)
    {
        ekrani_temizle();
        sabit_durum_cubugu_yazdir(oyuncu);
        
        printf(Ortala "\t\t\t\t      /| ________________\n");
        printf(Ortala "\t\t\t\tO|===|* >________________>\n");
        printf(Ortala "\t\t\t\t      \\| \n");
        printf(Ortala "\t\t\t\t   --- DEMIRCI USTASI GENDRY ---\n\n");
        printf(Ortala "\tUsta: 'Westeros'un en saglam celigini mi ariyorsun? Dogru yerdesin.'\n\n");
        
        dukkani_yazdir(silah_dukkani);
        
        printf("\n" Ortala " [0] Dukkandan Cik\n");

        int secim = sayiKontrol("\n\nSatin almak istediginiz silahin numarasini girin: ");

        if (secim == 0) break;

        Esya *gecici = silah_dukkani;
        int bulundu = 0;
        
        while (gecici != NULL)
        {
            if (gecici->id == secim)
            {
                bulundu = 1;
                if (oyuncu->para >= gecici->fiyat)
                {
                    printf("\n" Ortala ">>> MUKEMMEL SECIM! %s artik senin!\n", gecici->ad);
                    printf(Ortala ">>> Gucun +%d artti!\n", gecici->etki_degeri);
                    
                    para_harcama(&(oyuncu->para), gecici->fiyat);
                    
                    deger_arttir("GUC", &(oyuncu->guc), gecici->etki_degeri);
                    oyuncu->envanter_eşya_sayisi++;
                    envantere_ekle(oyuncu, gecici); 

                    deger_azalt("TOKLUK", &(oyuncu->tokluk), 5);
                    sleep(2);
                }
                else
                {
                    printf("\n" Ortala ">>> Usta: 'Paran yetmiyor evlat, veresiye calismiyoruz!'\n");
                    sleep(2);
                }
                break;
            }
            gecici = gecici->sonraki;
        }
        if (!bulundu)
        {
            printf("\n" Ortala ">>> Hatali secim! Tezgahta boyle bir silah yok.\n");
            sleep(1);
        }
    }
    dukkani_temizle(silah_dukkani);
}

void menu_buyucu_dukkani(Karakter *oyuncu)
{
    Esya *buyu_dukkani = NULL;
    dukkan_listesine_ekle(&buyu_dukkani, 1, "Kucuk Sifa Iksiri", 20, 20, 2); 
    dukkan_listesine_ekle(&buyu_dukkani, 2, "Buyuk Sifa Iksiri", 50, 50, 2); 
    dukkan_listesine_ekle(&buyu_dukkani, 3, "Ejderha Nefesi", 150, 5, 2); 
    dukkan_listesine_ekle(&buyu_dukkani, 4, "Golge Yuruyusu", 100, 5, 2); 

    while(1)
    {
        ekrani_temizle();
        sabit_durum_cubugu_yazdir(oyuncu);
        
        printf(Ortala "\t\t\t\t\t      _____\n");
        printf(Ortala "\t\t\t\t\t     `.___,'\n");
        printf(Ortala "\t\t\t\t\t      (___)\n");
        printf(Ortala "\t\t\t\t\t      <   >\n");
        printf(Ortala "\t\t\t\t\t       ) (\n");
        printf(Ortala "\t\t\t\t\t      /`-. \n");
        printf(Ortala "\t\t\t\t\t     /     \\ \n");
        
        printf(Ortala "\t\t\t        --- GIZEMLI BUYUCUNUN ODASI ---\n\n");
        printf(Ortala "\tBuyucu: 'Siselerin icinde olum de var yasam da... Secim senin.'\n\n");
        
        dukkani_yazdir(buyu_dukkani);
        printf("\n" Ortala " [0] Odadan Cik\n");

        int secim = sayiKontrol("\n\nSatin almak istediginiz iksirin numarasini girin: ");

        if (secim == 0) break;

        Esya *gecici = buyu_dukkani;
        int bulundu = 0;
        
        while (gecici != NULL)
        {
            if (gecici->id == secim)
            {
                bulundu = 1;
                if (oyuncu->para >= gecici->fiyat)
                {   
                    printf("\n" Ortala ">>> %s satin aldin ve cantana koydun.\n", gecici->ad);
                    
                    para_harcama(&(oyuncu->para), gecici->fiyat);
                    oyuncu->envanter_eşya_sayisi++;
                    envantere_ekle(oyuncu, gecici); 
                    
                    sleep(2);
                }
                else
                {
                    printf("\n" Ortala ">>> Buyucu: 'Altin enerjidir, enerjin yoksa buyu de yok!'\n");
                    sleep(2);
                }
                break;
            }
            gecici = gecici->sonraki;
        }
        if (!bulundu) { printf("\n" Ortala ">>> Hatali secim!\n"); sleep(1); }
    }
    dukkani_temizle(buyu_dukkani);
}

void menu_sifahane(Karakter *oyuncu)
{
    while(1)
    {
        ekrani_temizle();
        sabit_durum_cubugu_yazdir(oyuncu);
        
        printf(Ortala "\t\t\t\t\t      _   _\n");
        printf(Ortala "\t\t\t\t\t     | | | |\n");
        printf(Ortala "\t\t\t\t\t    _| |_| |_\n");
        printf(Ortala "\t\t\t\t\t   |_________|\n\n");
        
        printf(Ortala "\t\t\t\t\t       --- SIFAHANE VE BAKIM ---\n\n");
        printf(Ortala "\t     Sifaci: 'Yaralarini sarabilirim, ama karsiliginda bagis beklerim.'\n\n");
        
        printf(Ortala "\t [1] Yaralarimi Sar (Cani Fulle)      >> 50 Altin\n");
        printf(Ortala "\t [2] Zehri Temizle (Hijyen +50)       >> 20 Altin\n");
        printf(Ortala "\t [3] Ruhsal Arinma (Mutluluk/Inanc +20) >> 30 Altin\n");
        printf(Ortala "\t [0] Cikis\n");
        
        int secim = sayiKontrol("\n\nSeciminiz: ");
        
        if (secim == 0) break;
        
        else if (secim == 1) 
        {
            if (oyuncu->para >= 50)
            {
                if(oyuncu->can >= 100)
                {
                     printf("\n" Ortala ">>> Zaten sagliklisin, bosuna para harcama!\n");
                }
                else
                {
                    printf("\n" Ortala ">>> Yaralariniz sarildi. Turp gibisiniz! (Can: 100)\n");
                    para_harcama(&(oyuncu->para), 50);
                    oyuncu->can = 100;
                }
                sleep(2);
            }
            else { printf("\n" Ortala ">>> Yetersiz Bakiye!\n"); sleep(1); }
        }
        
        else if (secim == 2) 
        {
             if (oyuncu->para >= 20)
            {
                printf("\n" Ortala ">>> Sicak su ve sabunla yikandiniz. Mis gibi oldunuz!\n");
                para_harcama(&(oyuncu->para), 20);
                deger_arttir("HIJYEN", &(oyuncu->hijyen), 50);
                deger_arttir("MUTLULUK", &(oyuncu->mutluluk), 10);
                sleep(2);
            }
            else { printf("\n" Ortala ">>> Yetersiz Bakiye!\n"); sleep(1); }
        }

        else if (secim == 3) 
        {
             if (oyuncu->para >= 30)
            {
                printf("\n" Ortala ">>> Sifaci ile dertlestiniz ve huzur buldunuz.\n");
                para_harcama(&(oyuncu->para), 30);
                deger_arttir("MUTLULUK", &(oyuncu->mutluluk), 20);
                deger_arttir("INANC", &(oyuncu->inanc), 20);
                sleep(2);
            }
            else { printf("\n" Ortala ">>> Yetersiz Bakiye!\n"); sleep(1); }
        }
        else
        {
            printf("\n" Ortala ">>> Hatali giris!\n");
            sleep(1);
        }
    }
}
void menu_han(Karakter *oyuncu)
{
    int han_secimi;
    char buffer[100];

    menu_gecisi_bekleme_fonksiyonu("\nHan'a Giriliyor...", 1);

    while (1)
    {
        ekrani_temizle();
        sabit_durum_cubugu_yazdir(oyuncu);
        
        printf(Ortala "\t\t\t              (  )   (   )  )\n");
        printf(Ortala "\t\t\t               ) (   )  (  (\n");
        printf(Ortala "\t\t\t               ( )  (    ) )\n");
        printf(Ortala "\t\t\t               _____________\n");
        printf(Ortala "\t\t\t              |_____________|  \n");
        printf(Ortala "\t\t\t              |             |  \n");
        printf(Ortala "\t\t\t              |   O R T A   |  \n");
        printf(Ortala "\t\t\t  /\\          |   D U N Y A |           /\\\n");
        printf(Ortala "\t\t\t /  \\         |     H A N   |          /  \\\n");
        printf(Ortala "\t\t\t/____\\________|_____________|_________/____\\\n");
        printf(Ortala "\t\t\t|    |        |  _   _   _  |         |    |\n");
        printf(Ortala "\t\t\t| [] |        | | | | | | | |         | [] |\n");
        printf(Ortala "\t\t\t|    |  ( )   | |_| |_| |_| |   ( )   |    |\n");
        printf(Ortala "\t\t\t|____|_(___)__|_____________|__(___)__|____|\n\n\n");

        printf(Ortala "\t\t       ??? Han'da Hangi Bolume Gitmek Istersin Savasci ??? \n\n");
        printf(Ortala "\t\t [0] == >    BASLANGIC NOKTASINA GERI DON...      < == [0] \n");
        printf(Ortala "\t\t [1] == >    SILAH SATICISI (Demirci Ustasi)      < == [1] \n");
        printf(Ortala "\t\t [2] == >    BUYUCUNUN ODASI (Iksirler/Buyuler)   < == [2] \n");
        printf(Ortala "\t\t [3] == >    SIFAHANE (Iyilesme Merkezi)          < == [3] \n");

        sprintf(buffer, "\n\nLutfen Gitmek Istedigin Yeri Sec %s : ", oyuncu->kahramanin_adi);
        han_secimi = sayiKontrol(buffer);

        if (han_secimi == 0)
        {
            printf("\n>>>>>>>> Baslangic Noktasina Geri Donuluyor...\n");
            sleep(1);
            return;
        }
        else if (han_secimi == 1)
        {
            menu_silahci(oyuncu);
        }
        else if (han_secimi == 2)
        {
            menu_buyucu_dukkani(oyuncu);
        }
        else if (han_secimi == 3)
        {
            menu_sifahane(oyuncu);
        }
        else
        {
            printf("\n!!! Hatali giris yaptiniz. Lutfen tekrar deneyin. !!!\n");
            sleep(1);
        }
    } 
}