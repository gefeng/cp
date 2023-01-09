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
using LL = long long;

class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool s1 = length >= 10000 || width >= 10000 || height >= 10000;
        bool s2 = 1LL * length * width * height >= (LL)1e9;
        bool s3 = mass >= 100;
        bool s4 = s1 || s2;
        
        if(s3 && s4) return "Both";
        if(s3) return "Heavy";
        if(s4) return "Bulky";
        return "Neither";
    }
};
