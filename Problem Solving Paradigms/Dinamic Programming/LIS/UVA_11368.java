import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;

public class UVA_11368 {
    static Pair[]b;
    static int[] DP, arr;
    static int it;
    //A LIS greedy with O(nlogn)
    static int solve(int n){
        ArrayList<Integer> lis = new ArrayList<>(n);
        lis.add(arr[0]);
        for(int i = 1 ; i < n ; ++i){
            if(arr[i]>=lis.get(lis.size() - 1)){
                lis.add(arr[i]);
            }else{
                int index = bs(lis, lis.size(), arr[i]);
                lis.set(index, arr[i]);
            }
        }
        return lis.size();
    }
    static int bs(ArrayList<Integer> arr, int n, int x){
        int l = 0, r = n -1;
        int mid, ans = n;
        while(l <= r){
            mid = (l+r)/2;
            if(arr.get(mid) > x){
                r = mid - 1;
                ans = mid;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter out = new BufferedWriter(
            new OutputStreamWriter(System.out));
        String[]data;
        int t = Integer.valueOf(in.readLine());
        while((t--)!=0){
            int m = Integer.valueOf(in.readLine());
            b = new Pair[m];
            data = in.readLine().split(" ");
            for(int i = 0 ; i < m ; ++i){
                b[i] = new Pair(Integer.valueOf(data[2*i]) * -1, Integer.valueOf(data[(2*i) + 1]));
            }
            Arrays.sort(b);
            arr = new int[m];
            for(int i = 0 ; i < m ; ++i){
                arr[i] = b[i].w;
            }
            
            out.write(solve(m)+"\n");
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
            return h - o.h != 0 ? h - o.h : w - o.w;
        }
        @Override
        public String toString() {
            return "[" + w + ", " + h + "]";
        }

        

    }
}
