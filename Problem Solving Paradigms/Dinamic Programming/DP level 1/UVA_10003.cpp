#include <bits/stdc++.h>

using namespace std;

int DP[102][102];
int dp(int i, int j, vector<int>& cuts){
    if( i == j){
        return DP[i][j] = 0;
    }
    if(DP[i][j] != -1){
        return DP[i][j];
    }
    int ans = INT_MAX;
    for(int k = i; k < j ; ++k){
        ans = min(ans, dp(i, k, cuts) + dp(k + 1, j, cuts) + cuts[j + 1] - cuts[i]);
    }
    return DP[i][j] = ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int l; 
    while(cin >> l, l){
        int n; cin >> n;
        vector<int> cuts(n+2);
        cuts[0] = 0;
        for(int i = 0 ; i < n + 2 ; ++i)
            for(int j = 0 ; j < n + 2 ; ++j)
                DP[i][j] = -1;
        for(int i = 0 ; i < n ; ++i){
            cin >> cuts[i + 1];
        }
        cuts[n + 1] = l;
        
        cout << "The minimum cutting is " << dp(0, n , cuts) << ".\n";
        
    }
    
    
}