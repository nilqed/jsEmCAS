# jsEmCAS
Javascript Computer Algebra System (standalone/emscripten based on eigenmath)

Standalone html file ``jsemcas.html`` (~3MB): [Test it.](http://nilqed.github.io/jsEmCAS/)

# Built-in functions

[Source](https://web.archive.org/web/20050322045320/http://eigenmath.sourceforge.net:80/functions.html)

Here is a list of the built-in functions. There is an index at the bottom of the page.

Index
[abs](#absx)
[adj](#adj)
arccos
arccosh
arcsin
arcsinh
arctan
arctanh
binomial
break
ceiling
check
condense
conj
contract
cos
cosh
d
det
dim
display
do
dot
draw
eigen
eval
exp
expcos
expsin
factor
factorial
filter
float
floor
for
gcd
hermite
hilbert
inner
integral
inv
isprime
laguerre
lcm
legendre
log
mod
outer
prime
print
product
prog
quote
rank
rationalize
return
roots
simplify
sin
sinh
sqrt
stop
subst
sum
tan
tanh
taylor
test
trace
transpose
unit
wedge
zero


## abs(x)
Returns the absolute value (vector length, magnitude) of x.

Enter

     abs(a - b) + abs(b - a)

Result

     2 abs(a - b)

Enter

     abs(3 + 4 i)

Result

     5

Enter

     abs((a,b,c))

Result

                   1/2
       2    2    2
     (a  + b  + c )

Enter

     A = (1,i,-i)

     sqrt(dot(A,conj(A))) - abs(A)

Result

     0

Enter

     A = ((1,2),(3,4))

     abs(A)

Result

     stop: abs(tensor) with tensor rank > 1

## adj(m)
Returns the adjunct of matrix m.

Enter

     A = ((a,b),(c,d))

     adj(A)

Result

     d     -b
 
     -c    a

The inverse of a matrix is equal to the adjunct divided by the determinant.

Enter

     inv(A) - adj(A) / det(A)

Result

     0

## arccos(x)
Returns the inverse cosine of x.

## arccosh(x)
Returns the inverse hyperbolic cosine of x.

## arcsin(x)
Returns the inverse sine of x.

## arcsinh(x)
Returns the inverse hyperbolic sine of x.

## arctan(x)
Returns the inverse tangent of x.

## arctanh(x)
Returns the inverse hyperbolic tangent of x.

## binomial(n,k)
Returns the binomial coefficient.

Enter

     binomial(10,5)

Result

     252

## break(x)
Causes an immediate return from a for function. Expression x is evaluated and returned as the for function value. A break with no argument returns the symbol nil. A break can be evaluated at any function level. For example, for() can evaluate f() which evaluates g() which evaluates break().

## ceiling(x)
Returns the smallest integer not less than x.

## check(x)
If x is zero then continue, else stop.

## condense(x)
Attempts to simplify expression x by factoring common terms.

Enter

     2 a (x + 1)

Result

     2 a + 2 a x

Enter

     condense(last)

Result

     2 a (x + 1)

## conj(x)
Returns the complex conjugate of x.

Enter

     conj(3+4i)

Result

     3 - 4 i

## contract(a,i,j)
Returns the contraction of tensor a across indices i and j. If i and j are omitted then indices 1 and 2 are used. The following example shows how contract adds diagonal elements.

Enter

     A = ((a,b),(c,d))

     contract(A,1,2)

Result

     a + d

## cos(x)
Returns the cosine of x.

## cosh(x)
Returns the hyperbolic cosine of x.

## d(f,x)
Returns the partial derivative of f with respect to x. The second argument can be omitted in which case the computer will guess which symbol to use.

Enter

     d(x^2,x)

Result

     2 x

For tensor f the derivative of each element is computed.

Enter

     d((x,x^2),x)

Result

      1
 
     2 x

Returns the gradient of f when x is a vector. Note that gradient raises the rank of f by 1.

Enter

     u = x^2 + y^3

     d(u,(x,y))

Result

     2 x
 
 
        2
     3 y

Functions with 0-arity are treated as dependent on all variables.

Enter

     d(f(),(x,y))

Result

     d(f(),x)
 
     d(f(),y)

Since partial derivatives commute, multi-derivatives are ordered to produce a canonical form.

Enter

     d(d(f(),y),x)

Result

     d(d(f(),x),y)

## det(m)
Returns the determinant of matrix m.

Enter

     A = ((a,b),(c,d))

     det(A)

Result

     a d - b c

## dim(a,i)
Returns the dimension of the ith index of tensor a. If i is omitted then the dimension of the first index is returned.

Enter

     A = (1,2,3,4)

     dim(A)

Result

     4

Enter

     A = ((1,2,3),(4,5,6))

     dim(A,1)

Result

     2

Enter

     dim(A,2)

Result

     3

## display(x)
Evaluates expression x and displays the result using Times and Symbol fonts. User symbols are scanned for the keywords shown below. Each keyword is replaced with its associated Greek letter glyph. Multiglyph symbols are displayed using subscripts. This function can be selected as the default display mode by setting tty = 0.

	Gamma	Γ 		alpha	α 		mu	μ
	Delta	Δ 		beta	β 		nu	ν
 	Theta	Θ 		gamma	γ 		xi	ξ
 	Lambda	Λ 		delta	δ 		pi	π
 	Xi	Ξ 		    epsilon	ε 		rho	ρ
 	Pi	Π 		    zeta	ζ 		sigma	σ
 	Sigma	Σ 		eta	η 		    tau	τ
 	Upsilon	Υ 		theta	θ 		upsilon	υ
 	Phi	Φ 		    iota	ι 		phi	φ
 	Psi	Ψ 		    kappa	κ 		chi	χ
 	Omega	Ω 		lambda	λ 		psi	ψ 
	omega	ω

## do(a,b,...)
Evaluates each statement in sequence. Returns the value of the last statement.

## dot(a,b,...)
Returns the dot product of tensors (aka inner product).

Enter

     A = (A1,A2,A3)

     B = (B1,B2,B3)

     dot(A,B)

Result

     A1 B1 + A2 B2 + A3 B3

The dot product is equivalent to an outer product followed by a contraction across the inner indices.

Enter

     A = hilbert(10)

     dot(A,A) - contract(outer(A,A),2,3)

Result

     0

## draw(f,x)
Draws a graph of f. The second argument can be omitted in which case the computer will guess what variable to use. Parametric drawing occurs when f returns a vector. Ranges are set with xrange and yrange. The defaults are xrange = (-10,10) and yrange = (-10,10). The parametric variable range is set with trange. The default is trange = (-pi,pi).

## eigen(m)
## eigenval(m)
## eigenvec(m)
These functions compute eigenvalues and eigenvectors numerically. Matrix m must be both numerical and symmetric. The eigenval function returns a matrix with the eigenvalues along the diagonal. The eigenvec function returns a matrix with the eigenvectors arranged as row vectors. The eigen function does not return anything but stores the eigenvalue matrix in D and the eigenvector matrix in Q.

Example 1. Check the relation AX = lambda X where lambda is an eigenvalue and X is the associated eigenvector.

Enter

     A = hilbert(3)

     eigen(A)

     lambda = D[1,1]

     X = Q[1]

     dot(A,X) - lambda X

Result

     -1.16435e-14
 
     -6.46705e-15
 
     -4.55191e-15

Example 2: Check the relation A = QTDQ.

Enter

	A - dot(transpose(Q),D,Q)

Result
 
	6.27365e-12    -1.58236e-11   1.81902e-11
 
	-1.58236e-11   -1.95365e-11   2.56514e-12
 
	1.81902e-11    2.56514e-12    1.32627e-11

## eval(x)
Returns the evaluation of expression x.

Enter

     A = quote(sin(pi/6))

     A

Result

          1
     sin(--- pi)
          6

Enter

     eval(A)

Result

      1
     ---
      2

## exp(x)
Returns the exponential of x. The expression exp(1) should be used to represent the natural number e.

Enter

     exp(1.0)

Result

     2.71828

Enter

     exp(a) exp(b)

Result

     exp(a + b)

## expcos(x)
Returns the exponential cosine of x.

Enter

     expcos(x)

Result

      1               1
     --- exp(-i x) + --- exp(i x)
      2               2

## expsin(x)
Returns the exponential sine of x.

Enter

     expsin(x)

Result

      1                 1
     --- i exp(-i x) - --- i exp(i x)
      2                 2

## factor(n)
## factor(p,x)
The first form returns the prime factors for integer n.

Enter

     factor(12345)

Result

     3 5 823

The second form factors polynomial p in x. The argument x can be omitted in which case the computer will guess which symbol to use.

Enter

     factor(x^3 + x^2 + x + 1)

Result

                   2
     (1 + x) (1 + x )

## factorial(x)
Returns the factorial of x. The syntax x! can also be used.

Enter

     factorial(100)

Result

     93326215443944152681699238856266700490715968264381621468592963895217599993229915
     608941463976156518286253697920827223758251185210916864000000000000000000000000

Enter

     factorial(100) - 100!

Result

     0

## filter(f,a,b,...)
Returns f with terms containing a (or b or...) removed. Useful for implementing a "poor man's" Fourier transform.

Enter

     Y = A exp(-i k x) + B exp(i k x)

     filter(Y exp(-i k x), x)

Result

     B

## float(x)
Converts rational numbers and integers in x to floating point values. The symbol pi is also converted.

Enter

     float(100!)

Result

     9.33262e+157

## floor(x)
Returns the largest integer not greater than x.

## for(a,i,j,b)
For a equals i through j evaluate b. Normally for() returns the symbol nil. A break() function can be used to return a different value. The variable a has local scope within the for function. The variable a remains unmodified after for returns. The expressions i and j must evaluate to integers. Usually b is a do() function.

Enter

     for(k,1,4,print(1/k,tab(10),1/k^2))

Result
 
     1         1
 
      1         1
     ---       ---
      2         4
 
      1         1
     ---       ---
      3         9
 
      1         1
     ---       ----
      4         16

## gcd(a,b)
Returns the greatest common divisor of a and b.

## hermite(x,n)
Returns the nth Hermite polynomial in x.

Enter

     H(x,3)

Result

                3
     -12 x + 8 x

## hilbert(n)
Returns a Hilbert matrix of order n.

Enter

     hilbert(3)

Result

             1      1
      1     ---    ---
             2      3
 
      1      1      1
     ---    ---    ---
      2      3      4
 
      1      1      1
     ---    ---    ---
      3      4      5

## inner(a,b,...)
Returns the inner product of tensors. This is the same function as the dot product.

Enter

     A = (A1,A2,A3)

     B = (B1,B2,B3)

     inner(A,B)

Result 

     A1 B1 + A2 B2 + A3 B3

## integral(f,x)
Returns the integral of f with respect to x. The second argument can be omitted in which case the computer will guess which symbol to use.

Enter

     integral(log(x),x)

Result

     -x + x log(x)

## inv(m)
Returns the inverse of matrix m.

Enter

     A = ((a,b),(c,d))

     inv(A)

Result

           d                 b
      -----------     - -----------
       a d - b c         a d - b c
 
            c               a
     - -----------     -----------
        a d - b c       a d - b c

## isprime(n)
Returns 1 if integer n is a prime number. Returns 0 if n is not a prime number.

Enter

     isprime(9007199254740991)

Result

     0

Enter

     isprime(2^53 - 111)

Result

     1

## laguerre(x,n,a)
Returns the nth Laguerre polynomial in x. If the argument a is omitted or a equals zero then the function returns the non-associated Laguerre polynomial.

Enter

     laguerre(x,2)

Result

                1   2
     1 - 2 x + --- x
                2

Enter

     laguerre(x,2,a)

Result

          3                   1   2    1   2
     1 + --- a - 2 x - a x + --- a  + --- x
          2                   2        2

## lcm(a,b)
Returns the least common multiple of a and b. The least common multiple is the smallest value or expression divisible by both a and b.

Enter

     lcm(4,6)

Result

     12

Enter

     lcm(4 x, 6 x y)

Result

     12 x y

## legendre(x,n,m)
Returns the nth Legendre polynomial in x.

Enter

     legendre(x,2)

Result

        1     3   2
     - --- + --- x
        2     2

Enter

     legendre(x,2,0)

Result

        1     3   2
     - --- + --- x
        2     2

Enter

     legendre(x,2,1)

Result

                  1/2
                2
     -3 x (1 - x )

## log(x)
Returns the natural logarithm of x.

Enter

     log(10.0)

Result

     2.30259

Enter

     log(-10.0)

Result

     2.30259 + i π

## mod(a,b)
Returns the remainder of a divided by b.

## outer(a,b,...)
Returns the outer product of tensors (aka tensor product).

Enter

     A = (A1,A2,A3)

     B = (B1,B2,B3)

     outer(A,B)

Result

     A1 B1    A1 B2    A1 B3

     A2 B1    A2 B2    A2 B3

     A3 B1    A3 B2    A3 B3

## prime(n)
Returns the nth prime number. The value of n must be greater than zero and less than 10,001.

Enter

     prime(1)

Result

     2

Enter

     prime(10000)

Result

     104729

## print(a,b,...)
The print function evaluates and prints each expression. The printing is done in tty mode. The symbol nil is returned as the function value. Spaces and other text can be printed by using quoted strings for print arguments. This function can be selected as the default printing mode by setting the symbol tty = 1.

## product(a,i,j,b)
For a equals i through j evaluate b. Returns the product of all b. The variable a has local scope within the product function, a remains unchanged after the product function returns. The expressions i and j should evaluate to integers.

Enter

     product(k,1,3,1/(1-(1/prime(k)^s)))

Result

                     1
     ----------------------------------
            1          1          1
      (1 - ----) (1 - ----) (1 - ----)
             s          s          s
            2          3          5

## prog(a,b,...,f)
The prog function evaluates f. The result of the evaluation of f is returned as the prog value. The variables a,b,... have local scope within prog. The variables a,b,... remain unmodified after prog returns. Usually f is a do function.

## quote(x)
Returns expression x without evaluating symbols or functions. Can be used to clear symbolic values.

Enter

     n = 3

     n

Result

     3

Enter

     n = quote(n)

     n

Result

     n

## rank(a)
Returns the rank (number of indices) of tensor a.

Enter

     U = (u1,u2,u3,u4)

     rank(U)

Result

     1

## rationalize(x)
Puts terms in x over a common denominator.

Enter

     rationalize(1/x + 1/y)

Result

      x + y
     -------
       x y

Rationalize can often simplify expressions.

Enter

     A = ((a,b),(c,d))

     B = inv(A)

     dot(A,B)

Result

         a d           b c
     ----------- - -----------                0
      a d - b c     a d - b c
 
                                      a d           b c
                 0                ----------- - -----------
                                   a d - b c     a d - b c

Enter

     rationalize(last)

Result

     1    0
 
     0    1

## return(x)
Evaluation of return causes an immediate exit from prog. Expression x is evaluated and returned as the prog value. A return with no argument returns the symbol nil. A return can be evaluated at any function level. For example, prog() can evaluate f() which evaluates g() which evaluates return().

## roots(p,x)
Finds the values of x for which the polynomial p(x) equals zero. Graphically, the roots of p are the x coordinates where the curve p(x) crosses the horizontal line. The argument p may be expressed as an equality. The argument x can be omitted if it is literally x, y, z, t or r. If there is more than one root then a vector containing the roots is returned. If p cannot be factored then roots returns the symbol nil. Note: The symbol nil is not normally printed so no result is visible when p cannot be factored.

Enter

     (x - 1/2) (x - 1/3) (x + 1/4) / x^3

Result

            1         1        7
     1 + ------- - ------- - ------
              3         2     12 x
          24 x      24 x

Enter

     roots(last,x)

Result

        1
     - ---
        4

       1
      ---
       3

       1
      ---
       2

Enter

     roots(a x = b)

Result

      b
     ---
      a

Enter

     roots(a x^2 + b x + c)

Result

                             1/2
                           2
         b      (-4 a c + b )
     - ----- - ------------------
        2 a           2 a

                             1/2
                           2
         b      (-4 a c + b )
     - ----- + ------------------
        2 a           2 a

## simplify(x)
Evaluates expression x and then attempts to simplify the result.

Enter

     (A-B)/(B-A)

Result

        A          B
     -------- - --------
      -A + B     -A + B
 
Enter

     simplify(last)

Result

     -1

Enter

     A = ((A11,A12),(A21,A22))

     det(A) inv(A) - adj(A)

Result

     ((-A22 + A11 A22^2 / (A11 A22 - A12 A21) - A12 A21 A22 / (A11 A22 - A12 A21),
     A12 - A11 A12 A22 / (A11 A22 - A12 A21) + A12^2 A21 / (A11 A22 - A12 A21)),
     (A21 - A11 A21 A22 / (A11 A22 - A12 A21) + A12 A21^2 / (A11 A22 - A12 A21),
     -A11 - A11 A12 A21 / (A11 A22 - A12 A21) + A11^2 A22 / (A11 A22 - A12 A21)))

Enter

     simplify(last)

Result

     0

In many cases the result of simplify will be a denormalized form. Denormalized forms can fail in tests for equality. The eval function returns normalized forms and can be used to undo the result of simplify.

## sin(x)
Returns the sine of x.

## sinh(x)
Returns the hyperbolic sine of x.

## sqrt(x)
Returns the square root of x.

## stop()
When evaluated in a script, the stop function exits run mode and returns to interactive mode.

## subst(a,b,c)
Substitutes a for b in c and returns the result. Note that this operation can return a denormalized expression. Use eval to normalize the result of subst.

Enter

     f = x^2

     subst(sqrt(x),x,f)

Result

           2
       1/2
     (x   )

Enter

     eval(last)

Result

     x

## sum(a,i,j,b)
For a equals i through j evaluate b. Returns the sum of all b. The variable a has local scope within the sum function, a remains unchanged after the sum function returns. The expressions i and j should evaluate to integers.

Enter

     sum(k,1,3,1/k^s)

Result

          1      1
     1 + ---- + ----
           s      s
          2      3

## tan(x)
Returns the tangent of x.

## tanh(x)
Returns the hyperbolic tangent of x.

## taylor(f,x,n,a)
Returns the Taylor expansion of f at a. If a is omitted then zero is used. The argument x is the free variable in f and n is the power of the expansion.

Enter

     taylor(1/cos(x),x,6)

Result

          1   2    5    4    61    6
     1 + --- x  + ---- x  + ----- x
          2        24        720

## test(a,b,c,d,...)
If a is true then b is returned else if c is true then d is returned, etc. If none are true then the test function is returned unevaluated. An expression is true if it evaluates to a nonzero numerical value. If an expression evaluates to zero or a symbolic expression then it is not true. The following relational operators and their equivalent functions can be used:

	==	testeq

	>=	testge

	>	testgt

	<=	testle

	<	testlt

Each relational operator evaluates to 1 if the relation is true and 0 if the relation is false. If the relation cannot be determined then the associated relational function is returned unevaluated.

Enter

	2 < 3

Result

	1

Enter

	3 < 2

Result

	0

Enter

	a < b

Result

	testlt(a,b)

The AND and OR of relations can be implemented using multiplication and addition. For example, the following function returns 1 when x is between a and b, otherwise 0 is returned.

     pulse(x) = test(
          (x >= a) * (x <= b), 1,
          (x < a) + (x > b), 0)		# could use else clause "1, 0)"

Relational operators have lower precedence than addition and multiplication so the relational expressions are parenthesized in this case. In this example the else clause is not used so that pulse returns unevaluated if the relation cannot be determined.

## trace(m)
Returns the trace of matrix m.

Enter

     A = ((a,b),(c,d))

     trace(A)

Result

     a + d

Note that trace is equivalent to contract.

Enter

     trace(A) - contract(A,1,2)

Result

     0

## transpose(a,i,j)
Returns the transpose of tensor a across indices i and j. If i and j are omitted then indices 1 and 2 are used.

## unit(n)
Returns a unit matrix with dimension n.

Enter

     unit(4)

Result

     1    0    0    0

     0    1    0    0

     0    0    1    0

     0    0    0    1

## wedge(u,v)
## wedge(u,v,w)
Returns the wedge product of tensors.

Enter

     u = (u1,u2,u3,u4)

     v = (v1,v2,v3,v4)

     wedge(u,v)

Result

           0           u1 v2 - u2 v1     u1 v3 - u3 v1     u1 v4 - u4 v1

     -u1 v2 + u2 v1          0           u2 v3 - u3 v2     u2 v4 - u4 v2

     -u1 v3 + u3 v1    -u2 v3 + u3 v2          0           u3 v4 - u4 v3

     -u1 v4 + u4 v1    -u2 v4 + u4 v2    -u3 v4 + u4 v3          0

Enter

     wedge(u,v) + wedge(v,u)

Result

     0

## zero(i,j,...)
Returns a zero tensor with dimensions i,j,... The zero function is useful for creating a tensor and then setting the component values.

Enter

     A = zero(2,2)
     A

Result

     0    0

     0    0

Enter

     A[1,2] = a
     A

Result

     0    a

     0    0

