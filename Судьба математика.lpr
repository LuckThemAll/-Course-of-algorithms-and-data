program program1;

{$H+}

Uses sysutils;

var
 number, tempRule: string;
 rules: array of string;
 ans, i ,j, lengthS: integer;
 boolCompare: boolean;

function Compare(a,b: Char; sign: string): boolean;
begin
  case sign of
    '>'  : Exit(a > b);
    '>=' : Exit(a >= b);
    '<'  : Exit(a < b);
    '<=' : Exit(a <= b);
    '='  : Exit(a = b);
    '<>' : Exit(a <> b);
  end;
end;

begin
  assign(input, 'input.txt'); reset(input);
  assign(output, 'output.txt'); rewrite(output);
  ans := 1000000;
  while not EOF(input) do begin
    SetLength(rules, Length(rules) + 1);
    readln(rules[High(rules)]);
  end;
  for i := 0 to 999999 do begin
    number := IntToStr(i);
    lengthS := Length(number);
    for j := 1 to (6 - lengthS) do begin
      number := '0' + number;
    end;
    boolCompare := true;
    for j := 0 to High(rules) do begin
      if (j > 0) and (rules[j] = rules[j-1]) then begin
        if not boolCompare then begin
          Dec(ans);
          Break;
        end
        else Break;
      end;
      if Length(rules[j]) = 3 then tempRule := rules[j][2]
      else tempRule := rules[j][2] + rules[j][3];
      if not Compare(number[StrToInt(rules[j][1])], number[StrToInt(rules[j][High(rules[j])])], tempRule) then begin
        Dec(ans);
        boolCompare := false;
        Break;
      end;
    end;
  end;
  write(ans);
  close(input);
  close(output);
end.
