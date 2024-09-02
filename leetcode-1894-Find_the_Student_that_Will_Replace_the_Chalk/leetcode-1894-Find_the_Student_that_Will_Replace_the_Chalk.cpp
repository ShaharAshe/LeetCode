#include <iostream>
#include <cstdlib>
#include <vector>


int chalkReplacer(std::vector<int>& chalk, int k) {
    int temp_k = k,
        sum = 0;
    size_t i = 0;

    for(; i<chalk.size(); ++i){
        if((sum+chalk[i])<=temp_k){
            sum+=chalk[i];
        } else {
            if(!i)
            {
                return 0;
            }
            break;
        }
    }
    if(i==chalk.size()) {
        temp_k%=sum;
    } else {
        return i%chalk.size();
    }
        
    for(i=0; i<chalk.size(); ++i){
        if((temp_k-chalk[i])<0)
            return i;
        
        temp_k-=chalk[i];
    }
    return 0;
}


int main(){
    // std::vector<int> vec = {5,1,5};
    // int k = 22;

    // std::vector<int> vec = {3,4,1,2};
    // int k = 25;

    std::vector<int> vec = {1,1,1,1,1,1,1,1,1,1};
    int k = 99;

    double res = chalkReplacer(vec, k);

    std::cout << res << std::endl;
    
    return EXIT_SUCCESS;
}