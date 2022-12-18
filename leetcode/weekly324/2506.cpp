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
    int similarPairs(vector<string>& words) {
        int ans = 0;
        int n = words.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(is_ok(words[i], words[j])) {
                    ans += 1;
                }
            }
        }
        
        return ans;
    }
    
    bool is_ok(string& s, string& t) {
        array<int, 26> cnt1{0};
        array<int, 26> cnt2{0};
        
        for(char c : s) {
            cnt1[c - 'a'] += 1;
        }
        for(char c : t) {
            cnt2[c - 'a'] += 1;
        }
        
        for(int i = 0; i < 26; i++) {
            if((cnt1[i] > 0 && cnt2[i] == 0) || (cnt1[i] == 0 && cnt2[i] > 0)) {
                return false;
            }
        }
        return true;
    }
};
