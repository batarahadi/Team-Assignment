#include <stdio.h>
#include <string.h>

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

struct DataSiswa {
    char nama[20];
    int umur;
    char nomorRegistrasi[10];
};

void cariDataSiswa() {
    clearScreen();
    char nama[20];
    char nomor[10];
    int tampNilai;
    int ditemukan = 0;
    struct DataSiswa siswa;

    FILE *dataSiswa = fopen("dataSiswa.txt", "r");
    if (dataSiswa == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    printf("=== Mencari Data Siswa ===\n\n");
    printf("Program ini akan mencari data siswa.\n");
    printf("Anda ingin mencari data siswa berdasarkan apa?\n1. Nama\n2. Nomor registrasi\nPilih Anda: ");
    scanf("%d", &tampNilai);
    getchar(); // membersihkan newline setelah scanf

    if (tampNilai == 1) {
        printf("Masukkan nama siswa yang akan dicari: ");
        fgets(nama, sizeof(nama), stdin);
        nama[strcspn(nama, "\n")] = '\0'; // hapus newline

        while (fscanf(dataSiswa, "%19s %d %9s", siswa.nama, &siswa.umur, siswa.nomorRegistrasi) == 3) {
            if (strcmp(siswa.nama, nama) == 0) {
                printf("\nData ditemukan!\n");
                printf("Nama: %s\n", siswa.nama);
                printf("Umur: %d\n", siswa.umur);
                printf("Nomor Registrasi: %s\n", siswa.nomorRegistrasi);
                ditemukan = 1;
                break;
            }
        }

        if (!ditemukan)
            printf("\nData dengan nama '%s' tidak ditemukan.\n", nama);
    }
    else if (tampNilai == 2) {
        printf("Masukkan nomor registrasi siswa yang akan dicari: ");
        scanf("%9s", nomor);

        while (fscanf(dataSiswa, "%19s %d %9s", siswa.nama, &siswa.umur, siswa.nomorRegistrasi) == 3) {
            if (strcmp(siswa.nomorRegistrasi, nomor) == 0) {
                printf("\nData ditemukan!\n");
                printf("Nama: %s\n", siswa.nama);
                printf("Umur: %d\n", siswa.umur);
                printf("Nomor Registrasi: %s\n", siswa.nomorRegistrasi);
                ditemukan = 1;
                break;
            }
        }

        if (!ditemukan)
            printf("\nData dengan nomor registrasi '%s' tidak ditemukan.\n", nomor);
    }
    else {
        printf("Pilihan tidak valid, kembali ke menu utama.\n");
    }

    fclose(dataSiswa);
}
