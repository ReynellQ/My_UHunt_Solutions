#include <iostream>
#include <queue>

using namespace std;
int A, B, C, D;
int dp[201][201][201], res[201];
const int INF = (1<<31)-1;
queue<int> QA, QB, QC, QTOT;
void push(int a, int b, int c, int tot) {
    QA.push(a), QB.push(b), QC.push(c), QTOT.push(tot);
}
void bfs(int a, int b, int c, int tot) {
    QA.push(a), QB.push(b), QC.push(c), QTOT.push(tot);
    while (!QA.empty()) {
        a = QA.front(), QA.pop();
        b = QB.front(), QB.pop();
        c = QC.front(), QC.pop();
        tot = QTOT.front(), QTOT.pop();
        if(tot >= res[D])   continue;
        if(tot >= dp[a][b][c])  continue;
        dp[a][b][c] = tot;
        res[a] = min(res[a], tot);
        res[b] = min(res[b], tot);
        res[c] = min(res[c], tot);
        if(a < B-b) push(0, b+a, c, tot+a);
        else        push(a-(B-b), B, c, tot+(B-b));
        if(a < C-c) push(0, b, c+a, tot+a);
        else        push(a-(C-c), b, C, tot+(C-c));
        if(b < A-a) push(a+b, 0, c, tot+b);
        else        push(A, b-(A-a), c, tot+(A-a));
        if(b < C-c) push(a, 0, c+b, tot+b);
        else        push(a, b-(C-c), C, tot+(C-c));
        if(c < A-a) push(a+c, b, 0, tot+c);
        else        push(A, b, c-(A-a), tot+(A-a));
        if(c < B-b) push(a, b+c, 0, tot+c);
        else        push(a, B, c-(B-b), tot+(B-b));
    }
    
}
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) {
        cin>>A>>B>>C>>D;
        for(int i = 0; i <= A; i++)
            for(int j = 0; j <= B; j++)
                for(int k = 0; k <= C; k++)
                    dp[i][j][k] = INF;
        for(int i = 0; i <= D; i++)
            res[i] = INF;
        bfs(0, 0, C, 0);
        while(res[D] == INF) D--;
        cout<<res[D]<<" "<<D<<"\n";
    }
    return 0;
}