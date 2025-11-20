#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"
#define 
//주사위 굴리는 함수 
int rolldie(void)
{
    return rand()%MAX_DIE + 1;
}

//게임 시작 및 종료를 알리는 출력 
int main(int argc, char *argv[])
{
  int
  int
  
  srand((unsigned) (time(NULL))); //한번 실행 해줘야됨. 
  //random한 값이 바로바로 나오도록 해줌.  
  
  
  //opening
  printf("====================================\n");
  printf("************************************\n");
  printf("        <<SHARK ISLAND GAME>>       \n");
  printf("************************************\n");
  printf("====================================\n\n\n");
  
  //게임 구성 계획짜기 (요런식으로 할거다라는 의미) 
  //step 1. initialization (플레이어 이름 세팅, variavles)
  int board_initBoard();
  
  //step 2. 본격적 게임 시작(do-while 반복문 사용)
  cnt = 0;
  pos = 0;
  int coinReslut = 0;
  do {
      int die_result;
      
  // 2-1. status printing
  board_printBoardStatus();
  
  // 2-2. roll die(규칙)
  die_result = rolldie();
  
  // 2-3. move(result)
  pos += die_result;
  
  printf("pos : %i (die:roll) \n"); //코인을 이만큼 얻었다.
  
  coinResult = board_getBoardCoin(pos);
  
  printf("coin : %i\n", coinResult); //코인을 이만큼 얻었다. 
  // 2-4. change turn, shark move 
  cnt ++;
} while(cnt < 5);
  
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
