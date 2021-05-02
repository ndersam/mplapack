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

void program_Rchkaa(INTEGER argc, char const *argv[]) {
    common cmn(argc, argv);
    FEM_CMN_SVE(program_Rchkaa);
    common_read read(cmn);
    common_write write(cmn);
    char &intstr = sve.intstr;
    REAL &threq = sve.threq;
    if (is_called_first_time) {
        threq = 2.0;
        intstr = "0123456789";
    }
    REAL s1 = 0.0;
    const INTEGER nmax = 132;
    INTEGER lda = 0;
    bool fatal = false;
    const INTEGER nin = 5;
    INTEGER vers_major = 0;
    INTEGER vers_minor = 0;
    INTEGER vers_patch = 0;
    const INTEGER nout = 6;
    INTEGER nm = 0;
    const INTEGER maxin = 12;
    arr_1d<maxin, int> mval;
    INTEGER i = 0;
    INTEGER nn = 0;
    arr_1d<maxin, int> nval;
    INTEGER nns = 0;
    arr_1d<maxin, int> nsval;
    const INTEGER maxrhs = 16;
    INTEGER nnb = 0;
    arr_1d<maxin, int> nbval;
    INTEGER nnb2 = 0;
    INTEGER nb = 0;
    INTEGER j = 0;
    arr_1d<maxin, int> nbval2;
    arr_1d<maxin, int> nxval;
    INTEGER nrank = 0;
    arr_1d<maxin, int> rankval;
    REAL thresh = 0.0;
    bool tstchk = false;
    bool tstdrv = false;
    bool tsterr = false;
    REAL eps = 0.0;
    char aline[72];
    char path[3];
    const INTEGER matmax = 30;
    INTEGER nmats = 0;
    char c1[1];
    INTEGER k = 0;
    INTEGER ic = 0;
    char c2[2];
    INTEGER nrhs = 0;
    INTEGER ntypes = 0;
    arr_1d<matmax, bool> dotype;
    const INTEGER kdmax = nmax + (nmax + 1) / 4;
    INTEGER la = 0;
    INTEGER lafac = 0;
    arr_1d<nmax, int> piv;
    arr_1d<nmax, REAL> e;
    REAL s2 = 0.0;
    static const char *format_9988 = "(/,1x,a3,' driver routines were not tested')";
    static const char *format_9989 = "(/,1x,a3,' routines were not tested')";
    static const char *format_9990 = "(/,1x,a3,':  Unrecognized path name')";
    static const char *format_9991 = "(' Relative machine ',a,' is taken to be',d16.6)";
    static const char *format_9993 = "(4x,a4,':  ',10i6,/,11x,10i6)";
    static const char *format_9995 = "(' Invalid input value: ',a4,'=',i6,'; must be <=',i6)";
    static const char *format_9996 = "(' Invalid input value: ',a4,'=',i6,'; must be >=',i6)";
    //
    //  -- LAPACK test routine --
    //  -- LAPACK is a software package provided by Univ. of Tennessee,    --
    //  -- Univ. of California Berkeley, Univ. of Colorado Denver and NAG Ltd..--
    //     Novemebr 2019
    //
    //  =====================================================================
    //
    //     .. Parameters ..
    //     ..
    //     .. Local Scalars ..
    //     ..
    //     .. Local Arrays ..
    //     ..
    //     .. External Functions ..
    //     ..
    //     .. External Subroutines ..
    //     ..
    //     .. Scalars in Common ..
    //     ..
    //     .. Arrays in Common ..
    //     ..
    //     .. Common blocks ..
    //     ..
    //     .. Data statements ..
    //     ..
    //     .. Executable Statements ..
    //
    s1 = dsecnd[-1];
    lda = nmax;
    fatal = false;
    //
    //     Read a dummy line.
    //
    read(nin, star);
    //
    //     Report values of parameters.
    //
    ilaver(vers_major, vers_minor, vers_patch);
    write(nout, "(' Tests of the DOUBLE PRECISION LAPACK routines ',/,' LAPACK VERSION ',"
                "i1,'.',i1,'.',i1,/,/,' The following parameter values will be used:')"),
        vers_major, vers_minor, vers_patch;
    //
    //     Read the values of M
    //
    read(nin, star), nm;
    if (nm < 1) {
        write(nout, format_9996), " NM ", nm, 1;
        nm = 0;
        fatal = true;
    } else if (nm > maxin) {
        write(nout, format_9995), " NM ", nm, maxin;
        nm = 0;
        fatal = true;
    }
    {
        read_loop rloop(cmn, nin, star);
        for (i = 1; i <= nm; i = i + 1) {
            rloop, mval(i);
        }
    }
    for (i = 1; i <= nm; i = i + 1) {
        if (mval[i - 1] < 0) {
            write(nout, format_9996), " M  ", mval(i), 0;
            fatal = true;
        } else if (mval[i - 1] > nmax) {
            write(nout, format_9995), " M  ", mval(i), nmax;
            fatal = true;
        }
    }
    if (nm > 0) {
        {
            write_loop wloop(cmn, nout, format_9993);
            wloop, "M   ";
            for (i = 1; i <= nm; i = i + 1) {
                wloop, mval(i);
            }
        }
    }
    //
    //     Read the values of N
    //
    read(nin, star), nn;
    if (nn < 1) {
        write(nout, format_9996), " NN ", nn, 1;
        nn = 0;
        fatal = true;
    } else if (nn > maxin) {
        write(nout, format_9995), " NN ", nn, maxin;
        nn = 0;
        fatal = true;
    }
    {
        read_loop rloop(cmn, nin, star);
        for (i = 1; i <= nn; i = i + 1) {
            rloop, nval(i);
        }
    }
    for (i = 1; i <= nn; i = i + 1) {
        if (nval[i - 1] < 0) {
            write(nout, format_9996), " N  ", nval(i), 0;
            fatal = true;
        } else if (nval[i - 1] > nmax) {
            write(nout, format_9995), " N  ", nval(i), nmax;
            fatal = true;
        }
    }
    if (nn > 0) {
        {
            write_loop wloop(cmn, nout, format_9993);
            wloop, "N   ";
            for (i = 1; i <= nn; i = i + 1) {
                wloop, nval(i);
            }
        }
    }
    //
    //     Read the values of NRHS
    //
    read(nin, star), nns;
    if (nns < 1) {
        write(nout, format_9996), " NNS", nns, 1;
        nns = 0;
        fatal = true;
    } else if (nns > maxin) {
        write(nout, format_9995), " NNS", nns, maxin;
        nns = 0;
        fatal = true;
    }
    {
        read_loop rloop(cmn, nin, star);
        for (i = 1; i <= nns; i = i + 1) {
            rloop, nsval(i);
        }
    }
    for (i = 1; i <= nns; i = i + 1) {
        if (nsval[i - 1] < 0) {
            write(nout, format_9996), "NRHS", nsval(i), 0;
            fatal = true;
        } else if (nsval[i - 1] > maxrhs) {
            write(nout, format_9995), "NRHS", nsval(i), maxrhs;
            fatal = true;
        }
    }
    if (nns > 0) {
        {
            write_loop wloop(cmn, nout, format_9993);
            wloop, "NRHS";
            for (i = 1; i <= nns; i = i + 1) {
                wloop, nsval(i);
            }
        }
    }
    //
    //     Read the values of NB
    //
    read(nin, star), nnb;
    if (nnb < 1) {
        write(nout, format_9996), "NNB ", nnb, 1;
        nnb = 0;
        fatal = true;
    } else if (nnb > maxin) {
        write(nout, format_9995), "NNB ", nnb, maxin;
        nnb = 0;
        fatal = true;
    }
    {
        read_loop rloop(cmn, nin, star);
        for (i = 1; i <= nnb; i = i + 1) {
            rloop, nbval(i);
        }
    }
    for (i = 1; i <= nnb; i = i + 1) {
        if (nbval[i - 1] < 0) {
            write(nout, format_9996), " NB ", nbval(i), 0;
            fatal = true;
        }
    }
    if (nnb > 0) {
        {
            write_loop wloop(cmn, nout, format_9993);
            wloop, "NB  ";
            for (i = 1; i <= nnb; i = i + 1) {
                wloop, nbval(i);
            }
        }
    }
    //
    //     Set NBVAL2 to be the set of unique values of NB
    //
    nnb2 = 0;
    for (i = 1; i <= nnb; i = i + 1) {
        nb = nbval[i - 1];
        for (j = 1; j <= nnb2; j = j + 1) {
            if (nb == nbval2[j - 1]) {
                goto statement_60;
            }
        }
        nnb2++;
        nbval2[nnb2 - 1] = nb;
    statement_60:;
    }
    //
    //     Read the values of NX
    //
    {
        read_loop rloop(cmn, nin, star);
        for (i = 1; i <= nnb; i = i + 1) {
            rloop, nxval(i);
        }
    }
    for (i = 1; i <= nnb; i = i + 1) {
        if (nxval[i - 1] < 0) {
            write(nout, format_9996), " NX ", nxval(i), 0;
            fatal = true;
        }
    }
    if (nnb > 0) {
        {
            write_loop wloop(cmn, nout, format_9993);
            wloop, "NX  ";
            for (i = 1; i <= nnb; i = i + 1) {
                wloop, nxval(i);
            }
        }
    }
    //
    //     Read the values of RANKVAL
    //
    read(nin, star), nrank;
    if (nn < 1) {
        write(nout, format_9996), " NRANK ", nrank, 1;
        nrank = 0;
        fatal = true;
    } else if (nn > maxin) {
        write(nout, format_9995), " NRANK ", nrank, maxin;
        nrank = 0;
        fatal = true;
    }
    {
        read_loop rloop(cmn, nin, star);
        for (i = 1; i <= nrank; i = i + 1) {
            rloop, rankval(i);
        }
    }
    for (i = 1; i <= nrank; i = i + 1) {
        if (rankval[i - 1] < 0) {
            write(nout, format_9996), " RANK  ", rankval(i), 0;
            fatal = true;
        } else if (rankval[i - 1] > 100) {
            write(nout, format_9995), " RANK  ", rankval(i), 100;
            fatal = true;
        }
    }
    if (nrank > 0) {
        {
            write_loop wloop(cmn, nout, format_9993);
            wloop, "RANK % OF N";
            for (i = 1; i <= nrank; i = i + 1) {
                wloop, rankval(i);
            }
        }
    }
    //
    //     Read the threshold value for the test ratios.
    //
    read(nin, star), thresh;
    write(nout, "(/,' Routines pass computational tests if test ratio is ','less than',"
                "f8.2,/)"),
        thresh;
    //
    //     Read the flag that indicates whether to test the LAPACK routines.
    //
    read(nin, star), tstchk;
    //
    //     Read the flag that indicates whether to test the driver routines.
    //
    read(nin, star), tstdrv;
    //
    //     Read the flag that indicates whether to test the error exits.
    //
    read(nin, star), tsterr;
    //
    if (fatal) {
        write(nout, "(/,' Execution not attempted due to input errors')");
        FEM_STOP(0);
    }
    //
    //     Calculate and prINTEGER the machine dependent constants.
    //
    eps = Rlamch("Underflow threshold");
    write(nout, format_9991), "underflow", eps;
    eps = Rlamch("Overflow threshold");
    write(nout, format_9991), "overflow ", eps;
    eps = Rlamch("Epsilon");
    write(nout, format_9991), "precision", eps;
    write(nout, star);
//
statement_80:
    //
    //     Read a test path and the number of matrix types to use.
    //
    try {
        read(nin, "(a72)"), aline;
    } catch (read_end const ) {
        goto statement_140;
    }
    path = aline[(3 - 1) * ldaline];
    nmats = matmax;
    i = 3;
statement_90:
    i++;
    if (i > 72) {
        nmats = matmax;
        goto statement_130;
    }
    if (aline[(i - 1) + (i - 1) * ldaline] == " ") {
        goto statement_90;
    }
    nmats = 0;
statement_100:
    c1 = aline[(i - 1) + (i - 1) * ldaline];
    for (k = 1; k <= 10; k = k + 1) {
        if (c1 == intstr[(k - 1) + (k - 1) * ldintstr]) {
            ic = k - 1;
            goto statement_120;
        }
    }
    goto statement_130;
statement_120:
    nmats = nmats * 10 + ic;
    i++;
    if (i > 72) {
        goto statement_130;
    }
    goto statement_100;
statement_130:
    c1 = path[(1 - 1)];
    c2 = path[(2 - 1) + (3 - 1) * ldpath];
    nrhs = nsval[1 - 1];
    //
    //     Check first character for correct precision.
    //
    if (!Mlsame(c1, "Double precision")) {
        write(nout, format_9990), path;
        //
    } else if (nmats <= 0) {
        //
        //        Check for a positive number of tests requested.
        //
        write(nout, format_9989), path;
        //
    } else if (Mlsamen(2, c2, "GE")) {
        //
        //        GE:  general matrices
        //
        ntypes = 11;
        Alareq(path, nmats, dotype, ntypes, nin, nout);
        //
        if (tstchk) {
            Rchkge(dotype, nm, mval, nn, nval, nnb2, nbval2, nns, nsval, thresh, tsterr, lda, &a[(1 - 1)], &a[(2 - 1) * lda], &a[(3 - 1) * lda], &b[(1 - 1)], &b[(2 - 1) * ldb], &b[(3 - 1) * ldb], work, rwork, iwork, nout);
        } else {
            write(nout, format_9989), path;
        }
        //
        if (tstdrv) {
            Rdrvge(dotype, nn, nval, nrhs, thresh, tsterr, lda, &a[(1 - 1)], &a[(2 - 1) * lda], &a[(3 - 1) * lda], &b[(1 - 1)], &b[(2 - 1) * ldb], &b[(3 - 1) * ldb], &b[(4 - 1) * ldb], s, work, rwork, iwork, nout);
        } else {
            write(nout, format_9988), path;
        }
        //
    } else if (Mlsamen(2, c2, "GB")) {
        //
        //        GB:  general banded matrices
        //
        la = (2 * kdmax + 1) * nmax;
        lafac = (3 * kdmax + 1) * nmax;
        ntypes = 8;
        Alareq(path, nmats, dotype, ntypes, nin, nout);
        //
        if (tstchk) {
            Rchkgb(dotype, nm, mval, nn, nval, nnb2, nbval2, nns, nsval, thresh, tsterr, &a[(1 - 1)], la, &a[(3 - 1) * lda], lafac, &b[(1 - 1)], &b[(2 - 1) * ldb], &b[(3 - 1) * ldb], work, rwork, iwork, nout);
        } else {
            write(nout, format_9989), path;
        }
        //
        if (tstdrv) {
            Rdrvgb(dotype, nn, nval, nrhs, thresh, tsterr, &a[(1 - 1)], la, &a[(3 - 1) * lda], lafac, &a[(6 - 1) * lda], &b[(1 - 1)], &b[(2 - 1) * ldb], &b[(3 - 1) * ldb], &b[(4 - 1) * ldb], s, work, rwork, iwork, nout);
        } else {
            write(nout, format_9988), path;
        }
        //
    } else if (Mlsamen(2, c2, "GT")) {
        //
        //        GT:  general tridiagonal matrices
        //
        ntypes = 12;
        Alareq(path, nmats, dotype, ntypes, nin, nout);
        //
        if (tstchk) {
            Rchkgt(dotype, nn, nval, nns, nsval, thresh, tsterr, &a[(1 - 1)], &a[(2 - 1) * lda], &b[(1 - 1)], &b[(2 - 1) * ldb], &b[(3 - 1) * ldb], work, rwork, iwork, nout);
        } else {
            write(nout, format_9989), path;
        }
        //
        if (tstdrv) {
            Rdrvgt(dotype, nn, nval, nrhs, thresh, tsterr, &a[(1 - 1)], &a[(2 - 1) * lda], &b[(1 - 1)], &b[(2 - 1) * ldb], &b[(3 - 1) * ldb], work, rwork, iwork, nout);
        } else {
            write(nout, format_9988), path;
        }
        //
    } else if (Mlsamen(2, c2, "PO")) {
        //
        //        PO:  positive definite matrices
        //
        ntypes = 9;
        Alareq(path, nmats, dotype, ntypes, nin, nout);
        //
        if (tstchk) {
            Rchkpo(dotype, nn, nval, nnb2, nbval2, nns, nsval, thresh, tsterr, lda, &a[(1 - 1)], &a[(2 - 1) * lda], &a[(3 - 1) * lda], &b[(1 - 1)], &b[(2 - 1) * ldb], &b[(3 - 1) * ldb], work, rwork, iwork, nout);
        } else {
            write(nout, format_9989), path;
        }
        //
        if (tstdrv) {
            Rdrvpo(dotype, nn, nval, nrhs, thresh, tsterr, lda, &a[(1 - 1)], &a[(2 - 1) * lda], &a[(3 - 1) * lda], &b[(1 - 1)], &b[(2 - 1) * ldb], &b[(3 - 1) * ldb], &b[(4 - 1) * ldb], s, work, rwork, iwork, nout);
        } else {
            write(nout, format_9988), path;
        }
        //
    } else if (Mlsamen(2, c2, "PS")) {
        //
        //        PS:  positive semi-definite matrices
        //
        ntypes = 9;
        //
        Alareq(path, nmats, dotype, ntypes, nin, nout);
        //
        if (tstchk) {
            Rchkps(dotype, nn, nval, nnb2, nbval2, nrank, rankval, thresh, tsterr, lda, &a[(1 - 1)], &a[(2 - 1) * lda], &a[(3 - 1) * lda], piv, work, rwork, nout);
        } else {
            write(nout, format_9989), path;
        }
        //
    } else if (Mlsamen(2, c2, "PP")) {
        //
        //        PP:  positive definite packed matrices
        //
        ntypes = 9;
        Alareq(path, nmats, dotype, ntypes, nin, nout);
        //
        if (tstchk) {
            Rchkpp(dotype, nn, nval, nns, nsval, thresh, tsterr, lda, &a[(1 - 1)], &a[(2 - 1) * lda], &a[(3 - 1) * lda], &b[(1 - 1)], &b[(2 - 1) * ldb], &b[(3 - 1) * ldb], work, rwork, iwork, nout);
        } else {
            write(nout, format_9989), path;
        }
        //
        if (tstdrv) {
            Rdrvpp(dotype, nn, nval, nrhs, thresh, tsterr, lda, &a[(1 - 1)], &a[(2 - 1) * lda], &a[(3 - 1) * lda], &b[(1 - 1)], &b[(2 - 1) * ldb], &b[(3 - 1) * ldb], &b[(4 - 1) * ldb], s, work, rwork, iwork, nout);
        } else {
            write(nout, format_9988), path;
        }
        //
    } else if (Mlsamen(2, c2, "PB")) {
        //
        //        PB:  positive definite banded matrices
        //
        ntypes = 8;
        Alareq(path, nmats, dotype, ntypes, nin, nout);
        //
        if (tstchk) {
            Rchkpb(dotype, nn, nval, nnb2, nbval2, nns, nsval, thresh, tsterr, lda, &a[(1 - 1)], &a[(2 - 1) * lda], &a[(3 - 1) * lda], &b[(1 - 1)], &b[(2 - 1) * ldb], &b[(3 - 1) * ldb], work, rwork, iwork, nout);
        } else {
            write(nout, format_9989), path;
        }
        //
        if (tstdrv) {
            Rdrvpb(dotype, nn, nval, nrhs, thresh, tsterr, lda, &a[(1 - 1)], &a[(2 - 1) * lda], &a[(3 - 1) * lda], &b[(1 - 1)], &b[(2 - 1) * ldb], &b[(3 - 1) * ldb], &b[(4 - 1) * ldb], s, work, rwork, iwork, nout);
        } else {
            write(nout, format_9988), path;
        }
        //
    } else if (Mlsamen(2, c2, "PT")) {
        //
        //        PT:  positive definite tridiagonal matrices
        //
        ntypes = 12;
        Alareq(path, nmats, dotype, ntypes, nin, nout);
        //
        if (tstchk) {
            Rchkpt(dotype, nn, nval, nns, nsval, thresh, tsterr, &a[(1 - 1)], &a[(2 - 1) * lda], &a[(3 - 1) * lda], &b[(1 - 1)], &b[(2 - 1) * ldb], &b[(3 - 1) * ldb], work, rwork, nout);
        } else {
            write(nout, format_9989), path;
        }
        //
        if (tstdrv) {
            Rdrvpt(dotype, nn, nval, nrhs, thresh, tsterr, &a[(1 - 1)], &a[(2 - 1) * lda], &a[(3 - 1) * lda], &b[(1 - 1)], &b[(2 - 1) * ldb], &b[(3 - 1) * ldb], work, rwork, nout);
        } else {
            write(nout, format_9988), path;
        }
        //
    } else if (Mlsamen(2, c2, "SY")) {
        //
        //        SY:  symmetric indefinite matrices,
        //             with partial (Bunch-Kaufman) pivoting algorithm
        //
        ntypes = 10;
        Alareq(path, nmats, dotype, ntypes, nin, nout);
        //
        if (tstchk) {
            Rchksy(dotype, nn, nval, nnb2, nbval2, nns, nsval, thresh, tsterr, lda, &a[(1 - 1)], &a[(2 - 1) * lda], &a[(3 - 1) * lda], &b[(1 - 1)], &b[(2 - 1) * ldb], &b[(3 - 1) * ldb], work, rwork, iwork, nout);
        } else {
            write(nout, format_9989), path;
        }
        //
        if (tstdrv) {
            Rdrvsy(dotype, nn, nval, nrhs, thresh, tsterr, lda, &a[(1 - 1)], &a[(2 - 1) * lda], &a[(3 - 1) * lda], &b[(1 - 1)], &b[(2 - 1) * ldb], &b[(3 - 1) * ldb], work, rwork, iwork, nout);
        } else {
            write(nout, format_9988), path;
        }
        //
    } else if (Mlsamen(2, c2, "SR")) {
        //
        //        SR:  symmetric indefinite matrices,
        //             with bounded Bunch-Kaufman (rook) pivoting algorithm
        //
        ntypes = 10;
        Alareq(path, nmats, dotype, ntypes, nin, nout);
        //
        if (tstchk) {
            Rchksy_rook(dotype, nn, nval, nnb2, nbval2, nns, nsval, thresh, tsterr, lda, &a[(1 - 1)], &a[(2 - 1) * lda], &a[(3 - 1) * lda], &b[(1 - 1)], &b[(2 - 1) * ldb], &b[(3 - 1) * ldb], work, rwork, iwork, nout);
        } else {
            write(nout, format_9989), path;
        }
        //
        if (tstdrv) {
            Rdrvsy_rook(dotype, nn, nval, nrhs, thresh, tsterr, lda, &a[(1 - 1)], &a[(2 - 1) * lda], &a[(3 - 1) * lda], &b[(1 - 1)], &b[(2 - 1) * ldb], &b[(3 - 1) * ldb], work, rwork, iwork, nout);
        } else {
            write(nout, format_9988), path;
        }
        //
    } else if (Mlsamen(2, c2, "SK")) {
        //
        //        SK:  symmetric indefinite matrices,
        //             with bounded Bunch-Kaufman (rook) pivoting algorithm,
        //             different matrix storage format than SR path version.
        //
        ntypes = 10;
        Alareq(path, nmats, dotype, ntypes, nin, nout);
        //
        if (tstchk) {
            Rchksy_rk(dotype, nn, nval, nnb2, nbval2, nns, nsval, thresh, tsterr, lda, &a[(1 - 1)], &a[(2 - 1) * lda], e, &a[(3 - 1) * lda], &b[(1 - 1)], &b[(2 - 1) * ldb], &b[(3 - 1) * ldb], work, rwork, iwork, nout);
        } else {
            write(nout, format_9989), path;
        }
        //
        if (tstdrv) {
            Rdrvsy_rk(dotype, nn, nval, nrhs, thresh, tsterr, lda, &a[(1 - 1)], &a[(2 - 1) * lda], e, &a[(3 - 1) * lda], &b[(1 - 1)], &b[(2 - 1) * ldb], &b[(3 - 1) * ldb], work, rwork, iwork, nout);
        } else {
            write(nout, format_9988), path;
        }
        //
    } else if (Mlsamen(2, c2, "SA")) {
        //
        //        SA:  symmetric indefinite matrices,
        //             with partial (Aasen's) pivoting algorithm
        //
        ntypes = 10;
        Alareq(path, nmats, dotype, ntypes, nin, nout);
        //
        if (tstchk) {
            Rchksy_aa(dotype, nn, nval, nnb2, nbval2, nns, nsval, thresh, tsterr, lda, &a[(1 - 1)], &a[(2 - 1) * lda], &a[(3 - 1) * lda], &b[(1 - 1)], &b[(2 - 1) * ldb], &b[(3 - 1) * ldb], work, rwork, iwork, nout);
        } else {
            write(nout, format_9989), path;
        }
        //
        if (tstdrv) {
            Rdrvsy_aa(dotype, nn, nval, nrhs, thresh, tsterr, lda, &a[(1 - 1)], &a[(2 - 1) * lda], &a[(3 - 1) * lda], &b[(1 - 1)], &b[(2 - 1) * ldb], &b[(3 - 1) * ldb], work, rwork, iwork, nout);
        } else {
            write(nout, format_9988), path;
        }
        //
    } else if (Mlsamen(2, c2, "S2")) {
        //
        //        SA:  symmetric indefinite matrices,
        //             with partial (Aasen's) pivoting algorithm
        //
        ntypes = 10;
        Alareq(path, nmats, dotype, ntypes, nin, nout);
        //
        if (tstchk) {
            Rchksy_aa_2stage(dotype, nn, nval, nnb2, nbval2, nns, nsval, thresh, tsterr, lda, &a[(1 - 1)], &a[(2 - 1) * lda], &a[(3 - 1) * lda], &b[(1 - 1)], &b[(2 - 1) * ldb], &b[(3 - 1) * ldb], work, rwork, iwork, nout);
        } else {
            write(nout, format_9989), path;
        }
        //
        if (tstdrv) {
            Rdrvsy_aa_2stage(dotype, nn, nval, nrhs, thresh, tsterr, lda, &a[(1 - 1)], &a[(2 - 1) * lda], &a[(3 - 1) * lda], &b[(1 - 1)], &b[(2 - 1) * ldb], &b[(3 - 1) * ldb], work, rwork, iwork, nout);
        } else {
            write(nout, format_9988), path;
        }
        //
    } else if (Mlsamen(2, c2, "SP")) {
        //
        //        SP:  symmetric indefinite packed matrices,
        //             with partial (Bunch-Kaufman) pivoting algorithm
        //
        ntypes = 10;
        Alareq(path, nmats, dotype, ntypes, nin, nout);
        //
        if (tstchk) {
            Rchksp(dotype, nn, nval, nns, nsval, thresh, tsterr, lda, &a[(1 - 1)], &a[(2 - 1) * lda], &a[(3 - 1) * lda], &b[(1 - 1)], &b[(2 - 1) * ldb], &b[(3 - 1) * ldb], work, rwork, iwork, nout);
        } else {
            write(nout, format_9989), path;
        }
        //
        if (tstdrv) {
            Rdrvsp(dotype, nn, nval, nrhs, thresh, tsterr, lda, &a[(1 - 1)], &a[(2 - 1) * lda], &a[(3 - 1) * lda], &b[(1 - 1)], &b[(2 - 1) * ldb], &b[(3 - 1) * ldb], work, rwork, iwork, nout);
        } else {
            write(nout, format_9988), path;
        }
        //
    } else if (Mlsamen(2, c2, "TR")) {
        //
        //        TR:  triangular matrices
        //
        ntypes = 18;
        Alareq(path, nmats, dotype, ntypes, nin, nout);
        //
        if (tstchk) {
            Rchktr(dotype, nn, nval, nnb2, nbval2, nns, nsval, thresh, tsterr, lda, &a[(1 - 1)], &a[(2 - 1) * lda], &b[(1 - 1)], &b[(2 - 1) * ldb], &b[(3 - 1) * ldb], work, rwork, iwork, nout);
        } else {
            write(nout, format_9989), path;
        }
        //
    } else if (Mlsamen(2, c2, "TP")) {
        //
        //        TP:  triangular packed matrices
        //
        ntypes = 18;
        Alareq(path, nmats, dotype, ntypes, nin, nout);
        //
        if (tstchk) {
            Rchktp(dotype, nn, nval, nns, nsval, thresh, tsterr, lda, &a[(1 - 1)], &a[(2 - 1) * lda], &b[(1 - 1)], &b[(2 - 1) * ldb], &b[(3 - 1) * ldb], work, rwork, iwork, nout);
        } else {
            write(nout, format_9989), path;
        }
        //
    } else if (Mlsamen(2, c2, "TB")) {
        //
        //        TB:  triangular banded matrices
        //
        ntypes = 17;
        Alareq(path, nmats, dotype, ntypes, nin, nout);
        //
        if (tstchk) {
            Rchktb(dotype, nn, nval, nns, nsval, thresh, tsterr, lda, &a[(1 - 1)], &a[(2 - 1) * lda], &b[(1 - 1)], &b[(2 - 1) * ldb], &b[(3 - 1) * ldb], work, rwork, iwork, nout);
        } else {
            write(nout, format_9989), path;
        }
        //
    } else if (Mlsamen(2, c2, "QR")) {
        //
        //        QR:  QR factorization
        //
        ntypes = 8;
        Alareq(path, nmats, dotype, ntypes, nin, nout);
        //
        if (tstchk) {
            Rchkqr(dotype, nm, mval, nn, nval, nnb, nbval, nxval, nrhs, thresh, tsterr, nmax, &a[(1 - 1)], &a[(2 - 1) * lda], &a[(3 - 1) * lda], &a[(4 - 1) * lda], &a[(5 - 1) * lda], &b[(1 - 1)], &b[(2 - 1) * ldb], &b[(3 - 1) * ldb], &b[(4 - 1) * ldb], work, rwork, iwork, nout);
        } else {
            write(nout, format_9989), path;
        }
        //
    } else if (Mlsamen(2, c2, "LQ")) {
        //
        //        LQ:  LQ factorization
        //
        ntypes = 8;
        Alareq(path, nmats, dotype, ntypes, nin, nout);
        //
        if (tstchk) {
            Rchklq(dotype, nm, mval, nn, nval, nnb, nbval, nxval, nrhs, thresh, tsterr, nmax, &a[(1 - 1)], &a[(2 - 1) * lda], &a[(3 - 1) * lda], &a[(4 - 1) * lda], &a[(5 - 1) * lda], &b[(1 - 1)], &b[(2 - 1) * ldb], &b[(3 - 1) * ldb], &b[(4 - 1) * ldb], work, rwork, nout);
        } else {
            write(nout, format_9989), path;
        }
        //
    } else if (Mlsamen(2, c2, "QL")) {
        //
        //        QL:  QL factorization
        //
        ntypes = 8;
        Alareq(path, nmats, dotype, ntypes, nin, nout);
        //
        if (tstchk) {
            Rchkql(dotype, nm, mval, nn, nval, nnb, nbval, nxval, nrhs, thresh, tsterr, nmax, &a[(1 - 1)], &a[(2 - 1) * lda], &a[(3 - 1) * lda], &a[(4 - 1) * lda], &a[(5 - 1) * lda], &b[(1 - 1)], &b[(2 - 1) * ldb], &b[(3 - 1) * ldb], &b[(4 - 1) * ldb], work, rwork, nout);
        } else {
            write(nout, format_9989), path;
        }
        //
    } else if (Mlsamen(2, c2, "RQ")) {
        //
        //        RQ:  RQ factorization
        //
        ntypes = 8;
        Alareq(path, nmats, dotype, ntypes, nin, nout);
        //
        if (tstchk) {
            Rchkrq(dotype, nm, mval, nn, nval, nnb, nbval, nxval, nrhs, thresh, tsterr, nmax, &a[(1 - 1)], &a[(2 - 1) * lda], &a[(3 - 1) * lda], &a[(4 - 1) * lda], &a[(5 - 1) * lda], &b[(1 - 1)], &b[(2 - 1) * ldb], &b[(3 - 1) * ldb], &b[(4 - 1) * ldb], work, rwork, iwork, nout);
        } else {
            write(nout, format_9989), path;
        }
        //
    } else if (Mlsamen(2, c2, "QP")) {
        //
        //        QP:  QR factorization with pivoting
        //
        ntypes = 6;
        Alareq(path, nmats, dotype, ntypes, nin, nout);
        //
        if (tstchk) {
            Rchkq3(dotype, nm, mval, nn, nval, nnb, nbval, nxval, thresh, &a[(1 - 1)], &a[(2 - 1) * lda], &b[(1 - 1)], &b[(3 - 1) * ldb], work, iwork, nout);
        } else {
            write(nout, format_9989), path;
        }
        //
    } else if (Mlsamen(2, c2, "TZ")) {
        //
        //        TZ:  Trapezoidal matrix
        //
        ntypes = 3;
        Alareq(path, nmats, dotype, ntypes, nin, nout);
        //
        if (tstchk) {
            Rchktz(dotype, nm, mval, nn, nval, thresh, tsterr, &a[(1 - 1)], &a[(2 - 1) * lda], &b[(1 - 1)], &b[(3 - 1) * ldb], work, nout);
        } else {
            write(nout, format_9989), path;
        }
        //
    } else if (Mlsamen(2, c2, "LS")) {
        //
        //        LS:  Least squares drivers
        //
        ntypes = 6;
        Alareq(path, nmats, dotype, ntypes, nin, nout);
        //
        if (tstdrv) {
            Rdrvls(dotype, nm, mval, nn, nval, nns, nsval, nnb, nbval, nxval, thresh, tsterr, &a[(1 - 1)], &a[(2 - 1) * lda], &b[(1 - 1)], &b[(2 - 1) * ldb], &b[(3 - 1) * ldb], rwork, &rwork[(nmax + 1) - 1], nout);
        } else {
            write(nout, format_9988), path;
        }
        //
    } else if (Mlsamen(2, c2, "EQ")) {
        //
        //        EQ:  Equilibration routines for general and positive definite
        //             matrices (THREQ should be between 2 and 10)
        //
        if (tstchk) {
            Rchkeq(threq, nout);
        } else {
            write(nout, format_9989), path;
        }
        //
    } else if (Mlsamen(2, c2, "QT")) {
        //
        //        QT:  QRT routines for general matrices
        //
        if (tstchk) {
            Rchkqrt(thresh, tsterr, nm, mval, nn, nval, nnb, nbval, nout);
        } else {
            write(nout, format_9989), path;
        }
        //
    } else if (Mlsamen(2, c2, "QX")) {
        //
        //        QX:  QRT routines for triangular-pentagonal matrices
        //
        if (tstchk) {
            Rchkqrtp(thresh, tsterr, nm, mval, nn, nval, nnb, nbval, nout);
        } else {
            write(nout, format_9989), path;
        }
        //
    } else if (Mlsamen(2, c2, "TQ")) {
        //
        //        TQ:  LQT routines for general matrices
        //
        if (tstchk) {
            Rchklqt(thresh, tsterr, nm, mval, nn, nval, nnb, nbval, nout);
        } else {
            write(nout, format_9989), path;
        }
        //
    } else if (Mlsamen(2, c2, "XQ")) {
        //
        //        XQ:  LQT routines for triangular-pentagonal matrices
        //
        if (tstchk) {
            Rchklqtp(thresh, tsterr, nm, mval, nn, nval, nnb, nbval, nout);
        } else {
            write(nout, format_9989), path;
        }
        //
    } else if (Mlsamen(2, c2, "TS")) {
        //
        //        TS:  QR routines for tall-skinny matrices
        //
        if (tstchk) {
            Rchktsqr(thresh, tsterr, nm, mval, nn, nval, nnb, nbval, nout);
        } else {
            write(nout, format_9989), path;
        }
        //
    } else if (Mlsamen(2, c2, "HH")) {
        //
        //        HH:  Householder reconstruction for tall-skinny matrices
        //
        if (tstchk) {
            Rchkorhr_col(thresh, tsterr, nm, mval, nn, nval, nnb, nbval, nout);
        } else {
            write(nout, format_9989), path;
        }
        //
    } else {
        //
        write(nout, format_9990), path;
    }
    //
    //     Go back to get another input line.
    //
    goto statement_80;
//
//     Branch to this line when the last record is read.
//
statement_140:
    cmn.io.close(nin);
    s2 = dsecnd[-1];
    write(nout, "(/,' End of tests')");
    write(nout, "(' Total time used = ',f12.2,' seconds',/)"), s2 - s1;
    //
    //     End of Rchkaa
    //
}

INTEGER main(INTEGER argc, char const *argv[]) { return main_with_catch(argc, argv, placeholder_please_replace::program_Rchkaa); }
