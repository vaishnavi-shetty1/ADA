#include <iostream>
#include <vector>
using namespace std;
void printBoard(vector<vector<int>> &board, int N) {
 for (int i = 0; i < N; ++i) {
 for (int j = 0; j < N; ++j) {
 cout << (board[i][j] ? "Q " : ". ");
 }
 cout << endl;
 }
 cout << endl;
}
bool isSafe(vector<vector<int>> &board, int row, int col, int N) {
 
 for (int i = 0; i < row; ++i)
 if (board[i][col])
 return false;
 
 for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
 if (board[i][j])
 return false;
 
 for (int i = row - 1, j = col + 1; i >= 0 && j < N; --i, ++j)
 if (board[i][j])
 return false;
 return true;
}
bool solveNQueens(vector<vector<int>> &board, int row, int N) {
 if (row == N) {
 printBoard(board, N);
 return true;
 
 }
bool res = false;
 for (int col = 0; col < N; ++col) {
 if (isSafe(board, row, col, N)) {
 board[row][col] = 1;
 res = solveNQueens(board, row + 1, N) || res;
 board[row][col] = 0;
 }
 }
 return res;
}
int main() {
 int N;
 cout << "Enter the value of N: ";
 cin >> N;
 vector<vector<int>> board(N, vector<int>(N, 0));
 if (!solveNQueens(board, 0, N))
 cout << "No solution exists for " << N << " queens." << endl;
 return 0;
}