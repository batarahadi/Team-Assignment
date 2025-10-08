#include <stdio.h>
#include <string.h>

// Union untuk media
union Media {
    char buku[50];     
    char majalah[50];  
};

// Struct untuk koleksi
struct Koleksi {
    char judul[100];
    int tahunTerbit;
    int jenisMedia; // 0 = Buku, 1 = Majalah
    union Media media;
};

int main() {
    struct Koleksi k;

    // Input judul
    printf("Masukkan Judul: ");
    fgets(k.judul, sizeof(k.judul), stdin);
    k.judul[strcspn(k.judul, "\n")] = 0; // hapus newline

    // Input tahun terbit
    printf("Masukkan Tahun Terbit: ");
    scanf("%d", &k.tahunTerbit);

    // Input jenis media
    printf("Jenis Media (0 = Buku, 1 = Majalah): ");
    scanf("%d", &k.jenisMedia);
    getchar(); // buang newline dari buffer

    if (k.jenisMedia == 0) {
        printf("Masukkan kategori Buku: ");
        fgets(k.media.buku, sizeof(k.media.buku), stdin);
        k.media.buku[strcspn(k.media.buku, "\n")] = 0;
    } else {
        printf("Masukkan edisi Majalah: ");
        fgets(k.media.majalah, sizeof(k.media.majalah), stdin);
        k.media.majalah[strcspn(k.media.majalah, "\n")] = 0;
    }

    // Tampilkan data
    printf("\n=== Data Koleksi ===\n");
    printf("Judul       : %s\n", k.judul);
    printf("Tahun Terbit: %d\n", k.tahunTerbit);
    if (k.jenisMedia == 0)
        printf("Jenis Media : Buku (%s)\n", k.media.buku);
    else
        printf("Jenis Media : Majalah (%s)\n", k.media.majalah);

    return 0;
}
