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
    long long coloredCells(int n) {
        return (1LL + 2LL * n - 1LL) * n - (2LL * n - 1LL);
    }
};
