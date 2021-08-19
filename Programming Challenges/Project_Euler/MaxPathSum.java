import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.lang.Math;

public class MaxPathSum {


  private static ArrayList<ArrayList<Integer>> pascalsTriangle(int n_rows) {
    ArrayList<ArrayList<Integer>> triangle = new ArrayList<>();
    triangle.add(new ArrayList<Integer>(){{add(1);}});
    triangle.add(new ArrayList<Integer>(){{add(1); add(1);}});

    for (int row = 2; row < n_rows; row++) {
      ArrayList<Integer> next_row = new ArrayList<>();
      next_row.add(1);
      for (int i = 1; i < triangle.get(row-1).size(); i++) {
        next_row.add(triangle.get(row-1).get(i-1) + triangle.get(row-1).get(i));
      }
      next_row.add(1);
      triangle.add(next_row);
    }
    return triangle;
  }

  private static ArrayList<ArrayList<Integer>> buildTriangle(int n_rows) {
    Scanner sc = new Scanner(System.in);
    ArrayList<ArrayList<Integer>> triangle = new ArrayList<>();

    for (int row = 1; row <= n_rows; row++) {
      ArrayList<Integer> row_arr = new ArrayList<>();
      for (int elem = 1; elem <= row; elem++) {
        row_arr.add(sc.nextInt());
      }
      triangle.add(row_arr);
    }
    return triangle;
  }


  private static int getOffset(int offset, int row, int i, ArrayList<ArrayList<Integer>> triangle, ArrayList<ArrayList<Integer>> p_triangle, ArrayList<Integer> sums) {
	  if (i > 1)  {
      if (i < (p_triangle.get(row).size()/2))   offset++;
      else if (i == triangle.get(row).size()-2) offset = sums.size() - p_triangle.get(row).get(i);
      else  offset = sums.size() - p_triangle.get(row).get(i) - (p_triangle.get(row).size() - i - 2);
    }

  	return offset;
  }

  private static int findLargestSum(ArrayList<ArrayList<Integer>> triangle, ArrayList<ArrayList<Integer>> p_triangle) {
    ArrayList<Integer> sums = new ArrayList<>();
    sums.add(triangle.get(0).get(0));

    // traverse the rows
    for (int row = 1, offset = 0; row < triangle.size(); row++, offset = 0) {
      ArrayList<Integer> new_sums = new ArrayList<>();

      // traverse each element in each row
      // add first element
      new_sums.add(sums.get(0) + triangle.get(row).get(0));

      //add middle elements
      for (int i = 1; i < triangle.get(row).size()-1; i++) {
        int n_times = p_triangle.get(row).get(i);
        // calculate offset from start of list
        offset = getOffset(offset, row, i, triangle, p_triangle, sums);

        for (int j = 0; j < n_times; j++) {
          new_sums.add(triangle.get(row).get(i) + sums.get(j+offset));
        }
      }

      // add last element
      new_sums.add(sums.get(sums.size()-1) + triangle.get(row).get(triangle.get(row).size()-1));
      // reset cumulative sums array
      sums = new_sums;
    }

    Collections.sort(sums);
    return sums.get(sums.size() - 1);
  }


  public static void main(String[] args) {
    int n_rows = Integer.parseInt(args[0]);

    // build pascalsTriangle
    ArrayList<ArrayList<Integer>> p_triangle = pascalsTriangle(n_rows);

    // build triangle from input
    ArrayList<ArrayList<Integer>> triangle = buildTriangle(n_rows);

    // traverse triangle finding largest sum
    int largest_sum = findLargestSum(triangle, p_triangle);

    // display results
    System.out.println(largest_sum);
  }
}
