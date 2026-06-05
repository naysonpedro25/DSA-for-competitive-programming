#include <stdio.h>

void swap(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void insertionSort(int s[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && s[j] > s[j - 1]) {
            swap(&s[j], &s[j - 1]);
            --j;
        }
    }
}

int main() {

    int s[6] = { 1,2,3,4 ,5,6 };
    int a;

    insertionSort(s, n);
    for (int i = 0; i < n; i++) printf("%d ", s[i]);



    return 0;
}
// https://www.youtube.com/watch?v=mTNC0ERo-ZI