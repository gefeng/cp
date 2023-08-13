#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        std::vector<int> v;
        ListNode* cur = head;
        while(cur) {
            v.push_back(cur->val);
            cur = cur->next;
        } 
        
        std::vector<int> a;
        int n = v.size();
        int c = 0;
        for(int i = n - 1; i >= 0; i--) {
            int x = (v[i] + v[i] + c) % 10;
            a.push_back(x);
            c = (v[i] * 2 + c) / 10;
        }
        
        if(c) {
            a.push_back(c);
        }
        
        ListNode* dh = new ListNode();
        cur = dh;
        for(int i = a.size() - 1; i >= 0; i--) {
            cur->next = new ListNode(a[i]);
            cur = cur->next;
        }
        
        return dh->next;
    }
};
