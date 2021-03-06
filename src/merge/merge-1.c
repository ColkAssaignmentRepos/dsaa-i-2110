#include <stdio.h>

#define M 10
#define N 5


int main(void) {
    int i, j, p;
    int a[] = {2, 4, 5, 7, 8, 10, 15, 20, 30, 40};
    int b[] = {6, 11, 25, 33, 35};
    int c[N + M]; // __(ア)__

    i = j = p = 0;
    while (i < M && j < N) { /* 配列のa,bのどちらかが終端になるまで繰り返す */
        if (a[i] <= b[j]) c[p++] = a[i++]; // __(イ)__
        else c[p++] = b[j++]; // __(ウ)__
    }

    while(i < M) c[p++] = a[i++]; /* 配列aを終端まで、配列cに格納する */ // __(エ)__
    while(j < N) c[p++] = b[j++]; /* 配列bを終端まで、配列cに格納する */ // __(オ)__

    for (i = 0; i < M+N; i++) printf("%d ", c[i]); // __(カ)__
    printf("\n");

    return 0;
}

