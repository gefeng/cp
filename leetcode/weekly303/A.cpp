#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

class Solution {
public:
    char repeatedCharacter(string s) {
        array<int, 26> cnt = {0};    
    
        char ans = ' ';
        for(char c : s) {
            cnt[c - 'a']++;
            if(cnt[c - 'a'] == 2) {
                ans = c;
                break;
            }
        }

        return ans;
    }
};
