#include <iostream>
#include <conio.h>
using namespace std;


bool gameover;
const int width = 20;
const int height = 17;
int row, col;           // head of snake
int len;                //length of snake
char dir;               // direction of movement
int fruit_row, fruit_col, score;
int path_row[100], path_col[100];       //snake coordinates


void setup() {
    gameover = false;
    dir = '.';
    len = 1;
    row = height / 2;
    col = width / 2;
    fruit_row = rand() % height;       //display fruit in a random place
    fruit_col = rand() % width;
    score = 0;
}

void draw() {
    system("cls");
    for (int i = 0; i < width + 2; i++)         // walls
        cout << "#";
    cout << endl ;

    for (int i = 0; i < height ; i++) {
        cout << "#";                            // walls
        for (int j = 0; j < width; j++) {
            if (i == fruit_row && j == fruit_col )
                cout << "%";                    // fruit
            else {
                bool print = false;
                for (int k = 0; k < len ; k++)
                    if (path_row[k] == i && path_col[k] == j) {
                        cout << "*";
                        print = true;
                    }

                if (!print)
                    cout << " ";
            }
        }
        cout << "#\n";
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << "\nScore : " << score;
    cout << "\nPress \"T\" Terminate";
}

void algorithm() {
    if (_kbhit ()) {
        switch (_getch ()) {
        case 'a':
            if (dir != 'd') dir = 'a'; // Left
            break;
        case 'd':
            if (dir != 'a') dir = 'd'; // Right
            break;
        case 'w':
            if (dir != 's') dir = 'w'; // Up
            break;
        case 's':
            if (dir != 'w') dir = 's'; // Down
            break;
        case 't':                       // terminate
            gameover = true; break;
        }
    }

    switch (dir) {
    case 'a':
        col--; break;     // Left
    case 'd':
        col++; break;     // Right
    case 'w':
        row--; break;     // Up
    case 's':
        row++; break;     // Down
    default:
        break;
    }

    row = (row + height) % height;
    col = (col + width) % width;

    for (int i = 0; i < len - 1 ; i++)
        if (row == path_row[i] && col == path_col[i])
            gameover = true;

    for (int i = len - 1; i > 0 ; i--) {
        path_row[i] = path_row[i - 1];
        path_col[i] = path_col[i - 1];
    }

    path_row[0] = row;      // 0 index represents head, len-1 is tail
    path_col[0] = col;

    if (row == fruit_row && col == fruit_col) {
        score += 10;
        fruit_row = rand() % height;
        fruit_col = rand() % width;
        len++;
    }
}

void exit() {
    system("cls");
    for (int i = 0; i < height / 2 ; i++)
        cout << "\n";
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl ;
    for (int j = 0; j < width / 2 - 4; j++)
        cout << " ";
    cout << "Game Over\n";
    for (int j = 0; j < width / 2 - 4; j++)
        cout << " ";
    cout << "Score: " << score << "\n";
    for (int i = 0; i < width + 2; i++)
        cout << "#";

    cout << "\n\nPress any key twice";
    _getch();
    _getch();
}


int main() {
    setup();
    while (!gameover) {
        draw();
        algorithm();
        for (int i = 0; i < 40000000; i++);     // delacol
    }
    exit();
    return 0;
}