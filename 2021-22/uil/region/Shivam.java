import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Shivam {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("shivam.dat"));
        int count = sc.nextInt();
        sc.nextLine();
        for (int i = 0; i < count; i++) {
            String s = sc.nextLine();
            int a = 0, b = 0, c = 0;
            s = s.substring(5);
            if(s.indexOf("x") == 0){
                a = 1;
            } else{
                a = Integer.parseInt(s.substring(0, s.indexOf("x")));
            }

            if(s.contains("+")||s.contains("-")){
                s = s.substring(s.indexOf("x^2") + 3);
                if (s.contains("x")) {
                    b = Integer.parseInt(s.substring(0, s.indexOf("x")));
                    s = s.substring(s.indexOf("x")+1);
                }
                if(s.contains("+")||s.contains("-")){
                    int index = 0;
                    index = Math.max(s.indexOf("+"),s.indexOf("-"));
                    s = s.substring(index);
                    c = Integer.parseInt(s);
                }
            }

            double x1 = 0,y1 = 0,x2 =0,y2 = 0;

            try{
                x1 = (-1 * b + Math.sqrt(b*b-4*a*c))/2/a;
                y1 = a * x1 * x1 + b * x1 + c;
                x2 = (-1 * b - Math.sqrt(b*b-4*a*c))/2/a;
                y2 = a * x2 * x2 + b * x2 + c;
            } catch (Error e){
                System.out.println("Imaginary");
            }

            if(x1 >= -0.005 && x1 <0){
                x1 = Math.abs(x1);
            }
            if(x2 >= -0.005 && x2 <0){
                x2 = Math.abs(x2);
            }
            if(y1 > -0.005 && y1 <0){
                y1 = Math.abs(y1);
            }
            if(y2 >= -0.005 && y2 <0){
                y2 = Math.abs(y2);
            }

            if((""+x1).equals("NaN")){
                System.out.println("Function "+(i+1)+": There are no real roots to the function.");
            }
             else if(x1 == x2){
                System.out.print("Function "+(i+1)+": There is one real root at ");
                System.out.printf("(%.2f,%.2f).",x1,y1);
                System.out.println();
            } else if(x1>x2){
                System.out.print("Function "+(i+1)+": There is two real roots at ");
                System.out.printf("(%.2f,%.2f) and (%f,%.2f).",x2,y2,x1,y1);
                System.out.println();
            } else{
                System.out.print("Function "+(i+1)+": There is two real roots at ");
                System.out.printf("(%.2f,%.2f) and (%.2f,%.2f).",x1,y1,x2,y2);
                System.out.println();
            }
        }
    }
}
