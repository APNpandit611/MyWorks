from pprint import pprint
def sudo_solver(puzzle_board):
    # gives a place to make a guess on the empty spot in the board
    row, col = find_empty_space(puzzle_board)

    # if no empty places is left then we got our solution
    # this is true if our find_empty_space function return None, None.
    if row is None:
        return True

    # if there's a place to put our guess:
    for guess in range(1, 10):
        # to check whether the guess is vaild or not for this position
        if isValid(puzzle_board, row, col, guess):
            # if the guess is valid guess, it puts the value right at the spot
            puzzle_board[row][col] = guess
            # we call our sudo_solver function recursively, until we find the solution
            if sudo_solver(puzzle_board):
                return True

        # if not a valid choice then it reset the position to O and again backtrack the board
        puzzle_board[row][col] = 0
    # if none of the number we took worked, then the solution doesn't exist
    return False


def find_empty_space(puzzle_board):
    # finds out the next row and col which is empty for 0
    # after finding the black empty spaces, returns row and col

    for r in range(9):
        for c in range(9):
            if puzzle_board[r][c] == 0:
                return r, c

    return None, None   # if found no spaces, it returns None, None


def isValid(puzzle_board, row, col, guess):
    # figures out whether the guess is valid in that row/col
    # to be a valid guess, the number should not repeat itself in row, col and 3x3 sub grid
    # for rows:
    row_value = puzzle_board[row]
    if guess in row_value:
        return False    # if the guess number is repeated in the row, then it's not valid

    # for cols:
    col_value = [puzzle_board[i][col] for i in range(9)]
    if guess in col_value:
        return False

    # for 3x3 sub grid:
    row_sub_grid = (row // 3) * 3
    col_sub_grid = (col // 3) * 3

    for r in range(row_sub_grid, row_sub_grid + 3):
        for c in range(col_sub_grid, col_sub_grid + 3):
            if puzzle_board[r][c] == guess:
                return False

    return True

if __name__ == '__main__':
    board = [
    [0, 0, 0, 9, 0, 1, 0, 0, 0],
    [0, 4, 0, 2, 8, 3, 0, 9, 0],
    [8, 0, 0, 7, 0, 6, 3, 0, 0],
    [6, 0, 9, 0, 0, 0, 1, 0, 5],
    [0, 3, 0, 0, 0, 0, 0, 7, 0],
    [1, 0, 8, 0, 0, 0, 9, 0, 6],
    [0, 0, 0, 5, 0, 4, 0, 0, 0],
    [0, 5, 0, 0, 9, 0, 0, 6, 0],
    [2, 0, 0, 6, 0, 8, 4, 0, 0]]

    print(sudo_solver(board))
    pprint(board)


