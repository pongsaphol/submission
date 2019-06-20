
#include "assistant.h"

void Assist(unsigned char *A, int N, int K, int R) {

  int i;
  for (i = 0; i < N; i++) {
    int req = GetRequest();
    if (req >= K)
      PutBack(req % K);
  }

}
