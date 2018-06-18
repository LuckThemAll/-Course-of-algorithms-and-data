program project1;

{$mode objfpc}{$H+}

uses
  math;

var
  a, temp_a: array of integer;
  n, i, time1, time2, max_time: integer;

procedure Generation(k, n:integer);
var
  i, j:integer;
begin
  if k>n then begin
    time1 := 0; time2 := 0;
    for j := 0 to High(a) do
      if temp_a[j] = 1 then
        time1 += a[j]
      else
        time2 += a[j];
    if max_time > Max(time1,time2) then
      max_time:=Max(time1,time2);
  end
  else
    for i := 0 to 1 do begin
      temp_a[k] := i;
      Generation(k+1, High(a));
    end;
end;

begin
  assign(input, 'input.txt');
  assign(output, 'output.txt');
  reset(input);
  rewrite(output);
  time1:=0; time2:=0;
  read(n);
  max_time := 9999999;
  SetLength(a, n); SetLength(temp_a, n);
  for i := 0 to High(a) do
    read(a[i]);
  Generation(0,High(a));
  write(max_time);
  close(input);
  close(output);
end.

