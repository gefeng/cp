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
    const int MAX = (int)1e5;
    
    std::vector<int> freq;
    std::vector<int> cnt_freq;

public:
    Solution() {
        freq.resize(MAX + 1, 0); 
        cnt_freq.resize(MAX + 1, 0);
    }
    
    void add(int number) {
        int f = freq[number];
        freq[number] = f + 1;
        cnt_freq[f] -= 1;
        cnt_freq[f + 1] += 1;
    }
    
    void deleteOne(int number) {
        int f = freq[number];
        if(f == 0) {
            return;
        }
        
        freq[number] = f - 1;
        cnt_freq[f] -= 1;
        cnt_freq[f - 1] += 1;
    }
    
    bool hasFrequency(int frequency) {
        return cnt_freq[frequency] > 0;
    }
};
