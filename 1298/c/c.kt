import java.util.Scanner
fun main(args: Array<String>) {
    //val read = Scanner(System.`in`)
    var ans = 0
    //var n = read.nextInt()
    var n = Integer.valueOf(readLine()) 
    val f = readLine()
    if(n<3)
    {
        print("0\n")
    }
    else
    {
        for(i in 0..n-3){

            if(f?.get(i).toString() =="x" && f?.get(i+1).toString() =="x" && f?.get(i+2).toString() =="x")
            {
                ans = ans + 1
            }
        }
        print(ans)
    }
}