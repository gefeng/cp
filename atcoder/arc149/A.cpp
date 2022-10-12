#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

bool larger(string& s, string& t) {
    if(s.length() == t.length()) {
        return s > t; 
    }
    return s.length() > t.length();
}
void run_case() {
    int N, M;
    cin >> N >> M;

    int max_d = 0;
    int max_l = 0;
    for(int i = 9; i > 0; i--) {
        int cur = 0;
        for(int j = 1; j <= N; j++) {
            cur = cur * 10 + i;
            cur = cur % M;

            if(cur == 0) {
                if(j > max_l) {
                    max_l = j;
                    max_d = i;
                }
            }

        }
    }

    if(max_l == 0) {
        cout << -1 << '\n';
    } else {
        for(int i = 0; i < max_l; i++) {
            cout << max_d;
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
