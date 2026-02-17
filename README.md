# ⚔️ Ghost of Westeros - RPG Game Project

> **"Kazanmak ya da ölmek... Arası yoktur."**

Bu proje, **C Programlama Dili** kullanılarak geliştirilmiş, **Veri Yapıları ve Algoritmalar** (Linked List, Stack, Queue) temellerine dayanan metin tabanlı bir RPG (Rol Yapma) oyunudur.

George R.R. Martin'in *Buz ve Ateşin Şarkısı* evreninde geçen bu oyun; dinamik bellek yönetimi, dosya işlemleri ve gerçek zamanlı savaş mekanikleri ile teknik bir derinlik sunar.

---

## 🚀 Teknik Özellikler ve Veri Yapıları

Bu proje sadece bir oyun değil, aynı zamanda mühendislik konseptlerinin pratik uygulamasıdır:

* **Dinamik Envanter Yönetimi (Linked List):** Oyuncunun eşyaları statik diziler yerine, bellekte dinamik olarak büyüyüp küçülebilen **Tek Yönlü Bağlı Liste** yapısında tutulur.
* **Zindan ve Keşif Sistemi (Stack / LIFO):** Zindan haritası bir matris değil, bir **Yığın** yapısıdır. Oyuncunun hareketleri yığına eklenir (Push), "Geri Dön" denildiğinde yığından çekilir (Pop) ve Backtracking algoritması uygulanır.
* **Görev Sistemi (Queue / FIFO):** Hikaye akışı ve görev zinciri **Kuyruk** veri yapısı ile yönetilir. Görevler sırasıyla gelir ve tamamlandıkça kuyruktan çıkarılır.
* **Refleks Tabanlı Savaş:** Standart sıra tabanlı sistem yerine, oyuncunun tepki süresini (`clock()`) ölçen gerçek zamanlı bir saldırı/savunma algoritması kullanılmıştır.
* **Kalıcı Veri (File I/O):** Oyun durumu (Save/Load) `.txt` dosyaları üzerinden serileştirilerek saklanır ve okunur.

---

## 🎮 Oynanış Özellikleri

* **Hayatta Kalma (Survival):** Tokluk, Susuzluk ve Mutluluk gibi parametreleri yönetin.
* **4 Farklı Bölge:** Winterfell (Başlangıç), Han (Ticaret), Karanlık Zindan (Risk) ve Kral Toprakları (Final).
* **Sinematik Anlatım:** "Typewriter Effect" ile harf harf işlenen hikaye anlatımı.
* **Yeniden Doğuş (Respawn):** Kalıcı ölüm yerine, belirli cezalarla tekrar başlama şansı.
* **Ekonomi:** Demirci ve Büyücü'den silah/iksir satın alma sistemi.

---

## 🛠️ Kurulum ve Çalıştırma

Projeyi bilgisayarınızda çalıştırmak için bir C derleyicisine (GCC önerilir) ihtiyacınız vardır.

1.  **Repo'yu Klonlayın:**
    ```bash
    git clone [https://github.com/KULLANICI_ADINIZ/Ghost-of-Westeros.git](https://github.com/KULLANICI_ADINIZ/Ghost-of-Westeros.git)
    cd Ghost-of-Westeros
    ```

2.  **Derleme (Compile):**
    Proje modüler yapıdadır (`src` ve `include` klasörleri). Terminalde şu komutu çalıştırın:
    ```bash
    gcc src/*.c -I include -o GhostOfWesteros
    ```

3.  **Çalıştırma (Run):**
    * **Windows:** `GhostOfWesteros.exe`
    * **Linux/Mac:** `./GhostOfWesteros`

---

## 👨‍💻 Geliştirici

**Bilal Doğru** - *Bilgisayar Mühendisliği Öğrencisi*
* **Proje Tarihi:** Şubat 2026

---
