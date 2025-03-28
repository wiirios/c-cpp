#include <math.h>
#include <stdio.h>

#undef sqrt
#define sqrt(x) ((x)>=0?sqrt(x):0)

int main() {
    printf("%1.2f\n", sqrt(-9.0));
    /*
    Some enterprising programmers take advantage of this behavior by writing
    macros whose names match reserved words or functions in the standard library,
    Consider the s q r t library function, s q r t computes the square root of its argu
    ment, returning an implementation-defined value if the argument is negative. Per
    haps we would prefer that s q r t return 0 if its argument is negative. Since s q r t is
    part of the standard library, we can't easily change it. We can, however, define a
    s q rt macro that evaluates to 0 when given a negative argument

    A later call of s q r t will be intercepted by the preprocessor, which expands il into
    the conditional expression shown here. The call of s q r t inside the conditional
    expression won’t be replaced during rescanning, so il will remain for the compiler
    to handle. (Note the use of #undef to undefine s q r t before defining the s q rt
    macro. As we’ll see in Section 2.l.l, the standard library is allowed to have both a
    macro and a function with the same name. Undefming s q rt before defining our
    own s q rt macro is a defensive measure, in case the library has already defined
    s q rt as a macro.)
    */

    /*
    gcc -E rewrite.c

    int main() {
    printf("%1.2f\n", ((-9.0)>=0?sqrt(-9.0):0));

    return 0;
}
    */   
    return 0;
}