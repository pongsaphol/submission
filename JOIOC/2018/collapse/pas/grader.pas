program grader;

uses collapse;

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

var
  N, C, Q: longint;
  T, X, Y, W, P: array of longint;
  answer: array of longint;
  i, j: longint;
begin
  N := readLongint();
  C := readLongint();
  Q := readLongint();
  setlength(T, C);
  setlength(X, C);
  setlength(Y, C);
  for i := 0 to C - 1 do begin
    T[i] := readLongint();
    X[i] := readLongint();
    Y[i] := readLongint();
  end;
  setlength(W, Q);
  setlength(P, Q);
  for j := 0 to Q - 1 do begin
    W[j] := readLongint();
    P[j] := readLongint();
  end;
  answer := simulateCollapse(N, T, X, Y, W, P);
  for j := low(answer) to high(answer) do begin
    writeln(answer[j]);
  end;
end.
