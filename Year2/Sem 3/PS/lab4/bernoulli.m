p = input('p=');
n = input('n=');
u = rand(1,n);
x = (u < p);
u_x = unique(x);
n_x = hist(x,length(u_x));
rel_freq = n_x / n;

