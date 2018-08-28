uses tetris, CTypes;

var
    n, i: longint;
    a: array of longint;

begin
	read(n);
	setlength(a, n);
	for i := 0 to n - 1 do begin
		read(a[i]);		
	end;

	init(n);
	for i := 0 to n - 1 do begin
		new_figure(a[i]);
		writeln(get_position(), ' ', get_rotation);		
	end;	
end.
