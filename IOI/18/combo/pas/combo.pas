unit combo;

interface

function guess_sequence(N: longint): ansistring;

implementation

uses combo_lib;

function guess_sequence(N: longint): ansistring;
var
  p, S: ansistring;
  coins, i: longint;
begin
  p := '';
  for i := 1 to 4 * N do begin
    p += 'A';
  end;
  coins := press(p);
  S := '';
  for i := 1 to N do begin
    S += 'A';
  end;
  exit(S);
end;

end.
