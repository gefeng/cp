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
using LL = long long;

struct BIT {
public:
    BIT(int n) : _n(n + 1) {
        _bit.resize(_n, 0);
    }

    void update(int i, int v) {
        for(i++; i < _n; i += i & -i) {
            _bit[i] += v;
        }
    }

    int query(int i) {
        int res = 0;
        for(i++; i > 0; i -= i & -i) {
            res += _bit[i];
        }
        return res;
    }

    int query(int l, int r) {
        return query(r) - query(l);
    }
private:
    int _n;
    vector<int> _bit;
};

class Solution {
public:
    const int MAX = 30000;

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        LL ans = 0LL;
        int n = nums1.size();
        
        BIT bit(MAX * 2 + 1);
        for(int i = 0; i < n; i++) {
            int x = nums1[i] - nums2[i] + diff;
            
            LL tot = bit.query(x + MAX);
            
            ans += tot;
            
            bit.update(nums1[i] - nums2[i] + MAX, 1);
        
        }
        
        return ans;
    }
};
