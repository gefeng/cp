#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<int> gcdValues(std::vector<int>& nums, std::vector<long long>& queries) {
        int n = nums.size();
        int q = queries.size();
        
        std::map<int, int64_t> freq;
        std::map<int, int64_t> freq_g;
        
        std::vector<int> ans(q);
        
        std::sort(nums.begin(), nums.end());
        
        for(int i = n - 1; i >= 0; i--) {
            int x = nums[i];
            std::vector<int> a;
            for(int f = 1; f * f <= x; f++) {
                if(x % f == 0) {
                    a.push_back(f);
                    if(x / f != f) {
                        a.push_back(x / f);
                    }
                }
            }
            
            std::sort(a.begin(), a.end());
            int max_d = a.back();
            
            std::map<int, int64_t> local;
            for(int j = a.size() - 1; j >= 0; j--) {
                int d = a[j];
                int64_t cnt = freq.find(d) == freq.end() ? 0 : freq[d];
                for(int k = a.size() - 1; k > j; k--) {
                    if(a[k] % d == 0) {
                        cnt -= local.find(a[k]) == local.end() ? 0 : local[a[k]];
                    }
                }
                
                if(cnt > 0) {
                    local[d] += cnt;
                }
            }
            
            for(auto [g, v] : local) {
                freq_g[g] += v;
            }
            
            for(int d : a) {
                freq[d] += 1;
            }
        }
        
        std::vector<std::pair<int, int64_t>> pairs;
        
        for(auto [g, f] : freq_g) {
            pairs.emplace_back(g, f);
        }
        
        int size = pairs.size();
        std::vector<int64_t> psum(size + 1, 0);
        for(int i = 0; i < size; i++) {
            psum[i + 1] = psum[i] + pairs[i].second;
        }
        
        auto bs = [&](int64_t idx) {
            int lo = 0;
            int hi = pairs.size() - 1;
            int g = 0;
            while(lo <= hi) {
                int mid = (lo + hi) >> 1;
                
                if(psum[mid + 1] - 1 >= idx) {
                    g = pairs[mid].first;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            
            return g;
        };
        
        for(int i = 0; i < q; i++) {
            int64_t idx = queries[i];
            ans[i] = bs(idx);
        }
        
        return ans;
    }
};
