unit reverse;

interface

type 
	TInt64Array = array of int64;

function reverse(a: TInt64Array): TInt64Array;

implementation

function reverse(a: TInt64Array): TInt64Array;
var
  res: TInt64Array;
begin
	setLength(res, length(a));
	reverse := res;
end;

end.