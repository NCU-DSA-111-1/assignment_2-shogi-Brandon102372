#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
//#include <ev.h>
#include "../inc/chess_board.h"
#include "../inc/coord.h"
#include "../inc/stack.h"
#include "../inc/file_processing.h" 
#define INPUT_SIZE 7

chess board[SIZE][SIZE];
stack *record=NULL;
typedef enum {NEW,LOAD}MODE;
/*get start and end coordinate*/
void get_move(coord *st,coord *ed,char*in){
	st->x=8-(in[0] - '0' -1);
	st->y=in[1] - '0' -1;
	ed->x=8-(in[3] - '0' -1);
	ed->y=in[4] - '0' -1;
}

int main(int argc, char *argv[]) {
	initialize(board);
	show(board);
	
	coord start,end;
	int turn=-1;
	COLOR player=BLUE;
	MODE current;
	char input_str[INPUT_SIZE];
	char file_name[30];
	char arguments;
	/*get parameters*/
	while((arguments=getopt(argc,argv,"ns:l:"))!=-1){
		switch(arguments){ //select mode
			case 'n':
				current=NEW;//play mode
				break;
			case 'l':
				current=LOAD;//load mode
				strncpy(file_name,optarg,30);
				break;
			case 's':
				strncpy(file_name,optarg,30);
				break;
			default:
				break;
		}
	}
	
	switch(current){
		case LOAD: //load mode
		{
			stack *pre_record=NULL;
			read_file(&record,file_name);
			while(true){
				/*get control input*/
				printf("foward=f , back=b : ");
				scanf(" %s",input_str);
				step now;
				/*take action*/
				if(input_str[0]=='f' && !isEmpty(record)){ //move to next step
					now=pop(&record);
					push(&pre_record,now);
					move_chess(board,now.start,now.end,now.promote);
					player=!player;
					system("clear");
					show(board);
				}else if(input_str[0]=='b' && !isEmpty(pre_record)){ //move to previous step
					now=pop(&pre_record);
					push(&record,now);
					regret(board,now,player);
					player=!player;
					system("clear");
					show(board);
				}else if(input_str[0]=='q'){ //quit
					break;
				}
				else{
					printf("invalid\n");
				}
			}
			break;
		}
		case NEW: //play mode
			while(true){
				printf("player %d : ",player);
				fgets(input_str,INPUT_SIZE,stdin);
				if(input_str[0] == 's'){ //save file
					write_file(record,file_name);
				}else if(input_str[0] =='0' && turn >=0){ //regret
					step back = pop(&record);
					regret(board,back,player);
					player = !player;
					turn-=1;
					system("clear");
					show(board);
				}else if(input_str[0] =='q'){ //quit
					break;
				}else{ //regular move
					get_move(&start,&end,input_str);
					
					/*check valid move*/
					if(valid_move(board,start,end,player)){
						CHESS_TYPE capture=board[end.y][end.x].type;
						bool check_promote = false;
						
						/*check if the chess pice can be promoted*/
						if(can_promote(board[start.y][start.x].type,start,end,player)){
							/*ask if the player want to promote the chess pice*/
							printf("Do you want to promote %s ? Yes:1 No:0 :",chess_name[board[start.y][start.x].type]);
							fgets(input_str,INPUT_SIZE,stdin);
							if(input_str[0]=='1')check_promote=true;
						}
						
						move_chess(board,start,end,check_promote); //move the chess pice
						step now={.start=start,.end=end,.promote=check_promote,.capture=capture};
						push(&record,now); //record step
						system("clear");
						show(board);
						if(capture==KING){ //determine if the king has been capture
							printf("Player %d wins \n",player);
							break;
						}
						turn+=1;
						player = !player;
					}else{
						printf("invalid input !\n");
					}
				}
			}
			break;
		default:
			break;
	}
	return 0;
}
