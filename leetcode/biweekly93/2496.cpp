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
    int maximumValue(vector<string>& strs) {
        int ans = 0;
        for(string s : strs) {
            bool letter = false;
            for(char c : s) {
                if(c >= 'a' && c <= 'z') {
                    letter = true;
                    break;
                }
            }
            
            if(letter) {
                ans = max(ans, (int)s.length());
            } else {
                ans = max(ans, stoi(s));
            }
        }
        
        return ans;
    }
};
