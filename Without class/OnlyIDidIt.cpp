#include <iostream>
#include <queue>
#include <set>

using namespace std;

set<int> problems[3], ans[3];
int S[3];
int p[3][10000];
int Max;
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int c = 0 ; c < t ; ++c){
        Max = 0;
        for(int i = 0 ; i < 3 ; ++i){
            problems[i].clear();
            ans[i].clear();
        }
        for(int i = 0 ; i < 3 ; ++i){
            cin>>S[i];
            for(int j = 0 ; j < S[i] ; ++j){
                cin>>p[i][j];
                problems[(i+1)%3].insert(p[i][j]);
                problems[(i+2)%3].insert(p[i][j]);
            }
        }
        for(int i = 0 ; i < 3 ; ++i){
            for(int j = 0 ; j < S[i] ; ++j){
                if(problems[i].find(p[i][j])==problems[i].end()){
                    ans[i].insert(p[i][j]);
                }
            }
            int s = ans[i].size();
            Max = max(Max, s);
        }
        cout<<"Case #"<<(c+1)<<":\n";
        for(int i = 0 ; i < 3; ++i){
            int s =ans[i].size();
            if(s==Max){
                cout<<(i+1)<<" "<<Max;
                for(int m : ans[i])
                    cout<<" "<<m;
                cout<<"\n";
            }  
        }
    }
    return 0;
}