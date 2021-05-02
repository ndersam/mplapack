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

void Cerrtsqr(const char *path, INTEGER const nunit) {
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
    const INTEGER nmax = 2;
    INTEGER i = 0;
    arr_2d<nmax, nmax, COMPLEX> a;
    arr_2d<nmax, nmax, COMPLEX> c;
    arr_2d<nmax, nmax, COMPLEX> t;
    arr_1d<nmax, COMPLEX> w;
    for (j = 1; j <= nmax; j = j + 1) {
        for (i = 1; i <= nmax; i = i + 1) {
            a[(i - 1) + (j - 1) * lda] = 1.0 / (i + j).real();
            c[(i - 1) + (j - 1) * ldc] = 1.0 / (i + j).real();
            t[(i - 1) + (j - 1) * ldt] = 1.0 / (i + j).real();
        }
        w[j - 1] = 0.0;
    }
    ok = true;
    //
    //     Error exits for TS factorization
    //
    //     Cgeqr
    //
    srnamt = "Cgeqr";
    infot = 1;
    arr_1d<nmax, COMPLEX> tau;
    INTEGER info = 0;
    Cgeqr(-1, 0, a, 1, tau, 1, w, 1, info);
    chkxer("Cgeqr", infot, nout, lerr, ok);
    infot = 2;
    Cgeqr(0, -1, a, 1, tau, 1, w, 1, info);
    chkxer("Cgeqr", infot, nout, lerr, ok);
    infot = 4;
    Cgeqr(1, 1, a, 0, tau, 1, w, 1, info);
    chkxer("Cgeqr", infot, nout, lerr, ok);
    infot = 6;
    Cgeqr(3, 2, a, 3, tau, 1, w, 1, info);
    chkxer("Cgeqr", infot, nout, lerr, ok);
    infot = 8;
    Cgeqr(3, 2, a, 3, tau, 8, w, 0, info);
    chkxer("Cgeqr", infot, nout, lerr, ok);
    //
    //     Cgemqr
    //
    tau[1 - 1] = 1;
    tau[2 - 1] = 1;
    srnamt = "Cgemqr";
    INTEGER nb = 1;
    infot = 1;
    Cgemqr("/", "N", 0, 0, 0, a, 1, tau, 1, c, 1, w, 1, info);
    chkxer("Cgemqr", infot, nout, lerr, ok);
    infot = 2;
    Cgemqr("L", "/", 0, 0, 0, a, 1, tau, 1, c, 1, w, 1, info);
    chkxer("Cgemqr", infot, nout, lerr, ok);
    infot = 3;
    Cgemqr("L", "N", -1, 0, 0, a, 1, tau, 1, c, 1, w, 1, info);
    chkxer("Cgemqr", infot, nout, lerr, ok);
    infot = 4;
    Cgemqr("L", "N", 0, -1, 0, a, 1, tau, 1, c, 1, w, 1, info);
    chkxer("Cgemqr", infot, nout, lerr, ok);
    infot = 5;
    Cgemqr("L", "N", 0, 0, -1, a, 1, tau, 1, c, 1, w, 1, info);
    chkxer("Cgemqr", infot, nout, lerr, ok);
    infot = 5;
    Cgemqr("R", "N", 0, 0, -1, a, 1, tau, 1, c, 1, w, 1, info);
    chkxer("Cgemqr", infot, nout, lerr, ok);
    infot = 7;
    Cgemqr("L", "N", 2, 1, 0, a, 0, tau, 1, c, 1, w, 1, info);
    chkxer("Cgemqr", infot, nout, lerr, ok);
    infot = 9;
    Cgemqr("R", "N", 2, 2, 1, a, 2, tau, 0, c, 1, w, 1, info);
    chkxer("Cgemqr", infot, nout, lerr, ok);
    infot = 9;
    Cgemqr("L", "N", 2, 2, 1, a, 2, tau, 0, c, 1, w, 1, info);
    chkxer("Cgemqr", infot, nout, lerr, ok);
    infot = 11;
    Cgemqr("L", "N", 2, 1, 1, a, 2, tau, 6, c, 0, w, 1, info);
    chkxer("Cgemqr", infot, nout, lerr, ok);
    infot = 13;
    Cgemqr("L", "N", 2, 2, 1, a, 2, tau, 6, c, 2, w, 0, info);
    chkxer("Cgemqr", infot, nout, lerr, ok);
    //
    //     Cgelq
    //
    srnamt = "Cgelq";
    infot = 1;
    Cgelq(-1, 0, a, 1, tau, 1, w, 1, info);
    chkxer("Cgelq", infot, nout, lerr, ok);
    infot = 2;
    Cgelq(0, -1, a, 1, tau, 1, w, 1, info);
    chkxer("Cgelq", infot, nout, lerr, ok);
    infot = 4;
    Cgelq(1, 1, a, 0, tau, 1, w, 1, info);
    chkxer("Cgelq", infot, nout, lerr, ok);
    infot = 6;
    Cgelq(2, 3, a, 3, tau, 1, w, 1, info);
    chkxer("Cgelq", infot, nout, lerr, ok);
    infot = 8;
    Cgelq(2, 3, a, 3, tau, 8, w, 0, info);
    chkxer("Cgelq", infot, nout, lerr, ok);
    //
    //     Cgemlq
    //
    tau[1 - 1] = 1;
    tau[2 - 1] = 1;
    srnamt = "Cgemlq";
    nb = 1;
    infot = 1;
    Cgemlq("/", "N", 0, 0, 0, a, 1, tau, 1, c, 1, w, 1, info);
    chkxer("Cgemlq", infot, nout, lerr, ok);
    infot = 2;
    Cgemlq("L", "/", 0, 0, 0, a, 1, tau, 1, c, 1, w, 1, info);
    chkxer("Cgemlq", infot, nout, lerr, ok);
    infot = 3;
    Cgemlq("L", "N", -1, 0, 0, a, 1, tau, 1, c, 1, w, 1, info);
    chkxer("Cgemlq", infot, nout, lerr, ok);
    infot = 4;
    Cgemlq("L", "N", 0, -1, 0, a, 1, tau, 1, c, 1, w, 1, info);
    chkxer("Cgemlq", infot, nout, lerr, ok);
    infot = 5;
    Cgemlq("L", "N", 0, 0, -1, a, 1, tau, 1, c, 1, w, 1, info);
    chkxer("Cgemlq", infot, nout, lerr, ok);
    infot = 5;
    Cgemlq("R", "N", 0, 0, -1, a, 1, tau, 1, c, 1, w, 1, info);
    chkxer("Cgemlq", infot, nout, lerr, ok);
    infot = 7;
    Cgemlq("L", "N", 1, 2, 0, a, 0, tau, 1, c, 1, w, 1, info);
    chkxer("Cgemlq", infot, nout, lerr, ok);
    infot = 9;
    Cgemlq("R", "N", 2, 2, 1, a, 1, tau, 0, c, 1, w, 1, info);
    chkxer("Cgemlq", infot, nout, lerr, ok);
    infot = 9;
    Cgemlq("L", "N", 2, 2, 1, a, 1, tau, 0, c, 1, w, 1, info);
    chkxer("Cgemlq", infot, nout, lerr, ok);
    infot = 11;
    Cgemlq("L", "N", 1, 2, 1, a, 1, tau, 6, c, 0, w, 1, info);
    chkxer("Cgemlq", infot, nout, lerr, ok);
    infot = 13;
    Cgemlq("L", "N", 2, 2, 1, a, 2, tau, 6, c, 2, w, 0, info);
    chkxer("Cgemlq", infot, nout, lerr, ok);
    //
    //     Print a summary line.
    //
    Alaesm(path, ok, nout);
    //
    //     End of Rerrtsqr
    //
}
