import java.io.*;
import java.util.*;

public class Perfection{
    static int[]sieve;
    public static void main(String[] args) throws IOException {
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter output = new BufferedWriter(
            new OutputStreamWriter(System.out));
        init();
        Scanner in = new Scanner(System.in);

        output.write("PERFECTION OUTPUT\n");
        int x;
        while( (x = in.nextInt()) != 0)
            output.write(print(x)+"\n");
        output.write("END OF OUTPUT\n");
        output.flush();
    }

    private static String print(int x) {
        char[] num = {' ', ' ', ' ', ' ', ' '};
        num[4] = '0';
        int i = 4;
        int aux = x;
        while(aux!=0){
            int digit = aux % 10;
            num[i] = (char) (digit+'0');
            aux/=10;
            i--;
        }
        if(x == sieve[x])
            return new String(num) + "  PERFECT";
        if(x < sieve[x])
            return new String(num) + "  ABUNDANT";
        return new String(num) + "  DEFICIENT";
    }

    private static void init() {
        int N = 60000;
        sieve = new int[N + 1];
        for(int i = 1 ; i <= N ; ++i){
            for(int j = i*2 ; j<= N ; j+=i ){
                sieve[j]+=i;
            }
        }
    }
}