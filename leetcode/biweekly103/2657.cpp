#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<int> findThePrefixCommonArray(std::vector<int>& A, std::vector<int>& B) {
        int n = A.size();
        
        std::vector<int> ans(n, 0);
        std::vector<int> cnt1(n + 1, 0);
        std::vector<int> cnt2(n + 1, 0);
        
        for(int i = 0; i < n; i++) {
            cnt1[A[i]] += 1;
            cnt2[B[i]] += 1;
            
            int res = 0;
            for(int j = 1; j <= n; j++) {
                if(cnt1[j] && cnt2[j]) {
                    res += 1;
                }
            }
            ans[i] = res;
        }
        
        return ans;
    }
};
