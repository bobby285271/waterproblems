import java.io.BufferedInputStream
import java.util.*

    fun main(args: Array<String>) {
        val cin = Scanner(BufferedInputStream(System.`in`))
        var t: Int
        t = cin.nextInt()
        while (t-- != 0) {
            var a: Int
            var b: Int
            var c: Int
            var d: Int
            var m: Int
            a = cin.nextInt()
            b = cin.nextInt()
            c = cin.nextInt()
            d = cin.nextInt()
            if (a > b) {
                m = a
                a = b
                b = m
            }
            if (c > d) {
                m = c
                c = d
                d = m
            }
            if (b == d && a + c == b) {
                System.out.printf("Yes\n")
            } else {
                System.out.printf("No\n")
            }
        }
    }
