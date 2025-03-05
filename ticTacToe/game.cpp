#include <iostream>

const int brows = 5;
const int bcols = 5;

void printBoard(std::string board [brows][bcols]) {
    for(int i = 0; i < bcols; ++i) {
        for(int j = 0; j < brows; ++j) {
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int player1Turn() {
    int player1; //"X's"
    std::cout << "Player1's turn: ";
    std::cin >> player1;
    std::cout << "Player1 put X at position " << player1 << std::endl;
    return player1;
}

int player2Turn() {
    int player2; //"O's"
    std::cout << "Player2's turn: ";
    std::cin >> player2;
    std::cout << "Player2 put O at position " << player2 << std::endl;
    return player2;
}

bool isValidPlay(int position, std::string board [brows][bcols]) {
    std::string empty = "   ";
    switch (position) {
        case 1:
            if (board[0][0] == empty) {
                return true;
            } else {
                return false;
            }
            break;
        case 2:
            if (board[0][2] == empty) {
                return true;
            } else {
                return false;
            }
            break;
        case 3:
            if (board[0][4] == empty) {
                return true;
            } else {
                return false;
            }
            break;
        case 4:
            if (board[2][0] == empty) {
                return true;
            } else {
                return false;
            }
            break;
        case 5:
            if (board[2][2] == empty) {
                return true;
            } else {
                return false;
            }
            break;
        case 6:
            if (board[2][4] == empty) {
                return true;
            } else {
                return false;
            }
            break;
        case 7:
            if (board[4][0] == empty) {
                return true;
            } else {
                return false;
            }
            break;
        case 8:
            if (board[4][2] == empty) {
                return true;
            } else {
                return false;
            }
            break;
        case 9:
            if (board[4][4] == empty) {
                return true;
            } else {
                return false;
            }
            break;
        default:
            return false;
    }
}

void placeMark(std::string mark, int position, std::string board [brows][bcols]) {
    //if (not isValidPlay(position, board)) {
    //    return;
    //}
    while (not isValidPlay(position, board)) {
        std::cout << "Invalid Move. Try Again." << std::endl;
        if (mark == " X ") {
            position = player1Turn();
        } else {
            position = player2Turn();
        }
    }

    switch (position) {
        case 1:
            board[0][0] = mark;
            break;
        case 2:
            board[0][2] = mark;
            break;
        case 3:
            board[0][4] = mark;
            break;
        case 4:
            board[2][0] = mark;
            break;
        case 5:
            board[2][2] = mark;
            break;
        case 6:
            board[2][4] = mark;
            break;
        case 7:
            board[4][0] = mark;
            break;
        case 8:
            board[4][2] = mark;
            break;
        case 9:
            board[4][4] = mark;
            break;
    }
    printBoard(board);
}

void printWinner(std::string mark) {
    if (mark == " X ") {
        std::cout << "Player1 wins!" << std::endl;
    }
    if (mark == " O ") {
        std::cout << "Player2 wins!" << std::endl;
    }
}

bool isTicTacToe(std::string board [brows][bcols]) {
    /*
                 (0,0) | (0,2) | (0,4)
                 ------+-------+------
                 (2,0) | (2,2) | (2,4)
                 ------+-------+------
                 (4,0) | (4,2) | (4,4)
    */
    // horizontal matches
    bool horizontalR0 = board[0][0] == board[0][2] and board[0][0] == board[0][4];
    bool horizontalR2 = board[2][0] == board[2][2] and board[2][0] == board[2][4];
    bool horizontalR4 = board[4][0] == board[4][2] and board[4][0] == board[4][4];
    // vertical matches
    bool verticalR0 = board[0][0] == board[2][0] and board[0][0] == board[4][0];
    bool verticalR2 = board[0][2] == board[2][2] and board[0][2]== board[4][2];
    bool verticalR4 = board[0][4] == board[2][4] and board[0][4] == board[4][4];
    // diagonal matches
    bool diagonalLR = board[0][0] == board[2][2] and board[0][0] == board[4][4];
    bool diagonalRL = board[4][0] == board[2][2] and board[4][0] == board[0][4];

    if (horizontalR0 and board[0][0] != "   ") {
        printWinner(board[0][0]);
        return true;
    } else if (horizontalR2 and board[2][0] != "   ") {
        printWinner(board[2][0]);
        return true;
    } else if (horizontalR4 and board[4][0] != "   ") {
        printWinner(board[4][0]);
        return true;
    } else if (verticalR0 and board[0][0] != "   ") {
        printWinner(board[0][0]);
        return true;
    } else if (verticalR2 and board[0][2] != "   ") {
        printWinner(board[0][2]);
        return true;
    } else if (verticalR4 and board[0][4] != "   ") {
        printWinner(board[0][4]);
        return true;
    } else if (diagonalLR and board[0][0] != "   ") {
        printWinner(board[0][0]);
        return true;
    } else if (diagonalRL and board[4][0] != "   ") {
        printWinner(board[4][0]);
        return true;
    } else {
        return false;
    }
}

bool isCatGame(std::string board [brows][bcols]) {
    std::string empty = "   ";

    for(int i = 0; i < bcols; ++i) {
        for(int j = 0; j < brows; ++j) {
            if (board[i][j] == empty) {
                return false;
            }
        }
    }
    std::cout << "Cat Game! Tie!" << std::endl;
    return true;
}

int main() {
    /*
    User spots
     1 | 2 | 3
    ---+---+---
     4 | 5 | 6
    ---+---+---
     7 | 8 | 9

     (0,0) | (0,2) | (0,4)
     ------+-------+------
     (2,0) | (2,2) | (2,4)
     ------+-------+------
     (4,0) | (4,2) | (4,4)
    */
    std::string boardEntries [brows][bcols] = {
        {" 1 ", "|", " 2 ", "|", " 3 "},
        {"---", "+", "---", "+", "---"},
        {" 4 ", "|", " 5 ", "|", " 6 "},
        {"---", "+", "---", "+", "---"},
        {" 7 ", "|", " 8 ", "|", " 9 "},
    };
    std::cout << "User inputs:" << std::endl;
    printBoard(boardEntries);
    std::string board [brows][bcols] = {
        {"   ", "|", "   ", "|", "   "},
        {"---", "+", "---", "+", "---"},
        {"   ", "|", "   ", "|", "   "},
        {"---", "+", "---", "+", "---"},
        {"   ", "|", "   ", "|", "   "},
    };

    int t = 0;
    while (t < 6) {
        std::cout << "Turn number: " << t << std::endl;
        placeMark(" X ", player1Turn(), board);
        if (isTicTacToe(board)) {
            break;
        }
        if (isCatGame(board)) {
            break;
        }
        placeMark(" O ", player2Turn(), board);
        if (isTicTacToe(board)) {
            break;
        }
        t++;
    }

    return 0;
}
