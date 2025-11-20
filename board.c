#if 0
int board_getSHarkPosition(void);
int board_stepShark(void);
#endif

#define N_BOARD         20 //몇 칸 할지 정하는 거 
#define BOARDSTATUS_OK   1 //상어에 의해서 파손 or 안 파손. 
#define BOARDSTATUS_NOK  0
#define N_COINPOS       12
#defien MAX_COIN         4

static int board_status[N_BOARD];
static int board_coin[N_BOARD];
static int shark_position;

void board_printBoardStatus(void)
{
     int i;
     
     printf("-----------------BOARD STATUS--------------\n");
     for (i=0;i<N_BOARD;i++)
     {
         printf("|");
         if (board_status[i] == BOARDSTATUS_NOK)
             printf("X");
         else
             printf("O");
      }
     printf("|\n");
     printf("-------------------------------------------\n");
     
     printf("----------------BOARD COIN-----------------\n");
     
     
}

void board_getBoardStatus(int pos)
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

int board_initBoard(void)
{
    int i;
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
            {
                board_coin[coinpos] = rand()%MAX_COIN + 1;
                flag_allocated = 1;
            } 
            } while(flag_allocated == 0); //코인 할당 했으면 여기 함수에서 나가도돼 
}
