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
    vector<int> evenOddBit(int n) {
        vector<int> ans(2, 0);
        
        int i = 0;
        while(n) {
            int b = n % 2;
            if(i % 2 == 0) {
                ans[0] += b;
            } else {
                ans[1] += b;
            }
            n /= 2;
            i += 1;
        }
        
        return  ans;
    }
};
