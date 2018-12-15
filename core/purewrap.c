#include "defs.h"

void em_eval(void)       { return eval(); } ;
void em_init(void)       { return init(); } ;
void em_lcm(void)        { return lcm();  } ;
void em_gcd(void)        { return gcd();  } ;
void em_sgn(void)        { return sgn();  } ;
void em_filter(void)     { return filter();  } ;
void em_transpose(void)  { return transpose();  } ;
void em_list(int n)      { return list(n);  } ;

// Howto:
// make
// gcc -c purewrap.c
// gcc -shared -o eigenmath.dll -lm *.o
