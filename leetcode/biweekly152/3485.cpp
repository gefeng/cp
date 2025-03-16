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
    void dfs(int k, std::vector<std::vector<int>>& next, std::vector<int>& freq, int v, std::string& s, std::string& best) {
        if(s.size() > best.size()) {
            best = s;
        }
        
        for(int i = 0; i < 26; i++) {
            if(next[v][i] != -1 && freq[next[v][i]] >= k) {
                s.push_back(char(i + 'a'));
                dfs(k, next, freq, next[v][i], s, best);
                s.pop_back();
            }
        }
    }
    
    void remove(std::vector<std::vector<int>>& next, std::vector<int>& freq, std::string& s) {
        int n = s.size();
        int now = 0;
        for(int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            now = next[now][c];
            freq[now] -= 1;
        }
    }
    
    void add(std::vector<std::vector<int>>& next, std::vector<int>& freq, std::string& s) {
        int n = s.size();
        int now = 0;
        for(int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            now = next[now][c];
            freq[now] += 1;
        }
    }
    
    std::vector<int> longestCommonPrefix(std::vector<std::string>& words, int k) {
        int n = words.size();
        std::vector<int> ans(n, 0);
        
        if(k == n) {
            return ans;
        }
        
        int m = 1;
        for(std::string& s : words) {
            m += s.size();
        }
        
        std::vector<std::vector<int>> next(m, std::vector<int>(26, -1));
        std::vector<int> freq;
        int id = 1;
        freq.push_back(0);
        
        for(std::string& s : words) {
            int size = s.size();
            int now = 0;
            for(int i = 0; i < size; i++) {
                int c = s[i] - 'a';
                if(next[now][c] == -1) {
                    next[now][c] = id++;    
                }
                now = next[now][c];
                if(freq.size() < id) {
                    freq.push_back(1);
                } else {
                    freq[now] += 1;
                }
            }
        }
        
        std::string s_1 = "";
        std::string s_2 = "";
        std::string s = "";
        dfs(k, next, freq, 0, s, s_1);
        
        s = "";
        remove(next, freq, s_1);
        
        dfs(k, next, freq, 0, s, s_2);
        
        add(next, freq, s_1);
        
        for(int i = 0; i < n; i++) {
            std::string& s = words[i];
            
            if(s.find(s_1) == 0) {
                ans[i] = s_2.size();
            } else {
                ans[i] = s_1.size();
            }
        }
        
        return ans;
    }
};
