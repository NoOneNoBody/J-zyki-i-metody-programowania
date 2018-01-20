//Wykonał Michał Warzecha I rok Informatyka EAIIB grupa 6b
#include <stdlib.h>
#include <time.h>
#include "pong.h"


void Start(void);
void FixedUpdate(void);
void Update(void);

void Start()
{
  isPlay = 0;
  isEnd = 0;
  round_counter = 0;
  winner = -1;
  Player_points = 0;
  Opponent_points = 0;
}

void FixedUpdate()
{
  if(isPlay)
  {
    GamePhysics(&PONG, &PADDLE, &PADDLE_AI, &TABLE);
  }
  else
  {
    if((round_counter/2)%2==0)
    {
      winner = -1;
      PONG.x = PADDLE.x;
      PONG.y = PADDLE.y+1;
      PONG.vel_x = 10*x_multiplier;
    }
    else if((round_counter/2)%2==1)
    {
      winner = 1;
      PONG.x = PADDLE_AI.x;
      PONG.y = PADDLE_AI.y+1;
      PONG.vel_x = -10*x_multiplier;
    }
    PONG.vel_y = -3;
  }
}

void Update()
{
  draw_table(&TABLE);
  draw_paddle(&PADDLE);
  draw_paddle(&PADDLE_AI);
  draw_pong(&PONG);
  draw_UI();
  paddle_movement(&PADDLE);
  check_keys();
}

void RunGame(int argc, char **argv)
{
  struct timespec tstart={0,0};
  clock_gettime(CLOCK_MONOTONIC, &tstart);
  double delta = 0;
  double last_time = ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec);
  
  if(argc>1)
  {
    PONG.vel_x = strtol(argv[1],NULL,10)*x_multiplier;
  }
  else
  {
    PONG.vel_x = 8*x_multiplier;
  }
  Start();
  while(1)
  {
    clock_gettime(CLOCK_MONOTONIC, &tstart);
    double current_time = ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec);
    delta = current_time - last_time;
    clear();
    Update();
    if(delta > DELAY)
    {
      last_time = current_time;
      FixedUpdate();
    }
    refresh();
  }
}

int main(int argc, char **argv)
{
  Initialise();
  RunGame(argc,argv);

  endwin();
  return 0;
}
