import java.io.*;

public class UVa_1197 {
    static int[] p;
    static boolean[] infected;
    static int n;

    static void init(int n) {
        p = new int[n];
        infected = new boolean[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
    }

    static int find(int x) {
        if (x != p[x])
            return p[x] = find(p[x]);
        return x;
    }

    static void union(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            p[y] = x;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String[] data;
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
        int n, m;

        while (!(data = in.readLine().split(" "))[0].equals("0")) {
            n = Integer.valueOf(data[0]);
            m = Integer.valueOf(data[1]);
            init(n);
            for (int g = 0; g < m; ++g) {
                data = in.readLine().split(" ");
                int k = Integer.valueOf(data[0]);
                for (int i = 2; i <= k; ++i) {
                    int x = Integer.valueOf(data[i - 1]);
                    int y = Integer.valueOf(data[i]);
                    union(x, y);
                }
            }
            infected[0] = true;
            infected[find(0)] = true;
            int res = 0;
            for (int i = 0; i < n; ++i) {
                if (infected[find(i)]) {
                    ++res;
                }
            }
            System.out.println(res);
        }
    }
}
