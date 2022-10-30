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
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    void dfs_1(TreeNode* root, int x, unordered_map<int, int>& h) {
        h[root->val] = x;
        if(root->left) {
            dfs_1(root->left, x + 1, h);
            h[root->val] = max(h[root->val], h[root->left->val]);
        }
        if(root->right) {
            dfs_1(root->right, x + 1, h);
            h[root->val] = max(h[root->val], h[root->right->val]);
        }
    }
    
    void dfs_2(TreeNode* root, int x, unordered_map<int, int>& h, map<int, int>& cnt_h, unordered_map<int, int>& m) {
        if(!cnt_h.empty()) {
            m[root->val] = cnt_h.rbegin()->first;
        }
        
        if(root->left) {
            int r = root->right ? h[root->right->val] : x;
            cnt_h[r] += 1;
            dfs_2(root->left, x + 1, h, cnt_h, m);
            if(--cnt_h[r] == 0) {
                cnt_h.erase(r);
            }
        }
        
        if(root->right) {
            int l = root->left ? h[root->left->val] : x;
            cnt_h[l] += 1;
            dfs_2(root->right, x + 1, h, cnt_h, m);
            if(--cnt_h[l] == 0) {
                cnt_h.erase(l);
            }
        }
    }
    
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<int, int> h;
        dfs_1(root, 0, h);
        
        unordered_map<int, int> m;
        map<int, int> cnt_h;
        dfs_2(root, 0, h, cnt_h, m);
        
        vector<int> ans;
        ans.reserve(queries.size());
        for(int q : queries) {
            ans.push_back(m[q]);
        }
        
        return ans;
    }
};
