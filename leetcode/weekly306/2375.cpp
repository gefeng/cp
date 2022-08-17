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
    string smallestNumber(string pattern) {
        int n = pattern.length();
        string ans = "";
        
        for(int i = 0; i < n + 1; i++) {
            ans += (i + 1) + '0';
        }
        
        for(int i = 0; i < n; ) {
            int j = i;
            while(i < n && pattern[i] == 'D') {
                i++;
            }
            
            if(j == i) {
                i++;
            } else {
                reverse(ans, j, i);
            }
        }
        
        return ans;
    }
    
    void reverse(string& s, int l, int r) {
        while(l < r) {
            swap(s[l++], s[r--]);
        }
    }
};
