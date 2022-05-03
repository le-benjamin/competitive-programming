import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class Ivan {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("ivan.dat"));
        int x = sc.nextInt();
        sc.nextLine();
        char[] key = new char[40];
        char[] input = sc.nextLine().toCharArray();
        for (int i = 0; i < 40; i++) {
            key[i] = input[i];
        }
        int count = 1;
        while(x>0){
            int score =0;
            int attempted = 0;
            int correct = 0;
            input = sc.nextLine().toCharArray();

            for (int i = 0; i < 40; i++) {
                if(input[i]==key[i]){
                    score += 6;
                    attempted++;
                    correct++;
                } else if(input[i] == '_'){

                } else{
                    score += -2;
                    attempted++;
                }

            }
            System.out.print("Exam #"+count+": "+score+" ");
            if(attempted == 0){
                System.out.print("0.0");
            } else{
                System.out.printf("%.1f",(double)correct/(double)attempted*100.0);
            }

            System.out.println();
            count++;
            x--;
        }
    }
}
