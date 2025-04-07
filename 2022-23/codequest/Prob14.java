import java.util.*;
import java.io.*;
import java.time.LocalDateTime;

public class Prob14 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); 
        int iter = sc.nextInt(); sc.nextLine();
        for(int i = 0;i<iter;i++) {
            String[] times = sc.nextLine().split(" ");
            double offSet = 60 * Double.parseDouble(times[2]);
            String[] date = times[0].split("/");
            int year = Integer.parseInt(date[2]);
            int month = Integer.parseInt(date[0]);
            int day = Integer.parseInt(date[1]);
            String[] time = times[1].split(":");
            int hour = Integer.parseInt(time[0]);
            int minute = Integer.parseInt(time[1]);
            LocalDateTime d =  LocalDateTime.of(year,month,day,hour,minute);
            d = d.plusHours(-(int)(offSet/60));
            d = d.plusMinutes(-(int)offSet % 60);
            System.out.printf("%02d/%02d/%04d %02d:%02d\n",d.getMonthValue(),d.getDayOfMonth(),d.getYear(),d.getHour(),d.getMinute());
        }
    }
}
