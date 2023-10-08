import java.io.*;
import java.util.Arrays;

public class UVA_1196 {
    static Pair[]b;
    static int[] DP, arr;
    static int it;
    //A LIS DP
    static int solve(int i){
        if(DP[i] != 0)
            return DP[i];
        int ans = 1;
        for(int j = 0 ; j < i; ++j){
            int prev = solve(j) + 1;
            if(arr[i] > arr[j]){
                if(prev >= ans){
                    ans = prev;
                }
            }
        }
        return DP[i] = ans;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("text.in"));
        BufferedWriter out = new BufferedWriter(
            new OutputStreamWriter(System.out));
        String[]data;
        int t = Integer.valueOf(in.readLine());
        while((t--)!=0){
            int m = Integer.valueOf(in.readLine());
            b = new Pair[m];
            data = in.readLine().split(" ");
            for(int i = 0 ; i < m ; ++i){
                b[i] = new Pair(Integer.valueOf(data[2*i]), Integer.valueOf(data[(2*i) + 1]));
            }
            Arrays.sort(b);
            arr = new int[m];
            for(int i = 0 ; i < m ; ++i){
                arr[i] = b[i].h;
            }
            System.out.println(Arrays.toString(b));
            
            int res = 0;
            DP = new int[m];
            for(int i = 0 ; i < m ; ++i)
                res = Math.max(solve(i), res);
            System.out.println(Arrays.toString(DP));
            
            out.write(res+"\n");
        }
        out.flush();
        out.close();
    }
    static class Pair implements Comparable<Pair>{
        public int w, h;
        public Pair(int w, int h) {
            this.w = w;
            this.h = h;
        }
        @Override
        public int compareTo(Pair o) {
            return w - o.w != 0 ? w - o.w : h - o.h;
        }
        @Override
        public String toString() {
            return "[" + w + ", " + h + "]";
        }

        

    }
}
