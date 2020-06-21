import java.util.Scanner
fun main(args: Array<String>) {
    val read = Scanner(System.`in`)
    var ans = 1
    val a = arrayOfNulls<Int>(60)
    val b = arrayOfNulls<Int>(60)
    var n = read.nextInt()
    
    for(i in 0..n-1)
    {
        a[i] = read.nextInt()
    }
    b[n-1] = a[n-1]
    if(n==1)
    {
        print("1\n")
        print(b[n-1])
    }
    else
    {
        for(i in n-2 downTo 0)
        {
            var flag = 0
            for(j in 1..ans)
            {
                if(b[n-j] == a[i])
                {
                    flag = 1
                }
            }
            if(flag == 0)
            {
                ans = ans + 1
                b[n-ans] = a[i]
            }
        }
        print(ans)
        print("\n")
        for(i in 0..ans-1)
        {
            print(b[n-ans+i])
            print(" ")
        }
        print("\n")
    }
    
}