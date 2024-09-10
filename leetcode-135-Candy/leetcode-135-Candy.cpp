#include <iostream>
#include <cstdlib>
#include <vector>


int candy(std::vector<int>& ratings) {
    std::vector<int> res_vec;
    res_vec.resize(ratings.size(),1);
    for(size_t i = 1; i<res_vec.size(); ++i)
    {
        if(ratings[i-1]<ratings[i])
        {
            res_vec[i] = res_vec[i-1]+1;
        }
    }
    int res = res_vec[res_vec.size()-1];
    for(int i = res_vec.size()-2; 0<=i; --i)
    {
        if(ratings[i+1]<ratings[i] && res_vec[i] < (res_vec[i+1]+1))
        {
            res_vec[i] = res_vec[i+1]+1;
        }
        res += res_vec[i];
    }
    return res;
}



int main(){
    std::vector<int> vec = {1,0,2};

    auto res = candy(vec);
    
    std::cout << res << std::endl;
    
    return EXIT_SUCCESS;
}