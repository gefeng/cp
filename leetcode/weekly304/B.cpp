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

class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();

        int ans = 0;
        int cur = 1;
        while(true) {
            if(n < cur) {
                break;
            }
            n -= cur;
            ans++;
            cur++;
        }

        return ans;
    }
};
