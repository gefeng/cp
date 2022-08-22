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
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> diff(n + 1, 0);
        
        for(vector<int>& v : shifts) {
            int sign = v[2] ? 1 : -1;
            diff[v[0]] += sign;
            diff[v[1] + 1] -= sign;
        }
        
        int cur = 0;
        for(int i = 0; i < n; i++) {
            cur += diff[i];
            cur %= 26;
            s[i] = ((s[i] - 'a' + cur + 26) % 26) + 'a';
        }
        
        return s;
    }
};
