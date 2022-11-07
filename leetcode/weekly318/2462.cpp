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
using LL = long long;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        LL ans = 0LL;
        int n = costs.size();
        priority_queue<int, std::vector<int>, std::greater<int>> q_1;
        priority_queue<int, std::vector<int>, std::greater<int>> q_2;
        
        int i = 0;
        int j = n - 1;
        while(i < candidates) {
            q_1.push(costs[i++]);
        }
        while(n - 1 - j < candidates && j >= i) {
            q_2.push(costs[j--]);
        }
        
        while(k) {
            if(q_1.empty()) {
                ans += q_2.top();
                q_2.pop();
                if(j >= i) {
                    q_2.push(costs[j--]);
                }
            } else if(q_2.empty()) {
                ans += q_1.top();
                q_1.pop();
                if(i <= j) {
                    q_1.push(costs[i++]);
                }
            } else {
                int min_1 = q_1.top();
                int min_2 = q_2.top();

                if(min_1 <= min_2) {
                    ans += min_1;
                    q_1.pop();
                    if(i <= j) {
                        q_1.push(costs[i++]);
                    }
                } else {
                    ans += min_2;
                    q_2.pop();
                    if(j >= i) {
                        q_2.push(costs[j--]);
                    }
                }
            }
            k -= 1;
        }
        
        return ans;
    }
};
