unit xylophone_lib;

interface

function query(s, t: longint): longint;
procedure answer(i, a: longint);

implementation

uses xylophone;

const
  QUERY_LIMIT: longint = 10000;

function readLongint(): longint;
begin
  if eof then begin
    writeln(stderr, 'Error while reading input.');
    halt(1);
  end;
  {$I-}
  read(readLongint);
  {$I+}
  if ioresult <> 0 then begin
    writeln(stderr, 'Error while reading input.');
    halt(1);
  end;
end;

procedure WA();
begin
  writeln('Wrong Answer');
  halt(0);
end;

var
  N: longint;
  A_: array of longint;
  answered: array of boolean;
  queryCount, answerCount: longint;

function query(s, t: longint): longint;
var
  min, max: longint;
  i: longint;
begin
  queryCount += 1;
  if queryCount > QUERY_LIMIT then WA();
  if not ((1 <= s) and (s <= t) and (t <= N)) then WA();
  min := N + 1;
  max := 0;
  for i := s to t do begin
    if min > A_[i] then min := A_[i];
    if max < A_[i] then max := A_[i];
  end;
  exit(max - min);
end;

procedure answer(i, a: longint);
begin
  if not ((1 <= i) and (i <= N)) then WA();
  if not ((1 <= a) and (a <= N)) then WA();
  if answered[i] then WA();
  answered[i] := true;
  answerCount += 1;
  if a <> A_[i] then WA();
end;

var
  i: longint;
begin
  N := readLongint;
  setlength(A_, N + 1);
  for i := 1 to N do begin
    A_[i] := readLongint();
  end;
  setlength(answered, N + 1);
  for i := 1 to N do begin
    answered[i] := false;
  end;
  queryCount := 0;
  answerCount := 0;
  solve(N);
  if answerCount <> N then WA();
  writeln('Accepted : ', queryCount);
  halt(0);
end.
