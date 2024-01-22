# include "iGraphics.h"

/*
What is left;
	1. starting page;
	2. check system;
	3. castling king and rook;
*/

char turn = 'W';
int board[10][10];
int temp_board[10][10];
int moveable[64][2];
int moveable_index = 0;
int eliminate[10][2];
int eliminate_index = 0;
int temp_eliminate[10][2];
int temp_eliminate_index = 0;
int count = 0;
int selectedX,selectedY;
bool selected = false;

int white_x, white_y, black_x, black_y;

char path[30][50] = {
	"Pic\\\\Pieces\\\\white-king.bmp",
	"Pic\\\\Pieces\\\\black-king.bmp",
	"Pic\\\\Red_marked\\\\white-king.bmp",
	"Pic\\\\Red_marked\\\\black-king.bmp",
	"Pic\\\\Pieces\\\\white-queen.bmp",
	"Pic\\\\Pieces\\\\black-queen.bmp",
	"Pic\\\\Red_marked\\\\white-queen.bmp",
	"Pic\\\\Red_marked\\\\black-queen.bmp",
	"Pic\\\\Pieces\\\\white-bishop.bmp",
	"Pic\\\\Pieces\\\\black-bishop.bmp",
	"Pic\\\\Red_marked\\\\white-bishop.bmp",
	"Pic\\\\Red_marked\\\\black-bishop.bmp",
	"Pic\\\\Pieces\\\\white-knight.bmp",
	"Pic\\\\Pieces\\\\black-knight.bmp",
	"Pic\\\\Red_marked\\\\white-knight.bmp",
	"Pic\\\\Red_marked\\\\black-knight.bmp",
	"Pic\\\\Pieces\\\\white-rook.bmp",
	"Pic\\\\Pieces\\\\black-rook.bmp",
	"Pic\\\\Red_marked\\\\white-rook.bmp",
	"Pic\\\\Red_marked\\\\black-rook.bmp",
	"Pic\\\\Pieces\\\\white-pawn.bmp",
	"Pic\\\\Pieces\\\\black-pawn.bmp",
	"Pic\\\\Red_marked\\\\white-pawn.bmp",
	"Pic\\\\Red_marked\\\\black-pawn.bmp"
};

struct Piece
{
	char name;
	int type;
	int dirsize;
	int dirX[8];
	int dirY[8]; 
	int moveCount;
	Piece(){}
	Piece(char s,int x, int y,int* arr,int* arr2,int moveC){
		name = s;
		type = x;
		dirsize = y;
		for(int i=0;i<y;i++) dirX[i] = arr[i];
		for(int i=0;i<y;i++) dirY[i] = arr2[i];
		moveCount = moveC;
	};
};

Piece types[7];

void init(){
	int arr[8] = {1,-1,-1,1,1,-1,0,0};
	int arr2[8] = {1,-1,1,-1,0,0,1,-1};
	types[1] = Piece('K',1,8,arr,arr2,1);
	types[2] = Piece('Q',2,8,arr,arr2,8);
	int arr3[4] = {1,-1,-1,1};
	int arr4[4] = {1,-1,1,-1};
	types[3] = Piece('B',3,4,arr3,arr4,8);
	int arr5[8] = {1,-1,1,-1,2,2,-2,-2};
	int arr6[8] = {2,2,-2,-2,1,-1,1,-1};
	types[4] = Piece('G',4,8,arr5,arr6,1);
	int arr7[4] = {0,0,1,-1};
	int arr8[4] = {1,-1,0,0};
	types[5] = Piece('R',5,4,arr7,arr8,8);
	int arr9[1] = {0};
	int arr10[1] = {1};
	types[6] = Piece('P',6,1,arr9,arr10,2);

	board[1][1] = board[1][8] = 5;
	board[1][2] = board[1][7] = 4;
	board[1][3] = board[1][6] = 3;
	board[1][4] = 2;
	board[1][5] = 1;
	for(int i = 1;i<=8;i++){
		board[2][i] = 6;
		board[0][i] = board[9][i] = 99;
	}
	for(int i=3;i<=6;i++){
		for(int j=1;j<=8;j++){
			board[i][j] = 0;
		}
	}

	board[8][1] = board[8][8] = -5;
	board[8][2] = board[8][7] = -4;
	board[8][3] = board[8][6] = -3;
	board[8][4] = -2;
	board[8][5] = -1;
	for(int i = 1;i<=8;i++){
		board[7][i] = -6;
		board[i][0] = board[i][9] = 99;
	}
	board[0][0] = board[9][9] = board[0][9] = board[9][0] = 99;
	white_x = 5, white_y = 1, black_x = 5, black_y = 8;
}

void copy_board(){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			temp_board[i][j] = board[i][j];
		}
	}
}

void temp_eliminating(int x, int y){
	temp_eliminate_index = 0;
	int p = (board[y][x]>0)?board[y][x]:-1*board[y][x];
	for(int i=0;i<types[p].dirsize;i++){
		int movex = x;
		int movey = y;
		printf("%d %d\n",movex,movey);
		for(int j=0;j<types[p].moveCount;j++){
			movex = movex + types[p].dirX[i];
			if(board[y][x] == -6) movey = movey - types[p].dirY[i];
			else movey = movey + types[p].dirY[i];

			if(movex <= 0 || movey <= 0 || movex >= 10 || movey >= 10) continue;
			else if(board[movey][movex] == 99) break;

			if((board[y][x] == 6 || board[y][x] == -6) && j == 0){
				if((movex+1)<9 && board[movey][movex+1]*board[y][x] < 0 ){
					temp_eliminate[eliminate_index][0] = movex+1;
					temp_eliminate[eliminate_index][1] = movey;
					printf("eli - %d %d\n", movex, movey);
					temp_eliminate_index++;
				}
				if((movex-1)>0 && board[movey][movex-1]*board[y][x] < 0){
					temp_eliminate[eliminate_index][0] = movex-1;
					temp_eliminate[eliminate_index][1] = movey;
					printf("eli - %d %d\n", movex, movey);
					temp_eliminate_index++;
				}
			}

			if(board[movey][movex]*board[y][x] < 0 && board[y][x] != 6 && board[y][x] != -6) {
				temp_eliminate[eliminate_index][0] = movex;
				temp_eliminate[eliminate_index][1] = movey;
				printf("eli - %d %d\n", movex, movey);
				temp_eliminate_index++;
				break;
			}
			else break;
			if(board[y][x] == 6 && y != 2)break;
			if(board[y][x] == -6 && y != 7)break;
		}
	}
}

bool checksystem(int x, int y){
	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++){
			if(temp_board[j][i]*temp_board[y][x] < 0){
				temp_eliminate_index = 0;
				temp_eliminating(j,i);
				for(int k=0;k<temp_eliminate_index;k++){
					if(temp_eliminate[k][0] == x && temp_eliminate[k][1] == y) return true;
				}
			}
		}
	}
	return false;
}

void GetCoordinates(int x, int y){
	moveable_index = 0;
	eliminate_index = 0;
	int p = (board[y][x]>0)?board[y][x]:-1*board[y][x];
	//printf("%d\n", p);
	for(int i=0;i<types[p].dirsize;i++){
		int movex = x;
		int movey = y;
		printf("%d %d\n",movex,movey);
		for(int j=0;j<types[p].moveCount;j++){
			movex = movex + types[p].dirX[i];
			if(board[y][x] == -6) movey = movey - types[p].dirY[i];
			else movey = movey + types[p].dirY[i];
			
			if(movex < 0 || movey < 0 || movex > 10 || movey > 10) continue;
			else if(board[movey][movex] == 99) break;
			if((board[y][x] == 6 || board[y][x] == -6) && j == 0){
				if((movex+1)<9 && board[movey][movex+1]*board[y][x] < 0 ){
					eliminate[eliminate_index][0] = movex+1;
					eliminate[eliminate_index][1] = movey;
					printf("eli - %d %d\n", movex, movey);
					eliminate_index++;

					temp_board[movey][movex+1] = temp_board[y][x];
					temp_board[y][x] = 0;
					bool check = (turn == 'W')?checksystem(white_x, white_y):checksystem(black_x, black_y);
					if(check) eliminate_index--;
				}
				if((movex-1)>0 && board[movey][movex-1]*board[y][x] < 0){
					eliminate[eliminate_index][0] = movex-1;
					eliminate[eliminate_index][1] = movey;
					printf("eli - %d %d\n", movex, movey);
					eliminate_index++;

					temp_board[movey][movex-1] = temp_board[y][x];
					temp_board[y][x] = 0;
					bool check = (turn == 'W')?checksystem(white_x, white_y):checksystem(black_x, black_y);
					if(check) eliminate_index--;
					copy_board();
				}
			}

			
			if(board[movey][movex] == 0){
				moveable[moveable_index][0] = movex;
				moveable[moveable_index][1] = movey;
				moveable_index++;

				temp_board[movey][movex] = temp_board[y][x];
				temp_board[y][x] = 0;
				bool check = (turn == 'W')?checksystem(white_x, white_y):checksystem(black_x, black_y);
				if(check) moveable_index--;
				copy_board();
			}
			
			else if(board[movey][movex]*board[y][x] < 0 && board[y][x] != 6 && board[y][x] != -6) {
				eliminate[eliminate_index][0] = movex;
				eliminate[eliminate_index][1] = movey;
				printf("eli - %d %d\n", movex, movey);
				eliminate_index++;

				temp_board[movey][movex] = temp_board[y][x];
				temp_board[y][x] = 0;
				bool check = (turn == 'W')?checksystem(white_x, white_y):checksystem(black_x, black_y);
				if(check) eliminate_index--;
				copy_board();
				break;
			}
			else break;
			if(board[y][x] == 6 && y != 2)break;
			if(board[y][x] == -6 && y != 7)break;
		}
	}
}

void iDraw() {
	iClear();
	iShowBMP(0, 0, "Pic\\Chess.bmp");
	int x = (52+4), y = (52+4);
	int i,j;
	for(i=1;i<=8;i++){
		for(j=1;j<=8;j++){
			int p = board[i][j];
			//printf("%d\n", p);
			if(p>0) {
				iShowBMP2(x,y,path[((p-1)*4)+0],255);
			}
			else if(p<0) {
				iShowBMP2(x,y,path[(((p*-1)-1)*4)+1],255);
			}
			x += (75);
		}
		x = (52+4);
		y += (75);
	}
	for(int i=0;i<moveable_index;i++){
		int cirx = (moveable[i][0]*75) +(52-75) + 4;
		int ciry = (moveable[i][1]*75) +(52-75) + 4;
		iShowBMP2(cirx,ciry,"Pic\\Pieces\\circle.bmp",255);
	}
	for(i=0;i<eliminate_index;i++){
		int cirx = (eliminate[i][0]*75) +(52-75) + 4;
		int ciry = (eliminate[i][1]*75) +(52-75) + 4;
		int p = board[eliminate[i][1]][eliminate[i][0]];
		if(p>0) {
			iShowBMP2(cirx,ciry,path[((p-1)*4)+2],0);
		}
		else if(p<0) {
			iShowBMP2(cirx,ciry,path[(((p*-1)-1)*4)+3],0);
		}
	}
		
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {
	printf("x = %d, y= %d\n",mx,my);
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my) {
	int movex = (mx>=52 && mx<=652)?((mx-52)/75)+1:0;
	int movey = (my>=52 && my<=652)?((my-52)/75)+1:0;
	printf("%d %d\n", movex, movey);
	count++;
	if (button == GLUT_LEFT_BUTTON && movex<9 && movex>0 && movey<9 && movey>0) {
		
		if(((turn == 'W' && board[movey][movex]>0) || (turn == 'B' && board[movey][movex]<0)) && count%2 == 0){
			selected = true;
			selectedX = movex;
			selectedY = movey;
			GetCoordinates(movex,movey);
			if(moveable_index == 0 && eliminate_index == 0) selected =  false;
		}
		else if(selected && count%2==0){
			selected = false;
			bool eli = false;
			for(int i=0;i<eliminate_index;i++){
				if(movex == eliminate[i][0] && movey == eliminate[i][1]){
					eli = true;
					break;
				}
			}
			for(int i=0;i<moveable_index;i++){
				if(movex == moveable[i][0] && movey == moveable[i][1]){
					eli = true;
					break;
				}
			}
			if(eli){
				board[movey][movex] = board[selectedY][selectedX];
				board[selectedY][selectedX] = 0;
				turn = (turn == 'W')?'B':'W';
			}
			if(board[movey][movex] == 1) {
				white_x = movex;
				white_y = movey;
			}
			else if(board[movey][movex] == -1){
				black_x = movex;
				black_y = movey;
			}
			moveable_index = 0;
			eliminate_index = 0;
			copy_board();
		}
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {
	if (key == ' ') {
		init();
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}
	//place your codes for other keys here
}

int main() {
	init();
	copy_board();
	iInitialize(700,700,"Chess Game");
	return 0;
}
