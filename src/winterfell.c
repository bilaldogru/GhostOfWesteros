#include "OyunIcerigi.h"
#define Ortala "                                                            " // 60 Boşluk

void menu_winterfell(Karakter *oyuncu)
{
    int kalede_yapilacak_aktivite;
    int kamp_atesi, kutsal_agac, odana_cik;
    char buffer[100];

    menu_gecisi_bekleme_fonksiyonu("\nWinterfell'e Gidiliyor...", 1);

    while (1)
    {
        ekrani_temizle();
        sabit_durum_cubugu_yazdir(oyuncu);
        
        printf(Ortala"\n\n\t\t\t\t\t\t\t              |>>>                                         |>>>                                    \n");
        printf(Ortala"          |                                            |                                    \n");
        printf(Ortala"      _  _|_  _                                    _  _|_  _                                   \n");
        printf(Ortala"     |;|_|;|_|;|                                  |;|_|;|_|;|                                    \n");
        printf(Ortala"     \\\\.  .   /                                   \\\\. .    /                                      \n");
        printf(Ortala"      \\\\:.    /                                    \\\\:.    /                                                    \n");
        printf(Ortala"       ||:   |              WINTERFELL              ||:   |                                                 \n");
        printf(Ortala"       ||:.  |                                      ||:.  |                                                 \n");
        printf(Ortala"       ||:  .|                                      ||:  .|                                                \n\n\n");

        printf(Ortala"      ??? WINTERFELL'De Ne Yapmak Istersin Savasci ??? \n\n\n");
        printf(Ortala" [0] == > \t\tBASLANGIC NOKTASINA GERI DON...\t\t < == [0] \n");
        printf(Ortala" [1] == > \t\tKAMP ATESININ BASINDA SARKI CAL...\t < == [1] \n");
        printf(Ortala" [2] == > \t\tKUTSAL AGACA GIT...\t\t\t < == [2]\n");
        printf(Ortala" [3] == > \t\tKALEDEKI ODANA CIK ...\t\t\t < == [3] \n");

        sprintf(buffer, "\n\nLutfen Yapmak Istedigin Aktiviteyi Sec %s : ", oyuncu->kahramanin_adi);
        kalede_yapilacak_aktivite = sayiKontrol(buffer);

        switch (kalede_yapilacak_aktivite)
        {
            case 1: 
            {
                printf("\n\n>>>>>>>> Kamp Atesine Dogru Ilerleniyor...\n");
                sleep(1);
                
                while (1)
                {
                    ekrani_temizle();
                    sabit_durum_cubugu_yazdir(oyuncu);
                    
                    printf(Ortala"\t\t\t\t  ### KAMP ATESI ###\n\n");
                    printf(Ortala"  [0] --> \t\tKamp Atesinden Ayril... \t\t  <-- [0]\n");
                    printf(Ortala"  [1] --> \t\t%s'i kullanarak sarki soyle... \t  <-- [1]\n", oyuncu->kahramanin_calgisi);
                    printf(Ortala"  [2] --> \t\t%s olmadan sarki soyle... \t\t  <-- [2]\n", oyuncu->kahramanin_calgisi);

                    sprintf(buffer, "\n\nTercihin Nedir %s >> ", oyuncu->kahramanin_adi);
                    kamp_atesi = sayiKontrol(buffer);

                    if (kamp_atesi == 0)
                    {
                        printf("\n>>>>>>>> Kamp Atesinden Ayriliyorsun...\n");
                        sleep(1);
                        break; 
                    }
                    else if (kamp_atesi == 1)
                    {
                        if(oyuncu->hijyen < 20)
                        {
                            printf("\n\t\t\t\tHIJYEN DURUMUNUZ SARKI SOYLEMEK ICIN YETERLI DEGIL !!!\n");
                        }
                        else
                        {
                            printf("\n%s kullanarak insanlari fazlasiyla eglendirdin...\n", oyuncu->kahramanin_calgisi);
                            
                            para_kazanma(oyuncu->karizma, oyuncu->hijyen, 1, &(oyuncu->para)); 
                            deger_arttir("XP", &(oyuncu->xp), 20);
                            deger_arttir("MUTLULUK", &(oyuncu->mutluluk), 10);
                            deger_azalt("UYKU", &(oyuncu->uyku), 5);
                            deger_azalt("TOKLUK", &(oyuncu->tokluk), 5);
                            deger_azalt("SUSUZLUK", &(oyuncu->susuzluk), 5);
                            
                            uyari_fonksiyonu("UYKU", &(oyuncu->uyku), 100, &(oyuncu->can));
                            uyari_fonksiyonu("TOKLUK", &(oyuncu->tokluk), 100, &(oyuncu->can));
                            uyari_fonksiyonu("SUSUZLUK", &(oyuncu->susuzluk), 100, &(oyuncu->can));
                        }
                        sleep(2); 
                    }
                    else if (kamp_atesi == 2)
                    {
                        if(oyuncu->hijyen < 20)
                        {
                             printf("\n\t\t\t\tHIJYEN DURUMUNUZ SARKI SOYLEMEK ICIN YETERLI DEGIL !!!\n");
                        }
                        else
                        {
                            printf("\n%s kullanmadan sarkini soyledin, insanlar biraz eglendi.\n", oyuncu->kahramanin_calgisi);
                            
                            para_kazanma(oyuncu->karizma, oyuncu->hijyen, 0, &(oyuncu->para));
                            deger_arttir("XP", &(oyuncu->xp), 15);
                            deger_arttir("MUTLULUK", &(oyuncu->mutluluk), 5);
                            deger_azalt("UYKU", &(oyuncu->uyku), 5);
                            deger_azalt("TOKLUK", &(oyuncu->tokluk), 5);
                            deger_azalt("SUSUZLUK", &(oyuncu->susuzluk), 5);
                            
                            uyari_fonksiyonu("UYKU", &(oyuncu->uyku), 100, &(oyuncu->can));
                            uyari_fonksiyonu("TOKLUK", &(oyuncu->tokluk), 100, &(oyuncu->can));
                            uyari_fonksiyonu("SUSUZLUK", &(oyuncu->susuzluk), 100, &(oyuncu->can));
                        }
                        sleep(2);
                    }
                    else
                    {
                        printf("\n!!! Hatali giris yaptiniz. Lutfen gecerli bir secenek girin. !!!\n");
                        sleep(1);
                    }
                }
                break; 
            }

            case 2: 
            {
                printf("\n\n>>>>>>>> Kutsal Agaca dogru ilerleniyor...\n");
                sleep(1);
                
                while (1)
                {
                    ekrani_temizle();
                    sabit_durum_cubugu_yazdir(oyuncu);
                    
                    printf(Ortala"\t\t\t### KUTSAL AGAC ###\n\n");
                    printf(Ortala"  [0] --> \t\tKutsal Agactan Ayril... \t\t  <-- [0]\n");
                    printf(Ortala"  [1] --> \t\tAgacin altinda Dua et...\t\t  <-- [1]\n");
                    printf(Ortala"  [2] --> \t\tKutsal suda temizlen... \t\t  <-- [2]\n");

                    sprintf(buffer, "\n\nTercihin Nedir %s >> ", oyuncu->kahramanin_adi);
                    kutsal_agac = sayiKontrol(buffer);

                    if (kutsal_agac == 0)
                    {
                        printf("\n>>>>>>>> Kutsal Agactan Ayriliyorsun...\n");
                        sleep(1);
                        break;
                    }
                    else if (kutsal_agac == 1)
                    {
                        printf("\nAgacin altinda oturup huzurla dua ettin...\n");
                        
                        deger_arttir("XP", &(oyuncu->xp), 15);
                        deger_arttir("MUTLULUK", &(oyuncu->mutluluk), 10);
                        deger_arttir("INANC", &(oyuncu->inanc), 10);
                        deger_azalt("UYKU", &(oyuncu->uyku), 5);
                        deger_azalt("TOKLUK", &(oyuncu->tokluk), 5);
                        deger_azalt("SUSUZLUK", &(oyuncu->susuzluk), 5);
                        
                        uyari_fonksiyonu("TOKLUK", &(oyuncu->tokluk), 100, &(oyuncu->can));
                        uyari_fonksiyonu("SUSUZLUK", &(oyuncu->susuzluk), 100, &(oyuncu->can));
                        uyari_fonksiyonu("UYKU", &(oyuncu->uyku), 100, &(oyuncu->can));
                        sleep(2);
                    }
                    else if (kutsal_agac == 2)
                    {
                        printf("\nKutsal suda temizlendin ve ferahladin...\n");
                        
                        deger_arttir("INANC", &(oyuncu->inanc), 10);
                        deger_arttir("HIJYEN", &(oyuncu->hijyen), 15);
                        deger_arttir("MUTLULUK", &(oyuncu->mutluluk), 5);
                        deger_azalt("TOKLUK", &(oyuncu->tokluk), 5);
                        deger_azalt("SUSUZLUK", &(oyuncu->susuzluk), 5);
                        deger_azalt("UYKU", &(oyuncu->uyku), 5);
                        
                        uyari_fonksiyonu("TOKLUK", &(oyuncu->tokluk), 100, &(oyuncu->can));
                        uyari_fonksiyonu("SUSUZLUK", &(oyuncu->susuzluk), 100, &(oyuncu->can));
                        uyari_fonksiyonu("UYKU", &(oyuncu->uyku), 100, &(oyuncu->can));
                        sleep(2);
                    }
                    else
                    {
                        printf("\n!!! Hatali giris yaptiniz. Lutfen gecerli bir secenek girin. !!!\n");
                        sleep(1);
                    }
                }
                break;
            }

            case 3: 
            {
                printf("\n\n>>>>>>>> Odana dogru ilerleniyor...\n");
                sleep(1);
                
                while (1)
                {
                    ekrani_temizle();
                    sabit_durum_cubugu_yazdir(oyuncu);
                    
                    printf(Ortala"\t\t\t### KALEDEKI ODAN ###\n\n");
                    printf(Ortala"  [0] --> \t\tOdandan Ayril... \t\t  <-- [0]\n");
                    printf(Ortala"  [1] --> \t\tYataginda uyu... \t\t  <-- [1]\n");
                    printf(Ortala"  [2] --> \t\tKiyafetlerini Degistir... \t  <-- [2]\n");
                    printf(Ortala"  [3] --> \t\tDini Rituel Gerceklestir... \t  <-- [3]\n");
                    printf(Ortala"  [4] --> \t\tKarnini Doyur... \t\t  <-- [4]\n");
                    
                    sprintf(buffer, "\n\nTercihin Nedir %s >> ", oyuncu->kahramanin_adi);
                    odana_cik = sayiKontrol(buffer);

                    if (odana_cik == 0)
                    {
                        printf("\n>>>>>>>> Odandan Ayriliyorsun...\n");
                        sleep(1);
                        break;
                    }
                    else if (odana_cik == 1)
                    {
                        printf("\nYataginda huzurlu bir uyku cektin...\n");
                        
                        deger_arttir("UYKU", &(oyuncu->uyku), 100);
                        deger_azalt("TOKLUK", &(oyuncu->tokluk), 5);
                        deger_azalt("SUSUZLUK", &(oyuncu->susuzluk), 5);
                        
                        uyari_fonksiyonu("TOKLUK", &(oyuncu->tokluk), 100, &(oyuncu->can));
                        uyari_fonksiyonu("SUSUZLUK", &(oyuncu->susuzluk), 100, &(oyuncu->can));
                        sleep(2);
                    }
                    else if (odana_cik == 2)
                    {
                        printf("\nKiyafetlerini degistirdin ve daha rahat hissediyorsun...\n");
                        
                        deger_arttir("MUTLULUK", &(oyuncu->mutluluk), 10);
                        deger_arttir("HIJYEN", &(oyuncu->hijyen), 10);
                        deger_azalt("UYKU", &(oyuncu->uyku), 5);
                        
                        uyari_fonksiyonu("MUTLULUK", &(oyuncu->mutluluk), 100, &(oyuncu->can));
                        uyari_fonksiyonu("HIJYEN", &(oyuncu->hijyen), 100, &(oyuncu->can));
                        uyari_fonksiyonu("UYKU", &(oyuncu->uyku), 100, &(oyuncu->can));
                        sleep(2);
                    }
                    else if(odana_cik == 3)
                    {
                        printf("\nDua ettin, artik daha huzurlu hissediyorsun...\n");
                        
                        deger_arttir("INANC", &(oyuncu->inanc), 5);
                        deger_arttir("MUTLULUK", &(oyuncu->mutluluk), 10);
                        sleep(2);
                    }
                    else if(odana_cik == 4)
                    {
                        printf("\nOdanda sicak bir yahni yedin ve bir seyler ictin..\n");
                        
                        deger_arttir("TOKLUK", &(oyuncu->tokluk), 10);
                        deger_arttir("SUSUZLUK", &(oyuncu->susuzluk), 10);
                        sleep(2);
                    }
                    else
                    {
                        printf("\n!!! Hatali giris yaptiniz. Lutfen gecerli bir secenek girin. !!!\n");
                        sleep(1);
                    }
                }
                break;
            }

            case 0: 
                printf("\n\n>>>>>>>> Baslangic Noktasina Geri Donuluyor...\n");
                sleep(1);
                return; 

            default:
                printf("\n\n!!! Hatali giris yaptiniz. Lutfen gecerli bir secenek girin. !!!\n");
                sleep(1);
                break;
        }
    }
}