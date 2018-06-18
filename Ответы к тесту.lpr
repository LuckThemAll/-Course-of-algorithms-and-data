program project1;

{$mode objfpc}{$H+}

var
  p, q, i: integer;
  arr: array of string;
  marks: array of integer;
  f: boolean;
  variant, ans: string;

procedure gen(k, n: integer);
var
  i, j, equalCount:integer;
begin
  if f then Exit;
   if k <= n then begin
       variant[k] := '+';
       gen(k + 1, n);
       variant[k] := '-';
       gen(k + 1, n);
   end else begin
     for i := 0 to p-1 do begin
       equalCount := 0;
       for j := 1 to q do begin
         if variant[j] = arr[i][j] then inc(equalCount);
       end;
       if equalCount <> marks[i] then exit;
     end;
     ans := variant;
     f := true;
   end;
end;

begin
  assign(input,'input.txt'); reset(input);
  assign(output, 'output.txt'); rewrite(output);
  readln(p, q);
  SetLength(arr, p);
  SetLength(marks, p);
  SetLength(variant, q);
  for i := 0 to p-1 do begin
    readln(arr[i]);
    readln(marks[i]);
  end;
  f := false;
  gen(1,q);
  write(ans);
  close(input);
  close(output);
end.

