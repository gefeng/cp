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
    struct node {
        array<node*, 26> children{nullptr};
        int cnt = 0;
    };
    
    node* root;
    
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        vector<int> ans(n, 0);
    
        root = new node();
        for(string s : words) {
            int len = s.length();
            node* cur = root;
            for(int i = 0; i < len; i++) {
                int j = s[i] - 'a';
                if(!cur->children[j]) {
                    cur->children[j] = new node();
                }
                cur = cur->children[j];
                cur->cnt++;
            }
        }
        
        for(int k = 0; k < n; k++) {
            string s = words[k];
            int len = s.length();
            int sum = 0;
            node* cur = root;
            for(int i = 0; i < len; i++) {
                int j = s[i] - 'a';
                cur = cur->children[j];
                sum += cur->cnt;
            }
            
            ans[k] = sum;
        }
        
        return ans;
    }
};
