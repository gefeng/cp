#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr double EPS = double(1e-6);

class Solution {
public:
    double separateSquares(std::vector<std::vector<int>>& squares) {
        int n = squares.size();
        double lo = 0.0;
        double hi = 2e9;
        double ans = 0.0;
    
        while(hi - lo > EPS) {
            double mid = (lo + hi) / 2.0;
            double above = 0.0;
            double below = 0.0;
            for(auto& s : squares) {
                double x = s[0];
                double y = s[1];
                double l = s[2];
                
                if(y - mid > EPS) {
                    above += l * l;
                } else if(mid - y - l > EPS) {
                    below += l * l;
                } else {
                    above += l * (y + l - mid);
                    below += l * (mid - y);
                }
            }

            if(std::abs(below - above) <= EPS) {
                ans = mid;
                hi = mid;
            } else if(below - above > EPS) {
                ans = mid;
                hi = mid;
            } else {
                lo = mid;
            }
        }
        
        return ans;
    }
};
