unit graderlib;

interface

function make_test(p: ansistring) : boolean;
                  
// For grader only

function __get_tests() : longint;
procedure __init(ss: ansistring);

implementation

var
    s: ansistring;
    tests: longint;

function __get_tests() : longint;
begin
    __get_tests := tests;    
end;

procedure __init(ss: ansistring);
begin
   s := ss;    
   tests := 0;
end;

function make_test(p: ansistring) : boolean;
var
    ss: ansistring;
    pr: array of longint;
    answer: boolean;
    i, k: integer;
begin
    inc(tests);
    for i := 1 to length(p) do begin
        if (p[i] <> '0') and (p[i] <> '1') then begin
            make_test := false;
            exit;
        end;
    end;

    ss := p + '#' + s;
     
    setlength(pr, length(ss) + 1);
    pr[0] := -1;
    answer := false;
    for i := 1 to length(ss) do begin
        k := pr[i - 1];
        while (k >= 0) and (ss[k + 1] <> ss[i]) do
            k := pr[k];
        pr[i] := k + 1;
        if (pr[i] = length(p)) then begin
            answer := true;
            break;
        end;
    end;

    //writeln(ss, ' ', answer);

    make_test := answer;    
end;

end.