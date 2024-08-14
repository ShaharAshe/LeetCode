#include <iostream>
#include <cstdlib>
#include <vector>


int count_pairs(std::vector<int>& nums, int mid) {
    size_t l = 0;
    int sum = 0;
    for (size_t r = (l+1); r < nums.size(); ++r)
    {
        while(nums[r]-nums[l] > mid)
            ++l;
        sum += (r-l);
    }
    return sum;
}

int smallestDistancePair(std::vector<int>& nums, int k) {
    int max = -1;
    for (const auto x : nums)
    {
        if(max<x)
        {
            max = x;
        }
    }
    
    std::vector<int> vec;
    std::vector<int> pairs_vec;


    vec.resize(max+1);
    pairs_vec.resize(max+1);

    for (const auto x : nums)
    {
        ++vec[x];
    }

    size_t j = 0;
    for(size_t i = 0; i<vec.size(); ++i)
    {
        while(vec[i])
        {
            nums[j++] = i;
            --vec[i];
        }
    }

    int small = 0,
        big = nums[nums.size()-1];
    
    while(small < big)
    {
        int mid = (big + small)/2;

        if(count_pairs(nums, mid) < k)
        {
            small = mid+1;
        } else {
            big = mid;
        }
    }

    return big;
}


int main(){
    std::vector<int> vec = {1,3,1};
    int k = 1;

    // std::vector<int> vec = {62,100,4};
    // int k = 2;

    // std::vector<int> vec = {9,10,7,10,6,1,5,4,9,8};
    // int k = 2;

    // std::vector<int> vec = {1,6,1};
    // int k = 3;
    
    auto res = smallestDistancePair(vec, k);
    std::cout << res << std::endl;
    
    return EXIT_SUCCESS;
}