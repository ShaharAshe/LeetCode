/* -- Id = 383 -- */

#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, size_t> m;

    for (auto &i : ransomNote)
    {
        if(m.find(i) == m.end())
        {
            m[i] = 0;
        }
        ++m[i];
    }

    for (auto &i : magazine)
    {
        if(m.find(i) != m.end())
        {
            --m[i];
            if(m[i] <= 0)
            {
                m.erase(i);
            }
        }
    }
    
    if (m.empty())
        return true;

    return false;
}

int main(int argc, char const *argv[])
{
    cout << canConstruct("aa", "aab") << endl;
    return EXIT_SUCCESS;
}


