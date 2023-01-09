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
    bool isItPossible(string word1, string word2) {
        array<int, 26> cnt1{0};
        array<int, 26> cnt2{0};
        
        for(char c : word1) {
            cnt1[c - 'a'] += 1;
        }
        
        for(char c : word2) {
            cnt2[c - 'a'] += 1;
        }
        
        for(int i = 0; i < 26; i++) {
            if(cnt1[i]) {
                for(int j = 0; j < 26; j++) {
                    if(cnt2[j]) {
                        cnt1[i] -= 1;
                        cnt1[j] += 1;
                        
                        cnt2[i] += 1;
                        cnt2[j] -= 1;
                        
                        int tot1 = 0;
                        int tot2 = 0;
                        for(int k = 0; k < 26; k++) {
                            if(cnt1[k]) {
                                tot1 += 1;
                            }
                            if(cnt2[k]) {
                                tot2 += 1;
                            }
                        }
                        
                        if(tot1 == tot2) {
                            return true;
                        }
                        
                        cnt1[i] += 1;
                        cnt1[j] -= 1;
                        
                        cnt2[i] -= 1;
                        cnt2[j] += 1;
                    }
                }
            }
        }
        
        return false;
    }
};
