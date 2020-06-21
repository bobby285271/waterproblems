import java.util.Scanner
fun main(args: Array<String>) {
    val read = Scanner(System.`in`)
	val n = read.nextInt()
	val w = read.nextInt()
	var minn = 0
	var maxn = w
	var s = 0
	for (i in 1..n) {
		s = s + read.nextInt()
		if (minn+s<0) minn = -s
		if (maxn+s>w) maxn = w-s
    }
    if(maxn>=minn)
        println(maxn-minn+1)
    else
	    println("0")
}
