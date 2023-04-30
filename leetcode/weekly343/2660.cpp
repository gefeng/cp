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
    int isWinner(std::vector<int>& player1, std::vector<int>& player2) { 
        auto solve = [](const std::vector<int>& a) {
            int sum = 0;
            int n = a.size();
            for(int i = 0; i < n; i++) {
                int score = a[i];
                if(i > 0 && a[i - 1] == 10) {
                    score *= 2;
                } else if(i > 1 && a[i - 2] == 10) {
                    score *= 2;
                }
                sum += score;
            }
            return sum;
        };
        
        int s1 = solve(player1);
        int s2 = solve(player2);
        
        if(s1 == s2) {
            return 0;
        }
        if(s1 > s2) {
            return 1;
        } else {
            return 2;
        }
    }
};
