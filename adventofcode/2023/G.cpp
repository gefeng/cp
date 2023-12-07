#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int FIVE_OF_A_KIND = 7;
constexpr int FOUR_OF_A_KIND = 6;
constexpr int FULL_HOUSE = 5;
constexpr int THREE_OF_A_KIND = 4;
constexpr int TWO_PAIR = 3;
constexpr int ONE_PAIR = 2;
constexpr int HIGH_CARD = 1;

std::vector<std::pair<std::string, int64_t>> A;

std::map<char, int> M1 = {{'A', 14}, {'K', 13}, {'Q', 12}, {'J', 11}, {'T', 10}, {'9', 9}, {'8', 8}, 
    {'7', 7}, {'6', 6}, {'5', 5}, {'4', 4}, {'3', 3}, {'2', 2}};

std::map<char, int> M2 = {{'A', 14}, {'K', 13}, {'Q', 12}, {'J', 1}, {'T', 10}, {'9', 9}, {'8', 8}, 
    {'7', 7}, {'6', 6}, {'5', 5}, {'4', 4}, {'3', 3}, {'2', 2}};

int get_strength(const std::string& s, int joker) {
    std::array<int, 15> cnt_cards = {};
    for(int i = 0; i < 5; i++) {
        cnt_cards[joker ? M2[s[i]] : M1[s[i]]] += 1;
    }

    std::array<int, 6> cnt = {};
    for(int i = 0; i < 15; i++) {
        if(cnt_cards[i]) {
            cnt[cnt_cards[i]] += 1;
        }
    }

    if(!joker || cnt_cards[M2['J']] == 0) {
        if(cnt[5]) {
            return FIVE_OF_A_KIND;
        }
        if(cnt[4]) {
            return FOUR_OF_A_KIND;
        }
        if(cnt[3] && cnt[2]) {
            return FULL_HOUSE;
        }
        if(cnt[3]) {
            return THREE_OF_A_KIND;
        }
        if(cnt[2] == 2) {
            return TWO_PAIR;
        }
        if(cnt[2]) {
            return ONE_PAIR;
        }
        return HIGH_CARD;
    }

    int cnt_j = cnt_cards[M2['J']];
    if(cnt[5] || cnt[4] || (cnt[3] && cnt[2])) {
        return FIVE_OF_A_KIND;
    }
    if(cnt[3]) {
        return FOUR_OF_A_KIND; 
    }
    if(cnt[2] == 2) {
        if(cnt_j == 2) {
            return FOUR_OF_A_KIND;
        }
        return FULL_HOUSE;
    }
    if(cnt[2]) {
        return THREE_OF_A_KIND;
    }
    return ONE_PAIR;
}

void run_case1() {
    auto cmp = [](const auto& a, const auto& b) {
        int ta = get_strength(a.first, 0);
        int tb = get_strength(b.first, 0);
        if(ta == tb) {
            for(int i = 0; i < 5; i++) {
                int x = M1[a.first[i]];
                int y = M1[b.first[i]];
                if(x != y) {
                    return x < y;
                }
            }
            return false;
        } 

        return ta < tb;
    };

    std::sort(A.begin(), A.end(), cmp); 
    
    int64_t ans = 0;
    for(int i = A.size() - 1; i >= 0; i--) {
        ans += (i + 1) * A[i].second; 
    } 

    std::cout << ans << '\n';
}

void run_case2() {
    auto cmp = [](const auto& a, const auto& b) {
        int ta = get_strength(a.first, 1);
        int tb = get_strength(b.first, 1);
        if(ta == tb) {
            for(int i = 0; i < 5; i++) {
                int x = M2[a.first[i]];
                int y = M2[b.first[i]];
                if(x != y) {
                    return x < y;
                }
            }
            return false;
        } 

        return ta < tb;
    };

    std::sort(A.begin(), A.end(), cmp); 
    
    int64_t ans = 0;
    for(int i = A.size() - 1; i >= 0; i--) {
        ans += (i + 1) * A[i].second; 
    } 

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string S;
    while(std::getline(std::cin, S)) {
        int n = S.size();
        std::string hand = S.substr(0, 5);
        std::string bid = S.substr(6, n - 6);
        
        A.emplace_back(hand, std::stol(bid));
    }

    run_case1();
    run_case2();
}
