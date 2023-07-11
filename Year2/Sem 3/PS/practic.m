%exercise 2

printf("solving exercise 2 \n");

x = [1001.7, 975.0, 978.3, 988.3, 978.7, 988.9, 1000.3, 979.2, 968.9, 983.5, 999.2, 985.6];
alpha = input('Significance level= ');
n= columns(x);

%a)
printf("solving subpoint a) \n");
printf("we have a right-tailed test \n");
printf("sigma is unknown, so we have to use the second part of the first case \n");
printf("the null hypotheisis is miu=995 \n");
printf("the alternative hypotheisis is miu >995 \n");

m0 = 995;

[H, P, CI, stat] = ttest(x, m0, "alpha", alpha, "tail", "right");

%H is the rejection of the null hypothesis, P is the P-value, CI is the confidence interval, stat is the value of the test statistics

if H==0
  printf("The null hypothesis is not rejected, the muzzles seem to be faster than 995 m/s \n");
else 
  printf("The null hypothesis is rejected, the muzzles seem to be slower than 995 m/s \n");
end 

z2 = norminv(1-alpha);
RR = [z2, inf]; %rejection region for right-tailed test

printf('The rejection region is (%4.4f,%4.4f) \n', RR(1), RR(2));
printf('The value of the test statistic z is %6.4f \n', stat);
%printf('The P_value of the test is %4.4f \n', P);
printf("The confidence interval is (%4.4f, %4.4f) \n", CI);