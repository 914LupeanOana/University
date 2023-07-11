clear
p=input('p=');
N=input('N=');

for i=1:N
  x(i) = 0;
  while rand >= p
    x(i) = x(i) + 1
  endwhile

endfor

k = 0:20;

u_x = unique(x);
n_x = hist(x,length(u_x));
rel_freq = n_x / N;

plot(u_x, n_x/N, "b*", k, geopdf(k,p), "r*");
legend("simulation", "geo_distribution");
