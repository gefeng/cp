#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void run_case() {
    int N;
    cin >> N;
    
    vector<int> A(N, 0);
    unordered_map<int, int> m;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        m[A[i]]++;
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        int sum = A[i];
        for(int j = i + 1; j < N; j++) {
            sum += A[j];
            if(m.find(sum) != m.end()) {
                ans += m[sum];
                m.erase(sum);
            }
        }
    }

    cout << ans << '\n';
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
