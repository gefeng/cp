#include <vector>
#include <set>
#include <map>

using namespace std;

void compress(vector<int>& a) {
    set<int> s(a.begin(), a.end());

    map<int, int> m;
    int id = 0;
    for(int x : s) {
        m[x] = id++;
    }

    for(int& x : a) {
        x = m[x];
    }
}
