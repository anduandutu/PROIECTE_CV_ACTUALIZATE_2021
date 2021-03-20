function [x] = SUP_TR(U,b)
 n = size(U);
 for i = n:-1:1
     s = b(i);
     for j = i+1:n
         s = s - U(i,j)*b(j);
     end
     x(i) = s/U(i,i);
 end
end