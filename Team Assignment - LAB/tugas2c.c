#include <stdio.h>

int main() {
    float totalPembelian, diskon = 0, totalPembeyaran;
    int kupon;

    // Input total pembelian
    printf("Maukan total pembelian : Rp ");
    scanf("%f", &totalPembelian);

    // Menghitung kupon
    kupon = totalPembelian / 100000;

    // Menghitung diskon
    if (totalPembelian >= 100000){
        diskon = totalPembelian * 0.15;
    }

    // Menghitung Total Pembayaran
    totalPembeyaran = totalPembelian + diskon;

    printf("\n===== RINCIAN PEMBELIAN =====\n");
    printf("Total pembelian awal.   : Rp %.0f\n", totalPembelian);
    printf("Jumlah kupon undian     : %d kupon\n", kupon);
    printf("Nominal diskon.         : Rp %.2f\n", diskon);
    printf("Total yang harus dibayar: %.0f\n", totalPembeyaran);

    return 0;
}