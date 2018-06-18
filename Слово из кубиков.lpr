program project1;

{$mode objfpc}{$H+}

uses
  sysutils, strutils;

var
  n, i, j: integer;
  s: string;
  cubs: array [1..12] of string;
  table: array [1..12] of array of integer;
  used: array [1..12] of integer;
  answer: boolean;

procedure FindWay(nLtr: integer);
var
  i, j: integer;
begin
  if not answer then begin
    if Length(s) < nLtr then begin
      for i := 1 to 12 do
        for j := 1 to 12 do
          if used[j] = i then begin
            answer := true;
            write(j,' ');
          end;
    end
    else begin
      for i := 0 to Length(table[nLtr])-1 do
        if used[table[nLtr][i]] = 0 then begin
          used[table[nLtr][i]] := nLtr;
          FindWay(nLtr + 1);
        end;
      for i := 1 to 12 do
        if used[i] = nLtr-1 then
          used[i] := 0;
    end;
  end;
end;

begin
  assign(input, 'input.txt');
  assign(output, 'output.txt');
  reset(input);
  rewrite(output);
  readln(n);
  readln(s);
  for i := 1 to n do
    readln(cubs[i]);
  for i := 1 to Length(s) do
    for j := 1 to n do
      if AnsiContainsStr(cubs[j], s[i]) then begin
        SetLength(table[i], Length(table[i]) + 1);
        table[i][High(table[i])] := j;
      end;
  for i := 1 to 12 do
    used[i] := 0;
  FindWay(1);
  if answer = false then write('0');
  close(input);
  close(output);
end.

