#include <stdio.h>
#include <stdlib.h>

struct Düğüm {
    struct Düğüm *dallar[26];
    int son;
};

// Yeni düğüm oluştur ve belleği temizle
struct Düğüm *yeni() {
    return (struct Düğüm *)calloc(1, sizeof(struct Düğüm));
}

// Kelime ekleme fonksiyonu
void ekle(struct Düğüm *r, char *s) {
    for (int i = 0; s[i]; i++) {
        int indis = s[i] - 'a';
        if (!r->dallar[indis]) r->dallar[indis] = yeni();
        r = r->dallar[indis];
    }
    r->son = 1;
}

int main() {
    struct Düğüm *root = yeni();
    ekle(root, "enes");
    printf("Trie hazir.");
    return 0;
}
