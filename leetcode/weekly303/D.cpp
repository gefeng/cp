#include <algorithm>
#include <array>
#include <bit>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        long long ans = 0;
         
        array<int, 32> cnt = {0};
        unordered_set<int> seen;
        for(int x : nums) {
            if(seen.count(x)) {
                continue;
            }
            
            cnt[popcount(x)]++;
            seen.insert(x);
        }

        for(int i = 0; i < 32; i++) {
            for(int j = 0; j < 32; j++) {
                if(i + j >= k) {
                    ans += (long long)cnt[i] * cnt[j];
                }
            }
        }

        return ans;
    }    
};
