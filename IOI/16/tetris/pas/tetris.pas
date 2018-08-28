unit tetris;

interface

procedure init(n: longint);
procedure new_figure(figure_type: longint);
function get_position(): longint;
function get_rotation(): longint;

implementation

var
    position, rotation: longint;

procedure init(n: longint);
begin	
end;

procedure new_figure(figure_type: longint);
begin	
end;

function get_position(): longint;
begin	
    get_position := position;
end;

function get_rotation(): longint;
begin
	get_rotation := rotation;
end;

end.