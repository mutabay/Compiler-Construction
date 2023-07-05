
{ This program implements some famous algorithms }

program minipas;

  var a: integer;
      b, i: integer;
      x: array [1..100] of real;
      b1, b2: boolean;


{ Main program }

begin
  b1 := false;
  b2 := false; 
  b2 := not b2;
  a := 48;
  b := 84;

  a := -24;
  a := -a;
  b := (a+16)*(2 div 1);
  b := b+10;

  { count all prime numbers from 2 to b }
  a := 1;
  i := 2;
  while i <= b do
  begin
    if b1 or b2 then
      a := a+1;
    i := i+1
  end;

  i := 1;
  while i < b do
  begin
    x[i] := (n-i+1)*3.14;
    i := i+1;
    a:=x[i]
  end

end.
