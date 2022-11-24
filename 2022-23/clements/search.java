import java.util.*;

public class search {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        ArrayList<Integer> arr = new ArrayList<>();
        for (String s : in.nextLine().split(" ")) arr.add(Integer.parseInt(s));
        Collections.sort(arr);
        
        
        int n = in.nextInt();
        
        System.out.println(arr.toString().replaceAll("[,\\[\\]]", ""));
        while (n-- > 0) {
            int k = in.nextInt();
            int res = Collections.binarySearch(arr, k);
            if (res < 0) System.out.printf("%d was not found and should be in position %d\n", k, -res-1);
            else System.out.printf("%d was found in position %d\n", k, res);
        }
        in.close();
    }
}