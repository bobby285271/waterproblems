import java.io.BufferedInputStream
import java.util.*


    fun upperBound(nums: LongArray, l: Int, r: Int, target: Long): Int {
        var l = l
        var r = r
        while (l < r) {
            val m = (l + r) / 2
            if (nums[m] <= target) l = m + 1 else r = m
        }
        return l
    }
    
    fun main(args: Array<String>) {
        val cin = Scanner(BufferedInputStream(System.`in`))
        var t: Int
        t = cin.nextInt()
        while (t-- != 0) {
//            int n;
//            int a[];
//            a = new int[100];
//            n=cin.nextInt();
//            int cnt=0;
//            int ans=0;
//            while(n>0){
//                if(n%10>0){
//                    a[cnt++]=n%10;
//                    ans++;
//                }
//                else{
//                    a[cnt++]=-1;
//                }
//                n/=10;
//            }
//            int ten=1;
//            System.out.printf("%d\n",ans);
//            for (int i=0;i<cnt;i++){
//                if(a[i]!=-1){
//                    System.out.printf("%d ",a[i]*ten);
//                }
//                ten*=10;
//            }
//            System.out.printf("\n");
            var n: Int
            var k: Int
            var x: Int
            var y: Int
            n = cin.nextInt()
            k = cin.nextInt()
            x = cin.nextInt()
            y = cin.nextInt()
            var a: LongArray
            var sum: LongArray
            a = LongArray(n)
            sum = LongArray(n)
            for (i in 0 until n) {
                a[i] = cin.nextLong()
            }
            var ans: Long
            ans = n * x.toLong()
            Arrays.sort(a)
            sum[0] = a[0]
            for (i in 1 until n) {
                sum[i] = sum[i - 1] + a[i]
            }
            val loc1 = upperBound(a, 0, n, k.toLong()).toLong()
            ans = (n - loc1) * x
            val loc = upperBound(sum, 0, n, n * k.toLong()).toLong()
            val cnt = n - loc
            //            System.out.printf("cnt: %d\n",cnt);
            val proans = cnt * x + y
            println(if (ans > proans) proans else ans)
        }
    }
