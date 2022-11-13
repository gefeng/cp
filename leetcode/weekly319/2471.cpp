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
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int sz = q.size();
            vector<int> v;
            while(sz--) {
                TreeNode* cur = q.front();
                q.pop();
                v.push_back(cur->val);
                
                if(cur->left) {
                    q.push(cur->left);
                }
                if(cur->right) {
                    q.push(cur->right);
                }
            }
            
            int n = v.size();
            
            vector<int> t(v);
            sort(t.begin(), t.end());
            
            unordered_map<int, int> m;
            for(int i = 0; i < n; i++) {
                m[v[i]] = i;
            }
            
            for(int i = 0; i < n; i++) {
                if(t[i] != v[i]) {
                    int p = m[t[i]];
                    m[t[i]] = i;
                    m[v[i]] = p;
                    swap(v[i], v[p]);
                    ans += 1;
                }
            }
        }
        
        return ans;
    }
};
