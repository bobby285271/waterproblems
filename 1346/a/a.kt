import java.io.BufferedInputStream
import java.util.*


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
            n = cin.nextInt()
            k = cin.nextInt()
            val temp = 1 + k + k * k + k * k * k
            //            System.out.printf("%d\n",k);
            var ans: Int
            ans = n / temp
            System.out.printf("%d %d %d %d\n", ans, ans * k, ans * k * k, ans * k * k * k)
        }
    }
