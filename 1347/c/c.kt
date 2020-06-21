import java.io.BufferedInputStream
import java.util.*



    fun main(args: Array<String>) {
        val cin = Scanner(BufferedInputStream(System.`in`))
        var t: Int
        t = cin.nextInt()
        while (t-- != 0) {
            var n: Int
            var a: IntArray
            a = IntArray(100)
            n = cin.nextInt()
            var cnt = 0
            var ans = 0
            while (n > 0) {
                if (n % 10 > 0) {
                    a[cnt++] = n % 10
                    ans++
                } else {
                    a[cnt++] = -1
                }
                n /= 10
            }
            var ten = 1
            System.out.printf("%d\n", ans)
            for (i in 0 until cnt) {
                if (a[i] != -1) {
                    System.out.printf("%d ", a[i] * ten)
                }
                ten *= 10
            }
            System.out.printf("\n")
        }
    }
