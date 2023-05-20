#include <vector>
#include <set>
#include <map>

void compress(std::vector<int>& a) {
    std::set<int> s(a.begin(), a.end());

    std::map<int, int> m;
    int id = 0;
    for(int x : s) {
        m[x] = id++;
    }

    for(int& x : a) {
        x = m[x];
    }
}
