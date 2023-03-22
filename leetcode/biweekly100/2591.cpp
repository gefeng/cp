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
    int distMoney(int money, int children) {
        if(money < children) {
            return -1;
        }
        
        int cnt = 0;
        int ans = 0;
        while(cnt * 8 <= money && cnt <= children) { 
            int left_m = money - cnt * 8;
            int left_c = children - cnt;

            if(left_m == 4 && left_c == 1) {
                cnt += 1;
                continue;
            }

            if(left_c == 0 && left_m) {
                cnt += 1;
                continue;
            }

            if(left_c && left_m < left_c) {
                cnt += 1;
                continue;
            }
            
            ans = cnt;
            cnt += 1;
        }
        
        return ans;
    }
};
