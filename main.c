#include <stdio.h>
#include <stdlib.h>
//1. 구현 시작
//게임 시작 및 종료를 알리는 출력 
int main(int argc, char *argv[])
{
  
  srand((unsigned) (time(NULL))); //한번 실행 해줘야됨. 
  //random한 값이 바로바로 나오도록 해줌.  
  
  printf("====================================\n");
  printf("************************************\n");
  printf("           <<BINGO GAME>>           \n");
  printf("************************************\n");
  printf("====================================\n\n\n");
  
  printf("\n\n\n\n\n\n\n\n\n\n");
  printf("====================================\n");
  printf("************************************\n");
  printf("            !!축하합니다!!          \n");
  printf("            !!!!BINGO!!!!!          \n");
  printf("            !!!YOU WIN!!!!          \n");
  printf("************************************\n");
  printf("====================================\n\n");
  
  system("PAUSE");	
  return 0;
}
