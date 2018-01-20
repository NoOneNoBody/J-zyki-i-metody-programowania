//Wykonał Michał Warzecha I rok Informatyka EAIIB grupa 6b
#include "pong.h"

_pong_ PONG = {
  .x = 0,
  .y = 0,
  .vel_x = 0*x_multiplier,
  .vel_y = 0,
  .acc_x = 0,
  .acc_y = 0,
  .gravity = 7,
  .rezistance = 0.9,
  .bouncines = 1
};

_paddle_ PADDLE = {
  .x = 0,
  .y = 12,
  .max_y = 20,
  .min_y = 10,
  .height = 3
};

_paddle_ PADDLE_AI = {
  .x = 30*x_multiplier,
  .y = 12,
  .max_y = 20,
  .min_y = 10,
  .height = 3
};

_table_ TABLE = {
  .min_x = 0,
  .min_y = 0,
  .max_x = 30.0*x_multiplier,
  .max_y = 20,
  .left_net = (15.0*x_multiplier)-1,
  .right_net = (15.0*x_multiplier)+1,
  .net_hight = 2
};

void pong_physics(_pong_* PONG);
void paddle_collision(_paddle_* PADDLE, _pong_* PONG, int side);
void net_collision(_pong_* PONG, _table_* TABLE);
void table_collision(_pong_* PONG, _table_* TABLE);
void ai_controll(_pong_* PONG, _paddle_* PADDLE_AI);

void Initialise(void)
{
  setlocale(LC_ALL, "");
  initscr();
  raw();
  noecho();
  scrollok(stdscr, TRUE);
  nodelay(stdscr, TRUE);
  keypad(stdscr, TRUE);
  curs_set(FALSE);
}

void GamePhysics(_pong_* PONG, _paddle_* PADDLE, _paddle_* PADDLE_AI, _table_* TABLE)
{
  paddle_collision(PADDLE, PONG, 1);
  paddle_collision(PADDLE_AI, PONG, -1);
  net_collision(PONG, TABLE);
  table_collision(PONG, TABLE);
  pong_physics(PONG);
  paddle_movement(PADDLE);
  ai_controll(PONG, PADDLE_AI);
  PONG->x += PONG->vel_x*SPEED;
  PONG->y += PONG->vel_y*SPEED;
  PONG->acc_x *= 0;
  PONG->acc_y *= 0;
}

void pong_physics(_pong_* PONG)
{
  PONG->rezistance = pow(0.9, DELAY);
  PONG->acc_y += PONG->gravity;
  PONG->vel_x += PONG->acc_x*SPEED;
  PONG->vel_y += PONG->acc_y*SPEED;
  PONG->vel_x *= PONG->rezistance;
  PONG->vel_y *= PONG->rezistance;
  PONG->x += PONG->vel_x*SPEED;
  PONG->y += PONG->vel_y*SPEED;
  PONG->acc_x *= 0;
  PONG->acc_y *= 0;
}

void paddle_movement(_paddle_* PADDLE)
{
  PADDLE->y += check_keys()[1];
}

void net_collision(_pong_* PONG, _table_* TABLE)
{
  if(((int)PONG->x==TABLE->left_net || ((int)PONG->x==TABLE->left_net+1 && PONG->vel_x>0))&&(PONG->y>=(int)TABLE->max_y-1 && PONG->y<=(int)TABLE->max_y+1))
  {
    PONG->vel_x = -abs(PONG->vel_x)*PONG->bouncines;
  }
  if(((int)PONG->x==TABLE->right_net || ((int)PONG->x==TABLE->right_net-1 && PONG->vel_x<0))&&(PONG->y>=(int)TABLE->max_y-1 && PONG->y<=(int)TABLE->max_y+1))
  {
    PONG->vel_x = abs(PONG->vel_x)*PONG->bouncines;
  }
}

void table_collision(_pong_* PONG, _table_* TABLE)
{
  if(PONG->x<TABLE->min_x)
  {
    GameOver(winner);
  }
  if(PONG->y<TABLE->min_y)
  {
    PONG->vel_y = abs(PONG->vel_y)*PONG->bouncines;
    PONG->y = TABLE->min_y;
  }
  if(PONG->x>TABLE->max_x)
  {
    GameOver(winner);
  }
  if(PONG->y>TABLE->max_y)
  {
	if(PONG->x>=TABLE->right_net)
	{
	  if(winner == 1)
	  {
	    GameOver(winner);
	  }
	  else if(winner == -1)
	  {
	    winner = 1;
	  }
	}
	if(PONG->x<TABLE->right_net-1)
	{
	  if(winner == -1)
	  {
	    GameOver(winner);
	  }
	  else if(winner == 1)
	  {
	    winner = -1;
	  }
	}
    PONG->vel_y = (-abs(PONG->vel_y)*PONG->bouncines);
    PONG->y = TABLE->max_y;
  }
}

void paddle_collision(_paddle_* PADDLE, _pong_* PONG, int side)
{
  if(PONG->y>=(int)PADDLE->y && PONG->y<((int)PADDLE->y+PADDLE->height+1))
  {
	if(side == 1 && PONG->x<PADDLE->x)
	{
	  if(winner == 1)
	  {
	    GameOver(winner);
	  }
	  PONG->x = PADDLE->x;
      PONG->vel_x = ((rand()%20/10.0)+8)*x_multiplier;
	  PONG->vel_y = -4+PONG->y-PADDLE->y;
	}
	else if(side == -1 && PONG->x>PADDLE->x)
	{
	  if(winner == -1)
	  {
	    GameOver(winner);
	  }
	  PONG->x = PADDLE->x;
      PONG->vel_x = -((rand()%20/10.0)+8)*x_multiplier;
	  PONG->vel_y = -5+PONG->y-PADDLE->y;
	}
  }
}

void draw_pong(_pong_* PONG)
{
  mvprintw((int)PONG->y,(int)PONG->x,"o");
}

void draw_paddle(_paddle_* PADDLE)
{
  if(PADDLE->y > PADDLE->max_y)
  {
    PADDLE->y = PADDLE->max_y;
  }
  if(PADDLE->y < PADDLE->min_y)
  {
    PADDLE->y = PADDLE->min_y;
  }
  for(int i=0;i<PADDLE->height;++i)
  {
    mvprintw((int)PADDLE->y+i,(int)PADDLE->x,"|");
  }
}

void draw_table(_table_* TABLE)
{
  for(int i=0;i<=TABLE->max_x+1;++i)
  {
	if(i==TABLE->right_net-1)
	{
      for(int j=0;j<TABLE->net_hight;++j)
	  {
		mvprintw(TABLE->max_y-j,i,"|");
	  }
	}
    mvprintw(TABLE->max_y+1,TABLE->max_x-i,"\u2588");
	mvprintw(8,i,"\u2588");
  }
}

int ai_delta = 0;

void ai_controll(_pong_* PONG, _paddle_* PADDLE_AI)
{
  ++ai_delta;
  if(ai_delta<10)
  {
    return;
  }
  ai_delta = 0;
  if((int)PONG->y > (int)PADDLE_AI->y)
  {
    PADDLE_AI->y += (rand()%30)/10.0;
  }
  if((int)PONG->y < (int)PADDLE_AI->y)
  {
    PADDLE_AI->y += -(rand()%30)/10.0;
  }
}

void draw_UI(void)
{
  char* line_to_print;
  if(Opponent_points >= 11 && (Opponent_points-Player_points) >= 2)
  {
	isPlay = 0;
	isEnd = 1;
	round_counter = 0;
	line_to_print = "Przegrales";
    mvprintw(5,(int)(TABLE.max_x/2)-(int)(strlen(line_to_print)/2),"%s",line_to_print);
	line_to_print = "Przycisnij spacje by zagrac ponownie";
    mvprintw((int)TABLE.max_y/2,(int)(TABLE.max_x/2)-(int)(strlen(line_to_print)/2),"%s",line_to_print);
  }
  else if(Player_points >= 11 && (Player_points-Opponent_points) >= 2)
  {
	isPlay = 0;
	isEnd = 1;
	round_counter = 0;
	line_to_print = "Wygrales";
    mvprintw(5,(int)(TABLE.max_x/2)-(int)(strlen(line_to_print)/2),"%s",line_to_print);
	line_to_print = "Przycisnij spacje by zagrac ponownie";
    mvprintw((int)TABLE.max_y/2,(int)(TABLE.max_x/2)-(int)(strlen(line_to_print)/2),"%s",line_to_print);
  }
  else if(isPlay==0)
  {
	if((round_counter/2)%2==0)
	{
	  line_to_print = "Przycisnij spacje by zaserwowac";
	}
	else if((round_counter/2)%2==1)
	{
	  line_to_print = "Przycisnij spacje by przeciwnik zaserwowal";
	}
    mvprintw((int)TABLE.max_y/2,(int)(TABLE.max_x/2)-(int)(strlen(line_to_print)/2),"%s",line_to_print);
  }
  line_to_print = " _   _        _ ";
  mvprintw(0,(int)(TABLE.max_x/2)-(int)(strlen(line_to_print)/2),"%s",line_to_print);
  line_to_print = "|_| | | |\\ | |  ";
  mvprintw(1,(int)(TABLE.max_x/2)-(int)(strlen(line_to_print)/2),"%s",line_to_print);
  line_to_print = "|   |_| | \\| |_|";
  mvprintw(2,(int)(TABLE.max_x/2)-(int)(strlen(line_to_print)/2),"%s",line_to_print);
  mvprintw(TABLE.max_y/2-6,TABLE.max_x/2-20,"%d",Player_points);
  mvprintw(TABLE.max_y/2-6,TABLE.max_x/2+20,"%d",Opponent_points);
}

void GameOver(int winner)
{
  isPlay = 0;
  ++round_counter;
  PADDLE_AI.y = rand()%5+11;
  if(winner == -1)
  {
	++Opponent_points;
  }
  else if(winner == 1)
  {
	++Player_points;
  }
}

int* check_keys(void)
{
  int* direction = (int*)malloc(2*sizeof(int));
  direction[0]=0;
  direction[1]=0;
  char input = getch();
  if (input == 'w') 
  {
    direction[1] = -1;
  }
  if (input == 's') 
  {
    direction[1] = 1;
  }
  if (input == 'a') 
  {
    direction[0] = -1;
  }
  if (input == 'd') 
  {
    direction[0] = 1;
  }
  if (input == ' ') 
  {
    isPlay = 1;
	if(isEnd)
	{
	  Player_points = 0;
      Opponent_points = 0;
	  isEnd = 0;
	}
  }
  if (input == 'q') 
  {
    endwin();
    exit(0);
  }
  return direction;
}