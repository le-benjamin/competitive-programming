import java.util.*;
import java.lang.*;
import java.text.*;
import java.io.*;


public class carracing {
	//private static PrintWriter l;
	public static int toInt(String s) {
		return Integer.parseInt(s);
	}
  public static void main(String[] args) throws IOException {
    Scanner sc = new Scanner(new File("input2.txt"));
		PrintWriter output = new PrintWriter("output.txt");
		//l = new PrintWriter("test.txt");
		int iter = sc.nextInt(); sc.nextLine();
		for(int i = 0;i<iter;i++) {
			int r = sc.nextInt();
			int cars = sc.nextInt();
			sc.nextLine();
			List<Car> list = new ArrayList<>();
			for(int j = 0;j<cars;j++) {
				String[] temp = sc.nextLine().split(" ");
				list.add(new Car(r,toInt(temp[1]),toInt(temp[2]),toInt(temp[3]),toInt(temp[4]),toInt(temp[0])));
			}
			// System.out.println(list);
			double lowtime = Integer.MAX_VALUE;
			int datid = -1;
			Car temp = null;
			for(Car x : list) {
				double time = x.sim();
				//l.print("Time" +time + "  id " +x.id+"\n") ;
				if(time < lowtime || (time == lowtime && x.id < datid)) {
					temp = x;
					lowtime = time;
					datid = x.id;
				}
			}
			//l.print("Case #"+(i+1)+": "+ temp.id+"\n\n\n");
			output.print("Case #"+(i+1)+": "+ temp.id+"\n");
			
		}
		sc.close();
		output.close();
		//l.close();
  }
}
class Car {
	public double pos, speed, turbo, cool, dur;
	public int id;
	public Car(int pos, int speed, int turbo, int cool, int dur, int id) {
		this.pos = pos;
		this.speed = speed;
		this.turbo = turbo;
		this.cool = cool;
		this.dur = dur;
		this.id = id;
	}
	public double sim() {
		boolean isBoosted = true;
		double time = 0;
		while(isBoosted && (pos-turbo*dur) > 0 || !isBoosted && (pos-speed*cool) > 0) {
			//System.out.print((420-pos) + " " + id+ " " + time+"\n");
			pos -= isBoosted ? turbo*dur : speed*cool;
			time += isBoosted ? dur : cool;
			isBoosted = !isBoosted;
		}
		//System.out.print(pos+ " "  +time+"\n");
		if(isBoosted) time += boosted();
		else time += notBoosted();
		return Math.ceil(time);
	}
	public double boosted() {
		return pos/turbo;
	}
	public double notBoosted() {
		return pos/speed;
	}
	@Override
	public String toString() {
		return pos + " "+ speed + " " + turbo + " " +cool + " " +dur + "  "+ id;
	}
}


/*
1
42 4
0 5 6 1 2
1 4 6 1 4
2 2 7 4 2
3 5 8 1 5


*/


/*
2
20 2
0 3 5 2 1
1 1 7 4 6
50 3
0 1 15 4 2
1 6 10 11 3
2 3 20 10 4
*/
/*
1
35 4
0 4 7 4 4
1 2 8 5 3
2 2 6 4 1
3 2 10 3 2
*/