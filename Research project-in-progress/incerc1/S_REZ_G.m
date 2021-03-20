load('input1.mat');
load('input.mat');
if(dorinta == 3)
    A = randn(n,n);
    b = randn(n,1);
    save('input_random.mat','A','b','optiune');
end
if (dorinta == 4)
    flag = 0;
    [file,path] = uigetfile('*.m');
    while(flag == 0)
    m=input('Do you want to continue, Y/N [Y]:','s');
    if m=='Y'

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
if(optiune ==1)
s=10:10:n;
timpi_G = zeros(1,n/10);
for i =10:10:n
tic();
A = randn(i);
[m,s]=size(A);
for j=1:m-1
    for z=2:m
        if A(j,j)==0
            t=A(j,:);A(j,:)=A(z,:);
            A(z,:)=t;
        end
    end
    for i=j+1:m
        A(i,:)=A(i,:)-A(j,:)*(A(i,j)/A(j,j));
    end
end
timpi_G(i/10) = toc()
end
gcf = figure('visible','off');
plot(timpi_G,'r');
saveas(gcf,'Andu.png');
save('incercare.mat','A','n','timpi_G');
end
if(optiune ==2)
    [m,n]=size(A);
for j=1:m-1
    for z=2:m
        if A(j,j)==0
            t=A(j,:);A(j,:)=A(z,:);
            A(z,:)=t;
        end
    end
    for i=j+1:m
        A(i,:)=A(i,:)-A(j,:)*(A(i,j)/A(j,j))
    end
    x = zeros(m,1);
    for i = m:-1:1
        s = b(i);
        for j = i+1:n
            s = s - A(i,j)*x(j);
        end
        x(i) = s/A(i,i);
    end
    save('solutie_G.mat','x','A','b');
end
end
%end
%end