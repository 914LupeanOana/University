%we are solving the first exercise with normal law

m = input('m= ');
s = input('s= ' );
alpha = input('alpha(in (0,1))= ');
beta = input('beta= ');

%we are solving 1a

p1a = normcdf(0,m,s);

p2a = 1 - p1a;

%we are sloving 1b

p1b = normcdf(1,m,s) - normcdf(-1,m,s);

p2b = 1 - p1b;

%we are solving 1c

p1c = norminv(alpha,m,s);

%we are solving 1d

p2c = norminv(1 - beta,m,s);

%quantile recall prefix of the law + inv !!!
%prints and comentaries !!



