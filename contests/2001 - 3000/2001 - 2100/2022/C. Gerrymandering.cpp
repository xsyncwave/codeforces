#include <bits/stdc++.h>

const int maxcol = 1e5 + 5;
    
void solve() {
    int v[2][maxcol] = { }, dp[maxcol][3] = { };
    int col; std::cin >> col;
    
    std::string s1, s2; std::cin >> s1 >> s2;
    
    for(int j = 0; j < col; j++) v[0][j + 1] = (s1[j] == 'A')? 1: 0;
    for(int j = 0; j < col; j++) v[1][j + 1] = (s2[j] == 'A')? 1: 0;
    
    for(int c = 0; c <= col; c++) {
        for(int t = 0; t < 3; t++) {
            int votes;
            if(t == 0) {
                votes = (v[0][c + 1] + v[0][c + 2] + v[0][c + 3]) / 2 +  // x * * *
                        (v[1][c + 1] + v[1][c + 2] + v[1][c + 3]) / 2 ;  // x * * *
                dp[c + 3][0] = std::max(votes + dp[c][0], dp[c + 3][0]);
                
                votes = (v[0][c + 1] + v[0][c + 2] + v[1][c + 1]) / 2 ;  // x * *  
                dp[c + 1][1] = std::max(votes + dp[c][0], dp[c + 1][1]); // x *
                
                votes = (v[0][c + 1] + v[1][c + 1] + v[1][c + 2]) / 2 ;  // x *
                dp[c + 1][2] = std::max(votes + dp[c][0], dp[c + 1][2]); // x * *
            }
            
            if(t == 1) {
                votes = (v[0][c + 2] + v[0][c + 3] + v[0][c + 4]) / 2 +  // x x * * *
                        (v[1][c + 1] + v[1][c + 2] + v[1][c + 3]) / 2 ;  // x * * *
                dp[c + 3][1] = std::max(votes + dp[c][1], dp[c + 3][1]);
                
                votes = (v[0][c + 2] + v[1][c + 1] + v[1][c + 2]) / 2 ;  // x x *
                dp[c + 2][0] = std::max(votes + dp[c][1], dp[c + 2][0]); // x * *
            }
            
            if(t == 2) {
                votes = (v[0][c + 1] + v[0][c + 2] + v[0][c + 3]) / 2 +  // x * * *
                        (v[1][c + 2] + v[1][c + 3] + v[1][c + 4]) / 2 ;  // x x * * *
                dp[c + 3][2] = std::max(votes + dp[c][2], dp[c + 3][2]);
                
                votes = (v[0][c + 1] + v[0][c + 2] + v[1][c + 2]) / 2 ;  // x * *
                dp[c + 2][0] = std::max(votes + dp[c][2], dp[c + 2][0]); // x x *
            }
        }
    }
    
    std::cout << dp[col][0] << std::endl;
}


signed main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);
    
    int t; std::cin >> t; while(t--) solve();
    return 0;
}
// g++ -std=c++20 <filename>.cpp
