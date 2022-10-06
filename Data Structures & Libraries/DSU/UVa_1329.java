import java.io.*;

public class UVa_1329 {
    static int[] p;
    static int[] distance;
    static int n;

    static void init(int n) {
        p = new int[n + 1];
        distance = new int[n + 1];
        for (int i = 0; i < n + 1; ++i) {
            p[i] = i;
        }
    }

    static int find(int x) {
        if (x != p[x]) {
            int oldP = p[x];
            p[x] = find(p[x]);
            distance[x] += distance[oldP];
        }

        return p[x];
    }

    static void union(int x, int y) {
        int dis = Math.abs(x - y) % 1000;
        if (x != y) {
            p[x] = y;
            distance[x] = dis;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String[] data;
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
        int n, m;
        int T = Integer.valueOf(in.readLine());
        while ((T--) != 0) {
            n = Integer.valueOf(in.readLine());
            init(n);
            String s;
            while (!(s = in.readLine()).equals("O")) {
                data = s.split(" ");
                char code = data[0].charAt(0);
                int I, J;
                I = Integer.valueOf(data[1]);
                if (code == 'E') {
                    find(I);
                    out.write(distance[I] + "\n");
                } else {
                    J = Integer.valueOf(data[2]);
                    union(I, J);
                }
            }
        }
        out.flush();
    }
}