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
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* modifiedList(std::vector<int>& nums, ListNode* head) {
        ListNode* dh = new ListNode();   
        
        std::set<int> s(nums.begin(), nums.end());
        
        ListNode* p1 = dh;
        ListNode* p2 = head;
        while(p2 != nullptr) {
            if(s.find(p2->val) == s.end()) {
                p1->next = p2;
                p1 = p1->next;
            }
            ListNode* tmp = p2->next;
            p2->next = nullptr;
            p2 = tmp;
        }
        
        return dh->next;
    }
};
