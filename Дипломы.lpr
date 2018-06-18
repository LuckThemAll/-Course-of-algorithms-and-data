program project1;

{$mode objfpc}{$H+}

uses
  math;

var
  W, H, N, l, r, mid: int64;

begin
  Assign(input, 'diploma.in'); reset(input);
  Assign(Output, 'diploma.out'); rewrite(Output);
  read(W, H, N);
  l := 0;
  r := sqr(max(w, h));
  while (r-l > 1) do begin
    mid := l + (r-l) div 2;
    if (mid div w)*(mid div h) >= n then
      r := mid
    else
      l := mid;
  end;
  write(r);
  close(Input);
  Close(Output);
end.

