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
    int splitNum(int num) {
        string s = to_string(num);
        
        sort(s.begin(), s.end());
        
        string x = "";
        string y = "";
        for(int i = 0; i < s.size(); i += 2) {
            x.push_back(s[i]);
            if(i + 1 < s.size()) {
                y.push_back(s[i + 1]);
            }
        }
        
        return stoi(x) + stoi(y);
    }
};
