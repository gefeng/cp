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
    int maxContainers(int n, int w, int maxWeight) {
        return std::min(n * n, maxWeight / w);
    }
};
