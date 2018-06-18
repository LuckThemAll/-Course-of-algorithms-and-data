program project1;

{$mode objfpc}{$H+}
type
  Neighbor = record
    S, F: integer;
  end;

var
  i, j, m, n, w1, w2, numStay, numAdd: integer;
  Chip: array of array of boolean;
  Visited: array of boolean;
  NeedAdd: array of integer;
  StayChip: array of Neighbor;

  procedure dfs(v: integer);
  var
    i: integer;
  begin
    Visited[v] := True;
    for i := 0 to High(Visited) do
      if Chip[v][i] and not Visited[i] then
      begin
        StayChip[numStay].S := v;
        StayChip[numStay].F := i;
        Inc(numStay);
        dfs(i);
      end;
  end;

begin
  Assign(input, 'input.txt');
  Reset(input);
  Assign(output, 'output.txt');
  Rewrite(output);
  Read(n, m);
  SetLength(Chip, n, n);
  SetLength(Visited, n);
  SetLength(StayChip, n);
  for i := 1 to m do
  begin
    Read(w1, w2);
    Chip[w1 - 1][w2 - 1] := True;
    Chip[w2 - 1][w1 - 1] := True;
  end;
  dfs(0);
  for i := 1 to High(Visited) do
    if not Visited[i] then
    begin
      dfs(i);
      Inc(numAdd);
      SetLength(NeedAdd, Length(NeedAdd) + 1);
      NeedAdd[High(NeedAdd)] := i + 1;
    end;
  WriteLn(numStay);
  for i := 0 to High(StayChip) do
    if StayChip[i].S <> StayChip[i].F then
      WriteLn(StayChip[i].S + 1, ' ', StayChip[i].F + 1)
    else
      Break;

  WriteLn(numAdd);
  for i := 0 to High(NeedAdd) do
    WriteLn(NeedAdd[i], ' ', 1);



  Close(input);
  Close(output);
end.
