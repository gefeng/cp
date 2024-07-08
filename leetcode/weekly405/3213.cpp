#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr int INF = (int)2e9;

struct node {
    std::array<node*, 26> ch;
    int val = INF;
    node() {
        for(int i = 0; i < 26; i++) {
            ch[i] = nullptr;
        }
    }
};

class Solution {
public:
    int minimumCost(std::string target, std::vector<std::string>& words, std::vector<int>& costs) {
        int n = target.size();
        int m = words.size();
        
        node* root = new node();
        for(int i = 0; i < m; i++) {
            std::string& s = words[i];
            node* cur = root;
            for(int j = s.size() - 1; j >= 0; j--) {
                int c = s[j] - 'a';
                if(cur->ch[c] == nullptr) {
                    cur->ch[c] = new node();
                }
                cur = cur->ch[c];
            }
            cur->val = std::min(cur->val, costs[i]);
        }
        
        std::vector<int> dp(n + 1, INF);
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            node* cur = root;
            int p = i - 1;
            while(p >= 0) {
                int c = target[p] - 'a';
                if(cur->ch[c] == nullptr) {
                    break;
                }
                cur = cur->ch[c];
                if(cur->val != INF && dp[p] != INF) {
                    dp[i] = std::min(dp[i], dp[p] + cur->val);
                }
                p -= 1;
            }
        }
        
        return dp[n] == INF ? -1 : dp[n];
    }
};
