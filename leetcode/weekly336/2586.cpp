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
    int vowelStrings(vector<string>& words, int left, int right) {
        int ans = 0;
        string vowels = "aeiou";
        for(int i = left; i <= right; i++) {
            if(vowels.find(words[i][0]) != string::npos && vowels.find(words[i][words[i].size() - 1]) != string::npos) {
                ans += 1;
            }
        }
        
        return ans;
    }
};
