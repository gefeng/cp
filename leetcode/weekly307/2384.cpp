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

class Solution {
public:
    string largestPalindromic(string num) {
        array<int, 10> cnt = {0};
        
        for(char c : num) {
            cnt[c - '0']++;
        }
        
        string s = "";
        
        for(int i = 9; i >= 0; i--) {
            if(cnt[i] > 0) {
                if(i != 0 || (i == 0 && s.length() != 0)) {
                    for(int j = 0; j < cnt[i] / 2; j++) {
                        s += i + '0';
                    }
                    cnt[i] -= cnt[i] / 2 * 2;
                } 
            }
        }
        
        string ans = s;
        reverse(s.begin(), s.end());
        
        for(int i = 9; i >= 0; i--) {
            if(cnt[i] > 0) {
                ans += i + '0';
                break;
            }
        }
        
        return ans + s;
    }
};
