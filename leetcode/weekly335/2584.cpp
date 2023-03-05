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
    int findValidSplit(vector<int>& nums) {
        map<int, int> m1;
        
        for(int x : nums) {
            for(int f = 2; f * f <= x; f++) {
                if(x % f == 0) {
                    m1[f] += 1;
                }
                while(x % f == 0) {
                    x /= f;
                }
            }
            if(x > 1) {
                m1[x] += 1;
            }
        }
        
        set<int> s;
        int ans = -1;
        int n = nums.size();
        for(int i = 0; i < n - 1; i++) {
            int x = nums[i];
            for(int f = 2; f * f <= x; f++) {
                if(x % f == 0) {
                    s.insert(f);
                    if(--m1[f] == 0) {
                        s.erase(f);
                    }
                }
                while(x % f == 0) {
                    x /= f;
                }
            }
            if(x > 1) {
                s.insert(x);
                if(--m1[x] == 0) {
                    s.erase(x);
                }
            }
            
            if(s.empty()) {
                ans = i;
                break;
            }
        }
        
        return ans;
    }
};
