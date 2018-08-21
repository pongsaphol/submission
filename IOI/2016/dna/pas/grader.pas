uses graderlib, dna, CTypes;

var
    s, ans: ansistring;
    t: longint;

begin
	readln(s);
	readln(t);
	__init(s);	
	ans := analyse(length(s), t);

	writeln(__get_tests());
	writeln(ans);
end.
