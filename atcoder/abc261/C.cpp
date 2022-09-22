#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);        // de-sync with c stream
    cin.tie(nullptr);                   // disable flushing of std::cout

    int n = 0;
    cin >> n;

    vector<string> v(n);
    unordered_map<string, int> map;
    for(int i = 0; i < n; i++) {
        cin >> v[i];

    }

    for(string& s : v) {
        if(!map.count(s)) {
            cout << s << '\n';
        } else {
            cout << s << '(' << map[s] << ')' << '\n';
        }

        map[s]++;
    }
}
