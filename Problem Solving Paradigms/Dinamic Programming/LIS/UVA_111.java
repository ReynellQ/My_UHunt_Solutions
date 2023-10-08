import java.io.*;

public class UVA_111 {
    static int[] ordering, a;
    static int[][] dp;
    static int lcs(int i, int j){
        if(i < 0 || j < 0)
            return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(ordering[i] == a[j])
            ans = lcs(i - 1, j - 1) +1;
        else
            ans = Math.max(lcs(i - 1, j), lcs(i, j - 1));
        return dp[i][j] = ans;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter out = new BufferedWriter(
            new OutputStreamWriter(System.out));
        String[]data;
        int n = Integer.valueOf(in.readLine());
        data = in.readLine().split(" ");
        ordering = new int[n];
        for(int i = 0 ; i < n ; ++i)
            ordering[Integer.valueOf(data[i]) - 1] = i;
        while(in.ready()){
            data = in.readLine().split(" ");
            a = new int[n];
            dp = new int[n][n];
            for(int i = 0 ; i < n ; ++i){
                for(int j = 0 ; j < n ; ++j){
                    dp[i][j] = -1;
                }
            }
            for(int i = 0 ; i < n ; ++i){
                a[Integer.valueOf(data[i]) - 1] = i;
            }
            out.write(lcs(n - 1, n - 1)+"\n");
        }
        out.flush();
    }
}
