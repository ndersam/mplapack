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
#include <fem.hpp> // Fortran EMulation library of fable module
using namespace fem::major_types;
using fem::common;
#include <mplapack_lin.h>
#include <mplapack.h>

void Crqt01(INTEGER const m, INTEGER const n, COMPLEX *a, COMPLEX *af, COMPLEX *q, COMPLEX *r, INTEGER const lda, COMPLEX *tau, COMPLEX *work, INTEGER const lwork, REAL *rwork, REAL *result) {
    // COMMON srnamc
    char[32] &srnamt = cmn.srnamt;
    //
    //
    //  -- LAPACK test routine --
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
    //     .. External Functions ..
    //     ..
    //     .. External Subroutines ..
    //     ..
    //     .. Intrinsic Functions ..
    //     ..
    //     .. Scalars in Common ..
    //     ..
    //     .. Common blocks ..
    //     ..
    //     .. Executable Statements ..
    //
    INTEGER minmn = min(m, n);
    REAL eps = Rlamch("Epsilon");
    //
    //     Copy the matrix A to the array AF.
    //
    Clacpy("Full", m, n, a, lda, af, lda);
    //
    //     Factorize the matrix A in the array AF.
    //
    srnamt = "Cgerqf";
    INTEGER info = 0;
    Cgerqf(m, n, af, lda, tau, work, lwork, info);
    //
    //     Copy details of Q
    //
    const COMPLEX rogue = COMPLEX(-1.0e+10, -1.0e+10);
    Claset("Full", n, n, rogue, rogue, q, lda);
    if (m <= n) {
        if (m > 0 && m < n) {
            Clacpy("Full", m, n - m, af, lda, &q[((n - m + 1) - 1)], lda);
        }
        if (m > 1) {
            Clacpy("Lower", m - 1, m - 1, af[(2 - 1) + ((n - m + 1) - 1) * ldaf], lda, &q[((n - m + 2) - 1) + ((n - m + 1) - 1) * ldq], lda);
        }
    } else {
        if (n > 1) {
            Clacpy("Lower", n - 1, n - 1, af[((m - n + 2) - 1)], lda, &q[(2 - 1)], lda);
        }
    }
    //
    //     Generate the n-by-n matrix Q
    //
    srnamt = "Cungrq";
    Cungrq(n, n, minmn, q, lda, tau, work, lwork, info);
    //
    //     Copy R
    //
    const REAL zero = 0.0;
    Claset("Full", m, n, COMPLEX(zero), COMPLEX(zero), r, lda);
    if (m <= n) {
        if (m > 0) {
            Clacpy("Upper", m, m, af[((n - m + 1) - 1) * ldaf], lda, r[((n - m + 1) - 1) * ldr], lda);
        }
    } else {
        if (m > n && n > 0) {
            Clacpy("Full", m - n, n, af, lda, r, lda);
        }
        if (n > 0) {
            Clacpy("Upper", n, n, af[((m - n + 1) - 1)], lda, r[((m - n + 1) - 1)], lda);
        }
    }
    //
    //     Compute R - A*Q'
    //
    const REAL one = 1.0;
    Cgemm("No transpose", "Conjugate transpose", m, n, n, COMPLEX(-one), a, lda, q, lda, COMPLEX(one), r, lda);
    //
    //     Compute norm( R - Q'*A ) / ( N * norm(A) * EPS ) .
    //
    REAL anorm = Clange("1", m, n, a, lda, rwork);
    REAL resid = Clange("1", m, n, r, lda, rwork);
    if (anorm > zero) {
        result[1 - 1] = ((resid / (max((INTEGER)1, n)).real()) / anorm) / eps;
    } else {
        result[1 - 1] = zero;
    }
    //
    //     Compute I - Q*Q'
    //
    Claset("Full", n, n, COMPLEX(zero), COMPLEX(one), r, lda);
    Cherk("Upper", "No transpose", n, n, -one, q, lda, one, r, lda);
    //
    //     Compute norm( I - Q*Q' ) / ( N * EPS ) .
    //
    resid = Clansy("1", "Upper", n, r, lda, rwork);
    //
    result[2 - 1] = (resid / (max((INTEGER)1, n)).real()) / eps;
    //
    //     End of Crqt01
    //
}
