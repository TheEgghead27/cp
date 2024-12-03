A = csvread("1");
sum(abs(sort(A(:,2)) - sort(A(:,1))))

s = 0;
for i = 1:length(A(:,1))
  %printf("%d checking %d, A(%d,1)\n", s, A(i,1), i);
  s += sum(A(:,2) == A(i,1)) * A(i,1);
end
printf("s = %d\n", s);
% s > 391
