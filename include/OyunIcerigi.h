#ifndef GAME_H
#define GAME_H

#ifdef _WIN32
    #include <windows.h>
    #define SLEEP_MS(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define SLEEP_MS(ms) usleep(ms * 1000)
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
typedef struct Esya
{
    int id;             
    char ad[50];        
    int fiyat;          
    int etki_degeri;    
    int tur;            
    struct Esya *sonraki; 
} Esya;

typedef struct YonNode 
{
    int yon; 
    struct YonNode *sonraki;
} YonNode;

typedef struct GorevNode
{
    int id;                 
    char baslik[50];        
    char aciklama[150];     
    char gereksinim[100]; 
    
    int odul_altin;
    int odul_xp;
    int odul_stat;         
  
    struct GorevNode *sonraki;
} GorevNode;

typedef struct {
    GorevNode *bas; 
    GorevNode *son; 
} GorevKuyruk;

typedef struct 
{
    char kahramanin_adi[30];
    char kahramanin_calgisi[30];

    int seviye;
    int xp;
    int can;
    int tokluk;
    int uyku;
    int susuzluk;
    int mutluluk;
    int hijyen;
    int inanc;
    int para;

    int guc;
    int ceviklik;
    int dayaniklilik;
    int karizma;
    int toplayicilik;

    int yukseltme_miktari;

    struct Esya *envanter;
    int envanter_eşya_sayisi;

    GorevKuyruk *gorevler;
} Karakter;


int sayiKontrol(char* mesaj);
void menu_gecisi_bekleme_fonksiyonu(char* mesaj, int saniye);
void ortalayarak_yaz(char *mesaj);
void durum_cubugu_gosterim_fonksiyonu(char* durum_adi, int deger, int max_deger);
void uyari_fonksiyonu(char* durum_adi, int *deger, int max_deger, int *can);
void beceri_cubugu_gosterim_fonksiyonu(char* beceri_adi, int deger, int max_deger, int artis);
void para_kazanma(int karizma, int hijyen, int muzik_aleti, int *para_miktari);
void para_harcama(int *para_miktari, int harcamaMiktari);
void deger_arttir(char* durum_adi, int* deger, int artis_miktari);
void deger_azalt(char* durum_adi, int* deger, int azalis_miktari);
void para_ayarlamasi(int *para_miktari, int *bahis);
void para_ayarlamasi2(int *para_miktari, int *bahis);
void para_ayarlamasi3(int *para_miktari, int *kazanc);
void ekrani_temizle();
void sabit_durum_cubugu_yazdir(Karakter *oyuncu);
void savas(Karakter *oyuncu, int dusman_guc, int dusman_ceviklik, int dusman_dayaniklilik, int dusman_can_max, char* dusman_adi, int xp_odul, int altin_odul);
void dukkan_listesine_ekle(Esya **baslangic, int id, char *ad, int fiyat, int etki, int tur);
void dukkani_yazdir(Esya *baslangic);
void dukkani_temizle(Esya *baslangic);
int menu_canta(Karakter *oyuncu);
void envantere_ekle(Karakter *oyuncu, Esya *alinan_esya);
int esya_kullan_ve_sil(Karakter *oyuncu);
void daktilo_efekti(char *metin);
void oyun_hikayesi();

YonNode* yigina_ekle(YonNode *tepe, int yon); 
YonNode* yigindan_cikar(YonNode *tepe, int *cikan_yon); 
YonNode* yigini_temizle(YonNode *tepe);

void menu_gorevler(Karakter *oyuncu);
void gorev_kuyrugunu_baslat(Karakter *oyuncu);
void gorev_ekle(GorevKuyruk *kuyruk, int id, char* bas, char* acik, char* gereksinim, int altin, int xp, int stat);
int gorev_tamamla(Karakter *oyuncu); 


void menu_winterfell(Karakter *oyuncu);
void menu_han(Karakter *oyuncu);
void menu_kral_topraklari(Karakter *oyuncu);
void menu_kesif(Karakter *oyuncu);
void menu_zindan(Karakter *oyuncu);
void menu_gelistirme(Karakter *oyuncu);
void menu_ozellikler(Karakter *oyuncu);
void save_game(Karakter *oyuncu);
int load_game(Karakter *oyuncu);
int menu_cikis(Karakter *oyuncu); 

#endif