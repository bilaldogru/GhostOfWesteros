#include "OyunIcerigi.h"
#define Ortala "                                                            " // 60 Boşluk

void menu_kral_topraklari(Karakter *oyuncu)
{
    int kral_topraklari_secimi;
    char buffer[100];

    menu_gecisi_bekleme_fonksiyonu("\nKral Topraklarina Dogru Gidiliyor...", 1);

    while (1)
    {
        ekrani_temizle();
        sabit_durum_cubugu_yazdir(oyuncu);
        
        printf(Ortala"\t\t\t        |#####             |#####\n");
        printf(Ortala"\t\t\t        | ####             | ####\n");
        printf(Ortala"\t\t\t        |#####             |#####\n");
        printf(Ortala"\t\t\t    _  _|_  _           _  _|_  _\n");
        printf(Ortala"\t\t\t   |;|_|;|_|;|         |;|_|;|_|;|\n");
        printf(Ortala"\t\t\t   \\\\. . . /           \\\\. . . /\n");
        printf(Ortala"\t\t\t    \\\\:   /             \\\\:   /\n");
        printf(Ortala"\t\t\t     || ||   /\\    /\\   || ||\n");
        printf(Ortala"\t\t\t     || ||  /  \\  /  \\  || ||\n");
        printf(Ortala"\t\t\t   ..|| || |    ||    | || ||..\n");
        printf(Ortala"\t\t\t   /                          \\\n");
        printf(Ortala"\t\t\t   /      KRAL TOPRAKLARI       \\\n");
        printf(Ortala"\t\t\t   \\______________________________/\n\n\n");

        printf(Ortala"             ??? Kral Topraklarinda Ne Yapmak Istersin %s ??? \n\n", oyuncu->kahramanin_adi);
        printf(Ortala"         [0] == > \tBASLANGIC NOKTASINA GERI DON...\t\t < == [0] \n");
        printf(Ortala"         [1] == > \tYEMEKHANEYE GIT...\t\t\t < == [1] \n");
        printf(Ortala"         [2] == > \tBARA GIT...\t\t\t         < == [2] \n");
        printf(Ortala"         [3] == > \tKUMARHANEYE GIT...\t\t\t < == [3] \n");
        printf(Ortala"         [4] == > \tMEYDANDA SARKI SOYLE...\t\t\t < == [4] \n");
        printf(Ortala"         [5] == > \tKILISEYE GIT... \t\t\t < == [5] \n");
        printf(Ortala"         [6] == > \tKRAL TOPRAKLARINDAKI ODANA CIK... \t < == [6] \n");

        sprintf(buffer, "\n\nLutfen Yapmak Istedigin Aktiviteyi Sec %s : ", oyuncu->kahramanin_adi);
        kral_topraklari_secimi = sayiKontrol(buffer);

        switch (kral_topraklari_secimi)
        {
            case 1: 
            {
                int yemek_secimi;
                printf("\n>>>>>>>> Yemekhaneye Dogru Ilerleniyor...\n");
                sleep(1);
                
                while (1)
                {
                    ekrani_temizle();
                    sabit_durum_cubugu_yazdir(oyuncu);
                    
                    printf(Ortala"\t\t\t\t     ### YEMEKHANE ###\n\n");
                    printf(Ortala"\t        [0] --> \tYemekhaneden Cikis...\t\t  <-- [0]\n");
                    printf(Ortala"\t        [1] --> \tMeyve Ye...  >>  [5]Altin\t  <-- [1]\n");
                    printf(Ortala"\t        [2] --> \tCorba Ic...  >>  [10]Altin\t  <-- [2]\n");
                    printf(Ortala"\t        [3] --> \tBiftek Ye... >>  [15]Altin\t  <-- [3]\n");

                    sprintf(buffer, "\n\nTercihin Nedir %s >> ", oyuncu->kahramanin_adi);
                    yemek_secimi = sayiKontrol(buffer);

                    if (yemek_secimi == 0) 
                    {
                        printf("\n>>>>>>>> Yemekhaneden Ayriliyorsun...\n");
                        sleep(1);
                        break; 
                    } 
                    else if (yemek_secimi == 1)
                    {
                        if (oyuncu->para < 5) 
                        {
                            printf("\n!!! YETERSIZ ALTIN MIKTARI !!!\n");
                        }
                        else 
                        {
                            printf("\nMeyve yediniz. Enerjiniz yenilendi!\n");
                            para_harcama(&(oyuncu->para), 5);
                            deger_arttir("TOKLUK", &(oyuncu->tokluk), 5);
                            uyari_fonksiyonu("TOKLUK", &(oyuncu->tokluk), 100, &(oyuncu->can));
                        }
                    } 
                    else if (yemek_secimi == 2) 
                    {
                        if (oyuncu->para < 10) 
                        {
                            printf("\n!!! YETERSIZ ALTIN MIKTARI !!!\n");
                        } 
                        else 
                        {
                            printf("\nCorba ictiniz. Kendinizi iyi hissediyorsunuz!\n");
                            para_harcama(&(oyuncu->para), 10);
                            deger_arttir("TOKLUK", &(oyuncu->tokluk), 10);
                            uyari_fonksiyonu("TOKLUK", &(oyuncu->tokluk), 100, &(oyuncu->can));
                        }
                    } 
                    else if (yemek_secimi == 3) 
                    {
                        if (oyuncu->para < 15) 
                        {
                            printf("\n!!! YETERSIZ ALTIN MIKTARI !!!\n");
                        } 
                        else 
                        {
                            printf("\nBiftek yediniz. Artik cok daha guclu hissediyorsunuz!\n");
                            para_harcama(&(oyuncu->para), 15);
                            deger_arttir("TOKLUK", &(oyuncu->tokluk), 15);
                            uyari_fonksiyonu("TOKLUK", &(oyuncu->tokluk), 100, &(oyuncu->can));
                        }
                    } 
                    else 
                    {
                        printf("\nHatali giris yaptiniz. Lutfen tekrar deneyin.\n");
                    }
                    sleep(2);
                }
                break;
            }
            case 2: 
            {
                int bar_secimi;
                printf("\n>>>>>>>> Bara Dogru Ilerleniyor...\n");
                sleep(1);
                
                while (1)
                {
                    ekrani_temizle();
                    sabit_durum_cubugu_yazdir(oyuncu);
                    
                    printf(Ortala"\t\t\t\t     ### BAR ###\n\n");
                    printf(Ortala"\t        [0] --> \tBardan Ayril...\t\t\t  <-- [0]\n");
                    printf(Ortala"\t        [1] --> \tBira Ic...   >> [5] Altin\t  <-- [1]\n");
                    printf(Ortala"\t        [2] --> \tSarap Ic...  >> [10] Altin\t  <-- [2]\n");
                    printf(Ortala"\t        [3] --> \tEglenceye Katil ve Dans Et...\t  <-- [3]\n");

                    sprintf(buffer, "\n\nTercihin Nedir %s >> ", oyuncu->kahramanin_adi);
                    bar_secimi = sayiKontrol(buffer);

                    if (bar_secimi == 0) 
                    {
                        printf("\n>>>>>>>> Bardan Ayriliyorsun...\n");
                        sleep(1);
                        break;
                    } 
                    else if (bar_secimi == 1) 
                    {
                        if (oyuncu->para < 5)
                        {
                            printf("\n!!! YETERSIZ ALTIN MIKTARI !!!\n");
                        } 
                        else 
                        {
                            printf("\nBira ictiniz. Rahatladiniz!\n");
                            para_harcama(&(oyuncu->para), 5);
                            deger_arttir("MUTLULUK", &(oyuncu->mutluluk), 10);
                            deger_arttir("SUSUZLUK", &(oyuncu->susuzluk), 30);
                            uyari_fonksiyonu("SUSUZLUK", &(oyuncu->susuzluk), 100, &(oyuncu->can));
                        }
                    } 
                    else if (bar_secimi == 2) 
                    {
                        if(oyuncu->para < 10) 
                        {
                            printf("\n!!! YETERSIZ ALTIN MIKTARI !!!\n");
                        } 
                        else 
                        {
                            printf("\nSarap ictiniz. Kendinizi keyifli hissediyorsunuz!\n");
                            para_harcama(&(oyuncu->para), 10);
                            deger_arttir("SUSUZLUK", &(oyuncu->susuzluk), 50);
                            deger_arttir("MUTLULUK", &(oyuncu->mutluluk), 10);
                            uyari_fonksiyonu("SUSUZLUK", &(oyuncu->susuzluk), 100, &(oyuncu->can));
                        }
                    } 
                    else if (bar_secimi == 3) 
                    {
                        printf("\nDans ettiniz ve eglendiniz!\n");
                        deger_arttir("MUTLULUK", &(oyuncu->mutluluk), 20);
                        deger_azalt("UYKU", &(oyuncu->uyku), 5);
                        uyari_fonksiyonu("UYKU", &(oyuncu->uyku), 100, &(oyuncu->can));
                    } 
                    else 
                    {
                         printf("\nHatali giris yaptiniz. Lutfen tekrar deneyin.\n");
                    }
                    sleep(2);
                }
                break;
            }
            case 3: 
            {
                int kumarhane_secimi, bahis, zar_secimi;
                char degisken[7];
                printf("\n>>>>>>>> Kumarhaneye Dogru Ilerleniyor...\n");
                sleep(1);
                
                while(1) 
                { 
                    ekrani_temizle();
                    sabit_durum_cubugu_yazdir(oyuncu);
                    
                    printf(Ortala"\t\t\t\t  ### KUMARHANE ###\n\n");
                    printf(Ortala"           [0] --> \tKumarhaneden Ayril...\t\t  <-- [0]\n");
                    printf(Ortala"           [1] --> \tRulet Masasina Otur...\t\t  <-- [1]\n");
                    printf(Ortala"           [2] --> \tZar Masasina Otur...\t\t  <-- [2]\n");
                    
                    sprintf(buffer, "\n\nTercihin Nedir %s >> ", oyuncu->kahramanin_adi);
                    kumarhane_secimi = sayiKontrol(buffer);

                    if (kumarhane_secimi == 0) 
                    {
                        printf("\n>>>>>>>> Kumarhaneden Ayriliyorsun...\n");
                        sleep(1);
                        break; 
                    } 
                    else if (kumarhane_secimi == 1) 
                    {
                        if (oyuncu->para < 10) 
                        {
                            printf("\nRulet masasina oturmak icin en az 10 altin gerekiyor!\n");
                            sleep(2);
                            continue; 
                        }
                        
                        printf("\n\n>>>> RULET MASASI <<<<\n\n");
                        printf("0 == > Rulet Masasindan Ayril\n");
                        printf("1 == > Kirmiziya Para Koy\n");
                        printf("2 == > Siyaha Para Koy\n");

                        sprintf(buffer, "\nLutfen Yapmak istedigin islemi sec %s >> ", oyuncu->kahramanin_adi);
                        int rulet_secimi = sayiKontrol(buffer);

                        if (rulet_secimi == 0) 
                        {
                            printf("\nRulet masasindan ayriliyorsunuz...\n");
                            sleep(1);
                            continue; 
                        } 
                        else if (rulet_secimi == 1 || rulet_secimi == 2) 
                        {
                            bahis = sayiKontrol("Lutfen bahis miktarini giriniz: ");
                            if (bahis > oyuncu->para) 
                            {
                                printf("\nYeterli paraniz yok!\n");
                            } 
                            else 
                            {
                                para_ayarlamasi(&(oyuncu->para), &bahis);
                                printf("\n%d altin ile bahis yaptiniz! Cark donuyor...\n", bahis);
                                sleep(2);
                                
                                if (rand() % 2 == 0)
                                { 
                                    para_ayarlamasi2(&(oyuncu->para), &bahis);
                                    strcpy(degisken, (rulet_secimi == 1) ? "Kirmizi" : "Siyah");
                                    printf("Tebrikler! %s Geldi. Yeni bakiyeniz: %d altin\n", degisken, oyuncu->para);
                                    deger_arttir("MUTLULUK", &(oyuncu->mutluluk), 10);
                                } 
                                else
                                { 
                                    strcpy(degisken, (rulet_secimi == 1) ? "Siyah" : "Kirmizi");
                                    printf("%s Geldi. Maalesef kaybettiniz. Yeni bakiyeniz: %d altin\n", degisken, oyuncu->para);
                                    deger_azalt("MUTLULUK", &(oyuncu->mutluluk), 10);
                                }
                                deger_azalt("INANC", &(oyuncu->inanc), 10);
                                uyari_fonksiyonu("MUTLULUK", &(oyuncu->mutluluk), 100, &(oyuncu->can));
                                uyari_fonksiyonu("INANC", &(oyuncu->inanc), 100, &(oyuncu->can));
                            }
                        } 
                        else 
                        {
                            printf("\nHatali giris yaptiniz. Lutfen tekrar deneyin.\n");
                        }
                        sleep(2);
                    } 
                    else if (kumarhane_secimi == 2) 
                    {
                        if (oyuncu->para < 10) 
                        {
                            printf("\nZar masasina oturmak icin en az 10 altin gerekiyor!\n");
                            sleep(2);
                            continue; 
                        }

                        printf("\n\n>>>> ZAR MASASI <<<<\n\n");
                        printf("0 == > Zar Masasindan Ayril\n");
                        printf("1 == > Zar Toplami Cift Secenegi\n");
                        printf("2 == > Zar Toplami Tek Secenegi\n");
                        
                        sprintf(buffer, "\nLutfen Yapmak istedigin islemi sec %s >> ", oyuncu->kahramanin_adi);
                        zar_secimi = sayiKontrol(buffer);

                        if(zar_secimi == 0) 
                        {
                            printf("\nZar masasindan ayriliyorsunuz...\n");
                            sleep(1);
                            continue; 
                        } 
                        else if (zar_secimi == 1 || zar_secimi == 2) 
                        { 
                            bahis = sayiKontrol("Lutfen bahis miktarini giriniz: ");
                            if (bahis > oyuncu->para) 
                            {
                                printf("\nYeterli paraniz yok!\n");
                            } 
                            else 
                            {
                                para_ayarlamasi(&(oyuncu->para), &bahis);
                                int zar1 = rand() % 6 + 1;
                                int zar2 = rand() % 6 + 1;
                                int toplam = zar1 + zar2;
                                printf("\nZarlar atiliyor... %d ve %d geldi! Toplam: %d\n", zar1, zar2, toplam);
                                sleep(2);

                                if ((zar_secimi == 1 && toplam % 2 == 0) || (zar_secimi == 2 && toplam % 2 == 1)) 
                                {
                                    para_ayarlamasi2(&(oyuncu->para), &bahis);
                                    printf("Tebrikler! Kazandiniz! Yeni bakiyeniz: %d altin\n", oyuncu->para);
                                    deger_arttir("MUTLULUK", &(oyuncu->mutluluk), 10);
                                } 
                                else 
                                {
                                    printf("Maalesef kaybettiniz. Yeni bakiyeniz: %d altin\n", oyuncu->para);
                                    deger_azalt("MUTLULUK", &(oyuncu->mutluluk), 10);
                                }
                                deger_azalt("INANC", &(oyuncu->inanc), 10);
                                uyari_fonksiyonu("MUTLULUK", &(oyuncu->mutluluk), 100, &(oyuncu->can));
                                uyari_fonksiyonu("INANC", &(oyuncu->inanc), 100, &(oyuncu->can));
                            }
                        } 
                        else 
                        {
                            printf("\nHatali giris yaptiniz. Lutfen tekrar deneyin.\n");
                        }
                        sleep(2);
                    }
                    else 
                    {
                        printf("\nHatali giris yaptiniz. Lutfen tekrar deneyin.\n");
                        sleep(1);
                    }
                } 
                break;
            }
            case 4: 
            {
                int meydan_secimi;
                printf("\n>>>>>>>> Meydana Dogru Ilerleniyor...\n");
                sleep(1);
                
                while(1)
                {
                    ekrani_temizle();
                    sabit_durum_cubugu_yazdir(oyuncu);
                    
                    printf(Ortala"\t\t\t\t     ### MEYDAN ###\n\n");
                    printf(Ortala"        [0] --> \tMeydandan Ayril...\t\t\t  <-- [0]\n");
                    printf(Ortala"        [1] --> \t%s'i kullanarak sarki soyle...\t  <-- [1]\n", oyuncu->kahramanin_calgisi);
                    printf(Ortala"        [2] --> \t%s'i kullanmadan sarki soyle...\t  <-- [2]\n", oyuncu->kahramanin_calgisi);
                    
                    sprintf(buffer, "\n\nTercihin Nedir %s >> ", oyuncu->kahramanin_adi);
                    meydan_secimi = sayiKontrol(buffer);

                    if (meydan_secimi == 0) 
                    {
                        printf("\n>>>>>>>> Meydandan Ayriliyorsun...\n");
                        sleep(1);
                        break;
                    } 
                    else if (meydan_secimi == 1) 
                    {
                        printf("\nMeydanda %s ile harika bir sarki soyledin!\n", oyuncu->kahramanin_calgisi);
                        para_kazanma(oyuncu->karizma, oyuncu->hijyen, 1, &(oyuncu->para));
                        deger_arttir("XP", &(oyuncu->xp), 20);
                        deger_arttir("MUTLULUK", &(oyuncu->mutluluk), 10);
                    } 
                    else if (meydan_secimi == 2)
                    {
                        printf("\nMeydanda sesinle sarki soyledin!\n");
                        para_kazanma(oyuncu->karizma, oyuncu->hijyen, 0, &(oyuncu->para));
                        deger_arttir("XP", &(oyuncu->xp), 15);
                        deger_arttir("MUTLULUK", &(oyuncu->mutluluk), 5);
                    } 
                    else 
                    {
                        printf("\nHatali giris yaptiniz. Lutfen tekrar deneyin.\n");
                    }
                    sleep(2);
                }
                break;
            }
            case 5: 
            {
                int kilise_secimi;
                printf("\n>>>>>>>> Kiliseye Dogru Ilerleniyor...\n");
                sleep(1);
                
                while(1)
                {
                    ekrani_temizle();
                    sabit_durum_cubugu_yazdir(oyuncu);
                    
                    printf(Ortala"\t\t\t\t     ### KILISE ###\n\n");
                    printf(Ortala"        [0] --> \tKiliseden Ayril...\t\t\t  <-- [0]\n");
                    printf(Ortala"        [1] --> \tDua Et...\t\t\t\t  <-- [1]\n");
                    
                    sprintf(buffer, "\n\nTercihin Nedir %s >> ", oyuncu->kahramanin_adi);
                    kilise_secimi = sayiKontrol(buffer);

                    if(kilise_secimi == 0) 
                    {
                        printf("\n>>>>>>>> Kiliseden Ayriliyorsun...\n");
                        sleep(1);
                        break;
                    } 
                    else if (kilise_secimi == 1) 
                    {
                        printf("\nDua Ettin.. Artik Daha Huzurlu Hissediyorusun...\n");
                        deger_arttir("INANC", &(oyuncu->inanc), 10);
                        deger_arttir("MUTLULUK", &(oyuncu->mutluluk), 10);
                    }
                    else 
                    {
                        printf("\nHatali giris yaptiniz. Lutfen tekrar deneyin.\n");
                    }
                    sleep(2);
                }
                break;
            }
            case 6: // Oda
            {
                int odana_cik;
                printf("\n>>>>>>>> Kral Kalesindeki Odana dogru ilerleniyor...\n");
                sleep(1);
                
                while (1)
                {
                    ekrani_temizle();
                    sabit_durum_cubugu_yazdir(oyuncu);
                    
                    printf(Ortala"\t\t\t\t     ### KRAL KALESINDEKI ODAN ###\n\n");
                    printf(Ortala"\t\t      [0] --> \tOdandan Ayril... \t\t  <-- [0]\n");
                    printf(Ortala"\t\t      [1] --> \tYataginda uyu... \t\t  <-- [1]\n");
                    printf(Ortala"\t\t      [2] --> \tKiyafetlerini Degistir... \t  <-- [2]\n");
                    printf(Ortala"\t\t      [3] --> \tDini Rituel Gerceklestir... \t  <-- [3]\n");
                    printf(Ortala"\t\t      [4] --> \tKarnini Doyur... \t\t  <-- [4]\n");
                    
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
                        printf("\nDua ettin, Artik daha rahat hissediyorsun...\n");
                        deger_arttir("INANC", &(oyuncu->inanc), 5);
                        deger_arttir("MUTLULUK", &(oyuncu->mutluluk), 10);
                        sleep(2);
                    }
                    else if(odana_cik == 4)
                    {
                        printf("\nOdanda sicak bir yahni yedin ve biraz sarap ictin..\n");
                        deger_arttir("TOKLUK", &(oyuncu->tokluk), 10);
                        deger_arttir("SUSUZLUK", &(oyuncu->susuzluk), 10);
                        sleep(2);
                    }
                    else
                    {
                        printf("\n!!! Hatali giris yaptiniz. Lutfen gecerli bir secim yapin. !!!\n");
                        sleep(1);
                    }
                }
                break; 
            }
            case 0:
                printf("\n>>>>>>>> Baslangic Noktasina Geri Donuluyor...\n");
                sleep(1);
                return; 
                
            default:
                printf("\n!!! Hatali giris yaptiniz. Lutfen tekrar deneyin.\n");
                sleep(1);
                break;
        } 
    } 
}