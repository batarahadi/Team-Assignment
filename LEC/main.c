#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct templetSiswa {
    char nama[50];
    int umur;
    int nomorRegistrasi[10];
};


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
        
        which (pilihan) {
            case 1:
                printf("Menambah data siswa...\n");

                
            case 2:
                printf("Menghapus data siswa...\n");


            case 3:
                printf("Mencari data siswa...\n");


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