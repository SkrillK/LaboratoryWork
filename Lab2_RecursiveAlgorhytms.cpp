#include <iostream>

using namespace std;

void chessBoardOut(int, int**);

bool nextMoveCheck(int x, int y, int n)
{
    return (x >= 0 && x < n && y >= 0 && y < n);
}

void knightsNextMove(int** chessBoard, int x, int y, int numOfMove, int n)
{
    chessBoard[x][y] = numOfMove;
    int moveX[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int moveY[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

    for (int i = 0; i < 8; i++)
    {
        int nextMoveX = x + moveX[i];
        int nextMoveY = y + moveY[i];

        if (nextMoveCheck(nextMoveX, nextMoveY, n) && chessBoard[nextMoveX][nextMoveY] == 0)
            knightsNextMove(chessBoard, nextMoveX, nextMoveY, numOfMove + 1, n);
    }
}

int** knightsMove(int n, int startPosX, int startPosY)
{
    int** chessBoard = new int* [n];

    for (int i = 0; i < n; i++)
    {
        chessBoard[i] = new int[n];
        for (int j = 0; j < n; j++)
            chessBoard[i][j] = 0;
    }
    knightsNextMove(chessBoard, startPosX, startPosY, 1, n);

    return chessBoard;
}

void knightsMoveStart()
{
    int n, startPosX, startPosY;

    cout << "\nSize of chess board: ";
    cin >> n;

    cout << "\nKnight's starting position:\nX = ";
    cin >> startPosX;
    cout << "Y = ";
    cin >> startPosY;

    int** chessBoard = knightsMove(n, startPosX - 1, startPosY - 1);

    chessBoardOut(n, chessBoard);
}

//---------------------------------------------------------------------

bool placingSafetyCheck(int row, int col, int **chessBoard, int N)
{
    for (int i = 0; i < col; i++)
        if (chessBoard[row][i])
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (chessBoard[i][j])
            return false;

    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (chessBoard[i][j])
            return false;

    return true;
}

bool queenPlacing(int col, int** chessBoard, int n)
{
    if (col == n)
        return true;
    for (int i = 0; i < n; i++)
    {
        if (placingSafetyCheck(i, col, chessBoard, n))
        {
            chessBoard[i][col] = 1;
            if (queenPlacing(col + 1, chessBoard, n))
                return true;
            chessBoard[i][col] = 0;
        }
    }

    return false;
}

void queenPlacingStart()
{
    int n;

    cout << "\nSize of chess board: ";
    cin >> n;

    int** chessBoard = new int* [n];
    for (int i = 0; i < n; i++)
        chessBoard[i] = new int[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            chessBoard[i][j] = 0;

    if (queenPlacing(0, chessBoard, n))
        chessBoardOut(n, chessBoard);
    else
        cout << "No solution.";
}

//---------------------------------------------------------------------

void moveDisk(int n, int from, int buff, int to, int& movesCount) {
    if (n == 1) {
        movesCount++;
        cout << "Disk:  " << n << "\tPeg: " << from << " -> " << to << endl;
        return;
    }
    moveDisk(n - 1, from, to, buff, movesCount);
    cout << "Disk:  " << n << "\tPeg: " << from << " -> " << to << endl;
    movesCount++;
    moveDisk(n - 1, buff, from, to, movesCount);
}

void hanoyTowersStart() {
    int n, movesCount = 0;

    cout << "\nAmount of disks: ";
    cin >> n;

    moveDisk(n, 1, 2, 3, movesCount);
    cout << "Count of moves: " << movesCount << "\n\n";
}

//---------------------------------------------------------------------

int maxEl(int* arr, int left, int right)
{
    int mid, leftMax, rightMax;
    if (left == right) 
        return arr[left];

    mid = (left + right) / 2;
    leftMax = maxEl(arr, left, mid);
    rightMax = maxEl(arr, mid + 1, right);

    return max(leftMax, rightMax);
}

void findMaxArrEl()
{
    int n;

    cout << "\nAmount of elements: ";
    cin >> n;

    int* array = new int[n];
    cout << "\nRandom array:\n";
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 100 - 50;
        cout << array[i] << " ";
    }
    cout << "\n";

    cout << "Max element: " << maxEl(array, 0, n - 1) << "\n\n";
}

//---------------------------------------------------------------------

void chessBoardOut(int n, int **chessBoard)
{
    cout << "\nChess board:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << chessBoard[i][j] << "\t";
        cout << "\n";
    }
    cout << "\n";
}

void algorhytmChoise()
{
    int n = 0, answer = 0;

    cout << "//----------------------------------------------------------\n\n";

    cout << "Choose the algorhytm.\n 1. Queen's placing\n 2. Knight's move\n";
    cout << " 3. Hanoy towers\n 4. Max element\nYour choise: ";
    cin >> answer;

    switch (answer) {
    default:
        return;
        break;
    case 1:
        queenPlacingStart();
        break;
    case 2:
        knightsMoveStart();
        break;
    case 3:
        hanoyTowersStart();
        break;
    case 4:
        findMaxArrEl();
        break;
    }

    algorhytmChoise();
}

int main()
{
    algorhytmChoise();
}