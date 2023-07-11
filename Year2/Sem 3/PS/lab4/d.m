clear
p=input('p=');
n=input('trials=');
N=input('simulations=');

for i=1:N
  for j=1:n
    x(j) = 0;
    while rand >=p
      x(j) = x(j) + 1;
    endwhile
  endfor
  y(i) = sum(x);
endfor

k = 0:150;
u_y = unique(y);
n_y = hist(y,length(u_y));
rel_freq = n_y / N;

plot(u_y, n_y/N, "b*", k, nbinpdf(k,n,p), "r*");


