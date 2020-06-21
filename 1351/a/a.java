import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        int t;
        t = cin.nextInt();
        while (t-- != 0) {
            int a, b;
            a = cin.nextInt();
            b = cin.nextInt();
            System.out.printf("%d\n", a + b);
        }
    }
}