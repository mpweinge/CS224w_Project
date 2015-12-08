%DropOut_Prediction


% Features are in this order
% PageRank, Weighted PageRank, # PACs, # Donors, # Indirect Donors, Amount

% Candidates are in this order, Obama, Clinton, Edwards, Biden, Dodd,
% Gravel, Kucinich, Richardson

% Everyone dropped out instead of Obama / Clinton
justPageX = [0.0111959
0.0121702
0.0258032
0.000841436
0.00851315
0.00144444
0.00266905
0.000926171
0.000957994
0.0041487
0.00293836
0.00675207
0.00244098
0.000598
0.000119689
0.00279839
0.00281624
0.0228337
0.0163011
0.0139361
0.00277
0.000356667
0.00260082
0.00103979
0.0000472
0.00154994
0.00642
0.00765919
0.00158
0.0189592
0.00238312
0.00683087
0.000250351
0.0129
0.00870395
0.00177323
0.00233223
0.00378
0.000550718
0.00233716
0.00038714
0.0000112
0.00181468
0.0000733];

pageFundX = [0.0111959	0.929431798
0.0121702	1
0.0258032	1
0.000841436	0.033013262
0.00851315	0.387812486
0.00144444	0.55963517
0.00266905	0.070518972
0.000926171	0.026971835
0.000957994	0.049216313
0.0041487	1
0.00293836	0.738213712
0.00675207	0.875211725
0.00244098	0.430520192
0.000598	0.157318187
0.000119689	0.024152344
0.00279839	0.488893078
0.00281624	0.413469458
0.0228337	1
0.0163011	0.834119797
0.0139361	1
0.00277	0.251286891
0.000356667	0.008753484
0.00260082	0.138704803
0.00103979	0.082924989
0.0000472	0.001501313
0.00154994	0.11716264
0.00642	0.502694814
0.00765919	1
0.00158	0.093169316
0.0189592	0.139578453
0.00238312	0.129541186
0.00683087	0.592813557
0.000250351	0.013346232
0.0129	1
0.00870395	1
0.00177323	0.299665536
0.00233223	0.524789901
0.00378	0.24204554
0.000550718	0.126786522
0.00233716	0.315355715
0.00038714	0.039434416
0.0000112	0.000734706
0.00181468	0.108930122
0.0000733	0.005846852];

pageFundClique = [0.0111959	0.929431798	0.0594
0.0121702	1	0.0594
0.0258032	1	0.1339
0.000841436	0.033013262	0.0048
0.00851315	0.387812486	0.1709
0.00144444	0.55963517	0.0688
0.00266905	0.070518972	0.0429
0.000926171	0.026971835	0.1753
0.000957994	0.049216313	0.1459
0.0041487	1	0.2419
0.00293836	0.738213712	0.1533
0.00675207	0.875211725	0.2381
0.00244098	0.430520192	0.2342
0.000598	0.157318187	0.126
0.000119689	0.024152344	0.1856
0.00279839	0.488893078	0.2513
0.00281624	0.413469458	0.2251
0.0163011	0.834119797	0.2567
0.0139361	1	0.2466
0.00277	0.251286891	0.2377
0.000356667	0.008753484	0.1981
0.00260082	0.138704803	0.3078
0.00103979	0.082924989	0.3286
0.0000472	0.001501313	0.0496
0.00154994	0.11716264	0.2839
0.00642	0.502694814	0.2368
0.00765919	1	0.2165
0.00158	0.093169316	0.1185
0.0189592	0.139578453	0.075
0.00238312	0.129541186	0.2052
0.00683087	0.592813557	0.2339
0.000250351	0.013346232	0.1241
0.00870395	1	0.1106
0.00177323	0.299665536	0.0853
0.00233223	0.524789901	0.1538
0.00378	0.24204554	0.1031
0.000550718	0.126786522	0.1257
0.00233716	0.315355715	0.1532
0.00038714	0.039434416	0.1073
0.0000112	0.000734706	0.0013
0.00181468	0.108930122	0.1421
0.0000733	0.005846852	0.023];

pageFundComm = [0.0111959	0.929431798	14
0.0121702	1	88
0.0258032	1	1332
0.000841436	0.033013262	88
0.00851315	0.387812486	88
0.00144444	0.55963517	6
0.00266905	0.070518972	88
0.000926171	0.026971835	25
0.000957994	0.049216313	40
0.0041487	1	19
0.00293836	0.738213712	67
0.00675207	0.875211725	9
0.00244098	0.430520192	67
0.000598	0.157318187	65
0.000119689	0.024152344	67
0.00279839	0.488893078	46
0.00281624	0.413469458	81
0.0228337	1	1512
0.0163011	0.834119797	14
0.0139361	1	63
0.00277	0.251286891	180
0.000356667	0.008753484	42
0.00260082	0.138704803	187
0.00103979	0.082924989	180
0.0000472	0.001501313	63
0.00154994	0.11716264	180
0.00642	0.502694814	180
0.00765919	1	28
0.00158	0.093169316	65
0.0189592	0.139578453	71
0.00238312	0.129541186	71
0.00683087	0.592813557	39
0.000250351	0.013346232	80
0.0129	1	221
0.00870395	1	74
0.00177323	0.299665536	20
0.00233223	0.524789901	178
0.00378	0.24204554	60
0.000550718	0.126786522	10
0.00233716	0.315355715	154
0.00038714	0.039434416	178
0.0000112	0.000734706	83
0.00181468	0.108930122	178
0.0000733	0.005846852	60];

pageFundCommRat = [0.0111959	0.929431798	0.919943797
0.0121702	1	1
0.0258032	1	3.53619E-07
0.000841436	0.033013262	1.15314E-08
0.00851315	0.387812486	1.16668E-07
0.00144444	0.55963517	1.97953E-08
0.00266905	0.070518972	3.65779E-08
0.000926171	0.026971835	1.26927E-08
0.000957994	0.049216313	1.31288E-08
0.0041487	1	1.16914E-07
0.00293836	0.738213712	8.28057E-08
0.00675207	0.875211725	1.9028E-07
0.00244098	0.430520192	6.87891E-08
0.000598	0.157318187	1.68522E-08
0.000119689	0.024152344	3.37295E-09
0.00279839	0.488893078	7.88612E-08
0.00281624	0.413469458	7.93642E-08
0.0228337	1	1
0.0163011	0.834119797	1.53554E-07
0.0139361	1	1.31276E-07
0.00277	0.251286891	2.60929E-08
0.000356667	0.008753484	3.35974E-09
0.00260082	0.138704803	2.44993E-08
0.00103979	0.082924989	9.79465E-09
0.0000472	0.001501313	4.44616E-10
0.00154994	0.11716264	1.46002E-08
0.00642	0.502694814	1.03088E-07
0.00765919	1	1.22986E-07
0.00158	0.093169316	2.53705E-08
0.0189592	0.139578453	3.04433E-07
0.00238312	0.129541186	3.82665E-08
0.00683087	0.592813557	1.09685E-07
0.000250351	0.013346232	4.01996E-09
0.0129	1	1
0.00870395	1	2.15882E-07
0.00177323	0.299665536	4.39811E-08
0.00233223	0.524789901	5.78459E-08
0.00378	0.24204554	9.37547E-08
0.000550718	0.126786522	1.36594E-08
0.00233716	0.315355715	5.79682E-08
0.00038714	0.039434416	9.60216E-09
0.0000112	0.000734706	2.77792E-10
0.00181468	0.108930122	4.50092E-08
0.0000733	0.005846852	1.81805E-09];

fundX = [0.929431798
1
1
0.033013262
0.387812486
0.55963517
0.070518972
0.026971835
0.049216313
1
0.738213712
0.875211725
0.430520192
0.157318187
0.024152344
0.488893078
0.413469458
1
0.834119797
1
0.251286891
0.008753484
0.138704803
0.082924989
0.001501313
0.11716264
0.502694814
1
0.093169316
0.139578453
0.129541186
0.592813557
0.013346232
1
1
0.299665536
0.524789901
0.24204554
0.126786522
0.315355715
0.039434416
0.000734706
0.108930122
0.005846852];

YClique = [0
1
0
0
1
1
1
1
1
0
0
0
1
0
1
1
1
0
0
1
1
1
1
1
1
0
1
1
0
0
0
0
0
1
0
0
1
1
1
1
1
1];

Y = [0
1
0
0
1
1
1
1
1
0
0
0
1
0
1
1
1
0
0
0
1
1
1
1
1
1
0
1
1
0
0
0
0
0
0
1
0
0
1
1
1
1
1
1];

%mdl = fitlm(X, Y)

%title('Drop out Prediction')
%xlabel('PageRank')
%ylabel('Normalized Total Funds')
set(gca,'fontsize',25)

svmStruct = svmtrain(pageFundCommRat,Y,'ShowPlot',true);
YPred = svmclassify(svmStruct, pageFundCommRat);
sum(abs(Y - YPred)) / length(Y)
%sum(abs(YClique - YPred)) / length(YClique)

% Go through y. If y == 1 for a candidate, then assign their pagerank to a
% different candidate

%
DemDist2000 = [623,0,0];
RepDist2000 = [13,687,126,67,188,202,2,21,3,1,1,14,40,51,21,3,18,12,3,1,10];
DemDist2004 = [429,402,526,55,6,403,322,387,494,65,8,629,366,435,136,8,285,225,75,3,440,393,4,47,47,6,6,485];
DemDist2008 = [5736,2688,163,1249,506,16,307,1740,86,1119,554,7,300,136,478,229,11,89,51,24,7,24,188,6,71,6,54,7];
RepDist2008 = [937,22,96,389,1613,2,20,86,91,361,899,1,32,10,134,24,3,20,30,67,0,6,319,1,24,1,17,3];
RepDist2012 = [171,325,118,233,444,28,0,206,6,380,79,20,123,88,1,477,3,126,52,212,86,1,538,7,29,47,41,0,172,22,80,7,0,36,1,21,0,107,4,0,140,2,4,0,16];

DemDist2000 = 1./DemDist2000;
RepDist2000 = 1./RepDist2000;
DemDist2004 = 1./DemDist2004;
DemDist2008 = 1./DemDist2008;
RepDist2008 = 1./RepDist2008;
RepDist2012 = 1./RepDist2012;

DemDist2000 = squareform(DemDist2000);
RepDist2000 = squareform(RepDist2000);
DemDist2004 = squareform(DemDist2004);
DemDist2008 = squareform(DemDist2008);
RepDist2008 = squareform(RepDist2008);
RepDist2012 = squareform(RepDist2012);

featDem2000 = pageFundCommRat(1:2, :);
YDem2000 = Y(1:2, :);

featRep2000 = pageFundCommRat(3:9, :);
YRep2000 = Y(3:9, :);

featDem2004 = pageFundCommRat(10:17, :);
YDem2004 = Y(10:17, :);

featDem2008 = pageFundCommRat(19:26, :);
YDem2008 = Y(19:26, :);

featRep2008 = pageFundCommRat(27:33, :);
YRep2008 = Y(27:33, :);

featRep2012 = pageFundCommRat(35:44, :);
YRep2012 = Y(35:44, :);

for i = 1 : 2
    minX = 1;
    minIdx = 0;
    if (Y(i) == 1)
        % Go through candidates for repdist2012 and see who they are
        % closest to
        for j = 1 : size(DemDist2000, 1)
            if (Y(j) == 0)
                if (DemDist2000(i, j) < minX)
                    minX = DemDist2000(i, j);
                    minIdx = j;
                end
            end
        end
        
        % Add data at i to j
        pageFundCommRat(j,:) = pageFundCommRat(j,:) + pageFundCommRat(i,:);
        pageFundCommRat(i,:) = pageFundCommRat(i,:) - pageFundCommRat(i,:);
    end
end

for i = 3 : 9
    minX = 1;
    minIdx = 0;
    if (Y(i) == 1)
        % Go through candidates for repdist2012 and see who they are
        % closest to
        for j = 1 : size(RepDist2000, 1)
            if (Y(j) == 0)
                if (RepDist2000(i-2, j) < minX)
                    minX = RepDist2000(i-2, j);
                    minIdx = j + 2;
                end
            end
        end
        
        % Add data at i to j
        pageFundCommRat(j,:) = pageFundCommRat(j,:) + pageFundCommRat(i,:);
        pageFundCommRat(i,:) = pageFundCommRat(i,:) - pageFundCommRat(i,:);
    end
end

for i = 10 : 17
    minX = 1;
    minIdx = 0;
    if (Y(i) == 1)
        % Go through candidates for repdist2012 and see who they are
        % closest to
        for j = 1 : size(DemDist2004, 1)
            if (Y(j) == 0)
                if (DemDist2004(i-9, j) < minX)
                    minX = DemDist2004(i-9, j);
                    minIdx = j+9;
                end
            end
        end
        
        % Add data at i to j
        pageFundCommRat(j,:) = pageFundCommRat(j,:) + pageFundCommRat(i,:);
        pageFundCommRat(i,:) = pageFundCommRat(i,:) - pageFundCommRat(i,:);
    end
end

for i = 19 : 26
    minX = 1;
    minIdx = 0;
    if (Y(i) == 1)
        % Go through candidates for repdist2012 and see who they are
        % closest to
        for j = 1 : size(DemDist2008, 1)
            if (Y(j) == 0)
                if (DemDist2008(i-18, j) < minX)
                    minX = DemDist2008(i-18, j);
                    minIdx = j+18;
                end
            end
        end
        
        % Add data at i to j
        pageFundCommRat(j,:) = pageFundCommRat(j,:) + pageFundCommRat(i,:);
        pageFundCommRat(i,:) = pageFundCommRat(i,:) - pageFundCommRat(i,:);
    end
end

for i = 27 : 33
    minX = 1;
    minIdx = 0;
    if (Y(i) == 1)
        % Go through candidates for repdist2012 and see who they are
        % closest to
        for j = 1 : size(RepDist2008, 1)
            if (Y(j) == 0)
                if (RepDist2008(i-26, j) < minX)
                    minX = RepDist2008(i-26, j);
                    minIdx = j+26;
                end
            end
        end
        
        % Add data at i to j
        pageFundCommRat(j,:) = pageFundCommRat(j,:) + pageFundCommRat(i,:);
        pageFundCommRat(i,:) = pageFundCommRat(i,:) - pageFundCommRat(i,:);
    end
end

for i = 35 : 44
    minX = 1;
    minIdx = 0;
    if (Y(i) == 1)
        % Go through candidates for repdist2012 and see who they are
        % closest to
        for j = 1 : size(RepDist2012, 1)
            if (Y(j) == 0)
                if (RepDist2012(i-34, j) < minX)
                    minX = RepDist2012(i-34, j);
                    minIdx = j+34;
                end
            end
        end
        
        % Add data at i to j
        pageFundCommRat(j,:) = pageFundCommRat(j,:) + pageFundCommRat(i,:);
        pageFundCommRat(i,:) = pageFundCommRat(i,:) - pageFundCommRat(i,:);
    end
end

YAct = [
    1 
    0
    1
    2
    0
    0
    3
    4
    0
    1
    2
    3
    0
    4
    0
    0
    0
    1
    1
    2
    0
    0
    0
    0
    0
    0
    1
    0
    0
    2
    3
    4
    5
    1
    1
    0
    2
    3
    0
    0
    0
    0
    0
    0];

YRev = [
    6 
    0
    6
    5
    0
    0
    4
    3
    0
    6
    5
    4
    0
    3
    0
    0
    0
    6
    6
    5
    0
    0
    0
    0
    0
    0
    6
    0
    0
    5
    4
    3
    2
    6
    6
    0
    5
    4
    0
    0
    0
    0
    0
    0];

YBin = [
    1 
    0
    1
    2
    0
    0
    2
    2
    0
    1
    2
    2
    0
    2
    0
    0
    0
    1
    1
    2
    0
    0
    0
    0
    0
    0
    1
    0
    0
    2
    2
    2
    2
    1
    1
    0
    2
    2
    0
    0
    0
    0
    0
    0];
    

%Don't train with 0 vectors
xTrain = pageFundCommRat;
xTrain(all(xTrain==0,2),:)=[]
mdl = fitlm(xTrain,  YAct(YAct~=0))

%svmStruct = svmtrain(pageFundCommRat,YBin,'ShowPlot',true);
%YPred = svmclassify(svmStruct, pageFundCommRat);

%error = 

X = [1:44];
close all
scatter(X, YAct, 'b');
hold on
YPred = mdl.predict(pageFundCommRat);

for i = 1 : length(Y)
    if (Y(i) == 1)
        YPred(i) = 0;
    end
end

%scatter(X, YPred, 'r');
[~, ~, YPred(1:2)] = unique(YPred(1:2));
[~, ~, YPred(3:9)] = unique(YPred(3:9));
[~, ~, YPred(10:17)] = unique(YPred(10:17));
YPred(18) = 2;
[~, ~, YPred(19:26)] = unique(YPred(19:26));
[~, ~, YPred(27:33)] = unique(YPred(27:33));
YPred(34) = 2;
[~, ~, YPred(35:44)] = unique(YPred(35:44));
scatter(X, YPred-1, 'rx');
hold off

%for i 
