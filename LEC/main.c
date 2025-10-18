#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/** Struktur data untuk menyimpan data siswa 
 * berfungsi sebagai template data siswa dan
 * menyimpan data sementara saat penambahan data siswa
*/
struct templetSiswa {
    char nama[20];
    int umur;
    char nomorRegistrasi[10];
};

/* Funtion untuk membersihkan layar terminal otomatis dan sudah disesuaikan dengan OS pengguna,
dan akan saya tambahkan pada setiap fungsi agar terlihat lebih rapi
*/
void clearScreen() {
#ifdef _WIN32
    system("cls");     // Windows
#else
    system("clear");   // Linux / macOS / Armbian / Debian
#endif
}

/*(SELESAI) Menambah data siswa, 
berfungsi untuk menambahkan data siswa ke file dataSiswa.txt,
jika file tidak ada maka akan membuat file baru secara otomatis
*/
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

/*(SELESAI) Menghapus data siswa bedasarkan pilihan user menggunakan nama atau nomor registrasi,
jika pilihan user salah maka akan kembali ke menu utama*/
void hapusDataSiswa() {
    clearScreen();
    char hapusNama[20];
    char hapusNomor[10];
    int tmpAngkaHapus;
    FILE *dataSiswa = fopen("dataSiswa.txt", "r");
    if (dataSiswa == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    printf("=== Menghapus Data Siswa ===\n\n");
    printf("Program ini akan menghapus data siswa.\nAnda ingin menghapus data siswa berdasarkan apa?\n1. Nama\n2. Nomor registrasi.\n Pilih Anda: ");
    scanf("%d", &tmpAngkaHapus);
    getchar();

    if (tmpAngkaHapus == 1) {                                                // if pertama menggunakan nama sebagai acuan penghapusan
        printf("Masukkan nama siswa yang akan dihapus: ");
        fgets(hapusNama, sizeof(hapusNama), stdin);
        hapusNama[strcspn(hapusNama, "\n")] = 0; // hapus newline

        FILE *temp = fopen("temp.txt", "w");
        char line[100];
        int found = 0;

        while (fgets(line, sizeof(line), dataSiswa)) {                  // membaca setiap baris
            char namaSiswa[50], nomorReg[20];                           // variabel namaSiswa, nomorReg, umur adalah
            int umur;                                                   // variabel sementara untuk menyimpan data
            sscanf(line, "%[^,],%d,%s", namaSiswa, &umur, nomorReg);

            if (strcmp(namaSiswa, hapusNama) != 0) {
                fprintf(temp, "%s", line);
            } else {
                found = 1;
            }
        }

        fclose(dataSiswa);
        fclose(temp);
        remove("dataSiswa.txt");
        rename("temp.txt", "dataSiswa.txt");

        if (found) {                                                                // jika data ditemukan
            printf("Data siswa bernama '%s' berhasil dihapus.\n", hapusNama);}           // akan menampilkan pesan berhasil
        else {                                                                      // jika data tidak ditemukan
            printf("Data siswa bernama '%s' tidak ditemukan.\n", hapusNama);}            // akan menampilkan pesan seperti berikut
    }
    else if (tmpAngkaHapus == 2) {                                             // else if kedua menggunakan nomor registrasi sebagai acuan penghapusan
        printf("Masukkan nomor registrasi siswa yang akan dihapus: ");
        scanf("%s", hapusNomor);

        FILE *temp = fopen("temp.txt", "w");
        char line[100];
        int found = 0;

        while (fgets(line, sizeof(line), dataSiswa)) {
            char nama[50], nomorReg[20];
            int umur;
            sscanf(line, "%[^,],%d,%s", nama, &umur, nomorReg);

            if (strcmp(nomorReg, hapusNomor) != 0) {
                fprintf(temp, "%s", line);
            } else {
                found = 1;
            }
        }
        fclose(dataSiswa);
        fclose(temp);
        remove("dataSiswa.txt");
        rename("temp.txt", "dataSiswa.txt");

        if (found)
            printf("Data berhasil dihapus.\n");
        else
            printf("Data tidak ditemukan.\n");
    }
    else {
        printf("Pilihan tidak valid, kembali ke menu utama.\n");
        return;
    }
}

/* (BELUM SELESAI) Mencari data siswa
mencari data siswa berdasarkan nama atau nomor registrasi*/
void cariDataSiswa() {
    clearScreen();
    char cariNama[20];
    char cariNomor[10];
    int tampNilai;
    int ditemukan = 0;
    struct templetSiswa siswa;
    FILE *dataSiswa = fopen("dataSiswa.txt", "r");
    if (dataSiswa == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    printf("=== Mencari Data Siswa ===\n\n");
    printf("Program ini akan mencari data siswa.\n");
    printf("Anda ingin mencari data siswa berdasarkan apa?\n1. Nama\n2. Nomor registrasi.\n Pilih Anda: ");
    scanf("%d", &tampNilai);
    getchar();

    if (tampNilai == 1) {                                      // pilihan pertama menggunakan nama sebagai acuan pencarian    
        printf("Masukkan nama siswa yang akan dicari: ");
        fgets(cariNama, sizeof(cariNama), stdin);
        cariNama[strcspn(cariNama, "\n")] = 0; // hapus newline

        char line[100];
        while (fgets(line, sizeof(line), dataSiswa)) {
            char nama[50], nomorReg[20];
            int umur;

            // Format sesuai dengan format penyimpanan di file
            sscanf(line, "%[^,], %d, %s", nama, &umur, nomorReg);

            if (strcmp(nama, cariNama) == 0) {
                printf("\nData ditemukan!\n");
                printf("Nama: %s\n", nama);
                printf("Umur: %d\n", umur);
                printf("Nomor Registrasi: %s\n", nomorReg);
                ditemukan = 1;
                break;
            }
        }

        if (!ditemukan)
            printf("\nData dengan nama '%s' tidak ditemukan.\n", cariNama);
    }
    else if (tampNilai == 2) {
        printf("Masukkan nomor registrasi siswa yang akan dicari: ");
        scanf("%s", cariNomor);

        char line[100];
        while (fgets(line, sizeof(line), dataSiswa)) {
            char nama[50], nomorReg[20];
            int umur;

            sscanf(line, "%[^,], %d, %s", nama, &umur, nomorReg);

            if (strcmp(nomorReg, cariNomor) == 0) {
                printf("\nData ditemukan!\n");
                printf("Nama: %s\n", nama);
                printf("Umur: %d\n", umur);
                printf("Nomor Registrasi: %s\n", nomorReg);
                ditemukan = 1;
                break;
            }
        }

        if (!ditemukan)
            printf("\nData dengan nomor registrasi '%s' tidak ditemukan.\n", cariNomor);
    }
    else {
        printf("Pilihan tidak valid, kembali ke menu utama.\n");
        return;
    }
    
    fclose(dataSiswa);
}

int main() {
    int pilihanWhile;
    
    while (1) {
        printf("\n=== Manajemen Siswa ===\n\n");
        printf("Pilih opsi:\n");
        printf("1. Menambah Data Siswa\n");
        printf("2. Menghapus Data Siswa\n");
        printf("3. Mencari Data Siswa\n");
        printf("4. Keluar\n\n");
        printf("Masukkan Pilihan Anda: ");
        scanf("%d", &pilihanWhile);
        
        if (pilihanWhile != 1 && pilihanWhile != 2 && pilihanWhile != 3 && pilihanWhile != 4) {
            printf("Pilihan tidak valid, keluar dari program\n");
            break;
        }

        switch (pilihanWhile) {
            case 1 : tambahDataSiswa(); continue; // SELESAI
            case 2 : hapusDataSiswa(); continue; // SELESAI
            case 3 : cariDataSiswa(); break; // SELESAI
            default : exit(0);
        }
    }

    return 0;
}