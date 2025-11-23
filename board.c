#if 0 //어떤게 있으면 좋을지 작성 (컴파일 안되게 하기) 
int board_initBoard(void); //했다 
int board_getBoardStatus(int pos); //했다 
int board_getSharkPosition(void); 
int board_stepShark(void);
int board_getBoardCoin(int pos); //했다 
void board_printBoardStatus(void); //했다 
#endif 

#include "board.h"

#define N_BOARD          20 //몇 칸 할지 정하는 거 
#define BOARDSTATUS_OK   1 //상어에 의해서 파손 or 안 파손. 
#define BOARDSTATUS_NOK  0

#include "board.h"

#define N_COINPOS        12
#define MAX_COIN         4 
#define MAX_SHARKSTEP    6
#define SHARK_INITPOS    -4 

//전역변수 사용 
static int board_status[N_BOARD];
static int board_coin[N_BOARD];
static int shark_position;

//ㅎㅎ 
int board_stepShark(void)
{
    int step = rand()%MAX_SHARKSTEP + 1;
    int i;
    for (i=0;i<step;i++);
    { //board칸 하나씩 부심 
        int posIdx = shark_position + i + 1; //0부터 안 시작하게 +1 해주기 
        if (posIdx >= 0) //윗줄 문제 안 생기게 방어 코드  
        board_status[posIdx] = BOARDSTATUS_NOK;
    }
    shark_position += step; //shark position 갱신  
}

void board_printBoardStatus(void)
{
     int i;
     
     printf("-----------------BOARD STATUS--------------\n");
     for (i=0;i<N_BOARD;i++)
     {
         printf("|");
         if (board_getBoardStatus(i) == BOARDSTATUS_NOK)
             printf("X");
         else
             printf("O");
      }
     printf("|\n");
     printf("-------------------------------------------\n");
     
     printf("-----------------BOARD COIN----------------\n");
     for (i=0;i<N_BOARD;i++)
     {
         printf("|");
      }
     printf("|\n");
     printf("-------------------------------------------\n");
}


//보드 정보 제공 
int board_getBoardStatus(int pos)
{
     return board_status[pos];
}

int board_getBoardCoin(int pos)
{
    int coin = board_coin[pos];
    board_coin[pos] = 0;
    return coin = 0;
    return board_coin[pos];
}

void board_initBoard(void) //지금은 반환할게 없어서 void 
{
    int i;
    
    shark_position = SHARK_INITPOS;
    
    //initialize arrays
    for (i=0;i<N_BOARD;i++)
    {
        board_status[i] = BOARDSTATUS_OK;
        board_coin[i] = 0;
    }
    //allocate coins 코인 할당
    for (i=0;i<N_BOARD;i++)
    {
        int flag_allocated = 0; //할당되면 1 안되면 0 
        do {
            int coinpos = rand()%N_BOARD;
            if (board_coin[coinpos] == 0)
            { //코인 할당하는 동작 
                board_coin[coinpos] = rand()%MAX_COIN + 1; //COINMAX 안 넘기게 랜덤으로 코인  넣어줌. 
                flag_allocated = 1;
            } 
        } while(flag_allocated == 0); //코인 할당 했으면 여기 함수에서 나가도돼 
    }
}
