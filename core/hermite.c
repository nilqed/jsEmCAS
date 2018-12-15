// Hermite polynomial

#include "defs.h"

void
eval_hermite(void)
{
	push(cadr(p1));
	eval();
	push(caddr(p1));
	eval();
	hermite();
}

#define X p1
#define N p2
#define Y p3
#define Y1 p4
#define Y0 p5

void
hermite(void)
{
	int n;

	N = pop();
	X = pop();

	push(N);
	n = pop_integer();

	if (n < 0) {
		push_symbol(HERMITE);
		push(X);
		push(N);
		list(3);
		return;
	}

	if (issymbol(X))
		hermite_f(n);
	else {
		Y = X;			// do this when X is an expr
		X = symbol(SECRETX);
		hermite_f(n);
		X = Y;
		push(symbol(SECRETX));
		push(X);
		subst();
		eval();
	}
}

// Uses the recurrence relation
//
//	H(x, 0) = 1
//
//	H(x, 1) = 2 x
//
//	H(x, k + 1) = 2 x H(x, k) - 2 k H(x, k - 1)

void
hermite_f(int n)
{
	int i;

	push_integer(1);
	push_integer(0);

	Y1 = pop();

	for (i = 0; i < n; i++) {

		Y0 = Y1;

		Y1 = pop();

		push(X);
		push(Y1);
		multiply();

		push_integer(i);
		push(Y0);
		multiply();

		subtract();

		push_integer(2);
		multiply();
	}
}
