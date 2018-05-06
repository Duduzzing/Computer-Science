/**
 * Create a Magic Square which its each sums of rows, columns,
 * and two diagonals are the same.
 * 
 * The size has to be an Odd number greater than 2.
 *
 * Step by step procedure:
 * 
 * 1. Place the number(N) 1 in the top center.
 * 2. Move one row up and one column right to place the next number, 
 *    unless...
 *     
 * a) Row index is above the array (-1). Then place the number at its 
 *    bottom of the column.
 *      
 * b) Indices are out of the right top corner (-1, size). Then place
 *    the number directly below the place where N - 1 is.
 *      
 * c) Column index is out of the right side of the array (size). Then
 *    place the number at the first index(0) of its row.
 *      
 * d) The place is already occupied. Then palce the number directly
 *    below where N - 1 is.
 * 
 * Example of 5 * 5 Magic Square:
 * 
 * 17	24	1	8	15	
 * 23	5	7	14	16	
 * 4	6	13	20	22	
 * 10	12	19	21	3	
 * 11	18	25	2	9
 */
public class MagicSquare {
    
    // A rogue value for an empty spot in the square
    private static final int EMPTY = 0 ;
    
    public static void main(String args[]) {
        
        createMagicSquare(5);
        
    }
    
    /**
     * Create a Magic Square which its each sums of the rows, columns,
     * and two diagonals are the same.
     * 
     * @param size It has to be an Odd number greater than 2.
     */ 
    public static void createMagicSquare(int size){
        
        if(size < 3){
            System.out.println("Size must be bigger than 2");
            return;
        }
        
        if(size % 2 == 0){
            System.out.println("Size must be an Odd Number");
            return;
        }
        
        int[][] magicSquare = new int[size][size];
        
        // fill in the square with empty spots
        for(int y = 0; y < size; y++){
            for(int x = 0; x < size; x++){
                magicSquare[y][x] = EMPTY;
            }
        }
        
        int row = 0;
        int col = size / 2;
        int number = 1;
        
        // initially start at top center
        magicSquare[row][col] = number;
        number++;
        
        for( ; number <= size * size; number++){
            
            // try move one rigth and up
            row--;
            col++;
            
            // it is out of right side
            if(col >= size){
                
                // it is out of right top corner
                if(row < 0){
                    
                    row += 2;
                    col--;
                    
                } else { //it is just out of right side 
                  
                    col = 0;
                    
                }
                
            } else if(row < 0){
            // it is out of top side
                
                row = size - 1;
                
            } else if(magicSquare[row][col] != EMPTY){
            // the target index is already filled
            
                row += 2;
                col--;
                
            }
            
            magicSquare[row][col] = number;
            
        }
    
        System.out.println("Magic Sqaure with size " + size + " is...\n");
        
         for(int y = 0; y < size; y++){
            for(int x = 0; x < size; x++){
                System.out.print(magicSquare[y][x] + "\t");
            }
            System.out.println();
        }
    
    }
    
}
