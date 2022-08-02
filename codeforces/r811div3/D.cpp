#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

void run_case() {
    string T;
    cin >> T;

    int N;
    cin >> N;
    
    vector<string> S(N);
    for(int i = 0; i < N; i++) {
        cin >> S[i];
    }

    unordered_map<int, vector<int>> map;
    for(int i = 0; i < N; i++) {
        int j = 0;
        while(true) {
            j = T.find(S[i], j);

            if(j == string::npos) {
                break;
            }

            map[i].push_back(j);
            j++;
        }
    }

    vector<pair<int, int>> ans;
    int len = T.length();
    for(int i = 0; i < len; ) {
        int max_l = 0;
        int max_i = 0; 
        int max_p = 0;

        for(auto& it : map) {
            for(int j : it.second) {
                int k = j + S[it.first].length() - 1;
                if(j <= i && k >= i) {
                    if(max_l < k - i + 1) {
                        max_l = k - i + 1;
                        max_i = it.first;
                        max_p = j;
                    }
                }
            }
        }

        if(!max_l) {
            cout << -1 << '\n';
            return;
        }

        ans.emplace_back(max_i + 1, max_p + 1);
        i += max_l;
    } 

    cout << ans.size() << '\n';
    for(auto& p : ans) {
        cout << p.first << ' ' << p.second << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);        // de-sync with c stream
    cin.tie(0);                         // disable flushing of std::cout
    
    int t = 0;
    cin >> t;
    while(t--) {
        run_case();
    }
}
