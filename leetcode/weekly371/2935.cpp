#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

struct node {
    std::array<node*, 2> c = {nullptr, nullptr};
    int cnt = 0;
};

class Solution {
public:
    node* root; 

    void insert(int x) {
        node* cur = root;
        for(int i = 20; i >= 0; i--) {
            int b = (x & (1 << i)) ? 1 : 0;
            if(cur->c[b] == nullptr) {
                cur->c[b] = new node();
            } 
            cur = cur->c[b];
            cur->cnt += 1;
        } 
    }
    
    int get_max(int x) {
        int max_xor = 0;
        node* cur = root;
        for(int i = 20; i >= 0; i--) {
            int b = (x & (1 << i)) ? 1 : 0;
            if(cur->c[b ^ 1] != nullptr) {
                max_xor |= 1 << i;
                cur = cur->c[b ^ 1];
            } else  {
                cur = cur->c[b];
            } 
        }
        
        return max_xor;
    }
    
    void remove(int x) {
        node* cur = root;
        for(int i = 20; i >= 0; i--) {
            int b = (x & (1 << i)) ? 1 : 0;
            if(--cur->c[b]->cnt == 0) {
                cur->c[b] = nullptr;
                break;
            }
            cur = cur->c[b];
        }
    }
    
    int maximumStrongPairXor(std::vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        std::sort(nums.begin(), nums.end());
        
        root = new node();
        
        for(int i = 0, j = 0; i < n; i++) {
            int x = nums[i];
            while(j < n && nums[j] - x <= x) {
                insert(nums[j]);
                j += 1;
            }
            
            ans = std::max(ans, get_max(x));
            remove(x);
        }
        
        return ans;
    }
};
