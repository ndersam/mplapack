/*
 * Copyright (c) 2021
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

#include <fem.hpp> // Fortran EMulation library of fable module
using namespace fem::major_types;
using fem::common;

#include <mplapack_matgen.h>
#include <mplapack_lin.h>

void Cerrps(const char *path, INTEGER const nunit) {
    common_write write(cmn);
    // COMMON infoc
    INTEGER &infot = cmn.infot;
    INTEGER &nout = cmn.nout;
    bool &ok = cmn.ok;
    bool &lerr = cmn.lerr;
    // COMMON srnamc
    char &srnamt = cmn.srnamt;
    //
    //
    //  -- LAPACK test routine --
    //  -- LAPACK is a software package provided by Univ. of Tennessee,    --
    //  -- Univ. of California Berkeley, Univ. of Colorado Denver and NAG Ltd..--
    //
    //     .. Scalar Arguments ..
    //     ..
    //
    //  =====================================================================
    //
    //     .. Parameters ..
    //     ..
    //     .. Local Scalars ..
    //     ..
    //     .. Local Arrays ..
    //     ..
    //     .. External Subroutines ..
    //     ..
    //     .. Scalars in Common ..
    //     ..
    //     .. Common blocks ..
    //     ..
    //     .. Intrinsic Functions ..
    //     ..
    //     .. Executable Statements ..
    //
    nout = nunit;
    write(nout, star);
    //
    //     Set the variables to innocuous values.
    //
    INTEGER j = 0;
    const INTEGER nmax = 4;
    INTEGER i = 0;
    arr_2d<nmax, nmax, COMPLEX> a;
    arr_1d<nmax, int> piv;
    arr_1d<2 * nmax, REAL> rwork;
    for (j = 1; j <= nmax; j = j + 1) {
        for (i = 1; i <= nmax; i = i + 1) {
            a[(i - 1) + (j - 1) * lda] = 1.0 / (i + j).real();
            //
        }
        piv[j - 1] = j;
        rwork[j - 1] = 0.0;
        rwork[(nmax + j) - 1] = 0.0;
        //
    }
    ok = true;
    //
    //        Test error exits of the routines that use the Cholesky
    //        decomposition of an Hermitian positive semidefinite matrix.
    //
    //        Cpstrf
    //
    srnamt = "Cpstrf";
    infot = 1;
    INTEGER rank = 0;
    INTEGER info = 0;
    Cpstrf("/", 0, a, 1, piv, rank, -1.0, rwork, info);
    chkxer("Cpstrf", infot, nout, lerr, ok);
    infot = 2;
    Cpstrf("U", -1, a, 1, piv, rank, -1.0, rwork, info);
    chkxer("Cpstrf", infot, nout, lerr, ok);
    infot = 4;
    Cpstrf("U", 2, a, 1, piv, rank, -1.0, rwork, info);
    chkxer("Cpstrf", infot, nout, lerr, ok);
    //
    //        Cpstf2
    //
    srnamt = "Cpstf2";
    infot = 1;
    Cpstf2("/", 0, a, 1, piv, rank, -1.0, rwork, info);
    chkxer("Cpstf2", infot, nout, lerr, ok);
    infot = 2;
    Cpstf2("U", -1, a, 1, piv, rank, -1.0, rwork, info);
    chkxer("Cpstf2", infot, nout, lerr, ok);
    infot = 4;
    Cpstf2("U", 2, a, 1, piv, rank, -1.0, rwork, info);
    chkxer("Cpstf2", infot, nout, lerr, ok);
    //
    //     Print a summary line.
    //
    Alaesm(path, ok, nout);
    //
    //     End of Cerrps
    //
}
