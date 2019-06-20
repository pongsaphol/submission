
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define inbuf_len 1 << 16
#define outbuf_len 1 << 16

void Init();
void TypeLetter(char L);
void UndoCommands(int U);
char GetLetter(int P);

int main() {
  Init();

  int cmd_num;
  tmp = scanf("%d", &cmd_num);
  assert(tmp == 1);

  int i;
  for (i = 0; i < cmd_num; i++) {
    char cmd;
    tmp = scanf(" %c", &cmd);
    assert(tmp == 1);
    if (cmd == 'T') {
      char letter;
      tmp = scanf(" %c", &letter);
      assert(tmp == 1);
      TypeLetter(letter);
    }
    else if (cmd == 'U') {
      int number;
      tmp = scanf("%d", &number);
      assert(tmp == 1);
      UndoCommands(number);
    }
    else if (cmd == 'P') {
      int index;
      char letter;
      tmp = scanf("%d", &index);
      assert(tmp == 1);
      letter = GetLetter(index);
      printf("%c\n", letter);
    }
  }
  
  puts("Let's test for cheating!!");

  return 0;

}
