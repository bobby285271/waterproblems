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
            var k1: Int
            var k2: Int
            var sss: String
            var temp: String
            n = cin.nextInt()
            k1 = cin.nextInt()
            k2 = cin.nextInt()
            sss = cin.nextLine()
            sss = cin.nextLine()
            //            System.out.printf("%s\n",sss);
            var a: CharArray
            a = CharArray(10000)
            a = sss.toCharArray()
            //            System.out.printf("%c\n",a[0]);
            var ans = 0
            var cnt = 0
            for (i in 0 until n) {
                if (a[i] == '0') {
                    ans += if (cnt == 1) {
                        k1
                    } else if (cnt % 2 == 0) {
                        cnt / 2 * if (k1 * 2 > k2) k2 else k1 * 2
                    } else {
                        if (k1 * 2 > k2) cnt / 2 * k2 + if (k1 > k2) k2 else k1 else cnt * k1
                    }
                    cnt = 0
                } else {
                    cnt++
                }
                if (i == n - 1) {
                    ans += if (cnt % 2 == 0) {
                        cnt / 2 * if (k1 * 2 > k2) k2 else k1 * 2
                    } else {
                        if (k1 * 2 > k2) cnt / 2 * k2 + if (k1 > k2) k2 else k1 else cnt * k1
                    }
                    cnt = 0
                }
            }
            System.out.printf("%d\n", ans)
        }
    }
