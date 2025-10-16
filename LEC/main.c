#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct templetSiswa {
    char nama[50];
    int umur;
    char nomorRegistrasi[10];
};

void tambahDataSiswa() {
    struct templetSiswa siswaBaru;
    FILE *dataSiswa = fopen("dataSiswa.txt", "a");
    if (dataSiswa == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    printf("Masukkan nama siswa: ");
    scanf("%[^\n]", siswaBaru.nama);
    printf("Masukkan umur siswa: ");
    scanf("%d", &siswaBaru.umur);
    printf("Masukkan nomor registrasi siswa 10 angka: ");
    scanf("%s", siswaBaru.nomorRegistrasi);

    fprintf(dataSiswa, "%s, %d, %s\n", siswaBaru.nama, siswaBaru.umur, siswaBaru.nomorRegistrasi);
    fclose(dataSiswa);
    printf("Data siswa berhasil ditambahkan.\n");
}



int main() {
    FILE *dataSiswa;
    struct templetSiswa siswaBaru;
    
    int pilihan;

    while (1) {
        printf("\n=== Manajemen Siswa ===\n");
        printf("1. Menambah data siswa\n");
        printf("2. Menghapus data siswa");
        printf("3. Mencari data siswa\n");
        printf("4. Keluar\n");
        printf("Pilih (1-3): ");
        scanf("%d", &pilihan);
        
        switch (pilihan) {
            case (1) : tambahDataSiswa();
            // case 2:
            // printf("Menghapus data siswa...\n");
// 
// 
            // case 3:
                // printf("Mencari data siswa...\n");


            case 4:
                printf("Keluar dari program.\n");
                return 0;
                break;
            default:
                printf("Pilihan tidak valid, keluar dari program\n");
                break;
        }   
    }

    return 0;
}