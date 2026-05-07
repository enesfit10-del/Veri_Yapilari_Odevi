#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HARF_SAYISI 26

struct TrieNode {
    struct TrieNode *cocuklar[HARF_SAYISI];
    bool kelimeBittiMi;
};

// Yeni bir düğüm oluşturma
struct TrieNode *dugumOlustur() {
    struct TrieNode *yeni = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    yeni->kelimeBittiMi = false;
    for (int i = 0; i < HARF_SAYISI; i++) yeni->cocuklar[i] = NULL;
    return yeni;
}

// Kelime ekleme algoritması
void ekle(struct TrieNode *root, char *kelime) {
    struct TrieNode *gezici = root;
    for (int i = 0; kelime[i] != '\0'; i++) {
        int indis = kelime[i] - 'a';
        if (!gezici->cocuklar[indis]) 
            gezici->cocuklar[indis] = dugumOlustur();
        gezici = gezici->cocuklar[indis];
    }
    gezici->kelimeBittiMi = true;
}

int main() {
    struct TrieNode *root = dugumOlustur();
    ekle(root, "enes");
    ekle(root, "veri");
    printf("Trie yapisi basariyla olusturuldu ve kelimeler eklendi.\n");
    return 0;
}
