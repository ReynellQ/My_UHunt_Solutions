#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 1000010;
vector<int> divisors(MAX_N+1), N;
void init(){
    divisors[1] = 1;
    for (int i = 2; i <= MAX_N; i++) {
        for (int j = i; j <= MAX_N; j += i)
            divisors[j]++;
        divisors[i]++;
    }
    N.push_back(1);
    for (int i = 1; N[i - 1]+ divisors[N[i - 1]] < MAX_N; i++) 
        N.push_back(N[i - 1]+ divisors[N[i - 1]]);
}
int binarySearch(int obj, vector<int> &arr){
    int l = 0, r = arr.size() - 1;
    while(l<=r){
        int mid = (l + r)/2;
        if(arr[mid] <obj){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    return l;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T; cin >>T;
    init();
    for(int i = 0 ; i < T ; ++i){
        int A, B; cin >>A>>B;
        int l = binarySearch(A, N);
        int r = binarySearch(B, N);
        cout <<"Case "<<(i+1)<<": "<< (r - l + (N[r] == B )) <<"\n";
    }
    
    
}