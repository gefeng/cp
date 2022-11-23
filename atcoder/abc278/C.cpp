#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using namespace std;

void run_case() {
    int N, Q;
    cin >> N >> Q;

    set<pair<int, int>> s;
    for(int i = 0; i < Q; i++) {
        int T, A, B;
        cin >> T >> A >> B;

        if(T == 1) {
            s.emplace(A, B);
        }
        if(T == 2) {
            s.erase({A, B});
        }
        if(T == 3) {
            if(s.find({A, B}) != s.end() && s.find({B, A}) != s.end()) {
                cout << "Yes" << '\n';
            } else {
                cout << "No" << '\n';
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
