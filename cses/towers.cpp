#include <iostream>
#include <vector>
#include <map>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    map<int, int> m;
    for(int i = 0; i < N; i++) {
        int X;
        cin >> X;

        auto it = m.upper_bound(X);
        if(it == m.end()) {
            m[X]++;
        } else {
            if(--(it->second) == 0) {
                m.erase(it);
            }
            m[X]++;
        }
    }
    
    int ans = 0;
    for(auto& [k, v] : m) {
        ans += v;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    run_case();
}
