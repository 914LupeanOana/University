x = [7,7,4,5,9,9,4,12,8,1,8,7,3,13,2,1,17,7,12,5,6,2,1,13,14,10,2,4,9,11,3,5,12,6,10,7];

n = length(x);

a = input('1-alpha= ');

alpha = 1 - a;

sample_mean = mean(x);

sigma = 5;

printf('Solving exercise 1b) a).\n');

m1 = sample_mean - sigma/sqrt(n) * norminv(1-alpha/2);

m2 = sample_mean - sigma/sqrt(n) * norminv(alpha/2);

printf('The conf int for pop mean in the case sigma known is : (%4.3f, %4.3f).\n', m1, m2);

samp_std = std(x);

samp_var = var(x);

m3 = sample_mean - samp_std/sqrt(n) * tinv(1-alpha/2, n-1 );

m4 = sample_mean - samp_std/sqrt(n) * tinv(alpha/2, n-1 );

printf('The conf int for pop mean in the case sigma unknown is : (%4.3f, %4.3f).\n', m3, m4);

m5 = ((n-1)*samp_var)/(chi2inv(1-alpha/2, n-1));

m6 = ((n-1)*samp_var)/(chi2inv(alpha/2, n-1));

