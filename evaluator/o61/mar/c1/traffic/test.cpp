#include "traffic.h"
#include <vector>
#include <iostream>

using namespace std;

int n,k;

main()
{
  traffic_init(&n,&k);
  int res = traffic_query(1,1,5,2);
  traffic_report(1,1,2,1, 0,0,0,0);
}
