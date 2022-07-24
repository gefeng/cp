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
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        if(count(suits.begin(), suits.end(), suits[0]) == 5) {
            return "Flush";
        }

        array<int, 14> cnt = {0};
        for(int i = 0; i < 5; i++) {
            cnt[ranks[i]]++; 
        }

        for(int i = 0; i < 14; i++) {
            if(cnt[i] > 2) {
                return "Three of a Kind";
            }
            if(cnt[i] > 1) {
                return "Pair";
            }
        }

        return "High Card";
    }
};
