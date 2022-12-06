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
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    set<int> s;
    for(int a = 1; a <= 1000; a++) {
        for(int b = 1; a * b <= 1000; b++) {
            s.insert(4 * a * b + 3 * a + 3 * b);
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(s.find(A[i]) == s.end()) {
            ans += 1;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
