#include <stdio.h>
#include <string.h>

char buf[1024];

void printdummy_() { printf("\n"); }

void printnum_(char *s, int *len, double *A) {
    memset(buf, 0, sizeof(buf));
    strncpy(buf, s, *len);
    printf("%s%+21.16e\n", buf, *A);
}

void printmat_(char *s, int *len, int *N, int *M, double *A, int *LDA) {
    memset(buf, 0, sizeof(buf));
    strncpy(buf, s, *len);
    double tmp;
    printf("%s[ ", buf);
    for (int i = 0; i < *N; i++) {
        printf("[ ");
        for (int j = 0; j < *M; j++) {
            tmp = A[i + j * (*LDA)];
            printf("%+21.16e", tmp);
            if (j < *M - 1)
                printf(", ");
        }
        if (i < *N - 1)
            printf("]; ");
        else
            printf("] ");
    }
    printf("]");
    printf("\n");
}

void printvec_(char *s, int *len, double *A, int *lenvec) {
    memset(buf, 0, sizeof(buf));
    strncpy(buf, s, *len);
    double tmp;
    printf("%s[ ", buf);
    for (int i = 0; i < *lenvec; i++) {
        tmp = A[i];
        printf("%+21.16e", tmp);
        if (i < *lenvec - 1)
            printf(", ");
    }
    printf("]");
    printf("\n");
}