/* -- Id = online Assessment - Candies -- */

#include <iostream>
#include <vector>
#include <unordered_map>

int distributeCandies(std::vector<int>& candyType) {
    int num_of_candies = candyType.size()/2;
    std::unordered_map<int, bool> types;
        
    for(auto &i: candyType){
        types[i] = true;
    }
        
    return(types.size()<num_of_candies)?types.size():num_of_candies;
}

int main(int argc, char const *argv[])
{
    std::vector<int> a = {1,1,2,2,3,3};
    std::cout << distributeCandies(a) << std::endl;
    
    return 0;
}


