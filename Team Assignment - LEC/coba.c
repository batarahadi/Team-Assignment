#include <stdio.h>

int main() {
    int arr[] = {64, 34, 25, 12, 22};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("hasil leng %d", n);
    
    return 0;
}