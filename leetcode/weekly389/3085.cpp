#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

const int INF = (int)1e9;

class Solution {
public:
    int minimumDeletions(std::string word, int k) {
        int n = word.size();
        
        std::array<int, 26> freq = {};
        for(char c : word) {
            freq[c - 'a'] += 1;
        }
  
        std::map<int, int> m;
        for(int i = 0; i < 26; i++) {
            if(freq[i]) {
                m[freq[i]] += 1;
            }
        }
        
        std::vector<std::pair<int, int>> a;
        for(auto [v, f] : m) {
            a.emplace_back(v, f);
        }
        
        int size = a.size();
        if(size == 1) {
            return 0;
        }
        
        int ans = INF;
        int cnt_pre = 0;
        for(int i = 0; i < size; i++) {
            int cnt_suf = 0;
            for(int j = size - 1; j >= i; j--) {
            
                int cnt = cnt_pre + cnt_suf;
                for(int s = i + 1; s <= j; s++) {
                    int d = std::max(0, a[s].first - a[i].first - k);
                    cnt += d * a[s].second;
                }

                ans = std::min(ans, cnt);
                cnt_suf += a[j].first * a[j].second;
            }
            cnt_pre += a[i].first * a[i].second;
        }
        
        return ans;
    }
};
