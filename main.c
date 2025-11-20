#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h" 

#define MAXLENGTH    30 //이름 길이 최대 30자 
#define MAX_DIE      6
#define N_PLATER     3

#define PLAYERSTATUS_LIVE   0
#define PLAYERSTATUS_DIE    1
#define PLAYERSTATUS_END    2

#define MAX_SHARKSTEP   6
#define SHARK_INITPOS  -4

//플레이어 이름 저장 
char player_name[N_PLAYER][MAXLENGTH]; //여러명이라서 2차원 배열 
int player_position[N_PLATER];
int player_coin[N_PLATER];
int player_status[N_PLATER]; //각 플레이어별로 죽었는지 살았는지 이런거 상태 저장 필요 
char player_statusString[3][MAXLENGTH] = {"LIVE", "DIE", "END"}; 
//0,1,2로 나오면 헷갈리니까 문자열로 나오게 하는 것 

void printPlayerPosition(int player)
{
     int i;
     for (i=0;i<N_BOARD;i++)
     {
         printf("|");
         if(i == player_position[player])
         {
              printf("%c", player_name[player][0]);
          }
          else
          {
              if (board_getBoardStatus(i) == BOARDSTATUS_OK)
                  printf(" ");
              else
                  printf("X");
          }
      }
     printf("|\n");
 }

void printPlayerStatus(void)
{
     int i;
     for(i=0;i<N_PLAYER;i++);
     {
        printf("%s : pos %i, coin : %i, status : %s\n", player_name[i], player_position[i], player_coin[i], player_statusString[player_status[i]]);
        printPlayerPosition(i)
     }
}


void initPlayer(void)
{
     int i;
     for(i=0;i<N_PLAYER;i++)
     {
         player_position[i] = 0; //position 0으로 세팅 
         player_coin[i] = 0;
         player_status[i] = PLAYERSTATUS_LIVE;
         printf("player %i's name: ", i);
         scanf("%s", player_name[i]);
         fflush(stdin); //얠 넣으면 동작이 더 깔끔하게 됨. 
     }
 }

//주사위 굴리는 함수 
int rolldie(void)
{
    return rand()%MAX_DIE + 1;
}

int main(int argc, char *argv[])
{
  int cnt; 
  int turn;
  int dum;
  int coinResult;
  
  srand((unsigned) (time(NULL))); //한번 실행 해줘야됨. 
  //random한 값이 바로바로 나오도록 해줌.  
  
  
  //opening
  printf("=====================================\n");
  printf("*************************************\n");
  printf("        <<SHARK ISLAND GAME>>        \n");
  printf("*************************************\n");
  printf("=====================================\n\n\n");
  
  //게임 구성 계획짜기 (요런식으로 할거다라는 의미) 
  //step 1. initialization (플레이어 이름 세팅, variavles)
  board_initBoard();
  init_player();
  //player init
   
  
  //step 2. 본격적 게임 시작(do-while 반복문 사용)
  cnt = 0; //0으로 초기화 
  turn = 0;
  int coinReslut = 0;
  do {
      int die_result;
      int coinResult; 
      
      // 2-1. status printing
      board_printBoardStatus();
      
    
      //player status (각자) 
      printPlayerStatus()
      
      // 2-2. roll die(규칙)
      printf("%s turn!! ", player_name[turn]);
      printf("Press any key to roll a die!!\n");
      scanf("%d", &dum)
      fflush(stdin);
      die_result = rolldie(); //player turn
  
      // 2-3. move(result) //player turn
      player_position[turn] += die_result;
      if (player_position[turn] >= N_BOARD - 1)
      {
          player_position[turn] = N_BOARD - 1;
          player_status[turn] = PLAYERSTATUS_END;
      }
      
      printf("Die result : %i, %s moved to %i\n", die_result, player_name[turn], player_position[turn]); //코인을 이만큼 얻었다.
  
      #if 0
      coinResult += board_getBoardCoin(pos); //요기 위치에 있는 코인 가져옴. 
      printf("coin : %i\n", coinResult); //코인을 이만큼 얻었다. 
      #endif
      
      // 2-4. change turn, shark move 
      //change turn
      turn = (turn + 1)%N_PLAYER;
      
      //shark move
      cnt++;
      
      
      } while(cnt < 5); //game end condition 
  
  //step 3. game end(이긴 사람 알려주기) - 반복문에서 벗어나면 끝 
  
  //ending
  printf("\n\n\n\n\n\n\n\n\n\n");
  printf("====================================\n");
  printf("************************************\n");
  printf("                                    \n");
  printf("               THE END              \n");
  printf("                                    \n");
  printf("************************************\n");
  printf("====================================\n\n");
  
  system("PAUSE");
  return 0;
}
