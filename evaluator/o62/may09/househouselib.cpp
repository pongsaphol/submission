#include <cstdio>
#include <cstdlib>

static int house_C, house_M, house_N;
static int day_passed;
static int amount_paid;

void househouse_init(int& C, int& M)
{
  scanf("%d %d %d", &house_C, &house_M, &house_N);
  C = house_C;
  M = house_M;

  day_passed = 0;
  amount_paid = 0;
}

void househouse_pay(int amount)
{
  day_passed++;
  if((amount != 1) && (amount != house_C)) {
    printf("Incorrect amount\n");
    exit(0);
  }
  
  amount_paid += amount;

  if((day_passed == house_N) || (amount == house_C)) {
    printf("You paid %d\n", amount_paid);
    exit(0);
  }
}
