#include <iostream>
#include <cstdlib>


class Solution {
public:
    int mySqrt(int x) {
        if (!x || x==1)
        {
            return x;
        }
        size_t bottom = 0,
               top = x,
               mid = (bottom+top)/2,
               temp = (mid*mid);
        while(!(temp<=x && (temp+(2*mid)+1)>x))
        {
            if(temp<x)
            {
                bottom = mid;
            } else {
                top = mid;
            }
            mid = (bottom+top)/2;
            temp = (mid*mid);
        }
        return mid;
    }
};


int main(){
    int x = 4;
    auto res = Solution().mySqrt(x);
    
    std::cout << res << std::endl;

    return EXIT_SUCCESS;
}