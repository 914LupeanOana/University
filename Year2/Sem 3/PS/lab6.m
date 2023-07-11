alpha = input('the significants level: ');

x = [7, 7, 4, 5, 9, 9, 4, 2 ,8,1,8,7,3,13,2,1,17,7,12,5,6,2,1,13,14,10,2,4,9,11,3,5,12,6,10,7];

n = length(x);

%the null hypothesis is H0: miu = 9
%the alt hypothesis is H1: miu < 9 
%left tailed test for miu

printf('Solving a \n');
printf('This is a left tail test for miu when sigma known\n ');

sigma = 5;

%the value of miu0
m0 = 9;
[h,p,ci,z,zcrit] = ztest(x,m0,sigma, 'alpha', alpha,'tail','left');
z2=norminv(alpha);
RR = [-inf, z2]; %rejection region for left tail test
printf('the value of h is %d \n', h);

if h ==1 
  printf('The null hypothesis is rejected.\n');
  printf('The data suggests that the standard is NOT met.\n');
else
  printf('The null hypothesis is NOT rejected.\n');
  printf('The data suggests that the standard is met.\n');
endif;

printf('The rejection region is (%4.4f,%4.4f) \n', RR(1), RR(2));
printf('The value of the test statistic z is %4.4f \n', z);
printf('The P_value of the test is %4.4f \n', p);

b = (mean(x) - m0)/(5/sqrt(n));