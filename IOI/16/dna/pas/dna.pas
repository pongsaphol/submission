unit dna;

interface

function analyse(n:longint; t: longint) : ansistring;

implementation

uses graderlib;

function analyse(n: longint; t: longint) : ansistring;
begin
    make_test('0');
    analyse := '0';	
end;

end.