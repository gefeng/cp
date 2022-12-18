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
    int smallestValue(int n) {
        int ans = n;
        
        while(true) {
            int x = n;
            int sum = 0;
            for(int f = 2; f * f <= x; f++) {
                while(x % f == 0) {
                    x /= f;
                    sum += f;
                }
            }
            if(x > 1) {
                sum += x;
            }
            
            if(sum == n) {
                break;
            }
            
            ans = min(ans, sum);
            n = sum;
        }
        
        return ans;
    }
};
