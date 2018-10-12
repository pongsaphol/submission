#include "wirelib.h"
#include <cstdlib>
#include <cstdio>

#define MAX_M 100

#define MAX_CALL 10000000

static int m;

static int conn[MAX_M];
static bool status[MAX_M];

static int ccount;

int wire_init()
{
  scanf("%d",&m);
  for(int i=0; i<m; i++) {
    scanf("%d",&conn[i]);
    conn[i]--;
    status[i] = false;
  }
  ccount = 0;
  return m;
}

static void cmd_check()
{
  ccount++;
  if(ccount > MAX_CALL) {
    printf("too many calls\n");
    exit(0);
  }
}

bool cmd_T(int w)
{
  cmd_check();
  return status[conn[w-1]];
}

bool cmd_C(int s)
{
  cmd_check();
  status[s-1] = !status[s-1];
  return status[s-1];
}

void cmd_D(int sol[])
{
  cmd_check();
  for(int i=0; i<m; i++) {
    printf("%d\n",sol[i+1]);
  }
  exit(0);
}
