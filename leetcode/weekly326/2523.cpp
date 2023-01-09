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

const int MAX = (int)1e6;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> is_p(MAX + 1, true);
        
        is_p[0] = false;
        is_p[1] = false;
        
        for(int i = 2; i <= MAX; i++) {
            if(is_p[i]) {
                for(int j = i + i; j <= MAX; j += i) {
                    is_p[j] = false;
                }
            }
        }
        
        int pre = -1;
        int ans_x = -1;
        int ans_y = -1;
        int min_d = MAX;
        for(int i = left; i <= right; i++) {
            if(is_p[i]) {
                if(pre != -1) {
                    if(i - pre < min_d) {
                        ans_x = pre;
                        ans_y = i;
                        min_d = i - pre;
                    }
                }
                
                pre = i;
            }
        }
        
        vector<int> ans;
        ans.push_back(ans_x);
        ans.push_back(ans_y);
        return ans;
    }
};
