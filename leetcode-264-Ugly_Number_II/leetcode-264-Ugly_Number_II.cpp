#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
#include <unordered_map>
#include <cmath>


int nthUglyNumber(int n) {
    std::unordered_map<size_t, size_t> factors = {{2,0}, {3,0}, {5,0}};
    std::vector<int> res = {1};

    while(res.size()!=n)
    {
        int min_val = -1, min_key = -1;
        for (const auto &i : factors)
        {
            if(min_val>res[i.second]*i.first)
            {
                min_val = res[i.second]*i.first;
                min_key = i.first;
            }
        }
        if(res[res.size()-1]<min_val)
            res.emplace_back(min_val);
        ++factors[min_key];
    }    
    
    return res[n-1];
}

int main(){
    int n = 10;

    int res = nthUglyNumber(n);
    
    std::cout << res << std::endl;
    
    return EXIT_SUCCESS;
}