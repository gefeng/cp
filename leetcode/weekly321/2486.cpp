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
    int appendCharacters(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        int i = 0, j = 0;
        for(; i < m && j < n; ) {
            if(s[i] == t[j]) {
                i += 1;
                j += 1;
            } else {
                i += 1;
            }
        }
        
        return j == n ? 0 : n - j;
    }
};
