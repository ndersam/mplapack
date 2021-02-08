# The MPLAPACK is a multiprecision linear algebra package based on BLAS and LAPACK.
This package is rewritten in C++, and supports several high precision
libraries like GMP, MPFR and QD etc so that users can choose for user's
convenience. The MPLAPACK is a free software (2-clause BSD style license with
original license by LAPACK).

# How to build and install
```
$ git clone https://github.com/nakatamaho/mplapack/
$ cd mplapack ; autoreconf --force --install ; aclocal ; autoconf ; automake; autoreconf --force --install
$ ./configure --enable-gmp --enable-__float128 --enable-dd --enable-mpfr
```
do not worry about a lot of warnings in the second commands.

# Docker build (not working yet)

```
$ docker image build -t maho/mplapack:latest .
$ docker run -it maho/mplapack:latest
```


# Acknowledgement:

This work has been supported by:
The Special Postdoctoral Researchers' Program of RIKEN (2008, 2009)
Grant-in-Aid for Scientific Research (B) 21300017 from the Japan Society for the Promotion of Science (2009, 2010, 2011).
Microsoft Research CORE6 (2010). 

# Special thanks to:

Fujisawa, Katsuki
Goto, Kazushige
Himeno, Ryutaro
.

Please refer userman.pdf for details. Please enjoy!

# contact
NAKATA Maho <maho@riken.jp>
