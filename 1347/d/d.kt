import java.io.BufferedInputStream
import java.util.*


    fun main(args: Array<String>) {
        val cin = Scanner(BufferedInputStream(System.`in`))
        var t: Int
        t = cin.nextInt()
        val a: IntArray
        a = IntArray(1100)
        while (t-- != 0) {
            var n: Int
            n = cin.nextInt()
            for (i in 1..n) {
                a[i] = cin.nextInt()
            }
            var l = 1
            var r = n
            var p = 0
            var le = 0
            var ri = 0
            var ll = 0
            var rr = 0
            while (l <= r) {
                p++
                le = 0
                while (le <= ri && l <= r) {
                    le += a[l++]
                }
                ll += le
                if (l > r) {
                    break
                }
                p++
                ri = 0
                while (ri <= le && l <= r) {
                    ri += a[r--]
                }
                rr += ri
            }
            System.out.printf("%d %d %d\n", p, ll, rr)
        }
    }
