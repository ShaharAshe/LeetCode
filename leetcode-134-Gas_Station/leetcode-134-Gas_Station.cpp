#include <iostream>
#include <cstdlib>
#include <vector>


int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
    if(gas.size()==1){
        if(gas[0]<cost[0])
            return -1;
        return 0;
    }
    for(size_t first_i = 0; first_i<gas.size(); ++first_i)
    {
        while(gas[first_i]<=cost[first_i])
        {
            ++first_i;
            if(first_i == gas.size())
            {
                return -1;
            }
        }
        
        int cur_cost = 0,
               cur_gas_cost = 0;
        
        for(size_t i = 0; i<gas.size(); ++i){
            size_t cur_i = (first_i+i)%gas.size();
            cur_cost = cost[cur_i];
            cur_gas_cost += gas[cur_i];
            cur_gas_cost -= cur_cost;
            if(cur_gas_cost<0) {
                first_i+=i;
                break;
            } else if(((cur_i+1)%gas.size()) == first_i){
                return first_i;
            }
        }
    }
    return -1;
}



int main(){
    std::vector<int> gas = {2,3,4};
    std::vector<int> cost = {3,4,3};
    
    auto res = canCompleteCircuit(gas, cost);
    
    std::cout << res << std::endl;
    
    return EXIT_SUCCESS;
}