#include "OyunIcerigi.h"
#define Ortala "                                                            " 

void menu_zindan(Karakter *oyuncu)
{
    YonNode *hareket_gecmisi = NULL; 
    
    int adim_sayisi = 0;
    char buffer[100];
    int zindan_aktif = 1;

    menu_gecisi_bekleme_fonksiyonu("\nKaranlik Zindana Giriliyor...", 1);

    while (zindan_aktif)
    {

        if (oyuncu->can <= 0) break;

        ekrani_temizle();
        sabit_durum_cubugu_yazdir(oyuncu);

        printf(Ortala "\t\t\t\t      .---.\n");
        printf(Ortala "\t\t\t\t     /_____\\\n");
        printf(Ortala "\t\t\t\t    (|     |)\n");
        printf(Ortala "\t\t\t\t     |     |\n");
        printf(Ortala "\t\t\t\t     |_____|\n\n");
        
        if (adim_sayisi == 0)
            printf(Ortala "\t\t\t>>> ZINDAN GIRISINDESIN <<<\n");
        else
            printf(Ortala "\t\t\t>>> Zindanin Derinliklerindesin (Derinlik: %d) <<<\n", adim_sayisi);

        printf("\n" Ortala "\t\t\t [1] KUZEYE ILERLE\n");
        printf(Ortala "\t\t\t [2] GUNEYE ILERLE\n");
        printf(Ortala "\t\t\t [3] DOGUYA ILERLE\n");
        printf(Ortala "\t\t\t [4] BATIYA ILERLE\n");
        printf(Ortala "\t\t\t [5] GERI DON (Geldigin Yoldan)\n");
        printf(Ortala "\t\t\t [0] ZINDANDAN CIK (Sadece Giriste)\n");

        int secim = sayiKontrol("\n\nHangi Yone Gideceksin? >> ");

        if (secim == 0) 
        {
            if (adim_sayisi == 0)
            {
                printf("\n" Ortala ">>> Zindandan sag salim cikiyorsun...\n");
                zindan_aktif = 0;
            }
            else
            {
                printf("\n" Ortala ">>> Buradan cikamazsin! Once girise (derinlik 0) donmelisin!\n");
                sleep(2);
            }
        }
        else if (secim == 5) 
        {
            int son_yon = 0;
            hareket_gecmisi = yigindan_cikar(hareket_gecmisi, &son_yon);
            
            if (son_yon == 0)
            {
                printf("\n" Ortala ">>> Zaten giristesin, daha geri gidemezsin!\n");
            }
            else
            {
                char *yon_adi = "";
                if (son_yon == 1) yon_adi = "Guneye (Geri)";
                if (son_yon == 2) yon_adi = "Kuzeye (Geri)";
                if (son_yon == 3) yon_adi = "Batiya (Geri)";
                if (son_yon == 4) yon_adi = "Doguya (Geri)";

                printf("\n" Ortala ">>> Geldigin yoldan %s donuyorsun...\n", yon_adi);
                adim_sayisi--;
                
                deger_azalt("TOKLUK", &(oyuncu->tokluk), 2);
                deger_azalt("SUSUZLUK", &(oyuncu->susuzluk), 3);
            }
            sleep(1);
        }
        else if (secim >= 1 && secim <= 4) 
        {
            hareket_gecmisi = yigina_ekle(hareket_gecmisi, secim);
            adim_sayisi++;
            
            printf("\n" Ortala ">>> Karanlik koridorlarda ilerliyorsun...\n");
            
            deger_azalt("TOKLUK", &(oyuncu->tokluk), 5);
            deger_azalt("SUSUZLUK", &(oyuncu->susuzluk), 7);
            deger_azalt("HIJYEN", &(oyuncu->hijyen), 3); 

            uyari_fonksiyonu("TOKLUK", &(oyuncu->tokluk), 100, &(oyuncu->can));
            uyari_fonksiyonu("SUSUZLUK", &(oyuncu->susuzluk), 100, &(oyuncu->can));
            
            if (oyuncu->can <= 0) 
            {
                printf("\n" Ortala ">>> Zindanin derinliklerinde acliktan ve yorgunluktan yigildin...\n");
                zindan_aktif = 0;
                break;
            }

            sleep(1);

            int olay = rand() % 100;

            if (olay < 40) 
            {
                printf("\n" Ortala "!!! DIKKAT! KARANLIKTAN BIR SEY FIRLADI !!!\n");
                sleep(1);
                char *dusmanlar[] = {"Zindan Bekcisi", "Iskelet Savasci", "Dev Orumcek", "Karanlik Ruh"};
                int d_guc = 2 + (adim_sayisi / 2);
                int d_can = 30 + (adim_sayisi * 5);
                savas(oyuncu, d_guc, 3, 2, d_can, dusmanlar[rand() % 4], 25, 20);
                if (oyuncu->can <= 0) zindan_aktif = 0;
            }
            else if (olay < 70) 
            {
                if (rand() % 2 == 0) printf("\n" Ortala ">>> Sessiz ve bos bir oda.\n");
                else
                {
                    printf("\n" Ortala ">>> TUZAK! Bastigin tas coktu! (Can -10)\n");
                    oyuncu->can -= 10;
                    if (oyuncu->can <= 0) zindan_aktif = 0;
                }
                sleep(2);
            }
            else 
            {
                printf("\n" Ortala ">>> Sanslisin! Bir sandik buldun!\n");
                int altin = rand() % 30 + 10;
                para_ayarlamasi3(&(oyuncu->para), &altin);
                
                if (rand() % 100 < 30) 
                {
                    Esya *bulunan = (Esya*)malloc(sizeof(Esya));
                    bulunan->id = 99; 
                    strcpy(bulunan->ad, "Bulunan Iksir");
                    bulunan->fiyat = 20;
                    bulunan->etki_degeri = 20;
                    bulunan->tur = 2;
                    envantere_ekle(oyuncu, bulunan);
                    free(bulunan);
                    printf("\n" Ortala ">>> Sandiktan bir iksir cikti!\n");
                }
                sleep(2);
            }
        }
        else
        {
            printf("\n" Ortala ">>> Hatali yon secimi!\n");
            sleep(1);
        }
    }

    hareket_gecmisi = yigini_temizle(hareket_gecmisi);
}