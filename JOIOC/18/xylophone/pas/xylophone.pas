unit xylophone;

interface

procedure solve(N: longint);

implementation

uses xylophone_lib;


procedure solve(N: longint);
var
  x: longint;
  i: longint;
begin
  x := query(1, N);
  for i := 1 to N do begin
    answer(i, i);
  end;
end;


end.
