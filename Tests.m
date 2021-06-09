%% Capita - Tests script
%
%
%% A

A = [3 1 -1 0 0 0 0;
     0 4 0.5 0 0 0 0;
     0 0 -1 0 -0.5 0 0;
     0 0 0 2 0 2 0;
     0 0 0 0 5 1 0;
     0 0 0 0 0 3 0;
     0 0 0 0 0 0 0]

[V, D] = eig(A);
%A
%[ 0.0207737 -0.0414434 -0.0829562 1.37967e-10 0.995474 6.89835e-11 0 ]
%CHECK
tA = A'*A;
[V, D] = eig(tA);
% AtA
%[ -0.00294474 0.0010017 0.0189345 0.0634814 0.927064 0.368991 0 ]
%CHECK
At = A*A';
[V, D] = eig(At)
% AtA
%[ -0.00294474 0.0010017 0.0189345 0.0634814 0.927064 0.368991 0 ]
%CHECK
%% B
B = [0 0 0 0 15;
     0 0 23 24 0;
     0 23 0 0 35;
     0 24 0 0 0;
     15 0 35 0 0]
 
[Vb, Db] = eig(B)

%[ 0.185258 0.431061 0.661911 0.239625 0.533217 ]
%CHECK

%% Bt
V = ones(5,1);

p = B'*V

l = B *p

Bt = B*B'

[Vb, Db] = eig(Bt)

[ 0.185257 0.431062 0.66191 0.239628 0.533216 ]

%% Heavy Tests

%Test 1 - grg
grg = mmread('gr_900_900_crg.mm');

[Vg, Dg] = eigs(grg);

%Test 2 - west
west = mmread('west_67_67_crg.mm');

[Vw, Dw] = eigs(west);

%Test 3 - gre
gre = mmread('gre_343_343_crg.mm');

[Ve, De] = eigs(gre);




