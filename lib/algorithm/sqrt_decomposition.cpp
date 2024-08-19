#include <utility>
#include <vector>

using LL = long long;

// Given a number x, split [1 : x] into buckets,
// in which for each element i, they have the same floor(x / i).
// Return a collection of <Q, L, R>.
std::vector<std::pair<LL, std::pair<LL, LL>>> lower_bound(LL x) {
    std::vector<std::pair<LL, std::pair<LL, LL>>> res;
    for(LL l = 1LL; l <= x; ) {
        LL r = x / (x / l);
        LL q = x / l;
        res.push_back(make_pair(q, std::make_pair(l, r)));
        l = r + 1;
    }    
    return res;
}

// if ceiling(x / i) is required, right bound should be (x - 1) / ((x - 1) / l)
