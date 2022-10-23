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
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int s_1 = to_min(event1[0]);
        int e_1 = to_min(event1[1]);
        int s_2 = to_min(event2[0]);
        int e_2 = to_min(event2[1]);
        
        if(s_1 < s_2) {
            return s_2 <= e_1;
        } else {
            return e_2 >= s_1;
        }
    }
    
    int to_min(string s) {
        return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
    }
};
