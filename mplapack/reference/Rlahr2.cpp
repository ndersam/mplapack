/*
 * Copyright (c) 2008-2021
 *      Nakata, Maho
 *      All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */

#include <mpblas.h>
#include <mplapack.h>

void Rlahr2(INTEGER const n, INTEGER const k, INTEGER const nb, REAL *a, INTEGER const lda, REAL *tau, REAL *t, INTEGER const ldt, REAL *y, INTEGER const ldy) {
    //
    //  -- LAPACK auxiliary routine --
    //  -- LAPACK is a software package provided by Univ. of Tennessee,    --
    //  -- Univ. of California Berkeley, Univ. of Colorado Denver and NAG Ltd..--
    //
    //     .. Scalar Arguments ..
    //     ..
    //     .. Array Arguments ..
    //     ..
    //
    //  =====================================================================
    //
    //     .. Parameters ..
    //     ..
    //     .. Local Scalars ..
    //     ..
    //     .. External Subroutines ..
    //     ..
    //     .. Intrinsic Functions ..
    //     ..
    //     .. Executable Statements ..
    //
    //     Quick return if possible
    //
    if (n <= 1) {
        return;
    }
    //
    INTEGER i = 0;
    const REAL one = 1.0;
    REAL ei = 0.0;
    const REAL zero = 0.0;
    for (i = 1; i <= nb; i = i + 1) {
        if (i > 1) {
            //
            //           Update A(K+1:N,I)
            //
            //           Update I-th column of A - Y * V**T
            //
            Rgemv("NO TRANSPOSE", n - k, i - 1, -one, &y[((k + 1) - 1)], ldy, &a[((k + i - 1) - 1)], lda, one, &a[((k + 1) - 1) + (i - 1) * lda], 1);
            //
            //           Apply I - V * T**T * V**T to this column (call it b) from the
            //           left, using the last column of T as workspace
            //
            //           Let  V = ( V1 )   and   b = ( b1 )   (first I-1 rows)
            //                    ( V2 )             ( b2 )
            //
            //           where V1 is unit lower triangular
            //
            //           w := V1**T * b1
            //
            Rcopy(i - 1, &a[((k + 1) - 1) + (i - 1) * lda], 1, &t[(nb - 1) * ldt], 1);
            Rtrmv("Lower", "Transpose", "UNIT", i - 1, &a[((k + 1) - 1)], lda, &t[(nb - 1) * ldt], 1);
            //
            //           w := w + V2**T * b2
            //
            Rgemv("Transpose", n - k - i + 1, i - 1, one, &a[((k + i) - 1)], lda, &a[((k + i) - 1) + (i - 1) * lda], 1, one, &t[(nb - 1) * ldt], 1);
            //
            //           w := T**T * w
            //
            Rtrmv("Upper", "Transpose", "NON-UNIT", i - 1, t, ldt, &t[(nb - 1) * ldt], 1);
            //
            //           b2 := b2 - V2*w
            //
            Rgemv("NO TRANSPOSE", n - k - i + 1, i - 1, -one, &a[((k + i) - 1)], lda, &t[(nb - 1) * ldt], 1, one, &a[((k + i) - 1) + (i - 1) * lda], 1);
            //
            //           b1 := b1 - V1*w
            //
            Rtrmv("Lower", "NO TRANSPOSE", "UNIT", i - 1, &a[((k + 1) - 1)], lda, &t[(nb - 1) * ldt], 1);
            Raxpy(i - 1, -one, &t[(nb - 1) * ldt], 1, &a[((k + 1) - 1) + (i - 1) * lda], 1);
            //
            a[((k + i - 1) - 1) + ((i - 1) - 1) * lda] = ei;
        }
        //
        //        Generate the elementary reflector H(I) to annihilate
        //        A(K+I+1:N,I)
        //
        Rlarfg(n - k - i + 1, a[((k + i) - 1) + (i - 1) * lda], &a[(min(k + i + 1, n)-1) + (i-1)* lda], 1, tau[i - 1]);
        ei = a[((k + i) - 1) + (i - 1) * lda];
        a[((k + i) - 1) + (i - 1) * lda] = one;
        //
        //        Compute  Y(K+1:N,I)
        //
        Rgemv("NO TRANSPOSE", n - k, n - k - i + 1, one, &a[((k + 1) - 1) + ((i + 1) - 1) * lda], lda, &a[((k + i) - 1) + (i - 1) * lda], 1, zero, &y[((k + 1) - 1) + (i - 1) * ldy], 1);
        Rgemv("Transpose", n - k - i + 1, i - 1, one, &a[((k + i) - 1)], lda, &a[((k + i) - 1) + (i - 1) * lda], 1, zero, &t[(i - 1) * ldt], 1);
        Rgemv("NO TRANSPOSE", n - k, i - 1, -one, &y[((k + 1) - 1)], ldy, &t[(i - 1) * ldt], 1, one, &y[((k + 1) - 1) + (i - 1) * ldy], 1);
        Rscal(n - k, tau[i - 1], &y[((k + 1) - 1) + (i - 1) * ldy], 1);
        //
        //        Compute T(1:I,I)
        //
        Rscal(i - 1, -tau[i - 1], &t[(i - 1) * ldt], 1);
        Rtrmv("Upper", "No Transpose", "NON-UNIT", i - 1, t, ldt, &t[(i - 1) * ldt], 1);
        t[(i - 1) + (i - 1) * ldt] = tau[i - 1];
        //
    }
    a[((k + nb) - 1) + (nb - 1) * lda] = ei;
    //
    //     Compute Y(1:K,1:NB)
    //
    Rlacpy("ALL", k, nb, &a[(2 - 1) * lda], lda, y, ldy);
    Rtrmm("RIGHT", "Lower", "NO TRANSPOSE", "UNIT", k, nb, one, &a[((k + 1) - 1)], lda, y, ldy);
    if (n > k + nb) {
        Rgemm("NO TRANSPOSE", "NO TRANSPOSE", k, nb, n - k - nb, one, &a[((2 + nb) - 1) * lda], lda, &a[((k + 1 + nb) - 1)], lda, one, y, ldy);
    }
    Rtrmm("RIGHT", "Upper", "NO TRANSPOSE", "NON-UNIT", k, nb, one, t, ldt, y, ldy);
    //
    //     End of Rlahr2
    //
}
