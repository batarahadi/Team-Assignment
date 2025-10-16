#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct templetSiswa {
    char nama[20];
    int umur;
    char nomorRegistrasi[10];
};

// Fungsi untuk membersihkan layar terminal otomatis dan sudah disesuaikan dengan OS pengguna
void clearScreen() {
#ifdef _WIN32
    system("cls");     // Windows
#else
    system("clear");   // Linux / macOS / Armbian / Debian
#endif
}

// Menambah data siswa
void tambahDataSiswa() {
    clearScreen();
    struct templetSiswa siswaBaru;
    FILE *dataSiswa = fopen("dataSiswa.txt", "a");
    if (dataSiswa == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    printf("=== Menambah Data Siswa ===\n\n");
    printf("Program ini akan menambah data siswa, silahkan isi data berikut.\n");
    printf("Masukkan nama siswa: ");
    getchar(); // Membaca newline yang mungkin tersisa
    fgets(siswaBaru.nama, sizeof(siswaBaru.nama), stdin);
    siswaBaru.nama[strcspn(siswaBaru.nama, "\n")] = 0; // Hapus newline yang mungkin tersisa di akhir string
    printf("Masukkan umur siswa: ");
    scanf("%d", &siswaBaru.umur);
    printf("Masukkan nomor registrasi siswa 10 angka: ");
    scanf("%s", siswaBaru.nomorRegistrasi);

    fprintf(dataSiswa, "%s, %d, %s\n", siswaBaru.nama, siswaBaru.umur, siswaBaru.nomorRegistrasi);
    fclose(dataSiswa);
    printf("Data siswa berhasil ditambahkan.\n");
}

void hapusDataSiswa() {
    clearScreen();
    char nama[20];
    char nomor[10];
    int tmpAngka;
    FILE *dataSiswa = fopen("dataSiswa.txt", "r+");
    if (dataSiswa == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    printf("=== Menghapus Data Siswa ===\n\n");
    printf("Program ini akan menghapus data siswa.\nAnda ingin menghapus data siswa berdasarkan apa?\n1. Nama\n2. Nomor registrasi.\n Pilih Anda: ");
    scanf("%d", &tmpAngka);
    if (tmpAngka == 1) {
        printf("Masukkan nama siswa yang akan dihapus: ");

    }
    else if (tmpAngka == 2) {
        printf("Masukkan nomor registrasi siswa yang akan dihapus: ");
        scanf("%s", nomor);
    }
    else {
        printf("Pilihan tidak valid, kembali ke menu utama.\n");
        return;
    }
}


int main() {
    FILE *dataSiswa;
    struct templetSiswa siswaBaru;
    
    int pilihan;

    while (1) {
        clearScreen();
        printf("\n=== Manajemen Siswa ===\n\n");
        printf("Pilih opsi:\n");
        printf("1. Menambah Data Siswa\n");
        printf("2. Menghapus Data Siswa\n");
        printf("3. Mencari Data Siswa\n");
        printf("4. Keluar\n\n");
        printf("Masukkan Pilihan Anda: ");
        scanf("%d", &pilihan);
        
        if (pilihan != 1 && pilihan != 2 && pilihan != 3 && pilihan != 4) {
            printf("Pilihan tidak valid, keluar dari program\n");
            break;
        }

        switch (pilihan) {
            case 1 : tambahDataSiswa(); continue;
            case 2: hapusDataSiswa(); continue;
            // case 3:
            default : exit(0);
        }
    }

    return 0;
}