unit graderlib;
interface
function Guess(x: longint): longint;
implementation
uses gradershare;
   function Guess(x: longint): longint;
   begin
      if (prev = -1) or (abs(x-TT) = abs(prev-TT)) then Guess := 0
      else if abs(x-TT)>abs(prev-TT) then guess := -1
      else Guess := 1;
      prev := x;
      if (x < 1) or (x > NN) then begin
         halt(92);
      end;
      moves := moves + 1;
   end;
begin
end.
