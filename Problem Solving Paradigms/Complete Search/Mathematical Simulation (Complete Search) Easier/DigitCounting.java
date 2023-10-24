import java.io.*;
import java.util.*;

public class DigitCounting {
    static int [][] DP;
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter output = new BufferedWriter(
            new OutputStreamWriter(System.out));
        init();
        int t = Integer.parseInt(in.readLine());
        while((t--)!=0){
            int N = Integer.parseInt(in.readLine());
            for(int i = 0 ; i < 10 ; ++i){
                output.write(DP[N][i] +(i != 9 ? " " : ""));
            }
            output.write("\n");
        }
        output.flush();
    }

    private static void init() {
        DP = new int[10000][10];
        for(int n = 1 ; n < 10000 ; ++n){
            int N = n;
            for(int i = 0 ; i < 10 ; ++i)
                DP[n][i] = DP[n - 1][i];
            while(N !=0){
                DP[n][N%10]++;
                N=N/10;
            }
        }
    }
}
