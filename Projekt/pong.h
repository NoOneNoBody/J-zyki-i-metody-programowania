//Wykonał Michał Warzecha I rok Informatyka EAIIB grupa 6b
#ifndef _PONG_H_
#define _PONG_H_

#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <unistd.h>
#include <locale.h>
#include <math.h>
#include <string.h>

#define _BSD_SOURCE
#define DELAY 0.01
#define SPEED 1.5*DELAY
#define x_multiplier 2.2

typedef struct
{
  double x, y;
  double vel_x, vel_y;
  double acc_x, acc_y;
  double gravity;
  double rezistance;
  double bouncines;
}_pong_;

typedef struct
{	
  double x, y;
  double max_y, min_y;
  double height;
}_paddle_;

typedef struct
{
  int min_x, min_y;
  int max_x, max_y;
  int left_net,right_net;
  int net_hight;
}_table_;

extern _pong_ PONG;
extern _paddle_ PADDLE;
extern _paddle_ PADDLE_AI;
extern _table_ TABLE;

int isPlay;
int winner;
int round_counter;
int player_points;
int opponent_points;
int isEnd;

void Initialise(void);
void GamePhysics(_pong_* PONG, _paddle_* PADDLE, _paddle_* PADDLE_AI, _table_* TABLE);
void paddle_movement(_paddle_* PADDLE);
void draw_UI(void);
void draw_pong(_pong_* PONG);
void draw_paddle(_paddle_* PADDLE);
void draw_table(_table_* TABLE);
int* check_keys(void);
void GameOver(int winner);

#endif