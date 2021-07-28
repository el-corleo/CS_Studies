import java.util.*;

// Java ArrayList
// https://www.hackerrank.com/challenges/java-arraylist/problem
public class Solution {

    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);

        // extract the relevant data by populating an ArrayList of ArrayLists
        ArrayList<ArrayList<Integer>> arr = new ArrayList<ArrayList<Integer>>();
        arr.add(0, null);
        int numLines = scan.nextInt();
        for (int i = 1; i <= numLines; i++)
        {
            int numElements = scan.nextInt();
            ArrayList<Integer> tempArr = new ArrayList<Integer>();
            tempArr.add(0, null);
            for (int j = 1; j <= numElements; j++)
                tempArr.add(j, scan.nextInt());
            arr.add(i, tempArr);
        }
        
        int numQueries = scan.nextInt();
        
        for (int i = 0; i < numQueries; i++)
        {
            int ind_start = scan.nextInt();
            int ind_end = scan.nextInt();
            try
            {
                System.out.println(arr.get(ind_start).get(ind_end));
            } catch (Exception e)
            {
                System.out.println("ERROR!");
            }
        }
    }
}