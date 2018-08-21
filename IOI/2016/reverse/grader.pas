uses reverse;

var
    n, i: longint;
    a, res: TInt64Array;

begin
	read(n);
	setlength(a, n);
	for i := 0 to n - 1 do begin
		read(a[i]);		
	end;

	res := reverse.reverse(a);

    for i := 0 to n - 1 do begin
		write(res[i], ' ');		
	end;	
	writeln();
end.
