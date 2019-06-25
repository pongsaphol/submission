program grader;
   uses math,gradershare, hottercolder;
   var h,n,i,t,OK,sub1,sub2,sub3: longint;
   var alpha,W,worst: real;
begin
   OK := 0; sub1:=0; sub2:=0;sub3:=0;
   worst:= 999999;
   TT := 0;
   NN := 0;
   n := 0;
   while not eof do begin
      readln(NN,TT);
      if NN > n then n := NN;
      prev := -1;
      moves := 0;
      h := HC(NN);
      if h <> TT then begin
         halt(91);
      end;
      W := floor(0.00001+ln(3*NN)/ln(2));
      alpha := 2 - moves/W;
      if alpha < worst then worst := alpha;
      if (NN<=500) and (moves>500)  then halt(93);
      if (NN<=500) and (moves>18) then sub2 := 1;
      if (NN<=500) and (moves>16) then sub3 := 1;
   end;
   if sub1 = 0 then writeln('OK 1');
   if sub2 = 0 then writeln('OK 2');
   if sub3 = 0 then writeln('OK 3');
   if (worst > 0) then writeln('OK 4 alpha ',worst:0:2);
end.
