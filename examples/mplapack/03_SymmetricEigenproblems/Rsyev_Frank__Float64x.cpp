//public domain
#include <mpblas__Float64x.h>
#include <mplapack__Float64x.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>

#define FLOAT64X_FORMAT "%+25.21Le"
#define FLOAT64X_SHORT_FORMAT "%+20.16Le"

void printnum(_Float64x rtmp)
{
    printf(FLOAT64X_FORMAT, rtmp);
    return;
}

//Matlab/Octave format
void printvec(_Float64x *a, int len) {
    _Float64x tmp;
    printf("[ ");
    for (int i = 0; i < len; i++) {
        tmp = a[i];
        printnum(tmp);
        if (i < len - 1)
            printf(", ");
    }
    printf("]");
}

void printmat(int n, int m, _Float64x *a, int lda)
{
    _Float64x mtmp;

    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("[ ");
        for (int j = 0; j < m; j++) {
            mtmp = a[i + j * lda];
            printnum(mtmp);
            if (j < m - 1)
                printf(", ");
        }
        if (i < n - 1)
            printf("]; ");
        else
            printf("] ");
    }
    printf("]");
}
void Frank(mplapackint n) {
    mplapackint lwork, info;
    _Float64x *a = new _Float64x[n * n];
    _Float64x *w = new _Float64x[n];
    _Float64x *lambda = new _Float64x[n];
    _Float64x *reldiff = new _Float64x[n];
    _Float64x PI;
    PI = pi(PI);

    // setting A matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[(i - 1) + (j - 1) * n] = n - std::max(i, j) + 1;
        }
    }
    printf("a =");
    printmat(n, n, a, n);
    printf("\n");

    // work space query
    lwork = -1;
    _Float64x *work = new _Float64x[1];

    Rsyev("V", "U", n, a, n, w, work, lwork, info);
    lwork = (int)cast2double(work[0]);
    delete[] work;
    work = new _Float64x[std::max((mplapackint)1, lwork)];

    // diagonalize matrix
    Rsyev("N", "U", n, a, n, w, work, lwork, info);

    // print out
    printf("#eigenvalues \n");
    printf("w ="); printvec(w, n); printf("\n");

    // print out
    printf("# analytic eigenvalues\n");
    for (int i = 1; i <= n; i++) {
        lambda[(n - i)] = 0.5 * 1.0 / (1.0 - cos((2.0 * i - 1.0) * PI / castREAL__Float64x(2 * n + 1)));
    }
    printf("lambda ="); printvec(lambda, n); printf("\n");

    for (int i = 1; i <= n; i++) {
        reldiff[i - 1] = abs((lambda[i - 1] - w[i - 1]) / lambda[i - 1]);
    }
    printf("reldiff ="); printvec(reldiff, n); printf("\n");

    _Float64x maxreldiff = 0.0;
    maxreldiff = reldiff[0]; 
    for (int i = 2; i <= n; i++) {
        maxreldiff = std::max(reldiff[i - 1], maxreldiff);
    }
    printf("maxreldiff_%d =", (int)n); printnum(maxreldiff); printf("\n");

    delete[] reldiff;
    delete[] lambda;
    delete[] work;
    delete[] w;
    delete[] a;
}

int main() {
    printf("split_long_rows(0)\n");
    for (int n = 1; n < 100; n++) {
        printf("# Eigenvalues of Frank matrix of order n=%d\n", n);
        Frank((mplapackint)n);
    }
    for (int n = 100; n < 10000; n = n + 100) {
        printf("# Eigenvalues of Frank matrix of order n=%d\n", n);
        Frank((mplapackint)n);
    }
}