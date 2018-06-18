program project1;

{$mode objfpc}{$H+}

uses
  math;

var
  n, i, j, distR, distL : integer;
  a, Rmax, Lmax: array of integer;

procedure FindMaxs(var arr: array of integer);
begin
  while j <> arr[j] do
    begin
      if a[arr[i]] > a[i] then
        Break
      else begin
        j := arr[j];
        arr[i] := j;
      end;
    end;
  if a[i] >= a[arr[i]] then
    arr[i] := i;
end;

begin
  assign(input, 'input.txt'); reset(input);
  assign(output, 'output.txt'); rewrite(output);
  read(n);
  SetLength(a, n); SetLength(Rmax, n);  SetLength(Lmax, n);
  for i := 0 to n-1 do
    read(a[i]);
  Rmax[High(Rmax)] := High(a);

  for i := 1 to n-1 do begin
    Lmax[i] := i - 1;
    j := Lmax[i];
    FindMaxs(Lmax);
  end;

  for i := n-2 downto 0 do begin
    Rmax[i] := i + 1;
    j := Rmax[i];
    FindMaxs(Rmax);
  end;

  for i := 0 to n-1 do begin
    distL := i - Lmax[i];
    distR := Rmax[i] - i;
    if (distL = 0) or (distR = 0) then
      write(max(distL, distR), ' ')
    else
      write(min(distL, distR), ' ');
  end;
  close(input);
  close(output);
end.

