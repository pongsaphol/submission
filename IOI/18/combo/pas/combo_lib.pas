unit combo_lib;

interface

function press(p: ansistring): longint;

implementation

uses combo;

const
  MAX_NUM_MOVES: longint = 8000;

var
  N: longint;
  S: ansistring;
  num_moves: longint;

procedure wrong_answer(MSG: ansistring);
begin
  writeln('Wrong Answer: ', MSG);
  halt(0);
end;

function press(p: ansistring): longint;
var
  len, coins, i, j: longint;
begin
  num_moves += 1;
  if num_moves > MAX_NUM_MOVES then begin
    wrong_answer('too many moves');
  end;
  len := length(p);
  if len > 4 * N then begin
    wrong_answer('invalid press');
  end;
  for i := 1 to len do begin
    if (p[i] <> 'A') and (p[i] <> 'B') and (p[i] <> 'X') and (p[i] <> 'Y') then begin
      wrong_answer('invalid press');
    end;
  end;
  coins := 0;
  j := 0;
  for i := 1 to len do begin
    if (j + 1 <= N) and (S[j + 1] = p[i]) then begin
      j += 1;
    end else if S[1] = p[i] then begin
      j := 1;
    end else begin
      j := 0;
    end;
    if coins < j then begin
      coins := j;
    end;
  end;
  exit(coins);
end;

var
  answer: ansistring;
begin
  if eof then begin
    writeln(stderr, 'Error while reading input');
    halt(1);
  end;
  {$I-}
  read(S);
  {$I+}
  if ioresult <> 0 then begin
    writeln(stderr, 'Error while reading input');
    halt(1);
  end;
  N := length(S);

  num_moves := 0;
  answer := guess_sequence(N);
  if answer <> S then begin
    wrong_answer('wrong guess');
  end;
  writeln('Accepted: ', num_moves);
end.
