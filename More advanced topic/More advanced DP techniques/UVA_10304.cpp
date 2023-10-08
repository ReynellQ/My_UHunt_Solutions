/*
Knuth optimization
*/

#include <bits/stdc++.h>

using namespace std;

int DP[251][251], op[251][251];

int rangeSum(int i, int j, vector<int>&e ){
    if(i == 0){
        return e[j];
    }
    return e[j] - e[i - 1];
}
int dp(int n, vector<int>& e){
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            DP[i][j]= 0;
            op[i][j] = max(i, j);
        }
    }

    for(int l = 1 ; l <= n ; ++l){
        for(int i = 0 ; i + l < n ; ++i){
            int j = i + l;
            DP[i][j] = INT_MAX;
            int sum = rangeSum(i, j, e);
            for(int k = op[i][j - 1]; k <= min(j, op[i+1][j]) ; ++k){
                int treeValue = sum - rangeSum(k, k, e);
                int val = DP[i][k - 1] + DP[k + 1][j] + treeValue;
                if(DP[i][j] >= val){
                    DP[i][j] = val;
                    op[i][j] = k;
                }
                
            }
        }
    }
    return DP[0][n - 1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; 
    while(cin >> n ){
        vector<int> e(n);
        for(int i = 0 ; i < n ; ++i){
            cin >> e[i];
        }
        for(int i = 1 ; i < n ; ++i){
            e[i] = e[i] + e[i - 1];
        }
        cout << dp(n, e) << "\n";
    }
    
    
}