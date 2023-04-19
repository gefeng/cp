#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        std::vector<int> save;
        
        dfs1(root, save, 0);
        
        dfs2(root, save, 0, 0);
        
        return root;
    }
    
    void dfs1(TreeNode* root, std::vector<int>& save, int d) {
        if(d == save.size()) {
            save.push_back(root->val);
        } else {
            save[d] += root->val;
        }
        
        if(root->left) {
            dfs1(root->left, save, d + 1);
        }
        if(root->right) {
            dfs1(root->right, save, d + 1);
        }
    }
    
    void dfs2(TreeNode* root, std::vector<int>& save, int d, int v) {
        root->val = save[d] - root->val - v;
        
        int v1 = root->left ? root->left->val : 0;
        int v2 = root->right ? root->right->val : 0;
        
        if(root->left) {
            dfs2(root->left, save, d + 1, v2);
        }
        if(root->right) {
            dfs2(root->right, save, d + 1, v1);
        }
    }
};
