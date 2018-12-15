# Makefile for building Eigenmath on Linux machines.
#
# 1. Compile it.
#
#	$ make
#
# 2. Test it.
#
#	$ ./math selftest
#
# 3. Press control-c to quit.
#
#	> ^C
#	$
#
# 4. Scripts can be run from the command line.
#
#	$ ./math StaticSphericalMetric
#
#	$ ./math script1 script2 script3
#
# 5. See eigenmath.net for more.


# divby1billion() in mstr.c doesn't work with -O2
CC = gcc
CFLAGS = -Wall -Wuninitialized -O -DLINUX

objects = \
abs.o \
add.o \
adj.o \
alloc.o \
append.o \
arccos.o \
arccosh.o \
arcsin.o \
arcsinh.o \
arctan.o \
arctanh.o \
arg.o \
bake.o \
besselj.o \
bessely.o \
bignum.o \
binomial.o \
ceiling.o \
choose.o \
circexp.o \
clear.o \
clock.o \
coeff.o \
cofactor.o \
condense.o \
conj.o \
cons.o \
contract.o \
cos.o \
cosh.o \
data.o \
decomp.o \
define.o \
defint.o \
degree.o \
denominator.o \
derivative.o \
det.o \
dirac.o \
display.o \
distill.o \
divisors.o \
dpow.o \
dsolve.o \
eigen.o \
erf.o \
erfc.o \
eval.o \
expand.o \
expcos.o \
expsin.o \
factor.o \
factorial.o \
factorpoly.o \
factors.o \
filter.o \
find.o \
float.o \
floor.o \
for.o \
gamma.o \
gcd.o \
guess.o \
hermite.o \
hilbert.o \
imag.o \
index.o \
init.o \
inner.o \
integral.o \
inv.o \
is.o \
isprime.o \
itab.o \
itest.o \
laguerre.o \
laplace.o \
lcm.o \
leading.o \
legendre.o \
list.o \
log.o \
madd.o \
mag.o \
main.o \
mcmp.o \
mgcd.o \
mini-test.o \
misc.o \
mmodpow.o \
mmul.o \
mod.o \
mpow.o \
mprime.o \
mroot.o \
mscan.o \
mstr.o \
multiply.o \
nroots.o \
numerator.o \
outer.o \
partition.o \
polar.o \
pollard.o \
power.o \
prime.o \
primetab.o \
print.o \
product.o \
qadd.o \
qdiv.o \
qmul.o \
qpow.o \
qsub.o \
quickfactor.o \
quotient.o \
rationalize.o \
real.o \
rect.o \
rewrite.o \
roots.o \
run.o \
scan.o \
selftest.o \
sgn.o \
simfac.o \
simplify.o \
sin.o \
sinh.o \
stack.o \
subst.o \
sum.o \
symbol.o \
tan.o \
tanh.o \
taylor.o \
tensor.o \
test.o \
transform.o \
transpose.o \
userfunc.o \
variables.o \
vectorize.o \
zero.o

math : $(objects)
	gcc -o math $(objects) -lm

$(objects) : defs.h prototypes.h

selftest.o : selftest.h
