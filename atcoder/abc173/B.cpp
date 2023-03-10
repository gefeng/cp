#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    map<string, int> m;
    for(int i = 0; i < N; i++) {
        string S;
        cin >> S;

        m[S] += 1; 
    }

    for(string s : {"AC", "WA", "TLE", "RE"}) {
        cout << s << " x " << m[s] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
