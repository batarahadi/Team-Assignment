#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definisi struct untuk pegawai
struct dataPegawai {
    char NIP[20];
    char nama[50];
    char alamat[100];
    char noHP[15];
    char jabatan[30];
    char golongan[3];
    char gajiPokok[20];
};

// Fungsi untuk menentukan gaji pokok berdasarkan golongan
long hitungGajiPokok(char golongan[]) {
    if (strcmp(golongan, "D1") == 0) {
        return 3000000;
    } else if (strcmp(golongan, "D2") == 0) {
        return 2500000;
    } else if (strcmp(golongan, "D3") == 0) {
        return 2000000;
    } else {
        return 0; // Golongan tidak valid
    }
}

// Fungsi untuk memformat angka menjadi format ribuan (pakai titik)
void formatRupiah(long angka, char hasil[]) {
    char temp[30];
    sprintf(temp, "%ld", angka);  // ubah angka ke string

    int len = strlen(temp);
    int titik = 0;
    int i, j = 0;
    char hasilTemp[40];

    // Tambahkan titik setiap 3 digit dari belakang
    for (i = len - 1; i >= 0; i--) {
        hasilTemp[j++] = temp[i];
        if (++titik == 3 && i != 0) {
            hasilTemp[j++] = '.';
            titik = 0;
        }
    }

    hasilTemp[j] = '\0';

    // Balik string agar urutannya benar
    int len2 = strlen(hasilTemp);
    for (i = 0; i < len2; i++) {
        hasil[i] = hasilTemp[len2 - i - 1];
    }
    hasil[len2] = '\0';
}

int main() {
    struct dataPegawai pegawai1;
    long gaji;
    char gajiFormatted[40];

    // Input data pegawai
    printf("Masukkan NIP: ");
    scanf("%s", pegawai1.NIP);
    getchar();

    printf("Masukkan Nama: ");
    fgets(pegawai1.nama, sizeof(pegawai1.nama), stdin);
    pegawai1.nama[strcspn(pegawai1.nama, "\n")] = 0;

    printf("Masukkan Alamat: ");
    fgets(pegawai1.alamat, sizeof(pegawai1.alamat), stdin);
    pegawai1.alamat[strcspn(pegawai1.alamat, "\n")] = 0;

    printf("Masukkan No HP: ");
    scanf("%s", pegawai1.noHP);
    getchar();

    printf("Masukkan Jabatan: ");
    fgets(pegawai1.jabatan, sizeof(pegawai1.jabatan), stdin);
    pegawai1.jabatan[strcspn(pegawai1.jabatan, "\n")] = 0;

    printf("Masukkan Golongan (D1/D2/D3): ");
    scanf("%s", pegawai1.golongan);

    // Hitung dan format gaji pokok otomatis
    gaji = hitungGajiPokok(pegawai1.golongan);
    formatRupiah(gaji, gajiFormatted);
    strcpy(pegawai1.gajiPokok, gajiFormatted);

    // Tampilkan data pegawai
    printf("\n=== DATA PEGAWAI ===\n");
    printf("NIP       : %s\n", pegawai1.NIP);
    printf("Nama      : %s\n", pegawai1.nama);
    printf("Alamat    : %s\n", pegawai1.alamat);
    printf("No HP     : %s\n", pegawai1.noHP);
    printf("Jabatan   : %s\n", pegawai1.jabatan);
    printf("Golongan  : %s\n", pegawai1.golongan);
    printf("\nGaji Pokok: Rp %s\n", pegawai1.gajiPokok);

    return 0;
}