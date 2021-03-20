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
if(optiune == 1)
   timpi_kaczmarz = zeros(1,n/10);
   for s = 10:10:n
     tic();
     alfa = 1;
    tau = 3;
    if((alfa>0)&&(alfa<2))
        A = randn(s,s);
        b = randn(s,1);
        [m,n]=size(A);
        x0 = randn(s,1);
        x=x0;
        r=norm(A*x-b);
        eps=1;
        nr_iter=0;
        nr_full = 0;
        rezid=r;
    while(r>eps)
    J = randperm(s,tau);
    sumproj=zeros(s,1);
    for k = 1:tau
        i = J(k);
        ai = A(i,:);
        sumproj=sumproj+((ai*x - b(i))/(norm(ai)^2))*ai';
    end
    x = x - (alfa/tau)*sumproj;
    %if(mod(nr_iter,ceil(n/tau))==0)
        r=norm(A*x-b)     
        %nr_full = nr_full+1;
        %[nr_full ; r]
    %end
    nr_iter=nr_iter+1;
    end
    end
    timpi_kaczmarz(s/10) = toc()
    end
    gcf = figure('visible','off');
    plot(timpi_kaczmarz,'r');
    saveas(gcf,'Andu.png');
    save('Kaczmarz_grafice.mat','A','b','x','timpi_kaczmarz');
    
end

if(optiune == 2)
alfa = 1;
tau = 2;
if((alfa>0)&&(alfa<2))
[m,n]=size(A);
x0 = randn(n,1);
x=x0;
r=norm(A*x-b);
eps=1e-1;
nr_iter=0;
nr_full = 0;
rezid=r;
while(r>eps)
    J = randperm(m,tau);
    sumproj=zeros(n,1);
    for k = 1:tau
        i = J(k);
        ai = A(i,:);
        sumproj=sumproj+((ai*x - b(i))/(norm(ai)^2))*ai';
    end
    x = x - (alfa/tau)*sumproj;
    r = norm(A*x-b)
%     if(mod(nr_iter,ceil(m/tau))==0)
%         r=norm(A*x-b);      
%         nr_full = nr_full+1;
%         [nr_full ; r]
%     end
    nr_iter=nr_iter+1;
end
else
    disp('alfa necorespunzator')
end
save('Kaczmarz.mat','A','b','n','x','alfa','eps','tau');
end