# include "iGraphics.h"
#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")


int page = 0;
char turn = 'W';
int board[10][10];
int moveable[64][2];
int moveable_index = 0;
int eliminate[10][2];
int eliminate_index = 0;
int temp_board[10][10];
int temp_eliminate[10][2];
int temp_eliminate_index = 0;
int count = 0;
int white_x, white_y, black_x, black_y;
int temp_white_x, temp_white_y, temp_black_x, temp_black_y;
bool check_red = false;
bool sound = false;

int selectedX,selectedY;
bool selected = false;
bool castling[4] = {true, true, true, true};

char player1[50] = "(Optional)";
int player1_index = 10;
char player2[50] = "(Optional)";
int player2_index = 10;
int name_selected = 0;

int minute[2] = {0,0}, second[2] = {0,0};
bool time_start = false;
int turn_time = 1;
int additonal = 0;

char Music[10][70]= {
	"music\\\\Ltheme.wav",
	"music\\\\cold.wav",
	"music\\\\jjk2.wav",
	"music\\\\onmyway.wav",
	"music\\\\unravel.wav",
	"music\\\\unstopable.wav",
	"music\\\\middleofthenight.wav",
	"music\\\\pubg.wav"
};
int musicindex = 0;
char additonal_sounds[50][50];
int musicOn = 1;
int winmusic = 0;

int Undo[10][10][100];
int undoindex = 0;

char Mode[50][50] = {
	"Pic\\\\Mode\\\\ (1).bmp",
	"Pic\\\\Mode\\\\ (2).bmp",
	"Pic\\\\Mode\\\\ (3).bmp",
	"Pic\\\\Mode\\\\ (4).bmp",
	"Pic\\\\Mode\\\\ (5).bmp",
	"Pic\\\\Mode\\\\ (6).bmp",
	"Pic\\\\Mode\\\\ (7).bmp",
	"Pic\\\\Mode\\\\ (8).bmp",
	"Pic\\\\Mode\\\\ (9).bmp",
	"Pic\\\\Mode\\\\ (10).bmp",
	"Pic\\\\Mode\\\\ (11).bmp",
	"Pic\\\\Mode\\\\ (12).bmp",
	"Pic\\\\Mode\\\\ (13).bmp",
	"Pic\\\\Mode\\\\ (14).bmp",
	"Pic\\\\Mode\\\\ (15).bmp",
	"Pic\\\\Mode\\\\ (16).bmp",
	"Pic\\\\Mode\\\\ (17).bmp",
	"Pic\\\\Mode\\\\ (18).bmp",
	"Pic\\\\Mode\\\\ (19).bmp",
	"Pic\\\\Mode\\\\ (20).bmp",
	"Pic\\\\Mode\\\\ (21).bmp",
	"Pic\\\\Mode\\\\ (22).bmp",
	"Pic\\\\Mode\\\\ (23).bmp",
	"Pic\\\\Mode\\\\ (24).bmp",
	"Pic\\\\Mode\\\\ (25).bmp",
	"Pic\\\\Mode\\\\ (26).bmp",
	"Pic\\\\Mode\\\\ (27).bmp",
	"Pic\\\\Mode\\\\ (28).bmp",
	"Pic\\\\Mode\\\\ (29).bmp",
	"Pic\\\\Mode\\\\ (30).bmp",
	"Pic\\\\Mode\\\\ (31).bmp",
	"Pic\\\\Mode\\\\ (32).bmp",
	"Pic\\\\Mode\\\\ (33).bmp",
	"Pic\\\\Mode\\\\ (34).bmp",
	"Pic\\\\Mode\\\\ (35).bmp",
	"Pic\\\\Mode\\\\ (36).bmp",
	"Pic\\\\Mode\\\\ (37).bmp",
	"Pic\\\\Mode\\\\ (38).bmp",
	"Pic\\\\Mode\\\\ (39).bmp",
	"Pic\\\\Mode\\\\ (40).bmp",
	"Pic\\\\Mode\\\\ (41).bmp",
	"Pic\\\\Mode\\\\ (42).bmp",
	"Pic\\\\Mode\\\\ (43).bmp",
	"Pic\\\\Mode\\\\ (44).bmp",
	"Pic\\\\Mode\\\\ (45).bmp",
	"Pic\\\\Mode\\\\ (46).bmp"
};
int modeindex = 0;
int mode_loop = 1;

int modeselect = 1;
void modeselected(){
	if(modeselect == 1) {
		minute[0] = 0;
		second[0] = 0;
		minute[1] = 0;
		second[1] = 0;
		additonal = 0;
	}
	else if(modeselect == 2){
		minute[0] = 1;
		second[0] = 0;
		minute[1] = 1;
		second[1] = 0;
		additonal = 0;
	}
	else if(modeselect == 3){
		minute[0] = 2;
		second[0] = 0;
		minute[1] = 2;
		second[1] = 0;
		additonal = 1;
	}
	else if(modeselect == 4){
		minute[0] = 3;
		second[0] = 0;
		minute[1] = 3;
		second[1] = 0;
		additonal = 2;
	}
	else if(modeselect == 5){
		minute[0] = 5;
		second[0] = 0;
		minute[1] = 5;
		second[1] = 0;
		additonal = 0;
	}
	else if(modeselect == 6){
		minute[0] = 10;
		second[0] = 0;
		minute[1] = 10;
		second[1] = 0;
		additonal = 0;
	}
	else if(modeselect == 7){
		minute[0] = 15;
		second[0] = 0;
		minute[1] = 15;
		second[1] = 0;
		additonal = 10;
	}
	else if(modeselect == 8){
		minute[0] = 30;
		second[0] = 0;
		minute[1] = 30;
		second[1] = 0;
		additonal = 0;
	}
}

char Win[50][50] = {
	"Pic\\\\Win\\\\ (1).bmp",
	"Pic\\\\Win\\\\ (2).bmp",
	"Pic\\\\Win\\\\ (3).bmp",
	"Pic\\\\Win\\\\ (4).bmp",
	"Pic\\\\Win\\\\ (5).bmp",
	"Pic\\\\Win\\\\ (6).bmp",
	"Pic\\\\Win\\\\ (7).bmp",
	"Pic\\\\Win\\\\ (8).bmp",
	"Pic\\\\Win\\\\ (9).bmp",
	"Pic\\\\Win\\\\ (10).bmp",
	"Pic\\\\Win\\\\ (11).bmp",
	"Pic\\\\Win\\\\ (12).bmp",
	"Pic\\\\Win\\\\ (13).bmp",
	"Pic\\\\Win\\\\ (14).bmp",
	"Pic\\\\Win\\\\ (15).bmp",
	"Pic\\\\Win\\\\ (16).bmp",
	"Pic\\\\Win\\\\ (17).bmp",
	"Pic\\\\Win\\\\ (18).bmp",
	"Pic\\\\Win\\\\ (19).bmp",
	"Pic\\\\Win\\\\ (20).bmp",
	"Pic\\\\Win\\\\ (21).bmp",
	"Pic\\\\Win\\\\ (22).bmp",
	"Pic\\\\Win\\\\ (23).bmp",
	"Pic\\\\Win\\\\ (24).bmp",
	"Pic\\\\Win\\\\ (25).bmp",
	"Pic\\\\Win\\\\ (26).bmp",
	"Pic\\\\Win\\\\ (27).bmp",
	"Pic\\\\Win\\\\ (28).bmp",
	"Pic\\\\Win\\\\ (29).bmp",
	"Pic\\\\Win\\\\ (30).bmp"
};
int winingindex = 0;

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
	"Pic\\\\ChessBoard\\\\Chess5.bmp"
};
int Board_index = 0;

char Buttons[30][50] = {
	"Pic\\\\Buttonoff.bmp",
	"Pic\\\\Buttonon.bmp",
	"Pic\\\\ingamebuttonoff.bmp",
	"Pic\\\\ingamebuttonon.bmp"

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

char file_name[100] = "Leaderboard.txt";
FILE* file;
char leaderboardshow[10][200]={0,0,0,0,0,0,0,0,0,0};
int leaderboard_ind = 0;

void init();
void copy_board();
bool win_lose();
void temp_eliminating(int x, int y);
bool checksystem(int x, int y);
void GetCoordinates(int x, int y);
void func();
void time();
void namechange();
bool Draw_game();
void copy_undo();

void init(){
	copy_board();
	modeselected();
	check_red =false;
	time_start = false;
	turn_time = 1;
	turn = 'W';
	castling[0] = castling[1] = castling[2] = castling[3] = true; 
	moveable_index = 0;
	eliminate_index = 0;
	temp_eliminate_index = 0;
	white_x = 5, white_y = 1, black_x = 5, black_y = 8;
	selected = false;
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
	copy_undo();
}

void copy_board(){
	temp_white_x = white_x, temp_white_y = white_y, temp_black_x = black_x, temp_black_y = black_y;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			temp_board[i][j] = board[i][j];
		}
	}
}

void namechange(){
	if(player1[0] == '(' || player1[0] == '\0'){
		player1[0] = 'P';
		player1[1] = 'l';
		player1[2] = 'a';
		player1[3] = 'y';
		player1[4] = 'e';
		player1[5] = 'r';
		player1[6] = ' ';
		player1[7] = '1';
		player1[8] = '\0';
	}
	if(player2[0] == '(' || player2[0] == '\0'){
		player2[0] = 'P';
		player2[1] = 'l';
		player2[2] = 'a';
		player2[3] = 'y';
		player2[4] = 'e';
		player2[5] = 'r';
		player2[6] = ' ';
		player2[7] = '2';
		player2[8] = '\0';
	}
}

void copy_undo(){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			Undo[i][j][undoindex] = board[i][j];
		}
	}
}

bool Draw_game(){
	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++){
			if(board[i][j] != 1 && board[i][j]>0) return false;
			if(board[i][j] != -1 && board[i][j]<0) return false;
		}
	}
	return true;
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
	////printf("%d\n", p);
	for(int i=0;i<types[p].dirsize;i++){
		int movex = x;
		int movey = y;
		////printf("%d %d\n",movex,movey);
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
					////printf("eli - %d %d\n", movex, movey);
					temp_eliminate_index++;
				}
				if((movex-1)>0 && temp_board[movey][movex-1]*temp_board[y][x] < 0){
					temp_eliminate[temp_eliminate_index][0] = movex-1;
					temp_eliminate[temp_eliminate_index][1] = movey;
					////printf("eli - %d %d\n", movex, movey);
					temp_eliminate_index++;
				}
			}

			if(temp_board[movey][movex] == 0){}
			else if(temp_board[movey][movex]*temp_board[y][x] < 0 && temp_board[y][x] != 6 && temp_board[y][x] != -6) {
				temp_eliminate[temp_eliminate_index][0] = movex;
				temp_eliminate[temp_eliminate_index][1] = movey;
				//printf("eli - %d %d\n", movex, movey);
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
	//printf("Position of King = %d - %d\n", y, x);
	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++){
			if(temp_board[j][i]*temp_board[y][x] < 0){
				temp_eliminate_index = 0;
				temp_eliminating(i,j);
				for(int k=0;k<temp_eliminate_index;k++){
					//printf("Elimimate to %d = %d - %d\n", temp_board[j][i], temp_eliminate[k][0] , temp_eliminate[k][1]);
					if(temp_eliminate[k][0] == x && temp_eliminate[k][1] == y) return true;
				}
				//printf("-----------------------------\n");
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
		//printf("%d %d\n",movex,movey);
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
					//printf("eli - %d %d\n", movex, movey);
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
					//printf("eli - %d %d\n", movex, movey);
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
				//printf("eli - %d %d\n", movex, movey);
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
						//printf("murikha %d %d", y, ind);
						break;
					}
					copy_board();
					temp_board[y][ind] = temp_board[y][x];
					temp_board[y][x] = 0;
					if (checksystem(ind, white_y)) {
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
				//printf("haha %d %d", moveable[moveable_index][0], moveable[moveable_index][1]);
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
						////printf("murikha %d %d", y, ind);
						break;
					}
					copy_board();
					temp_board[y][ind] = temp_board[y][x];
					temp_board[y][x] = 0;
					if (checksystem(ind, black_y)) {
						temp_cas = false;
						////printf("muri khabi");
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
	printf("movable and eli - %d %d", moveable_index, eliminate_index);
	for(int muri=0;muri<moveable_index;muri++){
		printf("movable index = %d %d\n", moveable[muri][0], moveable[muri][1]);
	}
	for(int muri=0;muri<eliminate_index;muri++){
		printf("eliminate index = %d %d\n", eliminate[muri][0], eliminate[muri][1]);
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
			////printf("%d\n", p);
			if(p>0) {
				if(check_red && board[i][j] == 1 && turn == 'W'){
					iShowBMP2(x,y,path[2],0);
				}
				else iShowBMP2(x,y,path[((p-1)*4)+0],255);
			}
			else if(p<0) {
				if(check_red && board[i][j] == -1 && turn == 'B'){
					iShowBMP2(x,y,path[3],0);
				}
				else iShowBMP2(x,y,path[(((p*-1)-1)*4)+1],255);
			}
			x += (75);
		}
		x = (52+4);
		y += (75);
	}
	for(int i=0;i<moveable_index;i++){
		//printf("haha");
		if(!((moveable[i][0]>=1 && moveable[i][0]<=8 )&&(moveable[i][1]>=1 && moveable[i][1]<=8 ))) continue;
		int cirx = (moveable[i][0]*75) +(52-75) + 4;
		int ciry = (moveable[i][1]*75) +(52-75) + 4;
		iShowBMP2(cirx,ciry,"Pic\\\\Pieces\\\\circle.bmp",255);
	}
	for(i=0;i<eliminate_index;i++){
		//printf("haha2");
		if(!((eliminate[i][0]>=1 && eliminate[i][0]<=8 )&&(eliminate[i][1]>=1 && eliminate[i][1]<=8 ))) continue;
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
	iShowBMP2(680,5,"Pic\\\\textbox.bmp",0);
	iShowBMP2(680,605,"Pic\\\\textbox.bmp",0);
	iText(699,50,player1,GLUT_BITMAP_HELVETICA_18);
	iText(699,650,player2,GLUT_BITMAP_HELVETICA_18);
	char str[6];
	str[0] = '1' -1+(minute[0]/10);
	str[1] = '1' -1+(minute[0]%10);
	str[2] = ':';
	str[3] = '1' -1+(second[0]/10);
	str[4] = '1' -1+(second[0]%10);
	str[5] = '\0';
	char str2[6];
	str2[0] = '1' -1+(minute[1]/10);
	str2[1] = '1' -1+(minute[1]%10);
	str2[2] = ':';
	str2[3] = '1' -1+(second[1]/10);
	str2[4] = '1' -1+(second[1]%10);
	str2[5] = '\0';
	if(Board_index == 4) iSetColor(255,255,255);
	if(modeselect != 1){
		iText(770,601,str,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(770,90,str2,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	iShowBMP2(695,0,Buttons[musicOn+2],255);
	if(modeselect != 1) iShowBMP2(695,0,"Pic\\\\plusten.bmp",255);
	iSetColor(0,0,0);
	if(page == 0){
		iShowBMP(0,0,Opening[openingpageindex]);
		iShowBMP(670,0,"Pic\\\\extra4.bmp");
	}
	else if(page == 1){
		iShowBMP(0,0,Starting[startingpageindex]);
		iShowBMP(670,0,"Pic\\\\extra2.bmp");
		iShowBMP2(690,0,Buttons[musicOn],255);
		iShowBMP2(690,0,"Pic\\\\StartingPage\\\\Leaderboard.bmp",255);
	}
	else if(page == 8){
		iShowBMP(0,0,Mode[modeindex]);
		iShowBMP2(670,0,"Pic\\\\extra5.bmp",0);
		iShowBMP(700,192,"Pic\\\\extra6.bmp");
		iShowBMP2(690,0,Buttons[musicOn],255);
	}
	else if(page == 5){
		iShowBMP(0,0,Nameinput[nameinputindex]);
		iShowBMP2(0,572,"Pic\\\\NameInput\\\\back.bmp",0);
		iSetColor(0,0,0);
		iText(117,414,player1,GLUT_BITMAP_HELVETICA_18);
		iText(117,334,player2,GLUT_BITMAP_HELVETICA_18);
		iShowBMP(670,0,"Pic\\\\extra2.bmp");
		iShowBMP2(690,0,Buttons[musicOn],255);
		iShowBMP2(690,0,"Pic\\\\BUttonPage5.bmp",255);
		iShowBMP2(0,0,"Pic\\\\NameInput\\\\extra.bmp",255);
		iShowBMP2(435,348,"Pic\\\\NameInput\\\\nameswap.bmp",0);
	}
	else if(page == 3) {
		if(turn == 'W') {
			iShowBMP(150,100,"Pic\\\\page2_black.bmp");
		}
		else if(turn == 'B') {
			iShowBMP(150,100,"Pic\\\\page2_white.bmp");
		}
	}
	else if(page == 4) {
		if(winmusic == 0 && !musicOn){
			PlaySound(0,0,0);
			PlaySound("music\\\\Win.wav", NULL, SND_LOOP | SND_ASYNC);
			winmusic = 1;
		}
		iShowBMP(0,0,Win[winingindex]);
		if(winingindex == 29) {
			if(turn == 'W') {
				iShowBMP(0,0,"Pic\\\\Win\\\\BLACK.bmp");
				iText(460,130,player2,GLUT_BITMAP_TIMES_ROMAN_24);
			}
			else {
				iShowBMP(0,0,"Pic\\\\Win\\\\WHITE.bmp");
				iText(460,130,player1,GLUT_BITMAP_TIMES_ROMAN_24);
			}
			if(Draw_game()) iShowBMP(0,0,"Pic\\\\Win\\\\Draw.bmp");

		}
		iShowBMP(700,0,"Pic\\\\extra7.bmp");
	}
	else if(page == 6){
		iShowBMP(0,0,"Pic\\\\StartingPage\\\\instructions.bmp");
		iShowBMP(670,0,"Pic\\\\extra3.bmp");
		iShowBMP2(690,0,Buttons[musicOn],255);
	}
	else if(page == 7){
		iShowBMP(0,0,"Pic\\\\StartingPage\\\\Credits.bmp");
		iShowBMP(670,0,"Pic\\\\extra.bmp");
		iShowBMP2(690,0,Buttons[musicOn],255);
	}
	else if(page == 9){
		iShowBMP(0,0,"Pic\\\\StartingPage\\\\Leaderboard_page.bmp");
		iShowBMP(670,0,"Pic\\\\extra.bmp");
		iShowBMP2(690,0,Buttons[musicOn],255);
		file = fopen(file_name, "r");
		leaderboard_ind = 0;
		char temp_name = fgetc(file);
		while(!feof(file)){
			if(temp_name == '-'){
				leaderboard_ind++;
			}
			temp_name = fgetc(file);
		}
		//printf("leader %d", leaderboard_ind);
		int temp_ind = 0;
		if(leaderboard_ind>10){
			leaderboard_ind -= 10;
			temp_ind = 9;
		}
		else {
			temp_ind = leaderboard_ind-1;
			leaderboard_ind = 0;
		}
		rewind(file);
		temp_name = fgetc(file);
		int temp_file_ind=0;
		while(!feof(file)){
			if(temp_name == '-'){
				if(leaderboard_ind>0) {
					leaderboard_ind--;
					temp_file_ind = 0;
				}
				else {
					leaderboardshow[temp_ind][temp_file_ind] = 0;
					temp_file_ind = 0;
					//printf("%s %d\n", leaderboardshow[temp_ind], temp_ind);
					temp_ind--;
				}
			}
			else {
				leaderboardshow[temp_ind][temp_file_ind] = temp_name;
				temp_file_ind++;
			}
			temp_name = fgetc(file);
		}
		leaderboardshow[temp_ind][temp_file_ind] = 0;
		fclose(file);
		for(int muri=0,minus=0;muri<10;muri++,minus-=30){
			iText(125,413+minus,"-> ",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(125+31,413+minus,leaderboardshow[muri],GLUT_BITMAP_HELVETICA_18);
		}
		
	}
}

void iMouseMove(int mx, int my) {
	////printf("x = %d, y= %d\n",mx,my);
}

void iMouse(int button, int state, int mx, int my) {
	int movex = (mx>=52 && mx<=652)?((mx-52)/75)+1:0;
	int movey = (my>=52 && my<=652)?((my-52)/75)+1:0;
	count++;
	printf("%d %d\n", mx, my);
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
	if((page == 1 || page == 5||page ==6 ||page == 7||page == 8||page == 9) && count%2==0){
		if(((690+61+37-mx)*(690+61+37-mx))+((my-403-61)*(my-403-61))<61*61) {
			if(musicOn){
				musicOn = false;
				PlaySound(0,0,0);
			}
			else {
				musicOn = true;
				PlaySound(Music[musicindex], NULL, SND_LOOP | SND_ASYNC);
			}
		}
		if(((690+61+37-mx)*(690+61+37-mx))+((my-265-61)*(my-265-61))<61*61) {
			musicindex++;
			if(musicindex>7) musicindex =0;
			if(musicOn){
				PlaySound(0,0,0);
				PlaySound(Music[musicindex], NULL, SND_LOOP | SND_ASYNC);
			}
		}
	}
	if(page == 1 && count%2==0) {
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
		if(((690+61+37-mx)*(690+61+37-mx))+((my-122-61)*(my-122-61))<61*61){
			page = 9;
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
	else if(page == 9 && count%2==0){
		if(mx>=26 && mx<=192 && my<=683 && my>=613){
			page = 1;
		}
		return;
	}
	else if(page == 4 && count%2==0){
		if(mx>=700+15 && mx<=170+700 && my>=71 && my<=342){
			if(!musicOn) {
				musicOn = true;
				PlaySound(0,0,0);
				PlaySound(Music[musicindex], NULL, SND_LOOP | SND_ASYNC);
			}
			page = 1;
			winmusic = 0;
		}
		else if(mx>=700+15 && mx<=170+700 && my>=391 && my<=661){
			init();
			page = 2;
			if(winmusic == 1){
				PlaySound(0,0,0);
			}
			winmusic = 0;
			if(undoindex>1) undoindex = 1;
		}
		return;
	}
	else if(page == 8 && count%2==0){
		if(mx>=26 && mx<=192 && my<=683 && my>=613){
			page = 5;
			return;
		}
		else if(mx>=187 && mx<=329 && my<=553 && my>=513){
			page = 2;
			modeselect = 1;
		}
		else if(mx>=177 && mx<=319 && my<=484 && my>=444){
			page = 2;
			modeselect = 2;
		}
		else if(mx>=335 && mx<=478 && my<=484 && my>=444){
			page = 2;
			modeselect = 3;
		}
		else if(mx>=178 && mx<=320 && my<=412 && my>=371){
			page = 2;
			modeselect = 4;
		}
		else if(mx>=335 && mx<=478 && my<=412 && my>=371){
			page = 2;
			modeselect = 5;
		}
		else if(mx>=166 && mx<=308 && my<=334 && my>=294){
			page = 2;
			modeselect = 6;
		}
		else if(mx>=320 && mx<=463 && my<=334 && my>=294){
			page = 2;
			modeselect = 7;
		}
		else if(mx>=476 && mx<=616 && my<=334 && my>=294){
			page = 2;
			modeselect = 8;
		}
		if(page == 2){
			init();
			modeselected();
			namechange();
			if(undoindex>1) undoindex = 1;
			musicOn =false;
			PlaySound(0,0,0);
			PlaySound("music\\\\board-start.wav", NULL, SND_ASYNC);
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
		if(((435+35-mx)*(435+35-mx))+((my-348-35)*(my-348-35))<30*30){
			if(!((player1[0] == '\0' && player2[0] == '(') || (player1[0] == '(' && player2[0] == '\0'))){
				char temp_name[20];
				int ind = 0;
				while(player1[ind]!='\0'){
					temp_name[ind] = player1[ind];
					ind++;
				}
				temp_name[ind] = '\0';
				ind = 0;
				while(player2[ind]!='\0'){
					player1[ind] = player2[ind];
					ind++;
				}
				player1[ind] = '\0';
				ind = 0;
				while(temp_name[ind]!='\0'){
					player2[ind] = temp_name[ind];
					ind++;
				}
				player2[ind] = '\0';
				printf("haha");
				ind = player1_index;
				player1_index = player2_index;
				player2_index = ind;
			}
		}
		if(((690+61+37-mx)*(690+61+37-mx))+((my-122-61)*(my-122-61))<61*61){
			page = 8;
			name_selected = 0;
		}
		return;
	}
	
	if(page == 2 && count%2==0){
		if(((695+59-mx)*(695+59-mx))+((my-430)*(my-430))<31*31){
			init();
		}
		else if(((695+59-mx)*(695+59-mx))+((my-353)*(my-353))<31*31){
			if(musicOn){
				PlaySound(0,0,0);
				musicOn = false;
			}
			else{
				musicOn = true;
				PlaySound(Music[musicindex], NULL, SND_LOOP | SND_ASYNC);
			}
		}
		else if(((695+59-mx)*(695+59-mx))+((my-273)*(my-273))<31*31){
			Board_index++;
			if(Board_index>=5) Board_index = 0;
		}
		else if(((695+143-mx)*(695+143-mx))+((my-430)*(my-430))<31*31){
			if(modeselect == 1 && undoindex>1){
				undoindex--;
				for(int i=0;i<10;i++){
					for(int j=0;j<10;j++){
						board[i][j] = Undo[i][j][undoindex-1];
					}
				}
				turn = (turn == 'W')?'B':'W';
				moveable_index = 0;
				eliminate_index = 0;
				check_red = (turn == 'W')?checksystem(white_x, white_y):checksystem(black_x, black_y);
				//printf("%d -------  %d",modeselect,undoindex);
			}
			else if(modeselect != 1) {
				second[0] += 10;
				if(second[0]>=60){
					minute[0]++;
					second[0] = second[0] %60;
				}
				second[1] += 10;
				if(second[1]>=60){
					minute[1]++;
					second[1] = second[1] %60;
				}
			}
		}
		else if(((695+143-mx)*(695+143-mx))+((my-353)*(my-353))<31*31){
			if(musicOn){
				PlaySound(0,0,0);
				musicindex++;
				if(musicindex > 7) musicindex = 0;
				PlaySound(Music[musicindex], NULL, SND_LOOP | SND_ASYNC);
			}
			else {
				musicindex++;
			}
		}
		else if(((695+143-mx)*(695+143-mx))+((my-273)*(my-273))<31*31){
			page = 4;
			winingindex = 0;
			time_start = false;
			file = fopen(file_name, "a");
			rewind(file);
			if(turn == 'W') fprintf(file,"%s Won against %s\n-", player2, player1);
			else fprintf(file,"%s Won against %s\n-", player1, player2);
			fclose(file);
		}
	}

	if (button == GLUT_LEFT_BUTTON && movex<9 && movex>0 && movey<9 && movey>0 && page == 2) {
		
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
				if(second[turn_time]<(60-additonal)) second[turn_time] += additonal;
				else{
					minute[turn_time] +=1;
					second[turn_time] = (second[turn_time]+additonal)-60;
				}
				turn_time = (turn == 'W')?1:0;
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
						if(!(musicOn || sound)) PlaySound("music\\\\castle.wav", NULL, SND_ASYNC);
						sound = true;
					}
					else if((movex - selectedX) == 2){
						board[movey][movex-1] = board[movey][8];
						board[movey][8] = 0;
						if(!(musicOn || sound)) PlaySound("music\\\\castle.wav", NULL, SND_ASYNC);
						sound = true;
					}
				}
				if(!time_start) time_start = true;
				check_red = false;
				if(undoindex == 0) undoindex++;
				copy_undo();
				undoindex++;
				printf("undoindex = %d", undoindex);
				if(!(musicOn || sound)) PlaySound("music\\\\move-self.wav", NULL, SND_ASYNC);
				sound = false;
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
			check_red = (turn == 'W')?checksystem(white_x, white_y):checksystem(black_x, black_y);
			if(check_red == true) PlaySound("music\\\\move-check.wav", NULL, SND_ASYNC);
			if(win_lose()) {
				page = 4;
				winingindex = 0;
				time_start = false;
				file = fopen(file_name, "a");
				if(turn == 'W') fprintf(file,"%s Won against %s\n-", player2, player1);
				else fprintf(file,"%s Won against %s\n-", player1, player2);
				fclose(file);
			}
			if(Draw_game()) {
				page = 4;
				winingindex = 0;
				time_start = false;
			}
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
			page = 8;
		}
	}
	else if(page == 5 && name_selected){
		if(!((key>='a' && key<='z') || (key>='A' && key<='Z') || key == ' ' || key == 8 || key == '.')) return;
		if(name_selected == 1 && key != 8 && player1_index<=9){
			if((player1[player1_index-1] == ' '|| player1_index == 0) && key == ' ') return;
			if((player1[player1_index-1] == '.'|| player1_index == 0) && key == '.') return;
			player1[player1_index] = key;
			player1_index++;
			player1[player1_index] = '\0';
		}
		else if(name_selected == 1 && key == 8){
			if(player1_index == 0) return;
			player1_index--;
			player1[player1_index] = '\0';
		}
		else if(name_selected == -1 && key != 8 && player2_index<=9){
			if((player2[player2_index-1] == ' ' || player2_index == 0) && key == ' ') return;
			if((player2[player2_index-1] == '.' || player2_index == 0) && key == '.') return;
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
	else if(key == 'b' || key == 'B'){
		Board_index++;
		if(Board_index >= 5) Board_index = 0;
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

	if(startingpageindex >= 45) {
		startingpageindex_loop = -1;
	}
	else if(startingpageindex <= 0){
		startingpageindex_loop = 1;
	}
	startingpageindex += startingpageindex_loop;

	if(nameinputindex >= 45) {
		nameinputindex_loop = -1;
	}
	else if(nameinputindex <= 0){
		nameinputindex_loop = 1;
	}
	nameinputindex += nameinputindex_loop;

	if(modeindex >= 45) {
		mode_loop = -1;
	}
	else if(modeindex <= 0){
		mode_loop = 1;
	}
	modeindex += mode_loop;

	if(winingindex < 29) winingindex++;
}

void time(){
	if(time_start){
		if(second[turn_time]>0) second[turn_time]--;
		if(second[turn_time]<=0 && minute[turn_time]) {
			minute[turn_time]--;
			second[turn_time] = 59;
		}
		if(minute[turn_time] == 0 && second[turn_time] == 0 && modeselect != 1){
			page = 4;
			winingindex = 0;
			time_start = false;
			file = fopen(file_name, "a");
			if(turn == 'W') fprintf(file,"%s Won against %s\n-", player2, player1);
			else fprintf(file,"%s Won against %s\n-", player1, player2);
			fclose(file);
		} 
	}
}

int main() {
	init();
	copy_board();
	if(musicOn){
		PlaySound(Music[musicindex], NULL, SND_LOOP | SND_ASYNC);
	}
	int t = iSetTimer(5, func);
	int t2 = iSetTimer(1000, time);
	iInitialize(900,700,"Chess Game");
	return 0;
}
