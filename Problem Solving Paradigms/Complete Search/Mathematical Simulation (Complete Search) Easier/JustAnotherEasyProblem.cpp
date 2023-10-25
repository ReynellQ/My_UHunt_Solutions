#include <bits/stdc++.h>
#define INF INT_MAX
#define MINF INT_MIN
#define ll long long
#define PB push_back 
#define PF push_front
#define P_F pop_front
#define P_B pop_back
#define F front
#define B back
#define f first
#define s second
#define MP make_pair
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define FORI(i, a, b) for(ll i = a; i >= b; i--)

using namespace std;

bool isSquare(int num){
    int sqr = sqrt(num);
    return sqr*sqr == num;
}
int solve(string N){
    string aux = N;
    int res = 0;
    for(int i = 0 ; i < 4 ; ++i){
        for(int j = 0 ; j < 10 ; ++j){
            if(i == 0 && j == 0) continue;
            if(j + '0' != N[i]){
                aux[i] = j + '0';
                int num = stoi(aux);
                //cout << num << "\n";
                if(isSquare(num)){
                    ++res;
                }
                aux[i] = N[i];
            }
        }
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int T; cin >> T;
    int c = 1;
    while(T--){
        string N; cin >> N;
        int res = solve(N);
        cout <<"Case " << c << ": "<< res << "\n";
        ++c;
    }
    return 0;
}