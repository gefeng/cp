#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    string S;
    cin >> S;

    vector<bool> fixed(10, false);
    vector<bool> excluded(10, false);
    for(int i = 0; i < 10; i++) {
        if(S[i] == 'o') {
            fixed[i] = true;
        } else if(S[i] == 'x') {
            excluded[i] = true;
        }
    }

    int ans = 0;
    for(int a = 0; a < 10; a++) {
        for(int b = 0; b < 10; b++) {
            for(int c = 0; c < 10; c++) {
                for(int d = 0; d < 10; d++) {
                    array<int, 10> cnt{0};
                    cnt[a] += 1;
                    cnt[b] += 1;
                    cnt[c] += 1;
                    cnt[d] += 1;
                    
                    bool ok = true;
                    for(int i = 0; i < 10; i++) {
                        if(cnt[i] && excluded[i]) {
                            ok = false;
                            break;
                        }
                    }
 
                    for(int i = 0; i < 10; i++) {
                        if(cnt[i] == 0 && fixed[i]) {
                            ok = false;
                            break;
                        }
                    }
 
                    if(ok) {
                        ans += 1;
                    }
                }
            }
        } 
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
