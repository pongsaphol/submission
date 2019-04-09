#include "hollib.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>

#define MAX_N 5000

#define HOL_UNINIT    0
#define HOL_INIT      1
#define HOL_READINPUT 2
#define HOL_ANSWERED  3

static int m;
static int n;
static int wcounter = 0;
static char coins[MAX_N];
static int state = HOL_UNINIT;
static bool used[MAX_N];
static int expected_result;

static void hol_die()
{
  printf("Wrong interation.  Program terminated.\n");
  exit(0);
}

int hol_init_all()
{
  if(state != HOL_UNINIT)
    hol_die();

  scanf("%d",&m);

  state = HOL_INIT;

  return m;
}

int hol_init()
{
  if((state != HOL_INIT) && (state != HOL_ANSWERED))
    hol_die();

  scanf("%s",coins);
  n = strlen(coins);
  wcounter = 0;

  expected_result = 0;
  for(int i=0; i<n; i++) {
    if(coins[i] == 'H')
      expected_result = 1;
    if(coins[i] == 'L')
      expected_result = 2;
  }
  
  state = HOL_READINPUT;
  
  return n;
}

int hol_weight(int lcount, int llist[],
               int rcount, int rlist[])
{
  if(state != HOL_READINPUT)
    hol_die();

  wcounter++;

  if(lcount > rcount)
    return -1;
  if(rcount > lcount)
    return 1;

  for(int i=0; i<n; i++)
    used[i] = false;

  int lw, rw;

  lw = 0;
  rw = 0;
  for(int i=0; i<lcount; i++) {
    if((llist[i] < 0) || (llist[i] > n-1))
      hol_die();

    if(used[llist[i]])
      hol_die();

    used[llist[i]] = true;
    if(coins[llist[i]] == 'H')
      lw += 1;
    if(coins[llist[i]] == 'L')
      lw -= 1;
  }

  for(int i=0; i<rcount; i++) {
    if((rlist[i] < 0) || (rlist[i] > n-1))
      hol_die();

    if(used[rlist[i]])
      hol_die();

    used[rlist[i]] = true;
    if(coins[rlist[i]] == 'H')
      rw += 1;
    if(coins[rlist[i]] == 'L')
      rw -= 1;
  }

  if(lw > rw)
    return -1;
  else if(lw == rw)
    return 0;
  else
    return 1;
}

void hol_answer(int result)
{
  if(state != HOL_READINPUT)
    hol_die();

  state = HOL_ANSWERED;
  
  if(result == expected_result)
    printf("Correct (%d)\n",wcounter);
  else
    printf("Incorrect (%d)\n",wcounter);
}

