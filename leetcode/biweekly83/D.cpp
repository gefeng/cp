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
    int shortestSequence(vector<int>& rolls, int k) {
        int ans = 0;
        unordered_set<int> set;
        
        for(int x : rolls) {
            set.insert(x);
            
            if(set.size() == k) {
                ans++;
                set = unordered_set<int>();
            }
        }
        
        return ans + 1;
    }
};
