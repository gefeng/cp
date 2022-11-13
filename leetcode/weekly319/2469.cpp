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
    vector<double> convertTemperature(double celsius) {
        vector<double> ans;
        
        ans.push_back(celsius + 273.15);
        ans.push_back(celsius * 1.8 + 32.0);
        
        return ans;
    }
};
