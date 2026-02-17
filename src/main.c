#include "OyunIcerigi.h"
#include <string.h> 
#include <time.h>   

#define Ortala "                                                            " // 60 Bosluk

int main()
{
    Karakter oyuncu = {0}; 
    int oyun_calisiyor = 1; 
    int yapilacak_aktivite = 0;
    int baslangic_secimi = 0; 
    char buffer[100]; 

    srand(time(NULL));

    if (load_game(&oyuncu) == 1)
    {
        printf("\n\n>>> Kayitli bir oyun bulundu: Savasci %s (Seviye %d)! <<<\n\n", oyuncu.kahramanin_adi, oyuncu.seviye);
        printf("[1] == > \tKAYITLI OYUNDAN DEVAM ET\t\t < == [1] \n");
        printf("[2] == > \tYENI OYUN BASLAT (Eski kayit silinir)\t < == [2] \n");
        
        baslangic_secimi = sayiKontrol("\nLutfen seciminizi yapin [1] veya [2]: ");

        if (baslangic_secimi == 1)
        {   
            menu_gecisi_bekleme_fonksiyonu("Kayitli Oyun Yukleniyor...", 2);
            printf("\n\n>>> Kayitli oyun basariyla yuklendi! <<<\n");
            printf("Tekrar hos geldin, %s!\n", oyuncu.kahramanin_adi);
            sleep(2);
        }
        else
        {
            baslangic_secimi = 2; 
            printf("\nKayitli oyun verileri uzerine yazilacak. Yeni oyun baslatiliyor...\n");
            menu_gecisi_bekleme_fonksiyonu("Yeni Oyun Hazirlaniyor...", 2);
            sleep(1);
        }
    }
    else
    {
        printf("\nKayitli oyun bulunamadi. Yeni oyun baslatiliyor...\n");
        menu_gecisi_bekleme_fonksiyonu("Yeni Oyun Hazirlaniyor...", 2);
        sleep(1);
        baslangic_secimi = 2; 
    }

    if (baslangic_secimi == 2)
    {
        oyun_hikayesi();
        memset(&oyuncu, 0, sizeof(oyuncu)); 
        gorev_kuyrugunu_baslat(&oyuncu);
        
        oyuncu.seviye = 1;
        oyuncu.xp = 0;
        oyuncu.can = 100;
        oyuncu.tokluk = 100;
        oyuncu.uyku = 100;
        oyuncu.susuzluk = 100;
        oyuncu.mutluluk = 100;
        oyuncu.hijyen = 100;
        oyuncu.inanc = 100;
        oyuncu.para = 20;
        oyuncu.guc = 2;
        oyuncu.ceviklik = 2;
        oyuncu.dayaniklilik = 2;
        oyuncu.karizma = 2;
        oyuncu.toplayicilik = 2;
        oyuncu.yukseltme_miktari = 0;
        
        oyuncu.envanter = NULL; 
        oyuncu.envanter_eşya_sayisi = 0;

        ekrani_temizle();
        printf("\n\n\n\n");
        printf(Ortala" ***** GHOST OF WESTEROS ***** \n\n");
        printf(Ortala" !!! Oyuna Hosgeldin Savasci !!!\n\n");

        printf(Ortala"Kendine Bir Isim Belirle Savasci : ");
        fgets(oyuncu.kahramanin_adi, sizeof(oyuncu.kahramanin_adi), stdin);
        oyuncu.kahramanin_adi[strcspn(oyuncu.kahramanin_adi, "\n")] = 0; 

        printf(Ortala"Kendine Bir Calgi Aleti Belirle *** %s *** : ", oyuncu.kahramanin_adi);
        fgets(oyuncu.kahramanin_calgisi, sizeof(oyuncu.kahramanin_calgisi), stdin);
        oyuncu.kahramanin_calgisi[strcspn(oyuncu.kahramanin_calgisi, "\n")] = 0;

        menu_gecisi_bekleme_fonksiyonu("!!! Bilgileriniz Isleniyor Lutfen Bekleyiniz !!!", 2);
        printf("\n\n" Ortala ">>>  ...MACERA BASLIYOR... <<< ");
        sleep(2);
        printf("\n\n\n" Ortala " ***** Westeros Evrenine Hosgeldin %s *****\n\n\n ", oyuncu.kahramanin_adi);
        sleep(2);
    }

    while (oyun_calisiyor)
    {
        ekrani_temizle();
        sabit_durum_cubugu_yazdir(&oyuncu); 

        printf("\n");
        printf(Ortala"       _______________________________________________________________\n");
        printf(Ortala"      /                                                               \\\n");
        printf(Ortala"     |       ??? Westeros Dunyasinda Ne Yapmak Istersin Savasci ???    |\n");
        printf(Ortala"     |_________________________________________________________________|\n");
        printf(Ortala"     |                                                                 |\n");
        printf(Ortala"     |   [1] WINTERFELL KALESINE GIT                                   |\n");
        printf(Ortala"     |   [2] HAN KALESINE GIT                                          |\n");
        printf(Ortala"     |   [3] KRAL TOPRAKLARINA GIT                                     |\n");
        printf(Ortala"     |   [4] WESTEROS DUNYASINI KESFE CIK                              |\n");
        printf(Ortala"     |   [5] KARANLIK ZINDANA GIR                                      |\n"); 
        printf(Ortala"     |   [6] GOREVLERI GOSTER                                          |\n");
        printf(Ortala"     |   [7] KARAKTER GELISTIRME                                       |\n");
        printf(Ortala"     |   [8] OZELLIKLERINI GOSTER                                      |\n");
        printf(Ortala"     |   [9] CANTAYI AC (Envanter)                                     |\n"); 
        printf(Ortala"     |   [10] OYUNU KAYDET                                             |\n");
        printf(Ortala"     |   [11] OYUNDAN CIK                                              |\n");
        printf(Ortala"      \\_______________________________________________________________/\n");

        sprintf(buffer, "\n\nLutfen Yapmak Istedigin Aktiviteyi Sec %s : ", oyuncu.kahramanin_adi);
        yapilacak_aktivite = sayiKontrol(buffer);

        switch (yapilacak_aktivite)
        {
            case 1:
                menu_winterfell(&oyuncu);
                break;
            case 2:
                menu_han(&oyuncu);
                break;
            case 3:
                menu_kral_topraklari(&oyuncu);
                break;
            case 4:
                menu_kesif(&oyuncu);
                break;
            case 5: 
                menu_zindan(&oyuncu);
                break;
            case 6: 
                menu_gorevler(&oyuncu);
                break;
            case 7:
                menu_gelistirme(&oyuncu);
                break;
            case 8:
                menu_ozellikler(&oyuncu);
                break;
            case 9: 
                menu_canta(&oyuncu);
                break;
            case 10: 
                save_game(&oyuncu);
                printf("\n\n" Ortala ">>> OYUN BASARIYLA KAYDEDILDI <<<\n");
                sleep(2);
                break;
            case 11: 
                save_game(&oyuncu);
                printf("\n\n" Ortala ">>> OYUN BASARIYLA KAYDEDILDI <<<\n");
                sleep(2);
                printf("\n\n" Ortala ">>> Oyundan Cikiliyor... Macera Seni Bekleyecek! <<<\n");
                oyun_calisiyor = 0; 
                break;
            default:
                printf("\n\n" Ortala " !!!!!!! HATALI SECIM... LUTFEN TEKRAR DENE !!!!!!!\n");
                sleep(2);
                break;
        }

        if (oyuncu.can <= 0)
        {
            ekrani_temizle();
            printf("\n\n\n\n");
            printf(Ortala"         (  .      )\n");
            printf(Ortala"           )          (              )\n");
            printf(Ortala"                .  '   .   '  .  '  .\n");
            printf(Ortala"        (    , )       (.   )  (   ',    )\n");
            printf(Ortala"         .' ) ( . )    ,  ( ,     )   ( .\n");
            printf(Ortala"      ). _ ( .   (   ) . (   ) . (   )  \n");
            printf(Ortala"     (_ )_ )._ ) _).  ( _ ) .( _) _)\n");
            printf(Ortala"                                   \n");
            printf(Ortala"     ***** ----- MAALESEF OLDUNUZ ----- ***** \n");
            printf(Ortala"      Westeros topragi bir savasciyi daha yuttu...\n\n");
            
            printf("\n" Ortala "Kulleriinden dogup tekrar savasmak ister misin?\n");
            printf(Ortala "[1] EVET (Yeniden Basla - Ayni Isimle)\n");
            printf(Ortala "[0] HAYIR (Oyunu Kapat)\n");

            int devam_secimi = sayiKontrol("\n" Ortala "Secimin Nedir Savasci? >> ");

            if (devam_secimi == 1)
            {
                printf("\n" Ortala ">>> Isik Tanrisi sana ikinci bir sans veriyor... Uyan Savasci! <<<\n");
                sleep(2);

                char yedek_isim[30];
                char yedek_calgi[30];
                strcpy(yedek_isim, oyuncu.kahramanin_adi);
                strcpy(yedek_calgi, oyuncu.kahramanin_calgisi);

                memset(&oyuncu, 0, sizeof(oyuncu));

                strcpy(oyuncu.kahramanin_adi, yedek_isim);
                strcpy(oyuncu.kahramanin_calgisi, yedek_calgi);

                oyuncu.seviye = 1;
                oyuncu.xp = 0;
                oyuncu.can = 100;      
                oyuncu.tokluk = 100;
                oyuncu.uyku = 100;
                oyuncu.susuzluk = 100;
                oyuncu.mutluluk = 100;
                oyuncu.hijyen = 100;
                oyuncu.inanc = 100;
                oyuncu.para = 20;
                oyuncu.guc = 2;
                oyuncu.ceviklik = 2;
                oyuncu.dayaniklilik = 2;
                oyuncu.karizma = 2;
                oyuncu.toplayicilik = 2;
                
            
                oyuncu.envanter = NULL; 
                gorev_kuyrugunu_baslat(&oyuncu); 

            
            }
            else
            {
                printf("\n" Ortala ">>> Huzur icinde uyu... Macera bitti. <<<\n");
                sleep(2);
                oyun_calisiyor = 0; 
            }
        }

        if (oyuncu.xp >= 100 && yapilacak_aktivite != 6 && oyun_calisiyor)
        {
            printf("\n" Ortala ">>> DIKKAT: XP PUANINIZ 100 OLDU! TERFI ALABILIRSINIZ! <<<\n");
            sleep(2);
        }
    } 

    printf("\n\n" Ortala "***** OYUN BITTI. ***** \n\n\n");
    return 0;
}