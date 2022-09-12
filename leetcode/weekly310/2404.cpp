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
    int mostFrequentEven(vector<int>& nums) {
        array<int, 100001> cnt{0};
        
        for(int x : nums) {
            cnt[x]++;
        }
        
        int max_f = 0;
        int max_v = -1;
        for(int i = 0; i <= 100000; i++) {
            if(cnt[i] > 0 && i % 2 == 0) {
                if(cnt[i] > max_f) {
                    max_v = i;
                    max_f = cnt[i];
                }
            }
        }
        
        return max_v;
    }
};
