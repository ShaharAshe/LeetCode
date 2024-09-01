#include <iostream>
#include <cstdlib>
#include <vector>

std::vector<std::vector<int>> construct2DArray(std::vector<int>& original, int m, int n) {
    std::vector<std::vector<int>> res;
    if((n*m)!=original.size())
        return res;
    
    size_t i = 0;

    for(size_t r = 0; r<m; ++r)
    {
        std::vector<int> temp;
        for(size_t c = 0; c<n; ++c,++i)
        {
            temp.emplace_back(original[i]);
        }
        res.emplace_back(temp);
    }
    return res;
}


int main(){
    std::vector<int> vec = {1,2,3,4};
    int m = 2;
    int n = 2;

    std::vector<std::vector<int>> res = construct2DArray(vec, m, n);

    std::cout << "[";
    for (size_t i = 0; i < m; ++i)
    {
        std::cout << "[";
        for (size_t j = 0; j<n; ++j)
        {
            std::cout << res[i][j];
            if(j != (n-1))
            {
                std::cout << ",";
            }
        }
        std::cout << "]";
        if(i != (m-1))
        {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;

    return EXIT_SUCCESS;
}