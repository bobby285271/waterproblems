import java.util.Scanner
fun main(args: Array<String>) {
    val read = Scanner(System.`in`)
    var s1 = read.nextInt()
    var s2 = read.nextInt()
    var s3 = read.nextInt()
    var s4 = read.nextInt()
    var maxsum: Int
    maxsum =s1
    if(s2>maxsum)
        maxsum=s2
    if(s3>maxsum)
        maxsum=s3
    if(s4>maxsum)
        maxsum=s4
    if(maxsum==s1){
        print(s1-s2)
        print(" ")
        print(s1-s3)
        print(" ")
        print(s1-s4)
        print("\n")
    }
    else if(maxsum==s2){
        print(s2-s1)
        print(" ")
        print(s2-s3)
        print(" ")
        print(s2-s4)
        print("\n")
    }
    else if(maxsum==s3){
        print(s3-s1)
        print(" ")
        print(s3-s2)
        print(" ")
        print(s3-s4)
        print("\n")
    }
    else if(maxsum==s4){
        print(s4-s1)
        print(" ")
        print(s4-s2)
        print(" ")
        print(s4-s3)
        print("\n")
    }
}