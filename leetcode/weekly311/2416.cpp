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
    int smallestEvenMultiple(int n) {
        return n % 2 ? 2 * n : n;
    }
};
