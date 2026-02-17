#include "OyunIcerigi.h"
#include <ctype.h>
#include <time.h>
#include <windows.h> 
#define Ortala "                                                            "

int sayiKontrol(char* mesaj) 
{
    int secim;
    int sonuc;
    while(1) 
    {
        printf("%s", mesaj);
        sonuc = scanf("%d", &secim);
        if (sonuc == 1) 
        {
            while(getchar() != '\n'); 
            return secim;
        }
        else
        {
            printf("Gecersiz giris! Lutfen bir sayi girin.\n");
            while(getchar() != '\n');
        }
    }
}

#define ORTALA "                                                            " // 60 Boşluk
void menu_gecisi_bekleme_fonksiyonu(char* mesaj, int saniye)
{
    int genislik = 30; 
    int adim_sayisi = 50; 
    int bekleme_suresi = (saniye * 1000) / adim_sayisi;

    printf("\n" ORTALA "     %s\n", mesaj);

    for (int i = 0; i <= adim_sayisi; i++) {
        float oran = (float)i / adim_sayisi;
        int doluluk = oran * genislik;

        printf("\r" ORTALA "     \033[1;32m["); 
        
        for (int j = 0; j < genislik; j++) {
            if (j < doluluk) printf("■");
            else printf(" ");
        }
        
        printf("] %%%.0f\033[0m", oran * 100);
        fflush(stdout);
        SLEEP_MS(bekleme_suresi);
    }
    printf("\n" ORTALA "\t\t\t\033[1;34mTamamlandi!\033[0m\n\n");
}

void durum_cubugu_gosterim_fonksiyonu(char* durum_adi, int deger, int max_deger)
{
    int toplam_uzunluk = 10;
    int parca_sayisi = (deger * toplam_uzunluk) / max_deger;
    int bos_parca = toplam_uzunluk - parca_sayisi;

    printf("\t\t\t\t\t%-15s >> %3d/%d  [", durum_adi, deger, max_deger);
    for (int i = 0; i < parca_sayisi; i++)
    {
        printf("■");
    }
    for (int i = 0; i < bos_parca; i++)
    {
        printf(" ");
    }
    printf("]\n");
}

void uyari_fonksiyonu(char* durum_adi, int *deger, int max_deger, int *can)
{
    if (*deger >= (max_deger * 30 / 100)) return; 

    if (*deger <= 0)
    {
        *deger = 0; 
        int hasar = 0;

        if (strcmp(durum_adi, "TOKLUK") == 0) hasar = 20;
        else if (strcmp(durum_adi, "SUSUZLUK") == 0) hasar = 15;
        else if (strcmp(durum_adi, "UYKU") == 0) hasar = 10;
        else if (strcmp(durum_adi, "MUTLULUK") == 0) hasar = 10;
        else if (strcmp(durum_adi, "INANC") == 0) hasar = 5;
        else if (strcmp(durum_adi, "HIJYEN") == 0) hasar = 5;

        if (hasar > 0)
        {
            *can -= hasar;
            printf("\n\033[1;31m[KRITIK DURUM]: %s sifirlandi! Canindan %d kaybettin! (Kalan Can: %d)\033[0m\n", durum_adi, hasar, *can);
        }
    }
    else 
    {
        printf("\n\033[1;33m[UYARI]: %s durumu kritik seviyede! (%d/%d)\033[0m\n", durum_adi, *deger, max_deger);
    }
}

void beceri_cubugu_gosterim_fonksiyonu(char* beceri_adi, int deger, int max_deger, int artis)
{
    int toplam_uzunluk = 10;
    int parca_sayisi = (deger * toplam_uzunluk + artis) / max_deger;
    int bos_parca = toplam_uzunluk - parca_sayisi;

    printf(ORTALA"\t\t\t\t\t%-15s >> %2d/%d  [", beceri_adi, deger + artis, max_deger);
    for (int i = 0; i < parca_sayisi; i++)
    {
        printf("#");
    }
    for (int i = 0; i < bos_parca; i++)
    {
        printf(" ");
    }
    printf("]\n");
}

void para_kazanma(int karizma, int hijyen, int muzik_aleti, int *para_miktari)
{
    int kazanc = 0;

    if (muzik_aleti)
    {
        kazanc = 10 + (karizma * hijyen) / 100;
    }
    else
    {
        kazanc = 5 + (karizma * hijyen) / 100;
    }

    *para_miktari += kazanc;
    printf("\n\nKazandigin  Altin: %d\n", kazanc);
    printf("Sahip Oldugun Altin: %d\n", *para_miktari);
}

void para_harcama(int *para_miktari, int harcamaMiktari)
{
    *para_miktari -= harcamaMiktari;
    printf("Kalan Altin Miktari : %d\n\n", *para_miktari);
}

void deger_arttir(char* durum_adi, int* deger, int artis_miktari)
{
    *deger += artis_miktari;
    if (*deger > 100)
    {
        *deger = 100;
    }
}

void deger_azalt(char* durum_adi, int* deger, int azalis_miktari)
{
    *deger -= azalis_miktari;
    if (*deger < 0)
    {
        *deger = 0;
    }
}

void ekrani_temizle()
{
    #ifdef _WIN32
        system("cls"); 
    #else
        system("clear"); 
    #endif
}

void sabit_durum_cubugu_yazdir(Karakter *oyuncu)
{
    printf(ORTALA"==================================================================================\n");
    printf(ORTALA" KAHRAMAN: %-12s | CAN: %-3d | ALTIN: %-4d | XP: %-4d \n", 
           oyuncu->kahramanin_adi, oyuncu->can, oyuncu->para, oyuncu->xp);
    printf(ORTALA" TOKLUK: %-3d | SU: %-3d | UYKU: %-3d | MUTLULUK: %-3d | HIJYEN: %-3d | INANC: %-3d\n", 
           oyuncu->tokluk, oyuncu->susuzluk, oyuncu->uyku, oyuncu->mutluluk, oyuncu->hijyen, oyuncu->inanc);
    printf(ORTALA"==================================================================================\n\n");
}

void para_ayarlamasi(int *para_miktari, int *bahis)
{
    *para_miktari -= *bahis;
    printf("Kalan Altin Miktari : %d\n", *para_miktari);
}

void para_ayarlamasi2(int *para_miktari, int *bahis)
{
    *para_miktari += *bahis * 2;
}

void para_ayarlamasi3(int *para_miktari, int *kazanc)
{
    *para_miktari += *kazanc;
}

void savas(Karakter *oyuncu, int dusman_guc, int dusman_ceviklik, int dusman_dayaniklilik, int dusman_can_max, char* dusman_adi, int xp_odul, int altin_odul)
{
    int dusman_can = dusman_can_max;
    int ganimet;
    char buffer[100];
    DWORD baslangic, bitis; 
    double gecen_sure;
    char hedef_harf, girilen_harf;

    printf("\n\n>>>>>>>> SAVAS BASLIYOR! <<<<<<<<\n");
    sleep(2);

    while (oyuncu->can > 0 && dusman_can > 0)
    {
        ekrani_temizle();
        sabit_durum_cubugu_yazdir(oyuncu);

        printf(Ortala"\t\t\t========================================\n");
        printf(Ortala"\t\t\t           DUSMAN: %s\n", dusman_adi);
        printf(Ortala"\t\t\t   Can: %d/%d  |  Guc: %d  |  Ceviklik: %d\n", dusman_can, dusman_can_max, dusman_guc, dusman_ceviklik);
        printf(Ortala"\t\t\t========================================\n\n");

        printf(Ortala"\t\t\t\t[1] SALDIR (Risk Al)\n");
        printf(Ortala"\t\t\t\t[2] KAC (Tabanlari Yagla)\n");
        printf(Ortala"\t\t\t\t[3] CANTAYI AC (Iksir Ic)\n");

        int secim = sayiKontrol("\n\nKararin Nedir Savasci? >> ");
        
        if (secim == 1) 
        {
            hedef_harf = 'A' + (rand() % 26);
            
            printf("\n\n" Ortala "\t\t\t\t\t>>> SALDIRI ZAMANI! <<<\n");

            printf(Ortala "\t\t\t2.5 saniye icinde [ %c ] harfine bas ve ENTER'la!\n", hedef_harf);
            
            fflush(stdin); 

            baslangic = GetTickCount(); 
            scanf(" %c", &girilen_harf);
            bitis = GetTickCount();
            
            gecen_sure = (double)(bitis - baslangic) / 1000.0;
            girilen_harf = toupper(girilen_harf);

            int temel_hasar = 3 * oyuncu->guc; 
            int vurulan_hasar = 0;

            if (girilen_harf == hedef_harf)
            {
                if (gecen_sure <= 1.0)
                {
                    vurulan_hasar = (int)(temel_hasar * 1.5);
                    printf("\n" Ortala "\t\t\t\033[1;32m>>> EFSANEVI VURUS! (Sure: %.2fs) <<<\033[0m\n", gecen_sure);
                }
                else if (gecen_sure <= 2.5) 
                {
                    vurulan_hasar = temel_hasar;
                    printf("\n" Ortala "\t\t\t>>> Basarili vurus. (Sure: %.2fs) <<<\n", gecen_sure);
                }
                else
                {
                    vurulan_hasar = 0; 

                    int kendine_hasar = (oyuncu->can > 10) ? (oyuncu->can / 10) : 1; 
                    oyuncu->can -= kendine_hasar;
                    printf("\n" Ortala "\t\t\033[1;31m>>> COK YAVAS KALDIN! DENGEYI KAYBETTIN! (-%d Can) (Sure: %.2fs) <<<\033[0m\n", kendine_hasar, gecen_sure);
                    if(oyuncu->can <= 0) break; 
                }
            }
            else
            {
                vurulan_hasar = 0;
                printf("\n" Ortala "\t\t\t\033[1;31m>>> YANLIS TUS! ISKALADIN! <<<\033[0m\n");
            }

            if (vurulan_hasar > 0)
            {
                int zirh_etkisi = (int)(dusman_dayaniklilik / 2);
                int net_hasar = vurulan_hasar - zirh_etkisi;
                
                if (net_hasar < 1) net_hasar = 1; 

                dusman_can -= net_hasar;
                printf(Ortala "\t\t\t>>> %s'e %d hasar verdin!\n", dusman_adi, net_hasar);
            }
            sleep(1);
        }
        else if (secim == 2)
        {
            int kacma_ihtimali = (3 * oyuncu->ceviklik) - dusman_ceviklik; 
            if (kacma_ihtimali < 10) kacma_ihtimali = 10; 

            if ((rand() % 100) < kacma_ihtimali)
            {
                printf("\n\n" Ortala "\t\t\t>>> Zar zor kacmayi basardiniz! <<<\n");
                sleep(2);
                return; 
            }
            else
            {
                printf("\n\n" Ortala "\t\t\t>>> Kacma basarisiz! Dusman ensene yapisti!\n");
                sleep(1);
            }
        }
        else if (secim == 3)
        {
            int esya_kullanildi_mi = menu_canta(oyuncu);
            
            if (esya_kullanildi_mi == 1)
            {
                printf("\n" Ortala "\t\t\t>>> Esya kullandigin icin siran gecti!\n");
                sleep(1);
            }
            else
            {
                continue; 
            }
        }

        if (dusman_can > 0)
        {
            printf("\n\n" Ortala "\t\t\t\t\t!!! DUSMAN SALDIRIYOR !!!\n");
            
            hedef_harf = 'A' + (rand() % 26); 
            
            printf(Ortala "\t\t\t\tKORUNMAK ICIN 1.5 SN ICINDE [ %c ] TUSUNA BAS!\n", hedef_harf);
            
            fflush(stdin);

            baslangic = GetTickCount();
            scanf(" %c", &girilen_harf);
            bitis = GetTickCount();
            
            gecen_sure = (double)(bitis - baslangic) / 1000.0;
            girilen_harf = toupper(girilen_harf);
            
            int dusman_temel_saldiri = 5 * dusman_guc;
            int alinan_hasar = 0;

            if (girilen_harf == hedef_harf && gecen_sure <= 1.5)
            {
                printf("\n" Ortala "\t\t\t\033[1;34m>>> BLOKLADIN! (Ama darbe agirdi) (Sure: %.2fs) <<<\033[0m\n", gecen_sure);
                
                int zirh_etkisi = (int)(oyuncu->dayaniklilik); 
                alinan_hasar = (int)(dusman_temel_saldiri * 0.4) - (zirh_etkisi / 2);
            }
            else
            {
                if (girilen_harf != hedef_harf)
                     printf("\n" Ortala "\t\t\t\033[1;31m>>> YANLIS TUS! SAVUNMA YOK! <<<\033[0m\n");
                else
                     printf("\n" Ortala "\t\t\t\033[1;31m>>> COK YAVASSIN! TAM DARBE ALDIN! (Sure: %.2fs) <<<\033[0m\n", gecen_sure);
                
                alinan_hasar = dusman_temel_saldiri - (int)(oyuncu->dayaniklilik / 5);
            }

            if (alinan_hasar < 1) alinan_hasar = 1; 

            oyuncu->can -= alinan_hasar;
            printf(Ortala "\t\t\t>>> %s size %d hasar verdi! (Kalan Can: %d)\n", dusman_adi, alinan_hasar, oyuncu->can);
            sleep(2);
        }
    } 

    if (oyuncu->can <= 0)
    {
        ekrani_temizle();
        printf("\n\n\n");
        printf(Ortala"\t\t\t%s size son darbeyi indirdi...\n", dusman_adi);
        printf(Ortala"\t\t\tGozlerin karariyor... Macera burada sona erdi.\n\n\n");
        sleep(3);
    }
    else if (dusman_can <= 0)
    {
        ganimet = altin_odul + (rand() % 11); 
        ekrani_temizle();
        sabit_durum_cubugu_yazdir(oyuncu);
        
        printf(Ortala"\t\t\t   *** ZAFER SENIN SAVASCI! ***\n\n");
        printf(Ortala"\t\t\t%s cansiz bedeni yere yigildi.\n", dusman_adi);
        printf(Ortala"\t\t\tKazanilan Ganimet: %d Altin\n", ganimet);
        printf(Ortala"\t\t\tKazanilan Deneyim: +%d XP\n", xp_odul);
        
        para_ayarlamasi3(&(oyuncu->para), &ganimet);
        deger_arttir("XP", &(oyuncu->xp), xp_odul);
        deger_arttir("MUTLULUK", &(oyuncu->mutluluk), 20);
        
        deger_azalt("TOKLUK", &(oyuncu->tokluk), 10);
        deger_azalt("SUSUZLUK", &(oyuncu->susuzluk), 10);
        
        sleep(3);
        uyari_fonksiyonu("TOKLUK", &(oyuncu->tokluk), 100, &(oyuncu->can));
        uyari_fonksiyonu("SUSUZLUK", &(oyuncu->susuzluk), 100, &(oyuncu->can));
    }
}

void dukkan_listesine_ekle(Esya **baslangic, int id, char *ad, int fiyat, int etki, int tur)
{
    Esya *yeni_esya = (Esya*)malloc(sizeof(Esya));
    
    yeni_esya->id = id;
    strcpy(yeni_esya->ad, ad);
    yeni_esya->fiyat = fiyat;
    yeni_esya->etki_degeri = etki;
    yeni_esya->tur = tur;
    yeni_esya->sonraki = NULL;

    if (*baslangic == NULL)
    {
        *baslangic = yeni_esya;
    }
    else
    {
        Esya *gecici = *baslangic;
        while (gecici->sonraki != NULL)
        {
            gecici = gecici->sonraki;
        }
        gecici->sonraki = yeni_esya;
    }
}

void dukkani_yazdir(Esya *baslangic)
{
    Esya *gecici = baslangic;
    while (gecici != NULL)
    {
        char *ozellik = (gecici->tur == 1) ? "Hasar" : "Can/Etki";
        printf(Ortala " [%d] %-20s >> Fiyat: %3d Altin | %s: +%d\n", 
               gecici->id, gecici->ad, gecici->fiyat, ozellik, gecici->etki_degeri);
        gecici = gecici->sonraki;
    }
}

void dukkani_temizle(Esya *baslangic)
{
    Esya *gecici;
    while (baslangic != NULL)
    {
        gecici = baslangic;
        baslangic = baslangic->sonraki;
        free(gecici);
    }
}


void envantere_ekle(Karakter *oyuncu, Esya *alinan_esya)
{

    Esya *yeni_esya = (Esya*)malloc(sizeof(Esya));
    
    if (yeni_esya == NULL) 
    {
        printf("Hata: Bellek dolu!\n");
        return;
    }

    yeni_esya->id = oyuncu->envanter_eşya_sayisi;
    strcpy(yeni_esya->ad, alinan_esya->ad);
    yeni_esya->fiyat = alinan_esya->fiyat;
    yeni_esya->etki_degeri = alinan_esya->etki_degeri;
    yeni_esya->tur = alinan_esya->tur;
    yeni_esya->sonraki = NULL; 

    if (oyuncu->envanter == NULL)
    {
        oyuncu->envanter = yeni_esya;
    }
    else
    {
        Esya *gecici = oyuncu->envanter;
        while (gecici->sonraki != NULL)
        {
            gecici = gecici->sonraki;
        }
        gecici->sonraki = yeni_esya;
    }
}
int esya_kullan_ve_sil(Karakter *oyuncu)
{
    Esya *gecici = oyuncu->envanter;
    Esya *onceki = NULL;

    while (gecici != NULL)
    {
        if (gecici->id == oyuncu->envanter_eşya_sayisi)
        {
            if (gecici->tur == 2)
            {
                if (strstr(gecici->ad, "Sifa") != NULL) 
                {
                    printf("\n" Ortala ">>> %s ictin! Canin +%d artti.\n", gecici->ad, gecici->etki_degeri);
                    deger_arttir("CAN", &(oyuncu->can), gecici->etki_degeri);
                }
                else if (strstr(gecici->ad, "Guc") != NULL)
                {
                    printf("\n" Ortala ">>> %s ictin! Gucun +%d artti.\n", gecici->ad, gecici->etki_degeri);
                    deger_arttir("GUC", &(oyuncu->guc), gecici->etki_degeri);
                }
                else if (strstr(gecici->ad, "Hiz") != NULL || strstr(gecici->ad, "Golge") != NULL)
                {
                    printf("\n" Ortala ">>> %s ictin! Cevikligin +%d artti.\n", gecici->ad, gecici->etki_degeri);
                    deger_arttir("CEVIKLIK", &(oyuncu->ceviklik), gecici->etki_degeri);
                }

                if (onceki == NULL) oyuncu->envanter = gecici->sonraki;
                else onceki->sonraki = gecici->sonraki;
                oyuncu->envanter_eşya_sayisi--;
                free(gecici);
                return 1;
            }
            else
            {
                printf("\n" Ortala ">>> Bu esya (Silah/Zirh) su an kullanilamaz!\n");
                sleep(1);
                return 0; 
            }
        }
        onceki = gecici;
        gecici = gecici->sonraki;
    }
    printf("\n" Ortala ">>> Cantada boyle bir esya yok!\n");
    sleep(1);
    return 0; 
}

int menu_canta(Karakter *oyuncu)
{
    while(1)
    {
        ekrani_temizle();
        
        printf(Ortala "      .---.\n");
        printf(Ortala "     /     \\\n");
        printf(Ortala "     | (|) |   --- HIZLI ENVANTER ---\n");
        printf(Ortala "    /`-----'\\\n");
        printf(Ortala "   /_________\\\n\n");

        if (oyuncu->envanter == NULL)
        {
            printf(Ortala ">>> Cantaniz bos!\n\n");
            printf(Ortala " [0] Geri Don\n");
            int secim = sayiKontrol("\nSecim: ");
            return 0; 
        }
        else
        {
            Esya *gecici = oyuncu->envanter;
            
            printf(Ortala "%-5s %-20s %-15s\n", "NO", "ESYA ADI", "ETKI");
            printf(Ortala "-------------------------------------------\n");
            
            while (gecici != NULL)
            {
                printf(Ortala "[%d]   %-20s (+%d)\n", gecici->id, gecici->ad, gecici->etki_degeri);
                gecici = gecici->sonraki;
            }
            
            printf("\n\n" Ortala " [0] Geri Don (Hicbir sey kullanma)\n");
            printf(Ortala " Kullanmak istediginiz esyanin ID numarasini girin: ");
            
            int secim;
            scanf("%d", &secim);
            
            if (secim == 0) return 0; 
            
            if (esya_kullan_ve_sil(oyuncu) == 1)
            {
                sleep(1);
                return 1; 
            }
        }
    }
}

YonNode* yigina_ekle(YonNode *tepe, int yon)
{
    YonNode *yeni_node = (YonNode*)malloc(sizeof(YonNode));
    if (yeni_node == NULL) return tepe; 

    yeni_node->yon = yon;
    yeni_node->sonraki = tepe; 
    
    return yeni_node; 
}

YonNode* yigindan_cikar(YonNode *tepe, int *cikan_yon)
{
    if (tepe == NULL) 
    {
        *cikan_yon = 0; 
        return NULL;
    }

    *cikan_yon = tepe->yon; 
    YonNode *silinecek = tepe;
    YonNode *yeni_tepe = tepe->sonraki; 
    
    free(silinecek); 
    return yeni_tepe; 
}

YonNode* yigini_temizle(YonNode *tepe)
{
    int cop; 
    while (tepe != NULL) 
    {
        tepe = yigindan_cikar(tepe, &cop);
    }
    return NULL;
}

void daktilo_efekti(char *metin)
{
    for (int i = 0; metin[i] != '\0'; i++) 
    {
        printf("%c", metin[i]);
        fflush(stdout); 
        SLEEP_MS(40);  
    }
}

void oyun_hikayesi()
{
    ekrani_temizle();
    printf("\n\n\n\n");

    char *satir1 = "                Yedi Krallik... Ihanetin, kanin ve buzun hukum surdugu topraklar...\n\n";
    char *satir2 = "                Kuzeyin dondurucu ruzgarlari, yaklasan buyuk savasin habercisi.\n";
    char *satir3 = "                Duvarin ardinda uyanan kadim kotuluk ve guneyde taht oyunlari...\n\n";
    char *satir4 = "                Sen, gecmisi olmayan, kaderini kendi kiliciyla yazacak yalniz bir savacisin.\n";
    char *satir5 = "                Burada merhamet zayifliktir. Guven ise en hizli olumdur.\n\n";
    char *satir6 = "                Unutma Savasci... Westeros'ta kural basittir:\n\n";
    char *satir7 = "                YA KAZANIRSIN... YA DA OLURSUN.\n";

    daktilo_efekti(satir1);
    sleep(1); 
    
    daktilo_efekti(satir2);
    sleep(1);
    
    daktilo_efekti(satir3);
    sleep(2);
    
    daktilo_efekti(satir4);
    sleep(1);
    
    daktilo_efekti(satir5);
    sleep(2);
    
    daktilo_efekti(satir6);
    sleep(1);
    
    for (int i = 0; satir7[i] != '\0'; i++) 
    {
        printf("\033[1;31m%c\033[0m", satir7[i]); 
        fflush(stdout);
        SLEEP_MS(100); 
    }
    
    sleep(3);
    
    printf("\n\n\n                [DEVAM ETMEK ICIN ENTER TUSUNA BASIN...]");
    getchar();
    getchar(); 
}