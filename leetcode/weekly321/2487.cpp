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

struct ListNode {
    int val;
    ListNode* next;
    
    ListNode(int val) : val(val), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        vector<int> v;
        ListNode* cur = head;
        while(cur) {
            v.push_back(cur->val);
            cur = cur->next;
        }
        
        int n = v.size();
        vector<bool> rem(n, false);
        
        int max_v = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(v[i] < max_v) {
                rem[i] = true;
            }
            max_v = max(max_v, v[i]);
        }
        
        ListNode* dh = new ListNode(0);
        cur = dh;
        
        for(int i = 0; i < n; i++) {
            if(!rem[i]) {
                cur->next = new ListNode(v[i]);
                cur = cur->next;
            }
        }
        
        return dh->next;
    }
};
