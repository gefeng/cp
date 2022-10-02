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
    int minimizeXor(int num1, int num2) {
        int cnt_1 = 0;
        int cnt_2 = 0;
        for(int i = 0; i < 32; i++) {
            if(num1 & (1 << i)) {
                cnt_1++;
            }
            if(num2 & (1 << i)) {
                cnt_2++;
            }
        }
        
        if(cnt_1 == cnt_2) {
            return num1;
        }
        int ans = 0;
        if(cnt_1 > cnt_2) {
            for(int i = 31; i >= 0 && cnt_2; i--) {
                if(num1 & (1 << i)) {
                    ans |= (1 << i);
                    cnt_2--;
                }
            }
        } else {
            for(int i = 31; i >= 0; i--) {
                if(num1 & (1 << i)) {
                    ans |= (1 << i);
                }
            }
            int d = cnt_2 - cnt_1;
            for(int i = 0; i < 32 && d; i++) {
                if(ans & (1 << i)) continue;
                
                ans |= (1 << i);
                d--;
            }
        }
        
        return ans;
    }
};
