
unit collapse;

interface

type
  ArrayOfLongint = array of longint;

function simulateCollapse(N: longint; T, X, Y, W, P: ArrayOfLongint): ArrayOfLongint;

implementation


function simulateCollapse(N: longint; T, X, Y, W, P: ArrayOfLongint): ArrayOfLongint;
var
  i: longint;
  answer: array of longint;
begin
  setlength(answer, length(W));
  for i := 0 to length(W) - 1 do answer[i] := N;
  exit(answer);
end;


end.
