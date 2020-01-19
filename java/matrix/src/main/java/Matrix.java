
class Matrix {
    int[][] matrix;
    int numRows;
    int numCols;
    Matrix(String matrixAsString) {

        String[] lines = matrixAsString.split("\n");
        this.numRows = lines.length;
        this.numCols = lines[0].split(" ").length;
        this.matrix = new int[this.numRows][this.numCols];

        for(int i = 0; i < lines.length; i++) {

            String[] wordsInLine = lines[i].split(" ");
            
            for(int j = 0; j < wordsInLine.length; j++) {
                this.matrix[i][j] = Integer.parseInt(wordsInLine[j]);
            }
        }
        printMatrix();
    }

    int[] getRow(int rowNumber) {
        return this.matrix[rowNumber-1];
    }

    int[] getColumn(int columnNumber) {
        int[] column = new int[this.numRows];
        for(int i = 0; i < this.numRows; i++) {
            column[i] = this.matrix[i][columnNumber-1];
        }
        return column;
    }

    void printMatrix() {
        for (int i = 0; i < numRows; i++) {
            for(int j = 0; j < numCols; j++) {
                System.out.print(this.matrix[i][j] + " ");
            }
            System.out.print("\n");
        }
    }
}
