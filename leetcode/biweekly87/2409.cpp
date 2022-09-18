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
    array<int, 12> days{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int ans = 0;
        int l_a = to_days(arriveAlice);
        int r_a = to_days(leaveAlice);
        int l_b = to_days(arriveBob);
        int r_b = to_days(leaveBob);
        
        if((l_b <= r_a && r_b >= r_a) || (r_b >= l_a && l_b <= r_a)) {
            return min(r_a, r_b) - max(l_a, l_b) + 1;
        } 
        
        return 0;
    }
    
    int to_days(string s) {
        string m_str = s.substr(0, 2);
        string d_str = s.substr(3, 2);
        
        int m = (m_str[0] - '0') * 10 + m_str[1] - '0';
        int d = (d_str[0] - '0') * 10 + d_str[1] - '0';
        
        int sum = 0;
        for(int i = 0; i < m - 1; i++) {
            sum += days[i];
        }
        sum += d;
        
        return sum;
    }
};
