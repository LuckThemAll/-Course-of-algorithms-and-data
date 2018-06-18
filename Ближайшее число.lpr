program project1;
var
  n, i, j: integer;
  a, ans: array of integer;
begin
  assign(input, 'input.txt');
  assign(output, 'output.txt');
  reset(input);
  rewrite(output);
  read(n);
  SetLength(a, n);
  SetLength(ans, n);
  for i := 0 to n - 1 do
    begin
      read(a[i]);
    end;
  ans[n - 1] := n - 1;
  for i := n-2 downto 0 do
  begin
    ans[i] := i + 1;
    j := ans[i];
    while j <> ans[j] do
      begin
        if a[ans[i]] > a[i] then
          Break
        else begin
          j := ans[j];
          ans[i] := j;
        end;
      end;
    if a[i] >= a[ans[i]] then
      ans[i] := i;
  end;
  for i := 0 to n - 1 do
    write(a[ans[i]], ' ');
end.
