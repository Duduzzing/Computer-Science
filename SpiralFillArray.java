public class MyClass {
    
    public static void main(String args[]) {

        generate(9);

    }

    /**
     * Output an 2D array filled spirally, starting from 0, 0
     */
    public static void generate(int N) {

        int[][] array = new int[N][N];
        int top = 0, bottom = N - 1, left = 0, right = N - 1;
        int Z = 1;
        int target = N*N;

        while (Z <= target) {

            for (int a = left; a <= right; a++) { // top row
                array[top][a] = Z;
                Z++;
            }
            top++;

            for (int a = top; a <= bottom; a++) { // right col
                array[a][right] = Z;
                Z++;
            }
            right--;

            for (int a = right; a >= left; a--) { // btm row
                array[bottom][a] = Z;
                Z++;
            }
            bottom--;

            for (int a = bottom; a >= top; a--) { // left col
                array[a][left] = Z;
                Z++;
            }
            left++;
        }
        out(array);
    }

    /**
     * Print out 2D array
     */
    public static void out(int[][] array) {

        for (int y = 0; y < array.length; y++) {
            for (int x = 0; x < array[0].length; x++) {

                System.out.print(array[y][x]);

                if (x != array[0].length - 1)
                    System.out.print(",\t");

            }
            System.out.println();
        }
    }
}
