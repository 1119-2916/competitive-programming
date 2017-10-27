import java.util.*;

class Main {

    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        // int n;  scanf("%d",&n);
        for (int loop = 0; loop < n; loop++) {
            String train = scan.next();
            //char input[LENGTH];
            //scanf("%s",input);
            HashSet<String> set = new HashSet<String>();
            //クラスHashSetのオブジェクト生成
            int len = train.length();
            //文字列trainの長さを取得してlenに代入
            for (int i = 1; i < len; i++) {
                String front = train.substring(0,i);
                //文字列trainの0番目からi-1番目をコピー
                String rear = train.substring(i);
                //文字列trainのi番目から終わりまでコピー
                
                String r_front = 
                    new StringBuffer(front).reverse().toString();
                String r_rear = 
                    new StringBuffer(rear).reverse().toString();
                //反転して保存


                //HashSet(名前はset)に挿入
                set.add(front.concat(rear));
                set.add(front.concat(r_rear));
                set.add(r_front.concat(rear));
                set.add(r_front.concat(r_rear));
                set.add(rear.concat(front));
                set.add(rear.concat(r_front));
                set.add(r_rear.concat(front));
                set.add(r_rear.concat(r_front));
            }
            System.out.println(set.size());
            //printf("%d\n",(setの要素数));
        }
    }
}





