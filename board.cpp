#include <assert.h>
#include <string>

#include "board.hpp"

bool Board::has_next(bool taken) const {

  int position_to_change = -1;
  for (int i = 0; i < size; ++i) {
    if (board[i] <= 0) {
      position_to_change = i;
      break;
    }
  }

  if (position_to_change == -1)
    return false;

  const int value = board[position_to_change];

  if (!taken && size == -value + 1)
    return false;

  return true;
}

void Board::next(bool taken) {

  int position_to_change = -1;
  for (int i = 0; i < size; ++i) {
    if (board[i] <= 0) {
      position_to_change = i;
      break;
    }
  }

  assert(position_to_change != -1);

  const int value = board[position_to_change];

  assert(taken || size != value - 1);

  if (taken)
    board[position_to_change] = -value + 1;
  else
    board[position_to_change] -= 1;
}

std::ostream &operator<<(std::ostream &stream, const Board &board) {
  for (int line = 0; line < board.size; ++line) {
    stream << "|";
    for (int row = 0; row < board.size; ++row) {
      if (board.board[row] - 1 == line)
        stream << "d";
      else if (board.board[row] < 0 && line <= -board.board[row] - 1)
        stream << ".";
      else
        stream << " ";
      stream << "|";
    }
    stream << "\n";
  }
  return stream;
}

// Checks if a position is valid: two queens are (i) on the same row if they
// have the position and (ii) are on the same diagonal if the distance is the
// same as the row distance.
bool Board::is_valid() const {
  // just to remember the array gives us how the queen sare laied on the board
  // check for each queen if there is any other queen in a conflicting position.

  // Iterate over each position in the board array.
  for (int i = 0; i < size; i++) {
    // If the value is 0, continue to the next position.
    if (board[i] == 0) {
      continue;
    }

    for (int j = 0; j < i; j++) {
      // check if there is any queen in the first n positions.
      // Matching absolute differences between row indices and column indices
      // means that the queens on the same diagonal.
      if (board[j] == board[i] || (abs(board[j] - board[i]) == abs(j - i))) {
        //  If there is, return false as it violates the rules.
        return false;
      }
    }
  }
  return true;
  // The negative values act as placeholders and have no impact on the validity
  // of the board configuration.
}

bool Board::is_full() const {
  // Count the number of queens on the board
  int queenCount = 0;
  for (int i = 0; i < size; i++) {
    // If there is a queen in this column, increment queenCount
    if (board[i] != 0) {
      queenCount++;
    }
  }

  // Check if the number of queens is equal to the size of the board
  return (queenCount == size);
}
