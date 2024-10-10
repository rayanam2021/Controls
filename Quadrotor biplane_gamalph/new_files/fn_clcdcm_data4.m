function [cl,cd,cm] = fn_clcdcm_data4(alpha,data,data2)

alpha = alpha*180/pi;


cl=0;cd=0;cm=0;

table_alpha1 = data(:,1);
table_cl1 = data(:,2);
table_cd1 = data(:,3);
table_cm1 = data(:,4);

table_alpha2 = data2(:,1);
table_cl2 = data2(:,2);
table_cd2 = data2(:,3);


if (alpha>=table_alpha1(1))&&(alpha<=table_alpha1(end))
	[cl,cd,cm]=fn_interp3(table_alpha1,table_cl1,table_cd1,table_cm1,alpha);
elseif (alpha>=25)
	cm = table_cm1(end);
	[cl,cd]=fn_interp2(table_alpha2,table_cl2,table_cd2,alpha);
elseif(alpha>table_alpha1(end))
	cm = table_cm1(end);
	s = (alpha-table_alpha1(end))/(table_alpha2(1)-table_alpha1(end));
	h1 =1-s;
	h2 =s;
	cl=h1*table_cl1(end)+h2*table_cl2(1);
	cd=h1*table_cd1(end)+h2*table_cd2(1);
elseif (alpha<-25)
	cm = table_cm1(1);
	[cl,cd]=fn_interp2(table_alpha2,table_cl2,table_cd2,abs(alpha));	
	cl=-cl;
elseif(alpha<table_alpha1(1))
	cm = table_cm1(1);
	s = (alpha-table_alpha1(1))/(-table_alpha2(1)-table_alpha1(1));
	h1 =1-s;
	h2 =s;
	cl=h1*table_cl1(1)-h2*table_cl2(1);
	cd=h1*table_cd1(1)+h2*table_cd2(1);
end





end
function yeq = fn_interp(x,y,xeq)
L = 1;
R = length(x);
while (R-L>1)
m=floor((L+R)/2);
if xeq > x(m)
	L=m;
elseif xeq < x(m)
	R=m;
else
	L = m;
	break
end


end

s = (xeq-x(L))/(x(R)-x(L));
h1 =1-s;
h2 =s;
yeq=h1*y(L)+h2*y(R);
end

function [yeq1,yeq2] = fn_interp2(x,y1,y2,xeq)
L = 1;
R = length(x);
while (R-L>1)
m=floor((L+R)/2);
if xeq > x(m)
	L=m;
elseif xeq < x(m)
	R=m;
else
	L = m;
	break
end


end

s = (xeq-x(L))/(x(R)-x(L));
h1 =1-s;
h2 =s;
yeq1=h1*y1(L)+h2*y1(R);
yeq2=h1*y2(L)+h2*y2(R);

end

function [yeq1,yeq2,yeq3] = fn_interp3(x,y1,y2,y3,xeq)
L = 1;
R = length(x);
while (R-L>1)
m=floor((L+R)/2);
if xeq > x(m)
	L=m;
elseif xeq < x(m)
	R=m;
else
	L = m;
	break
end


end

s = (xeq-x(L))/(x(R)-x(L));
h1 =1-s;
h2 =s;
yeq1=h1*y1(L)+h2*y1(R);
yeq2=h1*y2(L)+h2*y2(R);
yeq3=h1*y3(L)+h2*y3(R);
end