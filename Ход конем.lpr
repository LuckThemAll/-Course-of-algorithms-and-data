program project1;

{$mode objfpc}{$H+}

uses
  sysutils;

var
  isFound: Boolean;
  n, m, k, l, min: Integer;
  Answer: String;

procedure FindWay(X, Y: integer; Way: string);
begin
  if Length(Way) >= 3*n*m then begin
    isFound := True;
    Answer := Way;
    Exit;
  end;
  if isFound then exit;
  if pos(chr(X + 65) + IntToStr(Y + 1), Way) > 0 then exit;
  if (X - 1 > min) and (Y + 2 < m) then
      FindWay(X-1, Y+2, Way+chr(X+65)+IntToStr(Y+1)+' ');
  if (X + 1 < n) and (Y + 2 < m ) then
      FindWay(X+1, Y+2, Way + chr(X+65) + IntToStr(Y+ 1) + ' ');
  if (X + 2 < n) and (Y + 1 < m) then
      FindWay(X + 2, Y + 1, Way + chr(X+65) + IntToStr(Y + 1) + ' ');
  if (X + 2 < n) and (Y - 1 > min) then
      FindWay(X + 2, Y - 1, Way + chr(X+65) + IntToStr(Y + 1) + ' ');
  if (X + 1 < n) and (Y - 2 > min) then
      FindWay(X + 1, Y - 2, Way + chr(X+65) + IntToStr(Y + 1) + ' ');
  if (X - 1 > min) and (Y - 2 > min) then
      FindWay(X - 1, Y - 2, Way + chr(X+65) + IntToStr(Y + 1) + ' ');
  if (X - 2 > min) and (Y - 1 > min) then
      FindWay(X - 2, Y - 1, Way + chr(X+65) + IntToStr(Y + 1) + ' ');
  if (X - 2 > min) and (Y + 1 < m) then
      FindWay(X - 2, Y + 1, way + chr(X+65) + IntToStr(Y + 1) + ' ');
end;

begin
  Assign(Input, 'input.txt');
  Assign(Output, 'output.txt');
  Reset(Input);
  Rewrite(Output);
  Read(n, m);
  min := -1;
  if (n = 1) and (m = 1) then begin
    Write('A1');
    Exit;
  end;
  for k := 0 to n-1 do
      for l := 0 to m-1 do begin
          FindWay(k, l, '');
          if isFound then Break;
      end;
  if isFound then
      WriteLn(Answer)
  else
      WriteLn('No solution');
  Close(Input);
  Close(Output);
end.

