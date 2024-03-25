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
    std::vector<std::vector<int>> nxt;
    std::vector<int> val;
    int id = 0;
    std::vector<int> stringIndices(std::vector<std::string>& wordsContainer, std::vector<std::string>& wordsQuery) {
        int n = wordsContainer.size();
        int m = wordsQuery.size();
        
        int size = 0;
        for(int i = 0; i < n; i++) {
            size += wordsContainer[i].size();
        }
        
        nxt.resize(size + 10);
        val.resize(size + 10, -1);
        for(int i = 0; i < size + 10; i++) {
            nxt[i].resize(26, -1);
        }
        
        for(int i = 0; i < n; i++) {
            insert(wordsContainer, wordsContainer[i], i);
        }
        
        std::vector<int> ans(m);
        for(int i = 0; i < m; i++) {
            ans[i] = query(wordsQuery[i]);
        }
        
        return ans;
    }
    
    void insert(std::vector<std::string>& a, std::string& s, int idx) {
        int n = s.size();
        int cur = 0;
        
        if(val[cur] == -1 || a[val[cur]].size() > n) {
            val[cur] = idx;
        } 
        
        for(int i = n - 1; i >= 0; i--) {
            int x = s[i] - 'a';
            if(nxt[cur][x] == -1) {
                nxt[cur][x] = ++id;
            }
            
            cur = nxt[cur][x];
            if(val[cur] == -1 || a[val[cur]].size() > n) {
                val[cur] = idx;
            } 
        }
    }
    
    int query(std::string& s) {
        int n = s.size();
        int cur = 0;
        int res = val[cur];
        
        for(int i = n - 1; i >= 0; i--) {
            int x = s[i] - 'a';
            
            if(nxt[cur][x] == -1) {
                break;
            }
            cur = nxt[cur][x];
            res = val[cur];
        }
        
        return res;
    }
};
