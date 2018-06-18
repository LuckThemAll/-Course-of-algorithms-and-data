program werwe;

{$mode objfpc}{$H+}

Uses
  math;

var
  N, P, C, Answer, D, Months: Integer;
  Coeff: Double;

function CheckDolg(M: int64): boolean;
var
  i: integer;
  AfterPay: integer;
begin
  D := C;
  AfterPay := D - m;
  if (afterpay*coeff > C) then begin
    Result := false;
    Exit;
  end;
  for i := 1 to Months do begin
    if (AfterPay*Coeff > C) then begin
      Result := false;
      Exit;
    end;
    if (D < 0 ) then begin
      Result := true;
      Exit;
    end;
    D := ceil((D-M)*(1+P/100));
  end;
  if (D <= 0) then Result := true else Result := false;
end;

procedure BinSearch (mbAnswer,left,right: int64);
begin
  if (right-left<=1) and CheckDolg(mbAnswer) then begin
    Answer := mbAnswer;
    Exit;
  end;
  if not CheckDolg(mbAnswer)then
  begin
    left := mbAnswer;
    mbAnswer := left + ((right - left) div 2);
    if (right-left<=1) then mbAnswer := right;
    BinSearch(mbAnswer,left,right);
  end else
  begin
    right := mbAnswer;
    mbAnswer := left + ((right - left) div 2);
    if (right-left<=1) then mbAnswer := left;
    BinSearch(mbAnswer,left,right);
  end;
end;

begin
  Assign(Input, 'input.txt'); Reset(Input);
  Assign(Output, 'Output.txt'); Rewrite(Output);
  Read(N, P, C);
  Months := N*12;
  Coeff := (P/100) + 1;
  BinSearch(C div 2,1,C);
  Write(Answer);
  Close(Input);
  Close(Output);
end.
