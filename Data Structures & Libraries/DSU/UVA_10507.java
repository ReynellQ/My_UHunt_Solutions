import java.io.*;
import java.util.ArrayList;
public class UVA_10507 {
    static int[]p;
    static int MAX_N = 26;
    static boolean[] awake;
    static void init(){
        p = new int[MAX_N + 1];
        for(int i = 1 ; i <= MAX_N ; ++i) p[i] = i;
    }
    static int find(int x){
        if(x != p[x]) return p[x] = find(p[x]);
        return x;
    }
    static void union(int x, int y){
        x = find(x); y = find(y);
        if(x == y) return;
        p[x] = y;
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
        String[]data;
        String s;
        while(!(s = in.readLine()).equals("")){
            awake = new boolean[MAX_N + 1];
            int N, M;
            N = Integer.valueOf(s);
            M = Integer.valueOf(in.readLine());
            init();
            char[]initial = in.readLine().toCharArray();
            for(int i = 0 ; i < 3 ; ++i)
                awake[initial[i]-'A'] = true;
            for(int i = 0 ; i < M ; ++i){
                char[]conn = in.readLine().toCharArray();
                union(conn[0]-'A', conn[1]-'A');
            }
            int res;
            int acum = 0;
            for(res = 1 ; res < MAX_N ; ++res){
                acum = 0;
                ArrayList<Integer> change = new ArrayList<>();
                for(int i = 0 ; i < MAX_N ; ++i){
                    if(awake[i]){
                        ++acum;
                    }else{
                        int m = 0;
                        for(int j = 0 ; j < MAX_N ; ++j){
                            if(awake[j] && find(i) == find(j)){
                                ++m;
                                System.out.println("CONEXION " +  (char)(i+'A') + " Y " + (char)(j+'A'));
                            }
                                
                            if(m == 3){
                                System.out.println("DESPERTADO " + (char)(i+'A'));
                                change.add(j);
                                acum++;
                                break;
                            }
                                
                        }
                    }
                }
                System.out.println("ACUM: " + acum);
                if(acum >= N)
                    break;
                if(change.isEmpty()){
                    res = -1;
                    break;
                }
                for(int e : change)
                    awake[e] = true;
            }
            if(res == -1){
                out.write("THIS BRAIN NEVER WAKES UP");
            }else{
                out.write("WAKE UP IN, "+res+", YEARS");
            }
            out.write("\n");
            in.readLine();
        }
        in.close();
        out.flush();
        out.close();
    }
}
