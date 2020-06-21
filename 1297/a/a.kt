    import java.util.Scanner
    fun main(args: Array<String>) {
        val read = Scanner(System.`in`)
        var n = read.nextInt()
        
        for(i in 0..n-1)
        {
            var b = read.nextInt()
            var ans=-1
            for(i in 0..999){
                var tempa = b-ans
                var tempb = b-i
                if(tempa<0)tempa*=-1
                if(tempb<0)tempb*=-1

                if(tempa>=tempb){
                    ans=i
                }
            }
            for(i in 0..999){
                var tempa = b-ans
                var tempb = b-i*1000
                if(tempa<0)tempa*=-1
                if(tempb<0)tempb*=-1

                if(tempa>=tempb){
                    ans=i*1000
                }
            }
            for(i in 0..2100){
                var tempa = b-ans
                var tempb = b-i*1000000
                if(tempa<0)tempa*=-1
                if(tempb<0)tempb*=-1

                if(tempa>=tempb){
                    ans=i*1000000
                }
            }
            if(ans<1000){
                print(ans)
                print("\n")
            }
            else{
                ans/=1000
                if(ans<1000){
                    print(ans)
                    print("K\n")
                }
                else{
                    ans/=1000
                    print(ans)
                    print("M\n")
                }
                }
            }
           
            
        
    }