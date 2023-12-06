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
    int countCompleteSubstrings(std::string word, int k) {
        int n = word.size();
        int ans = 0;
        
        for(int x = 1; x <= 26; x++) {
            if(x * k <= n) {
                int len = x * k;
                int cnt = 0;
                std::array<int, 26> freq = {};
                for(int l = 0, r = 0; r < n; r++) {
                    freq[word[r] - 'a'] += 1;
                    
                    if(r && std::abs(word[r] - word[r - 1]) > 2) {
                        cnt += 1;
                    }
                    
                    if(r - l + 1 > len) {
                        freq[word[l] - 'a'] -= 1;
                        int d = std::abs(word[l + 1] - word[l]);
                        if(d > 2) {
                            cnt -= 1;
                        }
                        l += 1;
                    }
                    
                    if(r - l + 1 == len) {
                        int seen = 0;
                        bool ok = true;
                        for(int i = 0; i < 26; i++) {
                            if(freq[i]) {
                                seen += 1;
                                if(freq[i] != k) {
                                    ok = false;
                                    break;
                                }
                            }
                        }
                        ok = ok && seen == x && cnt == 0;
                        
                        if(ok) {
                            ans += 1;
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};
