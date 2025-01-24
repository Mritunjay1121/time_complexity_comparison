import java.util.*;

public class TimeComplexities {

    public static void main(String[] args) {
        System.out.println("STARTING FOR JAVA ................");
        oOfN();
        oOfNSquared();
        oOfNLogN();
        oOfLogN();
        aToN();
        nFactorial();
        System.out.println("ENDING FOR JAVA ................");
    }

    public static void oOfN() {
        long start = System.nanoTime();
        int count = (int) 10000000;
        List<Integer> numbers = new ArrayList<>();
        for (int v = 1; v <= count; v++) {
            numbers.add(v);
        }
        long end = System.nanoTime();
        System.out.println("Time taken to count " + count + " is: " + (end - start) / 1e9 + " seconds");
    }

    public static void oOfNSquared() {
        int count = 10000;
        List<Integer> numbers = new ArrayList<>();
        for (int v = 1; v <= count; v++) {
            numbers.add(v);
        }
        long start = System.nanoTime();
        for (int i = 0; i < count; i++) {
            for (int j = 0; j < count; j++) {
                int multiply = numbers.get(i) * numbers.get(j);
            }
        }
        long end = System.nanoTime();
        System.out.println("Time taken for an n_squared operation on " + count + " is: " + (end - start) / 1e9 + " seconds");
    }

    public static void oOfNLogN() {
        int count_nlogn = (int) 10000000;
        List<Integer> numbers_nlogn = new ArrayList<>();
        for (int v = 1; v <= count_nlogn; v++) {
            numbers_nlogn.add(v);
        }
        long start = System.nanoTime();
        Collections.sort(numbers_nlogn);
        
        // Counting occurrences
        Map<Integer, Integer> result = new HashMap<>();
        int current_count = 1;
        for (int i = 1; i < count_nlogn; i++) {
            if (numbers_nlogn.get(i).equals(numbers_nlogn.get(i - 1))) {
                current_count++;
            } else {
                result.put(numbers_nlogn.get(i - 1), current_count);
                current_count = 1;
            }
        }
        
        long end = System.nanoTime();
        System.out.println("Time taken for an n_logn operation on " + count_nlogn + " is: " + (end - start) / 1e9 + " seconds");
    }

    public static void oOfLogN() {
        int count_logn = (int) 10000000;
        List<Integer> numbers_logn = new ArrayList<>();
        Random rand = new Random();
        for (int i = 0; i < count_logn; i++) {
            numbers_logn.add(rand.nextInt(10000000) + 1);
        }
        Collections.sort(numbers_logn);
        int search_for = numbers_logn.get(rand.nextInt(count_logn));

        long start = System.nanoTime();
        int low = 0, high = count_logn - 1;
        boolean found = false;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (numbers_logn.get(mid) == search_for) {
                found = true;
                break;
            }
            if (numbers_logn.get(mid) < search_for) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        long end = System.nanoTime();
        System.out.println("Time taken for a logn operation on " + count_logn + " is: " + (end - start) / 1e9 + " seconds");
    }

    public static void aToN() {
        long a = 2;  
        long n = 100000;  

        long start = System.nanoTime();

        long result = 1;
        for (long i = 0; i < n; i++) {
            result *= a;
        }

        long end = System.nanoTime();

        System.out.println("Time taken for a a^n operation on a = " + a + " and n= " + n + "is : " + (end - start) / 1e9 + " seconds");
    }

    public static void nFactorial() {
        int n = 20; 
        long start = System.nanoTime();
        long result = 1;
        for (int i = 1; i <= n; i++) {
            result *= i;
        }
        long end = System.nanoTime();
        System.out.println("Time taken for a n-factorial operation on n= " + n + "is : " + (end - start) / 1e9 + " seconds");

    }




}