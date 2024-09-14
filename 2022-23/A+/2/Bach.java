import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;

public class Bach {
    public static class Event {
        public String name;
        public int time;
        
        public Event(String name, int time) {
            this.name = name;
            this.time = time;
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), q = in.nextInt();
        List<Event> events = new ArrayList<>();
        while (n-->0) {
            String name = in.next();
            String[] time = in.next().split(":");
            events.add(new Event(name, Integer.parseInt(time[0] + String.format("%02d", Integer.parseInt(time[1])))));
        }
        Collections.sort(events, Comparator.comparing((Event e) -> e.time));
        while (q-->0) {
            String[] time = in.next().split(":");
            int index = Math.abs(Collections.binarySearch(events, new Event("", Integer.parseInt( time[0] + String.format("%02d", Integer.parseInt(time[1])) )), Comparator.comparing((Event e) -> e.time)) + 1);
            for (int i = 0; i < index; i++) out.print((i == 0 ? "" : " ") + events.get(i).name);
            if (index == 0) out.print("Why Don't You Make Like a Tree and Get Outta Here?");
            out.println();
        }
    }
}