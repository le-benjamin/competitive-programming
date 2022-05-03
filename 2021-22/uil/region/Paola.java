import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Paola {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("paola.dat"));
        int count = sc.nextInt();
        sc.nextLine();
        for (int a = 0; a < count; a++){
            String s = sc.nextLine();
            char letter = s.split(" ")[0].toCharArray()[0];
            int layers = Integer.parseInt(s.split(" ")[1]);
            for (int i = 0; i < layers; i++){
                for(int j = 0; j < layers-i-1; j++){
                    System.out.print(" ");
                }
                for (int j = 0; j < i+1; j++){
                    System.out.print(letter);
                    if(letter=='Z'){
                        letter = 'A';
                    } else{
                        letter++;
                    }
                }
                System.out.println();
            }
        }
    }
}
