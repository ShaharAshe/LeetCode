#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>


void searchComb(int start_i, int sum, int target, std::vector<int>& candidates, std::vector<std::vector<int>>& res, std::vector<int>& comb){
    if(sum == target)
    {
        res.emplace_back(comb);
        return;
    }
    for(size_t i = start_i; i<candidates.size(); ++i)
    {
        if(i > start_i && candidates[i] == candidates[i-1]){
            continue;
        }
        if(target-sum < candidates[i])
        {
            break;
        }
        comb.push_back(candidates[i]);
        searchComb((i+1), (sum+candidates[i]), target, candidates, res, comb);
        comb.pop_back();
    }
}

std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    std::vector<std::vector<int>> res;
    std::vector<int> comb;
    
    for(size_t i = 0; i<candidates.size(); ++i)
    {
        if((i == 0) || (i != 0 && candidates[i] != candidates[i-1]))
        {
            comb.push_back(candidates[i]);
        } else {
            continue;
        }
        searchComb((i+1), candidates[i], target, candidates, res, comb);
        comb.pop_back();
    }
    return res;
}

int main(){
    // std::vector<int> vec = {10,1,2,7,6,1,5};
    // int target = 8;

    // std::vector<int> vec = {2,5,2,1,2};
    // int target = 5;

    // std::vector<int> vec = {1, 2};
    // int target = 3;

    // std::vector<int> vec = {2,2,2};
    // int target = 4;

    // std::vector<int> vec = {4,2,5,2,5,3,1,5,2,2};
    // int target = 9;

    // std::vector<int> vec = {4,4,2,1,4,2,2,1,3};
    // int target = 6;

    // std::vector<int> vec = {4,2,5,2,5,3,1,5,2,2};
    // int target = 9;

    std::vector<int> vec = {14,6,25,9,30,20,33,34,28,30,16,12,31,9,9,12,34,16,25,32,8,7,30,12,33,20,21,29,24,17,27,34,11,17,30,6,32,21,27,17,16,8,24,12,12,28,11,33,10,32,22,13,34,18,12};
    int target = 27;

    auto res = combinationSum2(vec, target);
    for(size_t i = 0; i<res.size(); ++i){
            std::cout << "[";
        for(size_t j = 0; j<res[i].size(); ++j){
            std::cout << res[i][j];
            if(j != res[i].size()-1)
                std::cout << ", ";
        }
            std::cout << "]" << std::endl;
    }

    return EXIT_SUCCESS;
}