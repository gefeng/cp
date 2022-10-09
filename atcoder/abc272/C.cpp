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

    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int max_eve_1 = -1;
    int max_eve_2 = -1;
    int max_odd_1 = -1;
    int max_odd_2 = -1;
    
    for(int x : A) {
        if(x & 1) {
            if(x > max_odd_1) {
                max_odd_2 = max_odd_1;
                max_odd_1 = x;
            } else if(x > max_odd_2) {
                max_odd_2 = x;
            }
        } else {
            if(x > max_eve_1) {
                max_eve_2 = max_eve_1;
                max_eve_1 = x;
            } else if(x > max_eve_2) {
                max_eve_2 = x;
            }
        }
    }

    if(max_odd_2 == -1 && max_eve_2 == -1) {
        cout << -1 << '\n';
        return;
    }

    if(max_odd_2 == -1) {
        cout << max_eve_1 + max_eve_2 << '\n';
        return;
    }
    if(max_eve_2 == -1) {
        cout << max_odd_1 + max_odd_2 << '\n';
        return;
    }

    cout << max(max_odd_1 + max_odd_2, max_eve_1 + max_eve_2) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
