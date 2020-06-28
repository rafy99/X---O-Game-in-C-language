
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>

char mark; // in which we save either x   or    o
int choice; // it is the number in board in which the user will enter
char option;// it is used if the user want to exit or to continue
char pl_1;// it a charecter in which we save first mark from user to calculate score
int sc_1 = 0, sc_2 = 0; // it's score of player 1  &&  player 2
char arr[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
// this is 1-D array throught which we will print board numbers
// now first function in program that will print the board
void print()
{
	printf("\t\t\t\t tic-tac-toe\n");

	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c \n", arr[1], arr[2], arr[3]);

	printf("-----|-----|-----\n");
	printf("     |     |     \n");

	printf("  %c  |  %c  |  %c \n", arr[4], arr[5], arr[6]);

	printf("-----|-----|-----\n");
	printf("     |     |     \n");

	printf("  %c  |  %c  |  %c \n", arr[7], arr[8], arr[9]);

	printf("     |     |     \n\n");
}
// second function that will check the logic of the game to set winner and loser
// 1---> to win
// 0----> if entered num is not in board
// -1----> to continue playing
int check_win()
{
	if (arr[1] == arr[2] && arr[2] == arr[3]) {
		return 1;
	}
	else if (arr[4] == arr[5] && arr[5] == arr[6])
	{
		return 1;
	}
	else if (arr[7] == arr[8] && arr[8] == arr[9])
	{
		return 1;
	}
	else if (arr[1] == arr[4] && arr[4] == arr[7])
	{
		return 1;
	}
	else if (arr[2] == arr[5] && arr[5] == arr[8])
	{
		return 1;
	}
	else if (arr[3] == arr[6] && arr[6] == arr[9])
	{
		return 1;
	}
	else if (arr[1] == arr[5] && arr[5] == arr[9])
	{
		return 1;
	}
	else if (arr[3] == arr[5] && arr[5] == arr[7])
	{
		return 1;
	}
	else if (arr[1] != '1' && arr[2] != '2' && arr[3] != '3' &&
		arr[4] != '4' && arr[5] != '5' && arr[6] != '6' && arr[7]
		!= '7' && arr[8] != '8' && arr[9] != '9')
	{
		return 0;  /* this condition means if all array elements are filled with marks so that
				   no matching cells to win
				   */
	}
	else
	{
		return -1;
	}
}
// this function to reset all aray elements to begin a new game...
void play_again()
{
	for (int i = 0; i < 10; i++)
	{
		arr[i] = '0' + i;
	}


}

// main function
void main()
{
	system("color 4E");// i used this code from c system in which first num -> 4
	// indicates back ground color and letter -> E indicates words color

	int i = -1; // we set check win function to -> -1 so players can play to set the winner

	print();
	printf("Hello Players :):) make sure that you use numbers in the above board if else you will have 3 opportunites unless you will lose\n");

	printf("player (1) enter weather 'x'  or  'o'-->\n");
	scanf_s(" %c", &mark); pl_1 = mark;// now first mark is in pl_1
	int errors = 3;/* this variable if user entered num which  is not in board and it decreases
				   till errors>0 then this players loses
				   */

	while ((i == -1 && errors>0))/* infinite while loop with two conditions check win =-1
								 so player can play and errors>0 untill 3 invalid move and game will end
								 */
	{

		printf("player (%c) enter one of the numbers--->\n", mark);
		scanf_s("%d", &choice);
		if (arr[choice] == '0' + choice) {// we check if num in board or not
			arr[choice] = mark;// if in board we replace board num with mark
			if (mark == 'x') {
				mark = 'o';        // then we change mark x with o and the reverse
			}
			else {
				mark = 'x';
			}
			system("cls");// here we don't want to print the board every time unless invalid move
		}// so with every entery to mark we clear 
		else {
			errors--;// if num is not in board we warn the player
			printf("not valid position \n");
		}

		print();// then we print board for next mark
		i = check_win();// and check if player win or lost after every mark enterd in board

	}

	/*
	now we will check the winner but now the mark will be changed after every entery so suppose
	player x wins the mark will be o ,so if(i==1) we will use pl_1 if it equal mark then
	player two will win since the mark now is not the mark of the winner now and similarly
	if mark!=pl_
	*/
	if (i == 1)
	{
		if (mark == pl_1)

		{
			sc_2 += 1;
			printf(" player (2) wins  \n");
			printf("------->player (1) wins %d games\n", sc_1);
			printf("------->player (2) wins %d games\n", sc_2);
		}
		else if (mark != pl_1)
		{
			sc_1 += 1;
			printf(" player (1) wins  \n");
			printf("------->player (1) wins %d games\n", sc_1);
			printf("------->player (2) wins %d games\n", sc_2);
		}
	}
	else if (i == 0) {// here we check the tie and score is printed without any increment 
		printf("tie\n");

		printf("player (1) score is%d\n", sc_1);
		printf("player (2) score is %d\n", sc_2);

	}
	/*
	now we will check for invalid move similarly if mark is x the n player x loses and player two
	winnes
	*/
	else if (errors == 0)
	{

		if (mark == pl_1)
		{
			sc_2 += 1;
			printf("Player (1) lost because 3 wrong position \n");
			printf("player (1) score is %d\n", sc_1);
			printf("player (2) score is %d\n", sc_2);
		}
		else if (mark != pl_1)
		{
			sc_1 += 1;
			printf("Player (2) lost because 3 wrong position \n");
			printf("player (1) score is %d\n", sc_1);
			printf("player (2) score is %d\n", sc_2);
		}
	}
	/*
	now we will ask the user if he want to exit he will press e that will supporte the exit(0)
	function in <stdlib.h> to close command window if he want to continue he will press c
	and then we will call play_again function to reset arrayy and we will reset mark->'0' &
	errors->3 & pl_='0' & choice=0 then we will call the maein function again
	*/
	printf("if you want to continue press ------> c\n");
	printf("if you want to exit press ------> e\n");
	scanf_s(" %c", &option);
	if (option == 'c')
	{
		system("cls");
		errors = 3;
		choice = 0;
		mark = '0';
		pl_1 = '0';
		i = -1;
		play_again();
		main();

	}
	else if (option == 'e')
	{
		exit(0);
	}


	_getch();
}

/*                           THANK YOU AND ENJOY TIC-TAC-TOE                                     */
/*      HANDELED BY:
LUJIN AHMED ELMOKADEM       ID-> 5317257
RAPHAEL ALFY ASAAD          ID-> 5317113
*/