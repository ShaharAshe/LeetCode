#include <iostream>
#include <cstdlib>


// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    // Solution(int bad) : m_bad(bad) {}
    int firstBadVersion(int n) {
        size_t top = n,
               base = 1,
               mid = (top+base)/2;
               
        while(base<=top)
        {
            if(isBadVersion(mid)) {
                top = (mid-1);
            } else {
                base = (mid+1);
            }
            mid = (top+base)/2;
        }
        return base;
    }
// private:
// bool isBadVersion(int mid) {
//     if(this->m_bad<=mid)
//         return true;
//     return false;
//     }

//     int m_bad;
};


int main(){
    int n = 5;
    int bad = 4;

    auto res = Solution(bad).firstBadVersion(n);
    
    std::cout << res << std::endl;

    return EXIT_SUCCESS;
}