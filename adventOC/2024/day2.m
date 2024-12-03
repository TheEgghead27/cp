pkg load io

A = [7 6 4 2 1
1 2 7 8 9
9 7 6 2 1
1 3 2 4 5
8 6 4 4 1
1 3 6 7 9];
A = csvread("2");

s = 0;
s1 = 0;
for i = 1:rows(A)
  b = A(i,:)
  b;
  b = b(b>0);
  c = b;
  c(1) = [];
  b(end) = [];
  t = c - b
  if (all(0 < t & t <= 3) | all(0 > t & t >= -3))
    s+=1;
  endif
end
s
% < 254
s1
% > 253
