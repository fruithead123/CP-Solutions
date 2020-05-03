import java.util.*;
import java.io.*;

public class ccc16s4 {
    public static void main(String[] args) throws IOException{
        BufferedReader kb = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(kb.readLine());
        String[] tokens = kb.readLine().split(" ");
        Integer[] balls = new Integer[tokens.length];
        
        for(int i=0; i<tokens.length; i++){
        	balls[i] = Integer.parseInt(tokens[i]);
        }
        int best = Collections.max(Arrays.asList(balls));
        System.out.println(best);
        
    }
}
