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
    int minMaxDifference(int num) {
        int max_v = num;
        int min_v = num;
        
        string s = to_string(num);
        int n = s.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 10; j++) {
                int x = remap(s, s[i] - '0', j);
                max_v = max(max_v, x);
                min_v = min(min_v, x);
            }
        }
        
        return max_v - min_v;
    }
    
    int remap(string s, int x, int y) {
        for(int i = 0; i < s.size(); i++) {
            if(s[i] - '0' == x) {
                s[i] = (char)('0' + y);
            }
        }
        return stoi(s);
    }
};
