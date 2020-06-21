import java.io.BufferedInputStream
import java.util.*


    fun main(args: Array<String>) {
        val cin = Scanner(BufferedInputStream(System.`in`))
        var t: Int
        t = cin.nextInt()
        while (t-- != 0) {
            var n: Int
            n = cin.nextInt()
            if (n == 1) {
                System.out.printf("1\n")
                continue
            }
            if (n == 2 || n == 3) {
                System.out.printf("-1\n")
                continue
            }
            if (n % 2 == 0) {
                run {
                    var i = 1
                    while (i <= n - 4) {
                        System.out.printf("%d ", i)
                        i += 2
                    }
                }
                System.out.printf("%d %d ", n - 1, n - 3)
                var i = n
                while (i >= 1) {
                    System.out.printf("%d ", i)
                    i -= 2
                }
                System.out.printf("\n")
            } else {
                run {
                    var i = 1
                    while (i <= n) {
                        System.out.printf("%d ", i)
                        i += 2
                    }
                }
                System.out.printf("%d %d ", n - 3, n - 1)
                var i = n - 5
                while (i >= 1) {
                    System.out.printf("%d ", i)
                    i -= 2
                }
                System.out.printf("\n")
            }
        }
    }
