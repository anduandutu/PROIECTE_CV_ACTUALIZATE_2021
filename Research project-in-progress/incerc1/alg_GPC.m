load('input1.mat');
load('input.mat');
if(dorinta == 3)
    A = randn(n,n);
    b = randn(n,1);
    save('input_random.mat','A','b','optiune');
end
if (dorinta == 4)
    flag = 0;
    while(flag == 0)
    m=input('Do you want to continue, Y/N [Y]:','s');
    if m=='Y'
        [file,path] = uigetfile('*.m');
        run(file);
        flag = 1;
        save('input_generat.mat','A','b','optiune');
    end
    end
end
if(dorinta == 3)
    load('input_random.mat');
end
if(dorinta == 4)
    load('input_generat.mat');
end
if(optiune==1)
dim=10:10:n;
timpi_GPC = zeros(1,n/10);
for s = 10:10:n
tic();
A = randn(s,s);
[dim1, dim2] = size(A);
p = 1:s; 
q = 1:s;
for k = 1:s-1
    [maxc, rowindices] = max(abs(A(k:s, k:s)));
    [maxm, colindex] = max(maxc);
    row = rowindices(colindex)+k-1; col = colindex+k-1;
    A( [k, row], : ) = A( [row, k], : );
    A( :, [k, col] ) = A( :, [col, k] );
    p( [k, row] ) = p( [row, k] ); q( [k, col] ) = q( [col, k] );
    if A(k,k) == 0
      break
    end
    A(k+1:s,k) = A(k+1:s,k)/A(k,k);
    i = k+1:s;
    A(i,i) = A(i,i) - A(i,k) * A(k,i);
end
L = tril(A,-1) + eye(s);
U = triu(A);
   P = eye(s);
   P = P(p,:);
   Q = eye(s);
   Q = Q(:,q);
timpi_GPC(s/10) = toc()
save('incercare_GPC','L','U','n','timpi_GPC');
end
gcf = figure('visible','off');
plot(timpi_GPC,'r');
saveas(gcf,'Andu.png');
end
if(optiune == 2)
s = size(A);
p = 1:s; 
q = 1:s;
for k = 1:s-1
    [maxc, rowindices] = max( abs(A(k:s, k:s)) );
    [maxm, colindex] = max(maxc);
    row = rowindices(colindex)+k-1; col = colindex+k-1;
    A( [k, row], : ) = A( [row, k], : );
    A( :, [k, col] ) = A( :, [col, k] );
    p( [k, row] ) = p( [row, k] ); q( [k, col] ) = q( [col, k] );
    if A(k,k) == 0
      break
    end
    A(k+1:s,k) = A(k+1:s,k)/A(k,k);
    i = k+1:s;
    A(i,i) = A(i,i) - A(i,k) * A(k,i);
end
L = tril(A,-1) + eye(s);
U = triu(A);
   P = eye(s);
   P = P(p,:);
   Q = eye(s);
   Q = Q(:,q);
   x = SUP_TR(U,b)';
   save('solutie_GPC.mat','A','b','x');
end