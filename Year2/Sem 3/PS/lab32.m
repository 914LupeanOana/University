%second exercise

n = input('n= ');
p = input('p= ' );
lambda = n*p;
k=0:n;

resultbino = binopdf(k,n,p);
resultpoisson = poisspdf(k,lambda);

plot(k, resultbino, 'm', k, resultpoisson, 'b');