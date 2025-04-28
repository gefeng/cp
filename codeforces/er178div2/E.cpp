#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    std::string S;
    std::cin >> S;

    std::vector<int> first(K, -1);
    std::vector<std::vector<int>> nxt(N, std::vector<int>(K, -1));

    for(int i = 0; i < N; i++) {
        first[S[i] - 'a'] = first[S[i] - 'a'] == -1 ? i : first[S[i] - 'a'];
    }

    for(int i = N - 2; i >= 0; i--) {
        nxt[i] = nxt[i + 1];
        nxt[i][S[i + 1] - 'a'] = i + 1;
    }

    std::vector<int> freq(K, 0);
    std::vector<int> cnt_full(N, 0);
    for(int i = N - 1; i >= 0; i--) {
        if(i < N - 1) {
            cnt_full[i] = cnt_full[i + 1];
        }

        bool full = true;
        for(int j = 0; j < K; j++) {
            if(!freq[j]) {
                full = false;
            }
        }

        if(full) {
            cnt_full[i] += 1;
            freq.assign(K, 0);
        }

        freq[S[i] - 'a'] += 1;
    }

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        std::string T;
        std::cin >> T;

        int len = T.size();
        int p = first[T[0] - 'a'];
        if(p == -1) {
            std::cout << 0 << '\n';
            continue;
        }

        bool is_subseq = true;
        for(int j = 1; j < len; j++) {
            p = nxt[p][T[j] - 'a'];
            if(p == -1) {
                is_subseq = false;
                break;
            }
        }

        if(!is_subseq) {
            std::cout << 0 << '\n';
            continue;
        }

        int cnt = cnt_full[p];
        std::cout << cnt + 1 << '\n'; 
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
