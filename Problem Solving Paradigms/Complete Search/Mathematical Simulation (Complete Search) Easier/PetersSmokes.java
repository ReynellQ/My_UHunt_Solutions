import java.io.*;
import java.util.*;

public class PetersSmokes {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter output = new BufferedWriter(
            new OutputStreamWriter(System.out));
            String r;
        while(in.ready()){
            String[]data = in.readLine().split(" ");
            int n, k;
            n = Integer.valueOf(data[0]);
            k = Integer.valueOf(data[1]);
            int res = n;
            int cigarrettes = n;
            int colletes = 0;
            int newC = -1;
            while(newC != 0){
                
                colletes += cigarrettes % k;
                newC = cigarrettes/k + (colletes / k);
                res+= newC;
                colletes = colletes% k;
                cigarrettes = newC;
            }
            output.write(res+"\n");
        }
        output.flush();
    }
}