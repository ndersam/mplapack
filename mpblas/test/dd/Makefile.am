#CTBSV, CTPSV might have bugs or intrinsically inaccurate
#Rnrm2 should be checked more
check_PROGRAMS = $(mpblas_dd_test_PROGRAMS) 
TESTS = $(check_PROGRAMS)
mpblas_dd_test_PROGRAMS = \
arithmetic.test_dd \
complex.test_dd \
iCamax.test.dd_opt iCamax.test.dd   \
iRamax.test.dd_opt iRamax.test.dd   \
Mlsame.test.dd_opt Mlsame.test.dd   \
Mxerbla.test.dd_opt Mxerbla.test.dd \
CRrot.test.dd_opt  CRrot.test.dd    \
CRscal.test.dd_opt CRscal.test.dd   \
Caxpy.test.dd_opt  Caxpy.test.dd    \
Ccopy.test.dd_opt  Ccopy.test.dd    \
Cdotc.test.dd_opt  Cdotc.test.dd	\
Cdotu.test.dd_opt  Cdotu.test.dd	\
Cgbmv.test.dd_opt  Cgbmv.test.dd	\
Cgemm.test.dd_opt  Cgemm.test.dd	\
Cgemv.test.dd_opt  Cgemv.test.dd	\
Cgerc.test.dd_opt  Cgerc.test.dd	\
Cgeru.test.dd_opt  Cgeru.test.dd    \
Chbmv.test.dd_opt  Chbmv.test.dd	\
Chemm.test.dd_opt  Chemm.test.dd	\
Chemv.test.dd_opt  Chemv.test.dd	\
Cher.test.dd_opt   Cher.test.dd 	\
Cher2.test.dd_opt  Cher2.test.dd	\
Cher2k.test.dd_opt Cher2k.test.dd	\
Cherk.test.dd_opt  Cherk.test.dd	\
Chpmv.test.dd_opt  Chpmv.test.dd	\
Chpr.test.dd_opt   Chpr.test.dd	\
Chpr2.test.dd_opt  Chpr2.test.dd	\
Crotg.test.dd_opt  Crotg.test.dd	\
Cscal.test.dd_opt  Cscal.test.dd	\
Cswap.test.dd_opt  Cswap.test.dd	\
Csymm.test.dd_opt  Csymm.test.dd    \
Csyr2k.test.dd_opt Csyr2k.test.dd	\
Csyrk.test.dd_opt  Csyrk.test.dd	\
Ctbmv.test.dd_opt  Ctbmv.test.dd	\
Ctbsv.test.dd_opt  Ctbsv.test.dd	\
Ctpmv.test.dd_opt  Ctpmv.test.dd	\
Ctpsv.test.dd_opt  Ctpsv.test.dd	\
Ctrmm.test.dd_opt  Ctrmm.test.dd	\
Ctrmv.test.dd_opt  Ctrmv.test.dd	\
Ctrsm.test.dd_opt  Ctrsm.test.dd	\
Ctrsv.test.dd_opt  Ctrsv.test.dd	\
RCabs1.test.dd_opt RCabs1.test.dd	\
RCasum.test.dd_opt RCasum.test.dd	\
RCnrm2.test.dd_opt RCnrm2.test.dd	\
Rasum.test.dd_opt  Rasum.test.dd    \
Raxpy.test.dd_opt  Raxpy.test.dd	\
Rcopy.test.dd_opt  Rcopy.test.dd	\
Rdot.test.dd_opt   Rdot.test.dd	\
Rgbmv.test.dd_opt  Rgbmv.test.dd	\
Rgemm.test.dd_opt  Rgemm.test.dd	\
Rgemv.test.dd_opt  Rgemv.test.dd	\
Rger.test.dd_opt   Rger.test.dd	\
Rnrm2.test.dd_opt  Rnrm2.test.dd	\
Rrot.test.dd_opt   Rrot.test.dd	\
Rrotg.test.dd_opt  Rrotg.test.dd	\
Rrotm.test.dd_opt  Rrotm.test.dd	\
Rsbmv.test.dd_opt  Rsbmv.test.dd	\
Rscal.test.dd_opt  Rscal.test.dd	\
Rspmv.test.dd_opt  Rspmv.test.dd    \
Rspr.test.dd_opt   Rspr.test.dd	\
Rspr2.test.dd_opt  Rspr2.test.dd	\
Rswap.test.dd_opt  Rswap.test.dd	\
Rsymm.test.dd_opt  Rsymm.test.dd	\
Rsymv.test.dd_opt  Rsymv.test.dd	\
Rsyr.test.dd_opt   Rsyr.test.dd	\
Rsyr2.test.dd_opt  Rsyr2.test.dd	\
Rsyr2k.test.dd_opt Rsyr2k.test.dd	\
Rsyrk.test.dd_opt  Rsyrk.test.dd	\
Rtbmv.test.dd_opt  Rtbmv.test.dd	\
Rtbsv.test.dd_opt  Rtbsv.test.dd	\
Rtpmv.test.dd_opt  Rtpmv.test.dd	\
Rtpsv.test.dd_opt  Rtpsv.test.dd	\
Rtrmm.test.dd_opt  Rtrmm.test.dd    \
Rtrmv.test.dd_opt  Rtrmv.test.dd	\
Rtrsm.test.dd_opt  Rtrsm.test.dd	\
Rtrsv.test.dd_opt  Rtrsv.test.dd

mpblas_dd_testdir = $(prefix)/share/mplapack/test/mpblas/dd
libdepends = -L$(top_builddir)/mpblas/reference -lmpblas_dd -lmpblas_mpfr
opt_libdepends = -L$(top_builddir)/mpblas/optimized/dd -lmpblas_dd_opt -L$(top_builddir)/mpblas/reference -lmpblas_mpfr
mplibs=-L$(MPC_LIBDIR) -L$(MPFR_LIBDIR) -L$(GMP_LIBDIR) -lmpc -lmpfr -lgmpxx -lgmp -L$(QD_LIBDIR) -lqd
refblas=-L$(top_builddir)/external/i/LAPACK/lib -lblas $(FCLIBS)

test_cxxflags = $(OPENMP_CXXFLAGS) -I$(top_srcdir)/include -I$(top_srcdir)/mpfrc++ -I$(GMP_INCLUDEDIR) -I$(MPFR_INCLUDEDIR) -I$(MPC_INCLUDEDIR) -I$(QD_INCLUDEDIR) -I$(top_srcdir)/mpfrc++ -D___MPLAPACK_BUILD_WITH_DD___ -D___MPLAPACK_INTERNAL___

if !IS_MACOSX
test_srcdepends = ../common/xerbla.cpp ../common/mplapack.test.cpp ../common/Mxerbla.override.cpp
endif

if IS_MACOSX
lib_LTLIBRARIES = libmxerbla_override.la
libmxerbla_override_la_CPPFLAGS = -I$(top_srcdir)/include -D___MPLAPACK_BUILD_WITH_DD___
libmxerbla_override_la_SOURCES =  ../common/Mxerbla.override.cpp
libmxerbla_override_la_LDFLAGS= -Wl,-flat_namespace,-undefined,dynamic_lookup
test_srcdepends = ../common/xerbla.cpp ../common/mplapack.test.cpp
mplibs+=-Wl,-flat_namespace,-undefined,dynamic_lookup
TESTS_ENVIRONMENT=DYLD_INSERT_LIBRARIES=.libs/libmxerbla_override.0.dylib
endif

##
arithmetic_test_dd_SOURCES=../common/arithmetic.test.cpp $(test_srcdepends)
arithmetic_test_dd_CXXFLAGS=$(test_cxxflags)
arithmetic_test_dd_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

complex_test_dd_SOURCES=../common/complex.test.cpp $(test_srcdepends)
complex_test_dd_CXXFLAGS=$(test_cxxflags)
complex_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

iCamax_test_dd_opt_SOURCES=../common/iCamax.test.cpp $(test_srcdepends)
iCamax_test_dd_opt_CXXFLAGS=$(test_cxxflags)
iCamax_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

iCamax_test_dd_SOURCES=../common/iCamax.test.cpp $(test_srcdepends)
iCamax_test_dd_CXXFLAGS=$(test_cxxflags)
iCamax_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

iRamax_test_dd_opt_SOURCES=../common/iRamax.test.cpp $(test_srcdepends)
iRamax_test_dd_opt_CXXFLAGS=$(test_cxxflags)
iRamax_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

iRamax_test_dd_SOURCES=../common/iRamax.test.cpp $(test_srcdepends)
iRamax_test_dd_CXXFLAGS=$(test_cxxflags)
iRamax_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Mlsame_test_dd_opt_SOURCES=../common/Mlsame.test.cpp $(test_srcdepends)
Mlsame_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Mlsame_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Mlsame_test_dd_SOURCES=../common/Mlsame.test.cpp $(test_srcdepends)
Mlsame_test_dd_CXXFLAGS=$(test_cxxflags)
Mlsame_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Mxerbla_test_dd_opt_SOURCES=../common/Mxerbla.test.cpp $(test_srcdepends)
Mxerbla_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Mxerbla_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Mxerbla_test_dd_SOURCES=../common/Mxerbla.test.cpp $(test_srcdepends)
Mxerbla_test_dd_CXXFLAGS=$(test_cxxflags)
Mxerbla_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

CRrot_test_dd_opt_SOURCES=../common/CRrot.test.cpp $(test_srcdepends)
CRrot_test_dd_opt_CXXFLAGS=$(test_cxxflags)
CRrot_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

CRrot_test_dd_SOURCES=../common/CRrot.test.cpp $(test_srcdepends)
CRrot_test_dd_CXXFLAGS=$(test_cxxflags)
CRrot_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

CRscal_test_dd_opt_SOURCES=../common/CRscal.test.cpp $(test_srcdepends)
CRscal_test_dd_opt_CXXFLAGS=$(test_cxxflags)
CRscal_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

CRscal_test_dd_SOURCES=../common/CRscal.test.cpp $(test_srcdepends)
CRscal_test_dd_CXXFLAGS=$(test_cxxflags)
CRscal_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Caxpy_test_dd_SOURCES=../common/Caxpy.test.cpp $(test_srcdepends)
Caxpy_test_dd_CXXFLAGS=$(test_cxxflags)
Caxpy_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Caxpy_test_dd_opt_SOURCES=../common/Caxpy.test.cpp $(test_srcdepends)
Caxpy_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Caxpy_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Ccopy_test_dd_SOURCES=../common/Ccopy.test.cpp $(test_srcdepends)
Ccopy_test_dd_CXXFLAGS=$(test_cxxflags)
Ccopy_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Ccopy_test_dd_opt_SOURCES=../common/Ccopy.test.cpp $(test_srcdepends)
Ccopy_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Ccopy_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Cdotc_test_dd_SOURCES=../common/Cdotc.test.cpp $(test_srcdepends)
Cdotc_test_dd_CXXFLAGS=$(test_cxxflags)
Cdotc_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Cdotc_test_dd_opt_SOURCES=../common/Cdotc.test.cpp $(test_srcdepends)
Cdotc_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Cdotc_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Cdotu_test_dd_SOURCES=../common/Cdotu.test.cpp $(test_srcdepends)
Cdotu_test_dd_CXXFLAGS=$(test_cxxflags)
Cdotu_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Cdotu_test_dd_opt_SOURCES=../common/Cdotu.test.cpp $(test_srcdepends)
Cdotu_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Cdotu_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Cgbmv_test_dd_SOURCES=../common/Cgbmv.test.cpp $(test_srcdepends)
Cgbmv_test_dd_CXXFLAGS=$(test_cxxflags)
Cgbmv_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Cgbmv_test_dd_opt_SOURCES=../common/Cgbmv.test.cpp $(test_srcdepends)
Cgbmv_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Cgbmv_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Cgemm_test_dd_SOURCES=../common/Cgemm.test.cpp $(test_srcdepends)
Cgemm_test_dd_CXXFLAGS=$(test_cxxflags)
Cgemm_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Cgemm_test_dd_opt_SOURCES=../common/Cgemm.test.cpp $(test_srcdepends)
Cgemm_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Cgemm_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Cgemv_test_dd_SOURCES=../common/Cgemv.test.cpp $(test_srcdepends)
Cgemv_test_dd_CXXFLAGS=$(test_cxxflags)
Cgemv_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Cgemv_test_dd_opt_SOURCES=../common/Cgemv.test.cpp $(test_srcdepends)
Cgemv_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Cgemv_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Cgerc_test_dd_SOURCES=../common/Cgerc.test.cpp $(test_srcdepends)
Cgerc_test_dd_CXXFLAGS=$(test_cxxflags)
Cgerc_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Cgerc_test_dd_opt_SOURCES=../common/Cgerc.test.cpp $(test_srcdepends)
Cgerc_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Cgerc_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Cgeru_test_dd_SOURCES=../common/Cgeru.test.cpp $(test_srcdepends)
Cgeru_test_dd_CXXFLAGS=$(test_cxxflags)
Cgeru_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Cgeru_test_dd_opt_SOURCES=../common/Cgeru.test.cpp $(test_srcdepends)
Cgeru_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Cgeru_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Chbmv_test_dd_SOURCES=../common/Chbmv.test.cpp $(test_srcdepends)
Chbmv_test_dd_CXXFLAGS=$(test_cxxflags)
Chbmv_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Chbmv_test_dd_opt_SOURCES=../common/Chbmv.test.cpp $(test_srcdepends)
Chbmv_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Chbmv_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Chemm_test_dd_SOURCES=../common/Chemm.test.cpp $(test_srcdepends)
Chemm_test_dd_CXXFLAGS=$(test_cxxflags)
Chemm_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Chemm_test_dd_opt_SOURCES=../common/Chemm.test.cpp $(test_srcdepends)
Chemm_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Chemm_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Chemv_test_dd_SOURCES=../common/Chemv.test.cpp $(test_srcdepends)
Chemv_test_dd_CXXFLAGS=$(test_cxxflags)
Chemv_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Chemv_test_dd_opt_SOURCES=../common/Chemv.test.cpp $(test_srcdepends)
Chemv_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Chemv_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Cher_test_dd_SOURCES=../common/Cher.test.cpp $(test_srcdepends)
Cher_test_dd_CXXFLAGS=$(test_cxxflags)
Cher_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Cher_test_dd_opt_SOURCES=../common/Cher.test.cpp $(test_srcdepends)
Cher_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Cher_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Cher2_test_dd_SOURCES=../common/Cher2.test.cpp $(test_srcdepends)
Cher2_test_dd_CXXFLAGS=$(test_cxxflags)
Cher2_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Cher2_test_dd_opt_SOURCES=../common/Cher2.test.cpp $(test_srcdepends)
Cher2_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Cher2_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Cher2k_test_dd_SOURCES=../common/Cher2k.test.cpp $(test_srcdepends)
Cher2k_test_dd_CXXFLAGS=$(test_cxxflags)
Cher2k_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Cher2k_test_dd_opt_SOURCES=../common/Cher2k.test.cpp $(test_srcdepends)
Cher2k_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Cher2k_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Cherk_test_dd_SOURCES=../common/Cherk.test.cpp $(test_srcdepends)
Cherk_test_dd_CXXFLAGS=$(test_cxxflags)
Cherk_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Cherk_test_dd_opt_SOURCES=../common/Cherk.test.cpp $(test_srcdepends)
Cherk_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Cherk_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Chpmv_test_dd_SOURCES=../common/Chpmv.test.cpp $(test_srcdepends)
Chpmv_test_dd_CXXFLAGS=$(test_cxxflags)
Chpmv_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Chpmv_test_dd_opt_SOURCES=../common/Chpmv.test.cpp $(test_srcdepends)
Chpmv_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Chpmv_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Chpr_test_dd_SOURCES=../common/Chpr.test.cpp $(test_srcdepends)
Chpr_test_dd_CXXFLAGS=$(test_cxxflags)
Chpr_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Chpr_test_dd_opt_SOURCES=../common/Chpr.test.cpp $(test_srcdepends)
Chpr_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Chpr_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Chpr2_test_dd_SOURCES=../common/Chpr2.test.cpp $(test_srcdepends)
Chpr2_test_dd_CXXFLAGS=$(test_cxxflags)
Chpr2_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Chpr2_test_dd_opt_SOURCES=../common/Chpr2.test.cpp $(test_srcdepends)
Chpr2_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Chpr2_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Crotg_test_dd_SOURCES=../common/Crotg.test.cpp $(test_srcdepends)
Crotg_test_dd_CXXFLAGS=$(test_cxxflags)
Crotg_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Crotg_test_dd_opt_SOURCES=../common/Crotg.test.cpp $(test_srcdepends)
Crotg_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Crotg_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Cscal_test_dd_SOURCES=../common/Cscal.test.cpp $(test_srcdepends)
Cscal_test_dd_CXXFLAGS=$(test_cxxflags)
Cscal_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Cscal_test_dd_opt_SOURCES=../common/Cscal.test.cpp $(test_srcdepends)
Cscal_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Cscal_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Cswap_test_dd_SOURCES=../common/Cswap.test.cpp $(test_srcdepends)
Cswap_test_dd_CXXFLAGS=$(test_cxxflags)
Cswap_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Cswap_test_dd_opt_SOURCES=../common/Cswap.test.cpp $(test_srcdepends)
Cswap_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Cswap_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Csymm_test_dd_SOURCES=../common/Csymm.test.cpp $(test_srcdepends)
Csymm_test_dd_CXXFLAGS=$(test_cxxflags)
Csymm_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Csymm_test_dd_opt_SOURCES=../common/Csymm.test.cpp $(test_srcdepends)
Csymm_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Csymm_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Csyr2k_test_dd_SOURCES=../common/Csyr2k.test.cpp $(test_srcdepends)
Csyr2k_test_dd_CXXFLAGS=$(test_cxxflags)
Csyr2k_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Csyr2k_test_dd_opt_SOURCES=../common/Csyr2k.test.cpp $(test_srcdepends)
Csyr2k_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Csyr2k_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Csyrk_test_dd_SOURCES=../common/Csyrk.test.cpp $(test_srcdepends)
Csyrk_test_dd_CXXFLAGS=$(test_cxxflags)
Csyrk_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Csyrk_test_dd_opt_SOURCES=../common/Csyrk.test.cpp $(test_srcdepends)
Csyrk_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Csyrk_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Ctbmv_test_dd_SOURCES=../common/Ctbmv.test.cpp $(test_srcdepends)
Ctbmv_test_dd_CXXFLAGS=$(test_cxxflags)
Ctbmv_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Ctbmv_test_dd_opt_SOURCES=../common/Ctbmv.test.cpp $(test_srcdepends)
Ctbmv_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Ctbmv_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Ctbsv_test_dd_SOURCES=../common/Ctbsv.test.cpp $(test_srcdepends)
Ctbsv_test_dd_CXXFLAGS=$(test_cxxflags)
Ctbsv_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Ctbsv_test_dd_opt_SOURCES=../common/Ctbsv.test.cpp $(test_srcdepends)
Ctbsv_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Ctbsv_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Ctpmv_test_dd_SOURCES=../common/Ctpmv.test.cpp $(test_srcdepends)
Ctpmv_test_dd_CXXFLAGS=$(test_cxxflags)
Ctpmv_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Ctpmv_test_dd_opt_SOURCES=../common/Ctpmv.test.cpp $(test_srcdepends)
Ctpmv_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Ctpmv_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Ctpsv_test_dd_SOURCES=../common/Ctpsv.test.cpp $(test_srcdepends)
Ctpsv_test_dd_CXXFLAGS=$(test_cxxflags)
Ctpsv_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Ctpsv_test_dd_opt_SOURCES=../common/Ctpsv.test.cpp $(test_srcdepends)
Ctpsv_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Ctpsv_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Ctrmm_test_dd_SOURCES=../common/Ctrmm.test.cpp $(test_srcdepends)
Ctrmm_test_dd_CXXFLAGS=$(test_cxxflags)
Ctrmm_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Ctrmm_test_dd_opt_SOURCES=../common/Ctrmm.test.cpp $(test_srcdepends)
Ctrmm_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Ctrmm_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Ctrmv_test_dd_SOURCES=../common/Ctrmv.test.cpp $(test_srcdepends)
Ctrmv_test_dd_CXXFLAGS=$(test_cxxflags)
Ctrmv_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Ctrmv_test_dd_opt_SOURCES=../common/Ctrmv.test.cpp $(test_srcdepends)
Ctrmv_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Ctrmv_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Ctrsm_test_dd_SOURCES=../common/Ctrsm.test.cpp $(test_srcdepends)
Ctrsm_test_dd_CXXFLAGS=$(test_cxxflags)
Ctrsm_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Ctrsm_test_dd_opt_SOURCES=../common/Ctrsm.test.cpp $(test_srcdepends)
Ctrsm_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Ctrsm_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Ctrsv_test_dd_SOURCES=../common/Ctrsv.test.cpp $(test_srcdepends)
Ctrsv_test_dd_CXXFLAGS=$(test_cxxflags)
Ctrsv_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Ctrsv_test_dd_opt_SOURCES=../common/Ctrsv.test.cpp $(test_srcdepends)
Ctrsv_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Ctrsv_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

RCabs1_test_dd_opt_SOURCES=../common/RCabs1.test.cpp $(test_srcdepends)
RCabs1_test_dd_opt_CXXFLAGS=$(test_cxxflags)
RCabs1_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

RCabs1_test_dd_SOURCES=../common/RCabs1.test.cpp $(test_srcdepends)
RCabs1_test_dd_CXXFLAGS=$(test_cxxflags)
RCabs1_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

RCasum_test_dd_opt_SOURCES=../common/RCasum.test.cpp $(test_srcdepends)
RCasum_test_dd_opt_CXXFLAGS=$(test_cxxflags)
RCasum_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

RCasum_test_dd_SOURCES=../common/RCasum.test.cpp $(test_srcdepends)
RCasum_test_dd_CXXFLAGS=$(test_cxxflags)
RCasum_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

RCnrm2_test_dd_opt_SOURCES=../common/RCnrm2.test.cpp $(test_srcdepends)
RCnrm2_test_dd_opt_CXXFLAGS=$(test_cxxflags)
RCnrm2_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

RCnrm2_test_dd_SOURCES=../common/RCnrm2.test.cpp $(test_srcdepends)
RCnrm2_test_dd_CXXFLAGS=$(test_cxxflags)
RCnrm2_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Rasum_test_dd_opt_SOURCES=../common/Rasum.test.cpp $(test_srcdepends)
Rasum_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Rasum_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Rasum_test_dd_SOURCES=../common/Rasum.test.cpp $(test_srcdepends)
Rasum_test_dd_CXXFLAGS=$(test_cxxflags)
Rasum_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Raxpy_test_dd_opt_SOURCES=../common/Raxpy.test.cpp $(test_srcdepends)
Raxpy_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Raxpy_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Raxpy_test_dd_SOURCES=../common/Raxpy.test.cpp $(test_srcdepends)
Raxpy_test_dd_CXXFLAGS=$(test_cxxflags)
Raxpy_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Rcopy_test_dd_opt_SOURCES=../common/Rcopy.test.cpp $(test_srcdepends)
Rcopy_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Rcopy_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Rcopy_test_dd_SOURCES=../common/Rcopy.test.cpp $(test_srcdepends)
Rcopy_test_dd_CXXFLAGS=$(test_cxxflags)
Rcopy_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Rdot_test_dd_opt_SOURCES=../common/Rdot.test.cpp $(test_srcdepends)
Rdot_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Rdot_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Rdot_test_dd_SOURCES=../common/Rdot.test.cpp $(test_srcdepends)
Rdot_test_dd_CXXFLAGS=$(test_cxxflags)
Rdot_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Rgbmv_test_dd_opt_SOURCES=../common/Rgbmv.test.cpp $(test_srcdepends)
Rgbmv_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Rgbmv_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Rgbmv_test_dd_SOURCES=../common/Rgbmv.test.cpp $(test_srcdepends)
Rgbmv_test_dd_CXXFLAGS=$(test_cxxflags)
Rgbmv_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Rgemm_test_dd_opt_SOURCES=../common/Rgemm.test.cpp $(test_srcdepends)
Rgemm_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Rgemm_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Rgemm_test_dd_SOURCES=../common/Rgemm.test.cpp $(test_srcdepends)
Rgemm_test_dd_CXXFLAGS=$(test_cxxflags)
Rgemm_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Rgemv_test_dd_opt_SOURCES=../common/Rgemv.test.cpp $(test_srcdepends)
Rgemv_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Rgemv_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Rgemv_test_dd_SOURCES=../common/Rgemv.test.cpp $(test_srcdepends)
Rgemv_test_dd_CXXFLAGS=$(test_cxxflags)
Rgemv_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Rger_test_dd_opt_SOURCES=../common/Rger.test.cpp $(test_srcdepends)
Rger_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Rger_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Rger_test_dd_SOURCES=../common/Rger.test.cpp $(test_srcdepends)
Rger_test_dd_CXXFLAGS=$(test_cxxflags)
Rger_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Rnrm2_test_dd_opt_SOURCES=../common/Rnrm2.test.cpp $(test_srcdepends)
Rnrm2_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Rnrm2_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Rnrm2_test_dd_SOURCES=../common/Rnrm2.test.cpp $(test_srcdepends)
Rnrm2_test_dd_CXXFLAGS=$(test_cxxflags)
Rnrm2_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Rrot_test_dd_opt_SOURCES=../common/Rrot.test.cpp $(test_srcdepends)
Rrot_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Rrot_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Rrot_test_dd_SOURCES=../common/Rrot.test.cpp $(test_srcdepends)
Rrot_test_dd_CXXFLAGS=$(test_cxxflags)
Rrot_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Rrotg_test_dd_opt_SOURCES=../common/Rrotg.test.cpp $(test_srcdepends)
Rrotg_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Rrotg_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Rrotg_test_dd_SOURCES=../common/Rrotg.test.cpp $(test_srcdepends)
Rrotg_test_dd_CXXFLAGS=$(test_cxxflags)
Rrotg_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Rrotm_test_dd_opt_SOURCES=../common/Rrotm.test.cpp $(test_srcdepends)
Rrotm_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Rrotm_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Rrotm_test_dd_SOURCES=../common/Rrotm.test.cpp $(test_srcdepends)
Rrotm_test_dd_CXXFLAGS=$(test_cxxflags)
Rrotm_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Rsbmv_test_dd_opt_SOURCES=../common/Rsbmv.test.cpp $(test_srcdepends)
Rsbmv_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Rsbmv_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Rsbmv_test_dd_SOURCES=../common/Rsbmv.test.cpp $(test_srcdepends)
Rsbmv_test_dd_CXXFLAGS=$(test_cxxflags)
Rsbmv_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Rscal_test_dd_opt_SOURCES=../common/Rscal.test.cpp $(test_srcdepends)
Rscal_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Rscal_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Rscal_test_dd_SOURCES=../common/Rscal.test.cpp $(test_srcdepends)
Rscal_test_dd_CXXFLAGS=$(test_cxxflags)
Rscal_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Rspmv_test_dd_opt_SOURCES=../common/Rspmv.test.cpp $(test_srcdepends)
Rspmv_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Rspmv_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Rspmv_test_dd_SOURCES=../common/Rspmv.test.cpp $(test_srcdepends)
Rspmv_test_dd_CXXFLAGS=$(test_cxxflags)
Rspmv_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Rspr_test_dd_opt_SOURCES=../common/Rspr.test.cpp $(test_srcdepends)
Rspr_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Rspr_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Rspr_test_dd_SOURCES=../common/Rspr.test.cpp $(test_srcdepends)
Rspr_test_dd_CXXFLAGS=$(test_cxxflags)
Rspr_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Rspr2_test_dd_opt_SOURCES=../common/Rspr2.test.cpp $(test_srcdepends)
Rspr2_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Rspr2_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Rspr2_test_dd_SOURCES=../common/Rspr2.test.cpp $(test_srcdepends)
Rspr2_test_dd_CXXFLAGS=$(test_cxxflags)
Rspr2_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Rswap_test_dd_opt_SOURCES=../common/Rswap.test.cpp $(test_srcdepends)
Rswap_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Rswap_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Rswap_test_dd_SOURCES=../common/Rswap.test.cpp $(test_srcdepends)
Rswap_test_dd_CXXFLAGS=$(test_cxxflags)
Rswap_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Rsymm_test_dd_opt_SOURCES=../common/Rsymm.test.cpp $(test_srcdepends)
Rsymm_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Rsymm_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Rsymm_test_dd_SOURCES=../common/Rsymm.test.cpp $(test_srcdepends)
Rsymm_test_dd_CXXFLAGS=$(test_cxxflags)
Rsymm_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Rsymv_test_dd_opt_SOURCES=../common/Rsymv.test.cpp $(test_srcdepends)
Rsymv_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Rsymv_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Rsymv_test_dd_SOURCES=../common/Rsymv.test.cpp $(test_srcdepends)
Rsymv_test_dd_CXXFLAGS=$(test_cxxflags)
Rsymv_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Rsyr_test_dd_opt_SOURCES=../common/Rsyr.test.cpp $(test_srcdepends)
Rsyr_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Rsyr_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Rsyr_test_dd_SOURCES=../common/Rsyr.test.cpp $(test_srcdepends)
Rsyr_test_dd_CXXFLAGS=$(test_cxxflags)
Rsyr_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Rsyr2_test_dd_opt_SOURCES=../common/Rsyr2.test.cpp $(test_srcdepends)
Rsyr2_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Rsyr2_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Rsyr2_test_dd_SOURCES=../common/Rsyr2.test.cpp $(test_srcdepends)
Rsyr2_test_dd_CXXFLAGS=$(test_cxxflags)
Rsyr2_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Rsyr2k_test_dd_opt_SOURCES=../common/Rsyr2k.test.cpp $(test_srcdepends)
Rsyr2k_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Rsyr2k_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Rsyr2k_test_dd_SOURCES=../common/Rsyr2k.test.cpp $(test_srcdepends)
Rsyr2k_test_dd_CXXFLAGS=$(test_cxxflags)
Rsyr2k_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Rsyrk_test_dd_opt_SOURCES=../common/Rsyrk.test.cpp $(test_srcdepends)
Rsyrk_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Rsyrk_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Rsyrk_test_dd_SOURCES=../common/Rsyrk.test.cpp $(test_srcdepends)
Rsyrk_test_dd_CXXFLAGS=$(test_cxxflags)
Rsyrk_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Rtbmv_test_dd_opt_SOURCES=../common/Rtbmv.test.cpp $(test_srcdepends)
Rtbmv_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Rtbmv_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Rtbmv_test_dd_SOURCES=../common/Rtbmv.test.cpp $(test_srcdepends)
Rtbmv_test_dd_CXXFLAGS=$(test_cxxflags)
Rtbmv_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Rtbsv_test_dd_opt_SOURCES=../common/Rtbsv.test.cpp $(test_srcdepends)
Rtbsv_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Rtbsv_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Rtbsv_test_dd_SOURCES=../common/Rtbsv.test.cpp $(test_srcdepends)
Rtbsv_test_dd_CXXFLAGS=$(test_cxxflags)
Rtbsv_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Rtpmv_test_dd_opt_SOURCES=../common/Rtpmv.test.cpp $(test_srcdepends)
Rtpmv_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Rtpmv_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Rtpmv_test_dd_SOURCES=../common/Rtpmv.test.cpp $(test_srcdepends)
Rtpmv_test_dd_CXXFLAGS=$(test_cxxflags)
Rtpmv_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Rtpsv_test_dd_opt_SOURCES=../common/Rtpsv.test.cpp $(test_srcdepends)
Rtpsv_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Rtpsv_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Rtpsv_test_dd_SOURCES=../common/Rtpsv.test.cpp $(test_srcdepends)
Rtpsv_test_dd_CXXFLAGS=$(test_cxxflags)
Rtpsv_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Rtrmm_test_dd_opt_SOURCES=../common/Rtrmm.test.cpp $(test_srcdepends)
Rtrmm_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Rtrmm_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Rtrmm_test_dd_SOURCES=../common/Rtrmm.test.cpp $(test_srcdepends)
Rtrmm_test_dd_CXXFLAGS=$(test_cxxflags)
Rtrmm_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Rtrmv_test_dd_opt_SOURCES=../common/Rtrmv.test.cpp $(test_srcdepends)
Rtrmv_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Rtrmv_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Rtrmv_test_dd_SOURCES=../common/Rtrmv.test.cpp $(test_srcdepends)
Rtrmv_test_dd_CXXFLAGS=$(test_cxxflags)
Rtrmv_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Rtrsm_test_dd_opt_SOURCES=../common/Rtrsm.test.cpp $(test_srcdepends)
Rtrsm_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Rtrsm_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Rtrsm_test_dd_SOURCES=../common/Rtrsm.test.cpp $(test_srcdepends)
Rtrsm_test_dd_CXXFLAGS=$(test_cxxflags)
Rtrsm_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

Rtrsv_test_dd_opt_SOURCES=../common/Rtrsv.test.cpp $(test_srcdepends)
Rtrsv_test_dd_opt_CXXFLAGS=$(test_cxxflags)
Rtrsv_test_dd_opt_LDFLAGS=$(opt_libdepends) $(mplibs) $(refblas)

Rtrsv_test_dd_SOURCES=../common/Rtrsv.test.cpp $(test_srcdepends)
Rtrsv_test_dd_CXXFLAGS=$(test_cxxflags)
Rtrsv_test_dd_LDFLAGS=$(libdepends) $(mplibs) $(refblas)

