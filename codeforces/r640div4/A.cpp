#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    vector<int> t;
    int base = 1;
    while(N) {
        int x = (N % 10) * base;
        if(x) {
            t.push_back(x);
        }
        N /= 10;
        base *= 10;
    }

    int m = t.size();
    cout << m << '\n';
    for(int i = 0; i < m; i++) {
        cout << t[i] << " \n"[i == m - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
