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
    int amountOfTime(TreeNode* root, int start) {
        vector<vector<int>> g(100001);
        get(root, nullptr, g);
        
        return dfs(g, start, -1) - 1;
    }
    
    int dfs(vector<vector<int>>& g, int cur, int p) {
        int max_d = 0;
        for(int nei : g[cur]) {
            if(nei != p) {
                max_d = max(max_d, dfs(g, nei, cur));
            }
        }
        return max_d + 1;
    }
    
    void get(TreeNode* root, TreeNode* p, vector<vector<int>>& g) {
        if(!root) {
            return;
        }
        
        get(root->left, root, g);
        get(root->right, root, g);
        
        if(p) {
            g[root->val].push_back(p->val);
        }
        if(root->left) {
            g[root->val].push_back(root->left->val);
        }
        if(root->right) {
            g[root->val].push_back(root->right->val);
        }
    }
};
