/*--------------------------------------------
   Program 2: Knight Escape
   The objective of this game is to get the white knight to the empty
	square in the upper right-hand corner of the board.
	
	The knight can only move in the way that it does during a traditional
	chess game. This means that a knight can only move in a valid L-shape
	(two squares in a horizontal direction, then one in a vertical direction OR 
	two squares in a vertical direction, then one in a horizontal direction).
		       
   Course: CS 141, Spring 2022
   System: Macbook - Replit
   Author: Muhammad Muzzammil
   UIN: 661657007
    
 ---------------------------------------------*/


#include <iostream>		// for input and output
#include <cctype>		   // for toupper()
using namespace std;



// Characters of the pieces to be used on the board
// Note that these are global constants, so their values cannot be changed.
const string WhiteKnight = "\u2658";		// White knight character
const string BlackKnight = "\u265E";		// Black knight character
const string BlankPosition = " ";			// Blank position character


string p1, p2, p3, p4, p5, p6, p7, p8, p9, p10;
string p11, p12, p13, p14, p15, p16, p17, p18, p19, p20;
string p21, p22, p23, p24, p25;
int positionFrom;
int positionTo;
string extraSpace;
int moveNumber;
int score;


   
void displayBoard()
{
    cout <<"\n"
         <<                          "    Board   " <<                               "      Position \n"
         << " " <<  p1 << " " <<  p2 << " " <<  p3 << " " <<  p4 << " " <<  p5 << "     1  2  3  4  5 \n"
         << " " <<  p6 << " " <<  p7 << " " <<  p8 << " " <<  p9 << " " << p10 << "     6  7  8  9 10 \n"
         << " " << p11 << " " << p12 << " " << p13 << " " << p14 << " " << p15 << "    11 12 13 14 15 \n"
         << " " << p16 << " " << p17 << " " << p18 << " " << p19 << " " << p20 << "    16 17 18 19 20 \n"
         << " " << p21 << " " << p22 << " " << p23 << " " << p24 << " " << p25 << "    21 22 23 24 25 \n"
         << endl;
}

string getValue(int position) {
  switch(position) {
         case 1:
            return p1;
         case 2:
            return p2;
         case 3:
            return p3;
         case 4:
            return p4;
         case 5:
            return p5;
         case 6:
            return p6;
         case 7:
            return p7;
         case 8:
            return p8;
         case 9:
           return p9;
         case 10:
            return p10;
         case 11:
            return p11;
         case 12:
            return p12;
         case 13:
            return p13;
         case 14:
            return p14;
         case 15:
            return p15;
         case 16:
            return p16;
         case 17:
            return p17;
         case 18:
            return p18;
         case 19:
           return p19;
         case 20:
           return p20;
         case 21:
            return p21;
         case 22:
            return p22;
         case 23:
            return p23;
         case 24:
           return p24;
         case 25:
            return p25;
         default:
            return "";
      }
}

void setValue(int position, string value) {
  switch(position) {
         case 1:
            p1 = value;
            break;
         case 2:
            p2 = value;
            break;
         case 3:
            p3 = value;
            break;
         case 4:
            p4 = value;
            break;
         case 5:
            p5 = value;
            break;
         case 6:
            p6 = value;
            break;
         case 7:
            p7 = value;
            break;
         case 8:
            p8 = value;
            break;
         case 9:
            p9 = value;
            break;
         case 10:
            p10 = value;
            break;
         case 11:
            p11 = value;
            break;
         case 12:
            p12 = value;
            break;
         case 13:
            p13 = value;
            break;
         case 14:
            p14 = value;
            break;
         case 15:
            p15 = value;
            break;
         case 16:
            p16 = value;
            break;
         case 17:
            p17 = value;
            break;
         case 18:
            p18 = value;
            break;
         case 19:
            p19 = value;
            break;
         case 20:
            p20 = value;
            break;
         case 21:
            p21 = value;
            break;
         case 22:
            p22 = value;
            break;
         case 23:
            p23 = value;
            break;
         case 24:
           p24 = value;
            break;
         case 25:
            p25 = value;
            break;
      }
}

void displayWelcomeMessage()
{
    cout << "Program 2: Knight Escape \n"
         << "CS 141, Spring 2022, UIC \n"
         << " \n"
         << "The objective of this puzzle is to get the white knight "
		 << "up to the empty square in the top right corner of the board. "
		 << "Use standard knight moves from a traditional chess game, "
		 << "where a knight moves in an L-shape. \n"
		 << "This means that a knight can only move either "
		 << "1) two squares in a horizontal direction, then one in a vertical direction, OR "
		 << "2) two squares in a vertical direction, then one in a horizontal direction."
		 << " \n"
		 << "Your score decreases by 5 with each valid move, and by 10 with each invalid move. \n"
		 << "Try to complete the puzzle with the smallest number of valid moves!"
    	 << endl;
}

void initBoard() {
  for (int i = 1; i <= 25; i++) {
    if (i == 5) {
      setValue(i, BlankPosition);
    } else if (i == 21) {
      setValue(i, WhiteKnight);
    } else {
      setValue(i, BlackKnight);
    }

  }
}

void promptMenuOptions(int step) {
  cout << "\n" << step << ". "
             << "Enter one of the following: \n"
			 << "  - M to move a knight from one position to another, \n"
			 << "  - R to reset the board back to the beginning, or \n"
			 << "  - X to exit the game. \n"
			 << "Your choice -> ";
}

void showScore() {
   cout << "Current score: " << score << "\n";
}

void resetGame() {
  moveNumber = 1;
  score = 500;
  initBoard();
  displayBoard();
  showScore();
}

bool isOutOfBounds(int to, int from) {
  bool destinationInvalid = to < 1 || to > 25;
  bool sourceInvalid = from < 1 || from > 25; 
  if (sourceInvalid) {
    cout << "The source position should be a valid position on the board (1-25). Try again.\n";    
    return true;
  } else if (destinationInvalid) {
    cout << "The destination position should be a valid position on the board (1-25). Try again.\n";
    return true;
  } 
  return false;
}

bool isNotBlank(int position) {
  bool isTrue = getValue(position) != BlankPosition;
  if (isTrue) {
    cout << "The destination position should be empty. Try again.\n";
  }
  return isTrue;
}

bool doesNotHaveKnight(int position) {
  bool isTrue = getValue(position) == BlankPosition;
  if (isTrue) {
    cout << "The source position should have a knight. Try again.\n";
  }
  return isTrue;
}

bool isNotValidMove(int to, int from) {
  bool isInvalid = true;
  int fromCol = from % 5;
  int toCol = to % 5;
  if (fromCol == 0) {
     fromCol = 10;
  }
  if (toCol == 0) {
     toCol = 10;
  }
  if (from - 11 == to || from - 7 == to || from + 3 == to || from + 9 == to) {
     if (fromCol > toCol) {
        isInvalid = false;
     }
   } else if (from - 9 == to || from - 3 == to || from + 7 == to || from + 11 == to) {
     if (fromCol < toCol) {
        isInvalid = false;
     }
  }
  if (isInvalid) {
    cout << "Invalid move. Knights can only move in an L-shape. Try again.\n";
  }
  return isInvalid;
}


int main() {
  char menuOption;
  displayWelcomeMessage();
  resetGame();
  while (true){
    if (getValue(5) == WhiteKnight) {
      cout << "\n\nCongratulations, you did it!\n";
      break;
    }
    if (score <= 0) {
      cout << "You have run out of moves. Try to do better next time!\n";
      break;
    }
    promptMenuOptions(moveNumber);
    cin >> menuOption;
    menuOption = toupper(menuOption);
    if (menuOption == 'X') {
      cout << "Exiting...\n";
      break;
    }  
    if (menuOption == 'R') {
      cout << "*** Restarting\n";
      resetGame();
    } else {
      cout << "Enter the positions from and to, separated by a space (e.g. 14 5 to move the knight in position 14 to position 5): ";
      cin >> positionFrom;
      cin >> positionTo;
      cout << "You have chosen to move a knight from position " << positionFrom << " to position " << positionTo << ".\n";
      if (isOutOfBounds(positionTo, positionFrom) || doesNotHaveKnight(positionFrom) || isNotBlank(positionTo) || isNotValidMove(positionTo, positionFrom)) {
        score -= 10;
        showScore();
        continue;
      }
      score -= 5;
      moveNumber++;
      string temp = getValue(positionFrom);
      setValue(positionFrom, getValue(positionTo));
      setValue(positionTo, temp);
      displayBoard();
      showScore();
    }
  }
  cout << "Thank you for playing!\n";
}
