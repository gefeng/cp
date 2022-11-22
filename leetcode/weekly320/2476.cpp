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

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val;
};

class Solution {
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        int n = queries.size();
        vector<vector<int>> ans(n);
        
        set<int> s;
        dfs(root, s);
        
        for(int i = 0; i < n; i++) {
            int q = queries[i];
            auto it = s.lower_bound(q);
            
            int x = -1;
            if(it == s.end()) {
                if(it != s.begin()) {
                    x = *(--it);
                }
            } else {
                if(*it == q) {
                    x = q;
                } else {
                    if(it == s.begin()) {
                        x = -1;
                    } else {
                        x = *(--it);
                    }
                }
            }
            
            ans[i].push_back(x);
            
            int y = -1;
            it = s.lower_bound(q);
            if(it == s.end()) {
                y = -1;
            } else {
                y = *it;
            }
            ans[i].push_back(y);
        }
        
        return ans;
    }
    
    void dfs(TreeNode* root, set<int>& s) {
        if(!root) return;
        
        s.insert(root->val);
        dfs(root->left, s);
        dfs(root->right, s);
    }    
};
