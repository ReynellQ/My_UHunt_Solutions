import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class UVa_793 {
    static int[] p;
    static int n;

    static void init(int n) {
        p = new int[n + 1];
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
        int t = Integer.valueOf(in.readLine());
        in.readLine();
        while ((t--) != 0) {
            int success = 0, unsuccess = 0;
            n = Integer.valueOf(in.readLine());
            init(n);
            String s;
            while (in.ready() && !(s = in.readLine()).equals("")) {
                data = s.split(" ");
                char c;
                int x, y;
                c = data[0].charAt(0);
                x = Integer.valueOf(data[1]);
                y = Integer.valueOf(data[2]);
                if (c == 'c') {
                    union(x, y);
                } else {
                    if (find(x) == find(y)) {
                        ++success;
                    } else {
                        ++unsuccess;
                    }
                }
            }
            System.out.println(success + "," + unsuccess);
            out.write(success + "," + unsuccess + "\n");
            if (t != 0) {
                System.out.println();
            }
        }
    }
}