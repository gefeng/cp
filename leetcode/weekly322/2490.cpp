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
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        
        for(int i = 0; i < n; i++) {
            if(sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1]) {
                return false;
            }
        }
        
        return sentence[n - 1] == sentence[0];
    }
};
