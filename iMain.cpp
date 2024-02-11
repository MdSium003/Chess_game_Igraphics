# include "iGraphics.h"
#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

char turn = 'W';
int page = 0;
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
bool castling[4] = {true, true, true, true};
bool musicOn = true;
char player1[50] = "(Optional)";
int player1_index = 10;
char player2[50] = "(Optional)";
int player2_index = 10;
int name_selected = 0;

int white_x, white_y, black_x, black_y;
int temp_white_x, temp_white_y, temp_black_x, temp_black_y;

char Music[10][70]= {
	"music\\\\Ltheme.wav",
	"music\\\\cold.wav"
};

char Opening[50][50] = {
	"Pic\\\\OpeningPage\\\\ (1).bmp",
	"Pic\\\\OpeningPage\\\\ (2).bmp",
	"Pic\\\\OpeningPage\\\\ (3).bmp",
	"Pic\\\\OpeningPage\\\\ (4).bmp",
	"Pic\\\\OpeningPage\\\\ (5).bmp",
	"Pic\\\\OpeningPage\\\\ (6).bmp",
	"Pic\\\\OpeningPage\\\\ (7).bmp",
	"Pic\\\\OpeningPage\\\\ (8).bmp",
	"Pic\\\\OpeningPage\\\\ (9).bmp",
	"Pic\\\\OpeningPage\\\\ (10).bmp",
	"Pic\\\\OpeningPage\\\\ (11).bmp",
	"Pic\\\\OpeningPage\\\\ (12).bmp",
	"Pic\\\\OpeningPage\\\\ (13).bmp",
	"Pic\\\\OpeningPage\\\\ (14).bmp",
	"Pic\\\\OpeningPage\\\\ (15).bmp",
	"Pic\\\\OpeningPage\\\\ (16).bmp",
	"Pic\\\\OpeningPage\\\\ (17).bmp",
	"Pic\\\\OpeningPage\\\\ (18).bmp",
	"Pic\\\\OpeningPage\\\\ (19).bmp",
	"Pic\\\\OpeningPage\\\\ (20).bmp",
	"Pic\\\\OpeningPage\\\\ (21).bmp",
	"Pic\\\\OpeningPage\\\\ (22).bmp",
	"Pic\\\\OpeningPage\\\\ (23).bmp",
	"Pic\\\\OpeningPage\\\\ (24).bmp",
	"Pic\\\\OpeningPage\\\\ (25).bmp",
	"Pic\\\\OpeningPage\\\\ (26).bmp",
	"Pic\\\\OpeningPage\\\\ (27).bmp",
	"Pic\\\\OpeningPage\\\\ (28).bmp",
	"Pic\\\\OpeningPage\\\\ (29).bmp",
	"Pic\\\\OpeningPage\\\\ (30).bmp",
	"Pic\\\\OpeningPage\\\\ (31).bmp",
	"Pic\\\\OpeningPage\\\\ (32).bmp",
	"Pic\\\\OpeningPage\\\\ (33).bmp",
	"Pic\\\\OpeningPage\\\\ (34).bmp",
	"Pic\\\\OpeningPage\\\\ (35).bmp",
	"Pic\\\\OpeningPage\\\\ (36).bmp",
	"Pic\\\\OpeningPage\\\\ (37).bmp",
	"Pic\\\\OpeningPage\\\\ (38).bmp",
	"Pic\\\\OpeningPage\\\\ (39).bmp",
	"Pic\\\\OpeningPage\\\\ (40).bmp",
	"Pic\\\\OpeningPage\\\\ (41).bmp",
	"Pic\\\\OpeningPage\\\\ (42).bmp",
	"Pic\\\\OpeningPage\\\\ (43).bmp",
	"Pic\\\\OpeningPage\\\\ (44).bmp",
	"Pic\\\\OpeningPage\\\\ (45).bmp",
	"Pic\\\\OpeningPage\\\\ (46).bmp"
};
int openingpageindex = 0;
int openingpageindex_loop = 1;

char Starting[70][70] = {
	"Pic\\\\StartingPage\\\\ (1).bmp",
	"Pic\\\\StartingPage\\\\ (2).bmp",
	"Pic\\\\StartingPage\\\\ (3).bmp",
	"Pic\\\\StartingPage\\\\ (4).bmp",
	"Pic\\\\StartingPage\\\\ (5).bmp",
	"Pic\\\\StartingPage\\\\ (6).bmp",
	"Pic\\\\StartingPage\\\\ (7).bmp",
	"Pic\\\\StartingPage\\\\ (8).bmp",
	"Pic\\\\StartingPage\\\\ (9).bmp",
	"Pic\\\\StartingPage\\\\ (10).bmp",
	"Pic\\\\StartingPage\\\\ (11).bmp",
	"Pic\\\\StartingPage\\\\ (12).bmp",
	"Pic\\\\StartingPage\\\\ (13).bmp",
	"Pic\\\\StartingPage\\\\ (14).bmp",
	"Pic\\\\StartingPage\\\\ (15).bmp",
	"Pic\\\\StartingPage\\\\ (16).bmp",
	"Pic\\\\StartingPage\\\\ (17).bmp",
	"Pic\\\\StartingPage\\\\ (18).bmp",
	"Pic\\\\StartingPage\\\\ (19).bmp",
	"Pic\\\\StartingPage\\\\ (20).bmp",
	"Pic\\\\StartingPage\\\\ (21).bmp",
	"Pic\\\\StartingPage\\\\ (22).bmp",
	"Pic\\\\StartingPage\\\\ (23).bmp",
	"Pic\\\\StartingPage\\\\ (24).bmp",
	"Pic\\\\StartingPage\\\\ (25).bmp",
	"Pic\\\\StartingPage\\\\ (26).bmp",
	"Pic\\\\StartingPage\\\\ (27).bmp",
	"Pic\\\\StartingPage\\\\ (28).bmp",
	"Pic\\\\StartingPage\\\\ (29).bmp",
	"Pic\\\\StartingPage\\\\ (30).bmp",
	"Pic\\\\StartingPage\\\\ (31).bmp",
	"Pic\\\\StartingPage\\\\ (32).bmp",
	"Pic\\\\StartingPage\\\\ (33).bmp",
	"Pic\\\\StartingPage\\\\ (34).bmp",
	"Pic\\\\StartingPage\\\\ (35).bmp",
	"Pic\\\\StartingPage\\\\ (36).bmp",
	"Pic\\\\StartingPage\\\\ (37).bmp",
	"Pic\\\\StartingPage\\\\ (38).bmp",
	"Pic\\\\StartingPage\\\\ (39).bmp",
	"Pic\\\\StartingPage\\\\ (40).bmp",
	"Pic\\\\StartingPage\\\\ (41).bmp",
	"Pic\\\\StartingPage\\\\ (42).bmp",
	"Pic\\\\StartingPage\\\\ (43).bmp",
	"Pic\\\\StartingPage\\\\ (44).bmp",
	"Pic\\\\StartingPage\\\\ (45).bmp",
	"Pic\\\\StartingPage\\\\ (46).bmp",
	"Pic\\\\StartingPage\\\\ (47).bmp",
	"Pic\\\\StartingPage\\\\ (48).bmp",
	"Pic\\\\StartingPage\\\\ (49).bmp",
	"Pic\\\\StartingPage\\\\ (50).bmp",
	"Pic\\\\StartingPage\\\\ (51).bmp",
	"Pic\\\\StartingPage\\\\ (52).bmp",
	"Pic\\\\StartingPage\\\\ (53).bmp",
	"Pic\\\\StartingPage\\\\ (54).bmp",
	"Pic\\\\StartingPage\\\\ (55).bmp",
	"Pic\\\\StartingPage\\\\ (56).bmp",
	"Pic\\\\StartingPage\\\\ (57).bmp",
	"Pic\\\\StartingPage\\\\ (58).bmp",
	"Pic\\\\StartingPage\\\\ (59).bmp",
	"Pic\\\\StartingPage\\\\ (60).bmp",
	"Pic\\\\StartingPage\\\\ (61).bmp",
	"Pic\\\\StartingPage\\\\ (62).bmp",
	"Pic\\\\StartingPage\\\\ (63).bmp",
	"Pic\\\\StartingPage\\\\ (64).bmp",
	"Pic\\\\StartingPage\\\\ (65).bmp",
	"Pic\\\\StartingPage\\\\ (66).bmp"
};
int startingpageindex = 0;
int startingpageindex_loop = 1;

char Nameinput[70][70] = {
	"Pic\\\\NameInput\\\\ (1).bmp",
	"Pic\\\\NameInput\\\\ (2).bmp",
	"Pic\\\\NameInput\\\\ (3).bmp",
	"Pic\\\\NameInput\\\\ (4).bmp",
	"Pic\\\\NameInput\\\\ (5).bmp",
	"Pic\\\\NameInput\\\\ (6).bmp",
	"Pic\\\\NameInput\\\\ (7).bmp",
	"Pic\\\\NameInput\\\\ (8).bmp",
	"Pic\\\\NameInput\\\\ (9).bmp",
	"Pic\\\\NameInput\\\\ (10).bmp",
	"Pic\\\\NameInput\\\\ (11).bmp",
	"Pic\\\\NameInput\\\\ (12).bmp",
	"Pic\\\\NameInput\\\\ (13).bmp",
	"Pic\\\\NameInput\\\\ (14).bmp",
	"Pic\\\\NameInput\\\\ (15).bmp",
	"Pic\\\\NameInput\\\\ (16).bmp",
	"Pic\\\\NameInput\\\\ (17).bmp",
	"Pic\\\\NameInput\\\\ (18).bmp",
	"Pic\\\\NameInput\\\\ (19).bmp",
	"Pic\\\\NameInput\\\\ (20).bmp",
	"Pic\\\\NameInput\\\\ (21).bmp",
	"Pic\\\\NameInput\\\\ (22).bmp",
	"Pic\\\\NameInput\\\\ (23).bmp",
	"Pic\\\\NameInput\\\\ (24).bmp",
	"Pic\\\\NameInput\\\\ (25).bmp",
	"Pic\\\\NameInput\\\\ (26).bmp",
	"Pic\\\\NameInput\\\\ (27).bmp",
	"Pic\\\\NameInput\\\\ (28).bmp",
	"Pic\\\\NameInput\\\\ (29).bmp",
	"Pic\\\\NameInput\\\\ (30).bmp",
	"Pic\\\\NameInput\\\\ (31).bmp",
	"Pic\\\\NameInput\\\\ (32).bmp",
	"Pic\\\\NameInput\\\\ (33).bmp",
	"Pic\\\\NameInput\\\\ (34).bmp",
	"Pic\\\\NameInput\\\\ (35).bmp",
	"Pic\\\\NameInput\\\\ (36).bmp",
	"Pic\\\\NameInput\\\\ (37).bmp",
	"Pic\\\\NameInput\\\\ (38).bmp",
	"Pic\\\\NameInput\\\\ (39).bmp",
	"Pic\\\\NameInput\\\\ (40).bmp",
	"Pic\\\\NameInput\\\\ (41).bmp",
	"Pic\\\\NameInput\\\\ (42).bmp",
	"Pic\\\\NameInput\\\\ (43).bmp",
	"Pic\\\\NameInput\\\\ (44).bmp",
	"Pic\\\\NameInput\\\\ (45).bmp",
	"Pic\\\\NameInput\\\\ (46).bmp",
	"Pic\\\\NameInput\\\\ (47).bmp",
	"Pic\\\\NameInput\\\\ (48).bmp",
	"Pic\\\\NameInput\\\\ (49).bmp",
	"Pic\\\\NameInput\\\\ (50).bmp",
	"Pic\\\\NameInput\\\\ (51).bmp",
	"Pic\\\\NameInput\\\\ (52).bmp",
	"Pic\\\\NameInput\\\\ (53).bmp",
	"Pic\\\\NameInput\\\\ (54).bmp",
	"Pic\\\\NameInput\\\\ (55).bmp",
	"Pic\\\\NameInput\\\\ (56).bmp",
	"Pic\\\\NameInput\\\\ (57).bmp",
	"Pic\\\\NameInput\\\\ (58).bmp",
	"Pic\\\\NameInput\\\\ (59).bmp",
	"Pic\\\\NameInput\\\\ (60).bmp",
	"Pic\\\\NameInput\\\\ (61).bmp",
	"Pic\\\\NameInput\\\\ (62).bmp",
	"Pic\\\\NameInput\\\\ (63).bmp",
	"Pic\\\\NameInput\\\\ (64).bmp",
	"Pic\\\\NameInput\\\\ (65).bmp",
};
int nameinputindex = 0;
int nameinputindex_loop = 1;

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

char BoardPic[30][50] = {
	"Pic\\\\ChessBoard\\\\Chess1.bmp",
	"Pic\\\\ChessBoard\\\\Chess2.bmp",
	"Pic\\\\ChessBoard\\\\Chess3.bmp",
	"Pic\\\\ChessBoard\\\\Chess4.bmp",
	"Pic\\\\ChessBoard\\\\Chess5.bmp",
	"Pic\\\\ChessBoard\\\\Chess6.bmp",
	"Pic\\\\ChessBoard\\\\Chess7.bmp"
};
int Board_index = 0;

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
	turn = 'W';
	castling[0] = castling[1] = castling[2] = castling[3] = true; 
	moveable_index = 0;
	eliminate_index = 0;
	temp_eliminate_index = 0;
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
		board[2][i] = 6;
		board[0][i] = board[9][i] = 99;
		board[7][i] = -6;
		board[i][0] = board[i][9] = 99;
	}
	board[0][0] = board[9][9] = board[0][9] = board[9][0] = 99;
	white_x = 5, white_y = 1, black_x = 5, black_y = 8;
}

void GetCoordinates(int x, int y);

void copy_board(){
	temp_white_x = white_x, temp_white_y = white_y, temp_black_x = black_x, temp_black_y = black_y;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			temp_board[i][j] = board[i][j];
		}
	}
}

bool win_lose(){
	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++){
			if(turn == 'B' && board[j][i] <0){
				GetCoordinates(i,j);
				if(moveable_index != 0 || eliminate_index != 0) {
					moveable_index = 0;
					eliminate_index = 0;
					return false;
				}
			} 
			else if(turn == 'W' && board[j][i]>0){
				GetCoordinates(i,j);
				if(moveable_index != 0 || eliminate_index != 0) {
					moveable_index = 0;
					eliminate_index = 0;
					return false;
				}
			}
		}
	}
	return true;
}

void temp_eliminating(int x, int y){
	temp_eliminate_index = 0;
	int p = (temp_board[y][x]>0)?temp_board[y][x]:-1*temp_board[y][x];
	//printf("%d\n", p);
	for(int i=0;i<types[p].dirsize;i++){
		int movex = x;
		int movey = y;
		//printf("%d %d\n",movex,movey);
		for(int j=0;j<types[p].moveCount;j++){
			movex = movex + types[p].dirX[i];
			if(temp_board[y][x] == -6) movey = movey - types[p].dirY[i];
			else movey = movey + types[p].dirY[i];
			
			if(movex <0 || movey <0 || movex >9 || movey> 9) continue;
			else if(temp_board[movey][movex] == 99) break;
			if((temp_board[y][x] == 6 || temp_board[y][x] == -6) && j == 0){
				if((movex+1)<9 && temp_board[movey][movex+1]*temp_board[y][x] < 0 ){
					temp_eliminate[temp_eliminate_index][0] = movex+1;
					temp_eliminate[temp_eliminate_index][1] = movey;
					//printf("eli - %d %d\n", movex, movey);
					temp_eliminate_index++;
				}
				if((movex-1)>0 && temp_board[movey][movex-1]*temp_board[y][x] < 0){
					temp_eliminate[temp_eliminate_index][0] = movex-1;
					temp_eliminate[temp_eliminate_index][1] = movey;
					//printf("eli - %d %d\n", movex, movey);
					temp_eliminate_index++;
				}
			}

			if(temp_board[movey][movex] == 0){}
			else if(temp_board[movey][movex]*temp_board[y][x] < 0 && temp_board[y][x] != 6 && temp_board[y][x] != -6) {
				temp_eliminate[temp_eliminate_index][0] = movex;
				temp_eliminate[temp_eliminate_index][1] = movey;
				printf("eli - %d %d\n", movex, movey);
				temp_eliminate_index++;
				break;
			}
			else break;
			if(board[y][x] == 6 && y != 2)break;
			else if(board[y][x] == -6 && y != 7)break;
		}
	}
}

bool checksystem(int x, int y){
	printf("Position of King = %d - %d\n", y, x);
	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++){
			if(temp_board[j][i]*temp_board[y][x] < 0){
				temp_eliminate_index = 0;
				temp_eliminating(i,j);
				for(int k=0;k<temp_eliminate_index;k++){
					printf("Elimimate to %d = %d - %d\n", temp_board[j][i], temp_eliminate[k][0] , temp_eliminate[k][1]);
					if(temp_eliminate[k][0] == x && temp_eliminate[k][1] == y) return true;
				}
				printf("-----------------------------\n");
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

					copy_board();
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

					copy_board();
					temp_board[movey][movex-1] = temp_board[y][x];
					temp_board[y][x] = 0;
					bool check = (turn == 'W')?checksystem(white_x, white_y):checksystem(black_x, black_y);
					if(check) eliminate_index--;
				}
			}

			
			if(board[movey][movex] == 0){
				moveable[moveable_index][0] = movex;
				moveable[moveable_index][1] = movey;
				moveable_index++;

				copy_board();
				temp_board[movey][movex] = temp_board[y][x];
				temp_board[y][x] = 0;
				if(temp_board[movey][movex] == 1)  temp_white_x = movex,temp_white_y = movey;
				else if(temp_board[movey][movex] == -1)  temp_black_x = movex,temp_black_y = movey;
				bool check = (turn == 'W')?checksystem(temp_white_x, temp_white_y):checksystem(temp_black_x, temp_black_y);
				if(check) moveable_index--;
			}
			else if(board[movey][movex]*board[y][x] < 0 && board[y][x] != 6 && board[y][x] != -6) {
				eliminate[eliminate_index][0] = movex;
				eliminate[eliminate_index][1] = movey;
				printf("eli - %d %d\n", movex, movey);
				eliminate_index++;

				copy_board();
				temp_board[movey][movex] = temp_board[y][x];
				temp_board[y][x] = 0;
				if(temp_board[movey][movex] == 1)  temp_white_x = movex,temp_white_y = movey;
				else if(temp_board[movey][movex] == -1)  temp_black_x = movex,temp_black_y = movey;
				bool check = (turn == 'W')?checksystem(temp_white_x,temp_white_y):checksystem(temp_black_x, temp_black_y);
				if(check) eliminate_index--;
				break;
			}
			else break;
			if(board[y][x] == 6 && y != 2)break;
			else if(board[y][x] == -6 && y != 7)break;
		}
	}
	if (board[y][x] == 1 || board[y][x] == -1) {
		copy_board();
		bool check = (turn == 'W') ? checksystem(white_x, white_y) : checksystem(black_x, black_y);
		if (!check){
			if (board[y][x] == 1 && castling[0]) {
				int ind = x - 1;
				bool temp_cas = true;
				while (ind > 1){
					if (board[y][ind] != 0) {
						temp_cas = false;
						printf("murikha %d %d", y, ind);
						break;
					}
					copy_board();
					temp_board[y][ind] = temp_board[y][x];
					temp_board[y][x] = 0;
					if (checksystem(ind, white_y)) {
						temp_cas = false;
						printf("muri khabi");
						break;
					}
					ind--;
				}
				if (temp_cas) {
					moveable[moveable_index][0] = x - 2;
					moveable[moveable_index][1] = y;
					moveable_index++;
				}
				printf("haha %d %d", moveable[moveable_index][0], moveable[moveable_index][1]);
			}
			if (board[y][x] == 1 && castling[1]) {
				int ind = x + 1;
				bool temp_cas = true;
				while (ind < 8) {
					if (board[y][ind] != 0) {
						temp_cas = false;
						break;
					}
					copy_board();
					temp_board[y][ind] = temp_board[y][x];
					temp_board[y][x] = 0;
					if (checksystem(ind, white_y)) {
						temp_cas = false;
						break;
					}
					ind++;
				}
				if (temp_cas) {
					moveable[moveable_index][0] = x + 2;
					moveable[moveable_index][1] = y;
					moveable_index++;
				}
			}
			if (board[y][x] == -1 && castling[2]) {
				int ind = x - 1;
				bool temp_cas = true;
				while (ind > 1){
					if (board[y][ind] != 0) {
						temp_cas = false;
						//printf("murikha %d %d", y, ind);
						break;
					}
					copy_board();
					temp_board[y][ind] = temp_board[y][x];
					temp_board[y][x] = 0;
					if (checksystem(ind, black_y)) {
						temp_cas = false;
						//printf("muri khabi");
						break;
					}
					ind--;
				}
				if (temp_cas) {
					moveable[moveable_index][0] = x - 2;
					moveable[moveable_index][1] = y;
					moveable_index++;
				}
			}
			if (board[y][x] == -1 && castling[3]) {
				int ind = x + 1;
				bool temp_cas = true;
				while (ind < 8) {
					if (board[y][ind] != 0) {
						temp_cas = false;
						break;
					}
					copy_board();
					temp_board[y][ind] = temp_board[y][x];
					temp_board[y][x] = 0;
					if (checksystem(ind, black_y)) {
						temp_cas = false;
						break;
					}
					ind++;
				}
				if (temp_cas) {
					moveable[moveable_index][0] = x + 2;
					moveable[moveable_index][1] = y;
					moveable_index++;
				}
			}
		}
	}
}

void iDraw() {
	iClear();
	iShowBMP(0, 0, BoardPic[Board_index]);
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
		iShowBMP2(cirx,ciry,"Pic\\\\Pieces\\\\circle.bmp",255);
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
	if(page == 0){
		iShowBMP(0,0,Opening[openingpageindex]);
	}
	if(page == 1){
		iShowBMP(0,0,Starting[startingpageindex]);
		//iShowBMP2(0,0,"Pic\\\\StartingPage\\\\Extra.bmp",0);
	}
	if(page == 5){
		iShowBMP(0,0,Nameinput[nameinputindex]);
		iShowBMP2(0,572,"Pic\\\\NameInput\\\\back.bmp",0);
		iSetColor(0,0,0);
		iText(117,412,player1,GLUT_BITMAP_HELVETICA_18);
		iText(117,334,player2,GLUT_BITMAP_HELVETICA_18);
	}
	if(page == 3) {
		if(turn == 'W') {
			iShowBMP(150,100,"Pic\\\\page2_black.bmp");
		}
		else if(turn == 'B') {
			iShowBMP(150,100,"Pic\\\\page2_white.bmp");
		}
	}
	if(page == 4) {
		if(turn == 'W') iShowBMP(50,98,"Pic\\\\Black_won.bmp");
		else iShowBMP(50,98,"Pic\\\\White_won.bmp");
	}
	if(page == 6){
		iShowBMP(0,0,"Pic\\\\StartingPage\\\\instructions.bmp");
	}
	if(page == 7){
		iShowBMP(0,0,"Pic\\\\StartingPage\\\\Credits.bmp");
	}
}

void iMouseMove(int mx, int my) {
	//printf("x = %d, y= %d\n",mx,my);
}

void iMouse(int button, int state, int mx, int my) {
	int movex = (mx>=52 && mx<=652)?((mx-52)/75)+1:0;
	int movey = (my>=52 && my<=652)?((my-52)/75)+1:0;
	count++;
	//printf("%d %d\n", movex, movey);
	if(page == 0) return;
	else if(page == 3 && count%2==0) {
		mx -= 150;
		my -= 100;
		if(mx>7 && mx<200){
			if(my>12 && my<=203){
				board[selectedY][selectedX] = (board[selectedY][selectedX]>0)?2:-2;
				page = 2;
			}
			else if(my>203 && my<395){
				board[selectedY][selectedX] = (board[selectedY][selectedX]>0)?3:-3;
				page = 2;
			}
		}
		else if(mx>=200 && mx<393){
			if(my>12 && my<=203){
				board[selectedY][selectedX] = (board[selectedY][selectedX]>0)?5:-5;
				page = 2;
			}
			else if(my>203 && my<395){
				board[selectedY][selectedX] = (board[selectedY][selectedX]>0)?4:-4;
				page = 2;
			}
		}
		return;
	}
	else if(page == 1 && count%2==0) {
		if(mx>=93){
			if(my>=250 && my<=300 && mx<=370){
				page = 7;
			}
			else if(my>=322 && my<=378 && mx<=430){
				page = 6;
			}
			else if(my>=403 && my<= 456 && mx<=398){
				page = 5;
			}
		}
		return;
	}
	else if(page == 6 && count%2==0){
		if(mx>=26 && mx<=192 && my<=683 && my>=613){
			page = 1;
		}
		return;
	}
	else if(page == 7 && count%2==0){
		if(mx>=26 && mx<=192 && my<=683 && my>=613){
			page = 1;
		}
		return;
	}
	else if(page == 5 && count%2==0){
		if(mx>=26 && mx<=192 && my<=683 && my>=613){
			page = 1;
		}
		else if(mx>=99 && mx<=420){
			if(my >=402 && my<= 436){
				name_selected = 1;
				if(player1[0] == '('){
					player1_index = 0;
					player1[player1_index] = '\0';
				}
			}
			else if(my>=323 && my<=356){
				name_selected = -1;
				if(player2[0] == '('){
					player2_index = 0;
					player2[player2_index] = '\0';
				}
			}
			else name_selected = 0;
		}
		else name_selected = 0;
		return;
	}
	
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
				if(board[movey][movex] == 6 && movey == 8) {
					page = 3;
					selectedX = movex;
					selectedY = movey;
				}
				else if(board[movey][movex] == -6 && movey == 1) {
					page = 3;
					selectedX = movex;
					selectedY = movey;
				}

				if(board[movey][movex] == 1) castling[0] = castling[1] = false;
				else if(board[movey][movex] == -1) castling[2] = castling[3] = false;
				else if(board[movey][movex] == 5) {
					if(selectedX == 1) castling[0] = false;
					else if(selectedX == 2) castling[1] = false;
				}
				else if(board[movey][movex] == -5){
					if(selectedX == 1) castling [2] = false;
					else if(selectedX == 8) castling[3] = false;
				}
				if(board[movey][movex] == 1 || board[movey][movex] == -1){
					if((selectedX - movex) == 2){
						board[movey][movex+1] = board[movey][1];
						board[movey][1] = 0;
					}
					else if((movex - selectedX) == 2){
						board[movey][movex-1] = board[movey][8];
						board[movey][8] = 0;
					}
				}
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
			if(win_lose()) page = 4;
		}
	}
}

void iKeyboard(unsigned char key) {
	if (key == ' ' && page == 0) {
		page = 1;
	}
	else if(page == 5 && key == 13) {
		if(name_selected == 1){
			name_selected = -1;
			if(player2[0] == '('){
				player2_index = 0;
				player2[player2_index] = '\0';
			}
		}
		else {
			init();
			page = 2;
			musicOn = false;
			PlaySound(0,0,0);
		}
	}
	else if(page == 5 && name_selected){
		if(!((key>='a' && key<='z') || (key>='A' && key<='Z') || key == ' ' || key == 8 || key == '.')) return;
		if(name_selected == 1 && key != 8 && player1_index<=25){
			if(player1[player1_index-1] == ' ' && key == ' ') return;
			player1[player1_index] = key;
			player1_index++;
			player1[player1_index] = '\0';
		}
		else if(name_selected == 1 && key == 8){
			if(player1_index == 0) return;
			player1_index--;
			player1[player1_index] = '\0';
		}
		else if(name_selected == -1 && key != 8 && player2_index<=25){
			if(player2[player2_index-1] == ' ' && key == ' ') return;
			player2[player2_index] = key;
			player2_index++;
			player2[player2_index] = '\0';
		}
		else if(name_selected == -1 && key == 8){
			if(player2_index == 0) return;
			player2_index--;
			player2[player2_index] = '\0';
		}
	}
	else if(key == 'b'){
		Board_index++;
		if(Board_index >= 7) Board_index = 0;
	}
	else if(key == 'p' || key == 'P'){
		if(musicOn){
			musicOn = false;
			PlaySound(0,0,0);
		}
		else if(!musicOn){
			musicOn = true;
			PlaySound(Music[0], NULL, SND_LOOP | SND_ASYNC);
		}
	}
}

void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}
	//place your codes for other keys here
}

void func(){
	if(openingpageindex >= 45) {
		openingpageindex_loop = -1;
	}
	else if(openingpageindex <= 0){
		openingpageindex_loop = 1;
	}
	openingpageindex += openingpageindex_loop;

	if(startingpageindex >= 65) {
		startingpageindex_loop = -1;
	}
	else if(startingpageindex <= 0){
		startingpageindex_loop = 1;
	}
	startingpageindex += startingpageindex_loop;

	if(nameinputindex >= 64) {
		nameinputindex_loop = -1;
	}
	else if(nameinputindex <= 0){
		nameinputindex_loop = 1;
	}
	nameinputindex += nameinputindex_loop;
}

int main() {
	init();
	copy_board();
	if(musicOn){
		PlaySound(Music[0], NULL, SND_LOOP | SND_ASYNC);
	}
	int t = iSetTimer(50, func);
	iInitialize(700,700,"Chess Game");
	return 0;
}
