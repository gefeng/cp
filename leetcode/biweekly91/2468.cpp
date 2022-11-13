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
    vector<string> splitMessage(string message, int limit) {
        int n = message.length();
        
        vector<string> ans;
        for(int i = 1; i < 10000; i++) {
            if(is_ok(n, limit, i)) {
                split(message, limit, i, ans);
                break;
            }
        }
        
        return ans;
    }
    
    void split(string s, int limit, int b, vector<string>& ans) {
        int n = s.length();
        
        string fixed = "/" + to_string(b) + ">";
        
        for(int i = 1, j = 0; i <= b; i++) {
            string prefix = "";
            string suffix = "<" + to_string(i) + fixed;
            
            int len = limit - suffix.length();
            while(len && j < n) {
                prefix.push_back(s[j++]);
                len--;
            }
            
            ans.push_back(prefix + suffix);
        }
    }
    
    bool is_ok(int n, int limit, int x) { 
        int suffix = to_string(x).length();
        int fixed = suffix + 3;
        
        if(fixed + suffix >= limit) {
            return false;
        }
        
        int need = 0;
        int a = 1;
        int b = x;
        int d = 9;
        while(b) {
            if(d < b) {
                need += d * (limit - fixed - a);
                b -= d;
            } else {
                need += b * (limit - fixed - a);
                b = 0;
            }
            a += 1;
            d *= 10;
        }
        
        if(need == n) {
            return true;
        }
        
        if(need < n) {
            return false;
        }
        
        return need - n < limit - fixed - suffix;
    }
};
