#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int lv = 0;
        while(!q.empty()) {
            int sz = q.size();
            vector<TreeNode*> row(sz);
            vector<int> v(sz, 0);
            
            for(int i = 0; i < sz; i++) {
                TreeNode* cur = q.front();
                q.pop();
                
                if(cur->left) {
                    q.push(cur->left);
                }
                if(cur->right) {
                    q.push(cur->right);
                }
                
                v[i] = cur->val;
                row[i] = cur;
            }
            
            if(lv & 1) {
                for(int i = 0; i < sz; i++) {
                    row[i]->val = v[sz - i - 1];
                }
            }
            lv++;
        }
        
        return root;
    } 
};
