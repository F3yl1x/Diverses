class SudokuSolver:
    def __init__(self, grid):
        self.grid = grid

    def numbers_from_row(self, row):

        zahlen_verfuegbar = {1,2,3,4,5,6,7,8,9}

        for i in range(0,9):
            zahlen_verfuegbar.discard(self.grid[row][i])

        return zahlen_verfuegbar

    def numbers_from_column(self, column):

        zahlen_verfuegbar = {1,2,3,4,5,6,7,8,9}

        for i in range(0,9):
            zahlen_verfuegbar.discard(self.grid[i][column])
        return zahlen_verfuegbar

    def numbers_from_box(self, row, column):
        
        box: int
        zahlen_verfuegbar = {1,2,3,4,5,6,7,8,9}

        if(row < 3):
            if(column < 3):
                grid = 1
            if(column >= 3 and column < 6):
                grid = 2
            if(column >=6):
                grid = 3
        
        if(row >= 3 and row < 6):
            if(column < 3):
                grid = 4
            if(column >= 3 and column < 6):
                grid = 5
            if(column >=6):
                grid = 6

        if(row >= 6):
            if(column < 3):
                grid = 7
            if(column >= 3 and column < 6):
                grid = 8
            if(column >=6):
                grid = 9

        if(grid == 1):
            for i in range(0,3):
                for z in range(0,3):
                    zahlen_verfuegbar.discard(self.grid[i][z])
        
        if(grid == 2):
            for i in range(0,3):
                for z in range(3,6):
                    zahlen_verfuegbar.discard(self.grid[i][z])

        if(grid == 3):
            for i in range(0,3):
                for z in range(6,9):
                    zahlen_verfuegbar.discard(self.grid[i][z])

        if(grid == 4):
            for i in range(3,6):
                for z in range(0,3):
                    zahlen_verfuegbar.discard(self.grid[i][z])
        
        if(grid == 5):
            for i in range(3,6):
                for z in range(3,6):
                    zahlen_verfuegbar.discard(self.grid[i][z])

        if(grid == 6):
            for i in range(3,6):
                for z in range(6,9):
                    zahlen_verfuegbar.discard(self.grid[i][z])
        
        if(grid == 7):
            for i in range(6,9):
                for z in range(0,3):
                    zahlen_verfuegbar.discard(self.grid[i][z])

        if(grid == 8):
            for i in range(6,9):
                for z in range(3,6):
                    zahlen_verfuegbar.discard(self.grid[i][z])
        
        if(grid == 9):
            for i in range(6,9):
                for z in range(6,9):
                    zahlen_verfuegbar.discard(self.grid[i][z])

        return zahlen_verfuegbar

    def possible_values(self, row, column):
        verfuegbar_row = SudokuSolver.numbers_from_row(self,row)
        verfuegbar_column = SudokuSolver.numbers_from_column(self,column)
        verfuegbar_box = SudokuSolver.numbers_from_box(self,row,column)
        verfuegbar = {1,2,3,4,5,6,7,8,9}
        zahlen_verfuegbar = {1,2,3,4,5,6,7,8,9}

        zahlen_verfuegbar = zahlen_verfuegbar - (verfuegbar - verfuegbar_row) - (verfuegbar - verfuegbar_column) - (verfuegbar - verfuegbar_box)

        return zahlen_verfuegbar

    def solve(self):

        SudokuSolver.solver(self)
        return self.grid
    
    def solver(self):
        find = SudokuSolver.find_empty(self)
        if not find:
            return True
        else:
            row, col = find

        for i in range(1,10):
            if SudokuSolver.valid(self, i, (row, col)):
                self.grid[row][col] = i

                if SudokuSolver.solver(self):
                    return True

                self.grid[row][col] = 0

        return False


    def valid(self, num, pos):
        for i in range(len(self.grid[0])):
            if self.grid[pos[0]][i] == num and pos[1] != i:
                return False

        for i in range(len(self.grid)):
            if self.grid[i][pos[1]] == num and pos[0] != i:
                return False

        box_x = pos[1] // 3
        box_y = pos[0] // 3

        for i in range(box_y*3, box_y*3 + 3):
            for j in range(box_x * 3, box_x*3 + 3):
                if self.grid[i][j] == num and (i,j) != pos:
                    return False

        return True

    def find_empty(self):
        for i in range(0,9):
            for j in range(0,9):
                if (self.grid[i][j] == 0):
                    return (i, j)
        return None

#---------------------------------------

Test1 = SudokuSolver([
[0, 0, 0, 2, 6, 0, 7, 0, 1],
[6, 8, 0, 0, 7, 0, 0, 9, 0],
[1, 9, 0, 0, 0, 4, 5, 0, 0],
[8, 2, 0, 1, 0, 0, 0, 4, 0],
[0, 0, 4, 6, 0, 2, 9, 0, 0],
[0, 5, 0, 0, 0, 3, 0, 2, 8],
[0, 0, 9, 3, 0, 0, 0, 7, 4],
[0, 4, 0, 0, 5, 0, 0, 3, 6],
[7, 0, 3, 0, 1, 8, 0, 0, 0]
])

Loesung = SudokuSolver.solve(Test1)

print("Lösung:")
for i in range(len(Loesung)):
    print(Loesung[i])

Test2 = SudokuSolver([
[0, 2, 0, 6, 0, 8, 0, 0, 0],
[5, 8, 0, 0, 0, 9, 7, 0, 0],
[0, 0, 0, 0, 4, 0, 0, 0, 0],
[3, 7, 0, 0, 0, 0, 5, 0, 0],
[6, 0, 0, 0, 0, 0, 0, 0, 4],
[0, 0, 8, 0, 0, 0, 0, 1, 3],
[0, 0, 0, 0, 2, 0, 0, 0, 0],
[0, 0, 9, 8, 0, 0, 0, 3, 6],
[0, 0, 0, 3, 0, 6, 0, 9, 0]
])

Loesung = SudokuSolver.solve(Test2)

print("Lösung:")
for i in range(len(Loesung)):
    print(Loesung[i])