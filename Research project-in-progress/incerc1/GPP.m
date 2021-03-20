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
if(optiune == 2 && (dorinta == 3 || dorinta == 4))
t=1;
n = size(A);
miu = zeros(n);
timpi_G = zeros(1,10);
    for k = 1:n-1
        max = A(k,k);
        for i = k:n
            if(max<A(i,k))
                max = A(i,k);
                t = i;
            end
        end
        for j = k:n
                aux = A(k,j);
                A(k,j) = A(t,j);
                A(t,j) = aux; 
        end
        for i = k+1:n
                %A(i,k) = A(i,k)/A(k,k);
                miu(i,k) =  A(i,k)/A(k,k);      
        end
        for i = k:n
            for j = k:n
                A(i,j) = A(i,j) - miu(i,k)*A(k,j);
            end
        end
    end
    x = SUP_TR(A,b)';
   save('incercare_GPP.mat','A','b','n','x');
end
if(optiune == 1)
    t=1;
    s=10:10:n;
    timpi_GPP = zeros(1,n/10);
    for m =10:10:n
    tic();
    A = randn(m);
    miu = zeros(m);
    for k = 1:m-1
        max(k) = A(k,k);
        for i = k:m
            if(max(k)<A(i,k))
                max(k) = A(i,k);
                t = i;
            end
        end
        for j = k:m
                aux = A(k,j);
                A(k,j) = A(t,j);
                A(t,j) = aux; 
        end
        for i = k+1:m
                A(i,k) = A(i,k)/A(k,k);
                miu(i,k) =  A(i,k)/A(k,k);      
        end
        for i = k:m
            for j = k:m
                A(i,j) = A(i,j) - miu(i,k)*A(k,j);
            end
        end
    end
    timpi_GPP(i/10) = toc()
    end
gcf = figure('visible','off');
plot(timpi_GPP,'r');
saveas(gcf,'Andu.png');
save('graficeGPP.mat','A','n','timpi_GPP');
end