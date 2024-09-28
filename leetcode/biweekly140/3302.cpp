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
    std::vector<int> validSequence(std::string word1, std::string word2) {
        int n = word1.size();
        int m = word2.size();
        
        std::vector<int> last(m, -1);
        for(int i = n - 1, j = m - 1; i >= 0 && j >= 0; ) {
            if(word1[i] == word2[j]) {
                last[j] = i;
                i -= 1;
                j -= 1;
            } else {
                i -= 1;
            }
        }
        
        std::vector<int> ans;
        bool used = false;
        for(int i = 0, j = 0; i < n && j < m; ) {
            if(word1[i] == word2[j]) {
                ans.push_back(i);
                i += 1;
                j += 1;
            } else {
                if(!used) {
                    if(j + 1 == m || last[j + 1] > i) {
                        ans.push_back(i);
                        i += 1;
                        j += 1;
                        used = true;
                    } else {
                        i += 1;
                    }
                } else {
                    i += 1;
                }
            }
        }
        
        if(ans.size() != m) {
            ans.clear();
        }
        return ans;
    }
};
