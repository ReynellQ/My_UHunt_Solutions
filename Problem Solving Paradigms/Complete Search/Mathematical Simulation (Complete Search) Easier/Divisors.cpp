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
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int T; cin >> T;
    while(T--){
        int N, K; cin >> N >> K;
        set<int> divisors;
        for(int i = 1 ; i*i <= N ; ++i){
            if(N % i == 0){
                if(i % K != 0)
                    divisors.insert(i);
                if((N/i) % K != 0)
                    divisors.insert(N/i);
            }
        }
        ll res = 0ll;
        for(int x : divisors){
            res+=x;
        }
        cout << res << "\n";
    }
    return 0;
}