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
using LL = long long;

class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        LL ans = 0LL;
        vector<int> odd;
        vector<int> eve;
        for(int x : target) {
            if(x & 1) odd.push_back(x);
            else eve.push_back(x);
        }
        
        sort(nums.begin(), nums.end());
        sort(odd.begin(), odd.end());
        sort(eve.begin(), eve.end());
        
        int p1 = 0;
        int p2 = 0;
        LL cnt = 0LL;
        for(int x : nums) {
            if(x & 1) {
                LL d = abs(x - odd[p1]) / 2;
                if(x > odd[p1]) {
                    // dec
                    if(cnt > 0) {
                        LL free = min(cnt, d);
                        ans += d - free;
                    } else {
                        ans += d;
                    }
                    cnt -= d;
                } else if(x < odd[p1]) {
                    // inc
                    if(cnt > 0) {
                        ans += d;
                    } else {
                        LL free = min(cnt * -1, d);
                        ans += d - free;
                    }
                    cnt += d;
                }
                p1++;
            } else {
                LL d = abs(x - eve[p2]) / 2;
                if(x > eve[p2]) {
                    // dec
                    if(cnt > 0) {
                        LL free = min(cnt, d);
                        ans += d - free;
                    } else {
                        ans += d;
                    }
                    cnt -= d;
                } else if(x < eve[p2]) {
                    // inc
                    if(cnt > 0) {
                        ans += d;
                    } else {
                        LL free = min(cnt * -1, d);
                        ans += d - free;
                    }
                    cnt += d;
                }
                p2++;
            }
        }
        
        return ans;
    }
};
