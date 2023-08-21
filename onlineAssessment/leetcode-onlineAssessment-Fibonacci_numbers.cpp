/* -- Id = online Assessment - Fibonacci numbers -- */

#include <iostream>

int fib(int n) {
    int num = 1,
    prev = 0;
    if(n == 0)
        return 0;
    
    for(size_t i = 1; i < n; ++i)
    {
        int temp = num;
        num += prev;
        prev = temp;
    }
    return(num);
}

int main(int argc, char const *argv[])
{
    std::cout << fib(2) << std::endl;
    return 0;
}
