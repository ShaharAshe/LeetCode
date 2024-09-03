#include <iostream>
#include <cstdlib>
#include <string>


int getLucky(std::string s, int k) {
    int convert = 0;
    for(const auto& x:s){
        int temp_sum = ((x-'a')+1);
        while(temp_sum){
            convert += (temp_sum%10);
            temp_sum /= 10;
        }
    }
    for(size_t i=1; i<k; ++i){
        int temp_sum = 0;
        while(convert){
            temp_sum += (convert%10);
            convert /= 10;
        }
        convert = temp_sum;
    }
    return convert;
}


int main(){
    std::string s = "iiii";
    int k = 1;

    int res = getLucky(s, k);

    std::cout << res << std::endl;
    
    return EXIT_SUCCESS;
}