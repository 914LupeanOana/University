p=input('p=');
N=input('simulations=');
n=input('trials=');

for i=1:N
  u = rand(n,1);
  x(i) = sum(u < p);
endfor

k = 0:n;
u_x = unique(x);
n_x = hist(x,length(u_x));
rel_freq = n_x / n;
plot(u_x, n_x / N, "*", k, binopdf(k,n,p), "r*");


