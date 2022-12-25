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
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        set<string> pos;
        set<string> neg;
        
        for(string s : positive_feedback) {
            pos.insert(s);
        }
        for(string s : negative_feedback) {
            neg.insert(s);
        }
        
        int n = report.size();
        vector<pair<int, int>> ans(n);
        for(int i = 0; i < n; i++) {
            int id = student_id[i];
            string r = report[i];
            
            ans[i].second = id;
            
            int score = 0;
            string cur = "";
            int len = r.length();
            for(int i = 0; i < len; i++) {
                if(r[i] != ' ') {
                    cur.push_back(r[i]);
                }
                
                if(r[i] == ' ' || i == len - 1) {
                    if(pos.find(cur) != pos.end()) {
                        score += 3;
                    }
                    if(neg.find(cur) != neg.end()) {
                        score -= 1;
                    }
                    cur = "";
                }
            }
            
            ans[i].first = score;
        }
        
        auto cmp = [](auto& a, auto& b) {
            if(a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        };
        sort(ans.begin(), ans.end(), cmp);
        
        vector<int> res;
        
        for(int i = 0; i < k; i++) {
            res.push_back(ans[i].second);    
        }
        
        return res;
        
    }
};
