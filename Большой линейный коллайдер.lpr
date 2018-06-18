program Project1;

{$mode objfpc}{$H+}

uses
  math;

type
  blk = record
    etype: boolean;
    coord: integer;
    lifetime: Double;
  end;

var
  n, i, t, c, j: int64;
  m, r, l: Double;
  line: array of blk;
  times: array of int64;
  lifetimes: array of Double;

procedure FindCpls;
var
  i: int64;
  arr: array of int64;
begin
  for i := 0 to High(line) do begin
    if line[i].etype then begin
      SetLength(arr, Length(arr) + 1);
      arr[High(arr)] := i;
    end
    else
      if (line[i].etype = false) and (Length(arr) <> 0) then begin
        line[i].lifetime := (line[i].coord-line[arr[High(arr)]].coord)/2;
        line[arr[high(arr)]].lifetime := line[i].lifetime;
        SetLength(lifetimes, Length(lifetimes)+1);
        lifetimes[High(lifetimes)] := line[i].lifetime;
        SetLength(arr, Length(arr) - 1);
      end;

  end;
end;

procedure qSort(l,r:longint);
var
  i,j:longint;
  w,q:real;
begin
  i := l; j := r;
  q := lifetimes[(l+r) div 2];
  repeat
    while (lifetimes[i] < q) do inc(i);
    while (q < lifetimes[j]) do dec(j);
    if (i <= j) then
    begin
      w:=lifetimes[i]; lifetimes[i]:=lifetimes[j]; lifetimes[j]:=w;
      inc(i); dec(j);
    end;
  until (i > j);
  if (l < j) then qSort(l,j);
  if (i < r) then qSort(i,r);
end;

begin
  assign(input, 'linear.in'); reset(input);
  assign(output, 'linear.out'); rewrite(output);
  readln(n);
  SetLength(line, n);
  for i := 0 to High(line) do begin
    readln(c, t);
    line[i].coord := c;
    if t = -1 then line[i].etype := false
    else line[i].etype := true;
  end;
  readln(n);
  SetLength(times, n);
  for i := 0 to High(times) do
    read(times[i]);
  FindCpls;
  qSort(0, High(lifetimes));
  r := High(lifetimes);
  l := 0;
  m := round((r+l) / 2);
  for j := 0 to High(times) do begin
    while (r - l > 1) do begin
      m := round((r+l) / 2);
      if lifetimes[round(m)] <= times[j]  then
        r := m
      else
        l := m;
    end;
    writeln(Length(line) - r*2);
  end;
  close(input);
  close(output);
end.
