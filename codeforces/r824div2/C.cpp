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

    string T;
    cin >> T;

    array<int, 26> map;
    array<bool, 26> used;
    map.fill(-1);
    used.fill(false);

    for(int i = 0; i < N; i++) {
        int c = T[i] - 'a';
        if(map[c] != -1) continue;

        for(int j = 0; j < 26; j++) {
            if(used[j]) continue;
            if(j == c) continue;
            int cycle = 1;
            int cur = j;
            while(true) {
                if(cur == c) {
                    break;
                }
                if(cur == -1) {
                    cycle = 0;
                    break;
                }
                cur = map[cur];
                cycle++;
            }

            if(cycle == 0 || cycle == 26) {
                map[c] = j;
                used[j] = true;
                break;
            }
        } 
    }

    string ans = "";
    for(int i = 0; i < N; i++) {
        ans.push_back((char)(map[T[i] - 'a'] + 'a'));
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
