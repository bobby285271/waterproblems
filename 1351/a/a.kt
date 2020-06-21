import java.io.BufferedInputStream
import java.util.*

    fun main(args: Array<String>) {
        val cin = Scanner(BufferedInputStream(System.`in`))
        var t: Int
        t = cin.nextInt()
        while (t-- != 0) {
            var a: Int
            var b: Int
            a = cin.nextInt()
            b = cin.nextInt()
            System.out.printf("%d\n", a + b)
        }
    }