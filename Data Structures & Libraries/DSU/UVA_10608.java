import java.io.*;

public class UVA_10608 {
    static int[]p;
    static int N;
    static int[]size, rank;
    static void init(){
        p = new int[N + 1];
        size = new int[N + 1];
        for(int i = 1 ; i <= N ; ++i){
            p[i] = i;
            size[i] = 1;
        }
    }
    static int find(int x){
        if(x != p[x])
            return find(p[x]); //return p[x] = find(p[x]) for path compression
        return x;
    }
    static void union(int x, int y){
        x = find(x); y = find(y);
        if(x == y) return;
        if (size[x] < size[y]){
            int aux = x; x = y; y = aux;
        }
        p[x] = y; size[y]+=size[x];
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
        String[]data;
        int T = Integer.valueOf(in.readLine());
        while((T--)!=0){
            int M;
            data = in.readLine().split(" ");
            N = Integer.valueOf(data[0]);
            M = Integer.valueOf(data[1]);
            init();
            for(int i = 0 ; i < M ; ++i){
                int A, B;
                data = in.readLine().split(" ");
                A = Integer.valueOf(data[0]);
                B = Integer.valueOf(data[1]);
                union(A, B);
            }
            int res = 0;
            for(int i = 1 ; i <= N ; ++i){
                res = Math.max(res, size[i]);
            }
            out.write(res+"\n");
        }
        in.close();
        out.flush();
        out.close();
    }
}
