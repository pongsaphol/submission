unit hottercolder;
interface
   function HC(N: longint):longint; 
implementation
   uses graderlib;
   function HC(N: longint):longint; 
      var g: longint;
   begin
      g := Guess(1);
      g := Guess(N);
      if g = 0 then HC := N div 2
      else if g < 0 then HC := N div 4
      else HC := 3*N div 4 
   end;
begin
end.
