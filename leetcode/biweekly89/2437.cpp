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
    int countTime(string time) {
        int cnt_1 = 1;
        int cnt_2 = 1;
        
        if(time[0] == '?') {
            if(time[1] == '?') {
                cnt_1 = 24;
            } else {
                if(time[1] > '3') {
                    cnt_1 = 2;
                } else {
                    cnt_1 = 3;
                }
            }
        } else {
            if(time[1] == '?') {
                if(time[0] == '2') {
                    cnt_1 = 4;
                } else {
                    cnt_1 = 10;
                }
            }
        }
        
        if(time[3] == '?') {
            if(time[4] == '?') {
                cnt_2 = 60;    
            } else {
                cnt_2 = 6;
            }
        } else {
            if(time[4] == '?') {
                cnt_2 = 10;
            }
        }
        
        return cnt_1 * cnt_2; 
    }
};
