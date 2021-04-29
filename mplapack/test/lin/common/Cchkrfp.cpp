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

void program_Cchkrfp(INTEGER argc, char const *argv[]) {
    common cmn(argc, argv);
    common_read read(cmn);
    common_write write(cmn);
    static const char *format_9991 = "(' Relative machine ',a,' is taken to be',d16.6)";
    static const char *format_9993 = "(4x,a4,':  ',10i6,/,11x,10i6)";
    static const char *format_9995 = "(' !! Invalid input value: ',a4,'=',i6,'; must be <=',i6)";
    static const char *format_9996 = "(' !! Invalid input value: ',a4,'=',i6,'; must be >=',i6)";
    //
    //  -- LAPACK test routine --
    //  -- LAPACK is a software package provided by Univ. of Tennessee,    --
    //  -- Univ. of California Berkeley, Univ. of Colorado Denver and NAG Ltd..--
    //
    //  =====================================================================
    //
    //     .. Parameters ..
    //     ..
    //     .. Local Scalars ..
    //
    //     ..
    //     .. Local Arrays ..
    //     ..
    //     .. External Functions ..
    //     ..
    //     .. External Subroutines ..
    //     ..
    //     .. Executable Statements ..
    //
    REAL s1 = dsecnd[-1];
    bool fatal = false;
    //
    //     Read a dummy line.
    //
    const INTEGER nin = 5;
    read(nin, star);
    //
    //     Report LAPACK version tag (e.g. LAPACK-3.2.0)
    //
    INTEGER vers_major = 0;
    INTEGER vers_minor = 0;
    INTEGER vers_patch = 0;
    ilaver(vers_major, vers_minor, vers_patch);
    const INTEGER nout = 6;
    write(nout, "(/,' Tests of the COMPLEX*16 LAPACK RFP routines ',/,' LAPACK VERSION ',"
                "i1,'.',i1,'.',i1,/,/,' The following parameter values will be used:')"),
        vers_major, vers_minor, vers_patch;
    //
    //     Read the values of N
    //
    INTEGER nn = 0;
    read(nin, star), nn;
    const INTEGER maxin = 12;
    if (nn < 1) {
        write(nout, format_9996), " NN ", nn, 1;
        nn = 0;
        fatal = true;
    } else if (nn > maxin) {
        write(nout, format_9995), " NN ", nn, maxin;
        nn = 0;
        fatal = true;
    }
    arr_1d<maxin, int> nval(fill0);
    INTEGER i = 0;
    {
        read_loop rloop(cmn, nin, star);
        for (i = 1; i <= nn; i = i + 1) {
            rloop, nval(i);
        }
    }
    const INTEGER nmax = 50;
    for (i = 1; i <= nn; i = i + 1) {
        if (nval[i - 1] < 0) {
            write(nout, format_9996), " M  ", nval(i), 0;
            fatal = true;
        } else if (nval[i - 1] > nmax) {
            write(nout, format_9995), " M  ", nval(i), nmax;
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
    INTEGER nns = 0;
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
    arr_1d<maxin, int> nsval(fill0);
    {
        read_loop rloop(cmn, nin, star);
        for (i = 1; i <= nns; i = i + 1) {
            rloop, nsval(i);
        }
    }
    const INTEGER maxrhs = 16;
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
    //     Read the matrix types
    //
    INTEGER nnt = 0;
    read(nin, star), nnt;
    const INTEGER ntypes = 9;
    if (nnt < 1) {
        write(nout, format_9996), " NMA", nnt, 1;
        nnt = 0;
        fatal = true;
    } else if (nnt > ntypes) {
        write(nout, format_9995), " NMA", nnt, ntypes;
        nnt = 0;
        fatal = true;
    }
    arr_1d<ntypes, int> ntval(fill0);
    {
        read_loop rloop(cmn, nin, star);
        for (i = 1; i <= nnt; i = i + 1) {
            rloop, ntval(i);
        }
    }
    for (i = 1; i <= nnt; i = i + 1) {
        if (ntval[i - 1] < 0) {
            write(nout, format_9996), "TYPE", ntval(i), 0;
            fatal = true;
        } else if (ntval[i - 1] > ntypes) {
            write(nout, format_9995), "TYPE", ntval(i), ntypes;
            fatal = true;
        }
    }
    if (nnt > 0) {
        {
            write_loop wloop(cmn, nout, format_9993);
            wloop, "TYPE";
            for (i = 1; i <= nnt; i = i + 1) {
                wloop, ntval(i);
            }
        }
    }
    //
    //     Read the threshold value for the test ratios.
    //
    REAL thresh = 0.0;
    read(nin, star), thresh;
    write(nout, "(/,' Routines pass computational tests if test ratio is ','less than',"
                "f8.2,/)"),
        thresh;
    //
    //     Read the flag that indicates whether to test the error exits.
    //
    bool tsterr = false;
    read(nin, star), tsterr;
    //
    if (fatal) {
        write(nout, "(/,' Execution not attempted due to input errors')");
        FEM_STOP(0);
    }
    //
    //     Calculate and prINTEGER the machine dependent constants.
    //
    REAL eps = Rlamch("Underflow threshold");
    write(nout, format_9991), "underflow", eps;
    eps = Rlamch("Overflow threshold");
    write(nout, format_9991), "overflow ", eps;
    eps = Rlamch("Epsilon");
    write(nout, format_9991), "precision", eps;
    write(nout, star);
    //
    //     Test the error exit of:
    //
    if (tsterr) {
        Cerrrfp(nout);
    }
    //
    //    Test the routines: Cpftrf, Cpftri, Cpftrs (as in Cdrvpo).
    //    This also tests the routines: Ctfsm, Ctftri, Ctfttr, Ctrttf.
    //
    fill0);
    fill0);
    arr_1d<3 * nmax, COMPLEX> z_work_zlatms(fill0);
    fill0);
    arr_1d<nmax, REAL> d_work_zlatms(fill0);
    arr_1d<nmax, REAL> d_work_Clanhe(fill0);
    arr_1d<nmax, REAL> d_work_Cpot01(fill0);
    arr_1d<nmax, REAL> d_work_Cpot02(fill0);
    arr_1d<nmax, REAL> d_work_Cpot03(fill0);
    Cdrvrfp(nout, nn, nval, nns, nsval, nnt, ntval, thresh, worka, workasav, workafac, workainv, workb, workbsav, workxact, workx, workarf, workarfinv, z_work_zlatms, z_work_Cpot02, z_work_Cpot03, d_work_zlatms, d_work_Clanhe, d_work_Cpot01, d_work_Cpot02, d_work_Cpot03);
    //
    //    Test the routine: Clanhf
    //
    Cdrvrf1(nout, nn, nval, thresh, worka, nmax, workarf, d_work_Clanhe);
    //
    //    Test the conversion routines:
    //       zhfttp, ztpthf, Ctfttr, Ctrttf, Ctrttp and Ctpttr.
    //
    fill0);
    Cdrvrf2(nout, nn, nval, worka, nmax, workarf, workap, workasav);
    //
    //    Test the routine: Ctfsm
    //
    Cdrvrf3(nout, nn, nval, thresh, worka, nmax, workarf, workainv, workafac, d_work_Clanhe, z_work_Cpot03, z_work_Cpot02);
    //
    //    Test the routine: Chfrk
    //
    Cdrvrf4(nout, nn, nval, thresh, worka, workafac, nmax, workarf, workainv, nmax, d_work_Clanhe);
    //
    cmn.io.close(nin);
    REAL s2 = dsecnd[-1];
    write(nout, "(/,' End of tests')");
    write(nout, "(' Total time used = ',f12.2,' seconds',/)"), s2 - s1;
    //
    //     End of Cchkrfp
    //
}

INTEGER main(INTEGER argc, char const *argv[]) { return main_with_catch(argc, argv, placeholder_please_replace::program_Cchkrfp); }