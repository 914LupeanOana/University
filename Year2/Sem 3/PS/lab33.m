p = input('p(0.05≤p≤0.95)= ');

for n = 1:5:1000
  k=0:n;
  a = binopdf(k,n,p);
  plot(k, a);
  pause(0.5);
  endfor