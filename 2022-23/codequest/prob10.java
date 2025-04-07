import java.util.*;
public class prob10 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int iter= sc.nextInt(); sc.nextLine();
        for(int i = 0;i<iter;i++) {
            int n = sc.nextInt();
            double[] arr = new double[n];
            double[] arr1 = new double[n];
            double ans = 0;
            for(int j = 0;j<n;j++) arr[j] = sc.nextDouble();
            for(int j = 0;j<n;j++) ans += sc.nextDouble() - arr[j];
            System.out.printf("%.2f\n",ans/n);
        }
    }
}
