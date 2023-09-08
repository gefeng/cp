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
    ListNode();
    ListNode(int x) : val(x) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while(cur != nullptr) {
            if(pre != nullptr) {
                ListNode* x = new ListNode(gcd(pre->val, cur->val));
                pre->next = x;
                x->next = cur;
            }
            pre = cur;
            cur = cur->next;
        }
        
        return head;
    }
    
    int gcd(int a, int b) {
        if(a == 0) {
            return b;
        }
        
        return gcd(b % a, a);
    }
};
