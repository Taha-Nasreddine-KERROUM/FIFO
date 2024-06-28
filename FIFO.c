#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void read ( int *x, int n, char *c ) {
    for ( int *p = x + 1; p <= x + n; ++p ) {
        printf(" %s[%ld] = ", c, p - x);
        scanf("%d", p);
    }
}

void display ( int *b, int *w, int *t, int n ) {
    printf(" bt wt tt\n");
    for( int *p = b + 1, *q = w + 1, *d = t + 1; p <= b + n; ++p, ++q, ++d )
        printf(" %02d %02d %02d\n", *p, *q, *d);
}

void calc ( int *b, int *w, int *t, int n ) {
    for( int *bt = b, *wt = w, *tt = t; bt < b + n; ++bt, ++wt, ++tt ) {
        *(wt + 1) = *bt + *wt;
        *(tt + 1) = *tt + *(bt + 1);
    }
}

double avrg ( int *x, int n ) {
    double avr = 0;
    for ( int *p = x + 1; p <= x + n; ++p )
        avr += *p;
    return avr / n;
}

int main()
{
    int wt[10], bt[10], tt[10], n;
    wt[0] = bt[0] = tt[0] = 0;
    
    printf(" Enter number of processes: ");
    scanf("%d", &n);
    printf(" Enter burst time (execution time): \n");
    read(bt, n, "bt");
    calc(bt, wt, tt, n);
    display(bt, wt, tt, n);
    printf("\n aw = %lf", avrg(wt, n));
    printf("\n at = %lf", avrg(tt, n));
    return 0;
}
