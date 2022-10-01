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
    vector<bool> v;
    int p_idx;
    int size;
    
    Solution(int n) {
        v.resize(n + 1, false);
        p_idx = 0;
        size = n;
    }
    
    void upload(int video) {
        v[video] = true;
        if(p_idx + 1 == video) {
            while(p_idx + 1 <= size && v[p_idx + 1]) {
                p_idx++;
            }
        }
    }
    
    int longest() {
        return p_idx;
    }
};
