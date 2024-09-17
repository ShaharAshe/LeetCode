#include <stdio.h>
#include <stdlib.h>

// ------ option 1 -------
/*int fib(int n){
    if (n == 0 || n == 1)
        return n;
    
    return fib(n-1)+fib(n-2);
}*/


// ------ option 2 -------
int num_fib[30+1] = {0};

int fib(int n){
    if((n == 0 || n == 1) && !num_fib[n])
        return num_fib[n] = n;
    return num_fib[n] = (num_fib[n])? num_fib[n] : fib(n-1)+fib(n-2);
}

// -----------
int main(){
    printf("%d", fib(4));

    return EXIT_SUCCESS;
}