#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<iostream.h>
#define pi 3.141592654
#define muo 0.000001256
int i;
float Et,K,KVA,m,Bm,Ki,f,PHIm,Ai,Agi,ct,d,p,q,r,s,KV,Kw,delta,ratio1,Aw,Hw,Ww,D,FDy,Ay,Agy,Dy,Hy,H,W,Df,Vls,Ctype,Vsp,Ts,Isp,as,x,y,delta1,as1,z,x1,y1,Ts1,lay,Lcs,cls,cly,bs,di,dc,lvi,Id,Od,st;
int c;
int c1;
float Vlp,Vpp,Tp,Vc,Nc,Vc1,Ncn,Nct,Tp1,Tp2,tp,tc,Ncl,Tncl,Ipp,ap,ap1;
float dp,dp1,dp2,Hlp,dbc,Lcp,clc,ti,bp,T,IDhv,ODhv,con,stp,ca,cr,dp3;
float Lmtp,Lmts,Dpm,Dsm,Rp,Rs,Ref,ep,rop,ros,Dm,Lmt,Lc,Xp,epx,epi,Li2r,Ls,Pi2r,Nl,Ny,Wl,Lcl,Wy,Lyl,Pi,Pc,Lt,eff,atc,aty,Mmmf,ATo,lm,ll,lo,per;


void design()
{
clrscr();
FILE *fp;
fp=fopen("C:\\design.txt","w");
printf("\n\n\n***CORE DESIGN***\n\n\n");
fprintf(fp,"\n\n\n***** CORE DESIGN OF THE TRANSFORMER *****\n\n\n");
printf("Enter the KVA rating of transformer:");
scanf("%f",&KVA);
fprintf(fp,"\nKVA rating of transformer is %.2fKVA",KVA);
printf("\nFor distribution transformer K=.45 \n For power transformer K=.6 to .7 \n");
printf("\nEnter the value of K: ");
scanf("%f",&K);
fprintf(fp,"\nValue of K is %.2f",K);
Et=K*sqrt(KVA);
fprintf(fp,"\nVoltage per turn is %.2f V",Et);
printf("\nEnter the value of line frequency(Hz):");
scanf("%f",&f);
printf("\nEnter the number of phase:");
scanf("%f",&m);
fprintf(fp,"\nNumber of phase of transformer is %.0f",m);
fprintf(fp,"\nLine frequency is %.0f Hz",f);
PHIm=Et/(4.44*f);
fprintf(fp,"\nFlux of core is %.6f Wb",PHIm);
printf("\nDistribution transformer Bm= 1 to 1.35 Wb/m^2\n Power transformer Bm= 1.25 to 1.45 Wb/m^2 \n Enter value of flux density:");
scanf("%f",&Bm);
fprintf(fp,"\nFlux density is %.4f Wb/m^2",Bm);
Ai=PHIm/Bm;
fprintf(fp,"\nNet iron area is %.6f m^2",Ai);
printf("\nNet iron area is %.6f m^2",Ai);
printf("\nEnter value of stacking factor:");
scanf("%f",&Ki);
fprintf(fp,"\nStacking factor is %.2f",Ki);
Agi=Ai/Ki;
fprintf(fp,"\nGross iron area is %.6f m^2",Agi);
printf("\nEnter type of core: \n 1. Square \n 2. cruciform \n 3. 3-stepped \n 4. 4-stepped \n");
scanf("%d",&i);
switch(i)
{
case 1:
fprintf(fp,"\nType of core is square");
ct=.45;
d=sqrt(Ai/ct);
fprintf(fp,"\nDiameter of core is %.4f m",d);
p=sqrt(.5)*d;
printf("\n The diamention is %f",p);
fprintf(fp,"\nThe diamention is %.3f",p);
break;
case 2:
fprintf(fp,"\nType of core is cruciform");
ct=.56;
d=sqrt(Ai/ct);
fprintf(fp,"\nDiameter of core is %.4f m",d);
p=.85*d;
q=.53*d;
printf("\n The diamention is %f%f",p,q);
fprintf(fp,"\nThe diamention is %.3f*%.3f",p,q);
break;
case 3:
fprintf(fp,"\nType of core is 3-stepped");
ct=.6;
d=sqrt(Ai/ct);
fprintf(fp,"\nDiameter of core is %.4f m",d);
p=.42*d;
q=.7*d;
r=.9*d;
printf("\n The diamention is %f%f%f",p,q,r);
fprintf(fp,"\nThe diamention is %.3f*%.3f*%.3f",p,q,r);
break;
case 4:
fprintf(fp,"\n Type of core is 4-stepped");
ct=.62;
d=sqrt(Ai/ct);
fprintf(fp,"\nDiameter of core is %.4f m",d);
p=.36*d;
q=.36*d;
r=.78*d;
s=.92*d;
printf("\nThe diamention is %f%f%f%f",p,q,r,s);
fprintf(fp,"\nThe diamention is %.3f*%.3f*%.3f*%.3f",p,q,r,s);
break;
}
clrscr();

printf("\n\n\n*** WINDOW DIMENSION ***\n\n\n");
fprintf(fp,"\n\n\n***WINDOW DIMENSION OF THE TRANSFORMER***\n\n\n");
printf("\nEnter the primary winding voltage: ");
scanf("%f",&KV);
fprintf(fp,"\nPrimary winding voltage is %.0f KV",KV);
fprintf(fp,"\nFlux density is %.4f Wb",Bm);
printf("\nEnter the current density(A/mm^2): ");
scanf("%f",&delta);
fprintf(fp,"\nCurrent density is %.2f A/mm^2",delta);
if(KVA>=1 && KVA<50)
Kw=8/(30+KV);
if(KVA>=50 && KVA<200)
Kw=10/(30+KV);
if(KVA>=200 && KVA<=1000)
Kw=12/(30+KV);
fprintf(fp,"\nWindow space factor is %.3f",Kw);
printf("\nThe calculated Window space factor is %f. \n Enter the modified Windows space factor: ",Kw);
scanf("%f",&Kw);
fprintf(fp,"\nModified window space factor is %.3f",Kw);
Aw=(KVA*1000)/(3.33*f*Bm*Kw*delta*Ai*1000000);
fprintf(fp,"\nArea of window is %.6f m^2",Aw);
printf("\nEnter the ratio height to width of the window(Range 2 to 4): ");
scanf("%f",&ratio1);
fprintf(fp,"\nRatio - Height to width of the window %.1f",ratio1);
Ww=sqrt(Aw/ratio1);
fprintf(fp,"\nWidth of window is %.3f m",Ww);
Hw=Ww*ratio1;
fprintf(fp,"\nHeight of window is %.3f m",Hw);
printf("\nThe calculated height and width of window are %f and %f. \n\n Enter modified height and width of window(m): ",Hw,Ww);
scanf("%f%f",&Hw,&Ww);
fprintf(fp,"\nModified height and width of window are %.3f m and %.3f m",Hw,Ww);
D=Ww+d;
fprintf(fp,"\nDistance beteween adjacent core is  %.3f m",D);
clrscr();
printf("\n\n\n***YOKE DESIGN***\n\n\n");
fprintf(fp,"\n\n\n***YOKE DESIGN OF TRANSFORMER***\n\n\n");
printf("\nArea of the yoke is 15-25% larger than the core(%f m^2) of the transformer\n",Ai);
printf("\nEnter the ratio- area of yoke to limbs: ");
scanf("%f",&ratio1);
fprintf(fp,"The ratio - area of yoke to limbs is %.2f",ratio1);
FDy=Bm/ratio1;
fprintf(fp,"\nFlux density in the yoke id %.6f Wb/m^2",FDy);
Ay=ratio1*(PHIm/Bm);
fprintf(fp,"\nArea of yoke is  %.6f m^2",Ay);
Agy=Ay/Ki;
fprintf(fp,"\nGross area of yoke is %.6f m^2",Agy);
printf("\nSelect the section of yoke is rectangular\n Take the depth of yoke as highest side of laminated core\n");
fprintf(fp,"\nSelected the section of yoke is rectangular\n Taking the depth of yoke as highest side of laminated core\n");
printf("\nDimensions of laminated core is %.3f * %.3f * %.3f * %.3f(in m) \n",p,q,r,s);
printf("\nEnter the value of depth of yoke(m): ");
scanf("%f",&Dy);
fprintf(fp,"\nDepth of yoke is  %.4f m",Dy);
Hy=Agy/Dy;
fprintf(fp,"\nHeight of yoke is %.4f m",Hy);
clrscr();
printf("\n\n\n ***OVERALL DIMENSION***\n");
fprintf(fp,"\n\n\n ***OVERALL DIMENSION OF TRANSFORMER ***\n");
D=d+Ww;
fprintf(fp,"\nDistance between adjacent core centers is %.3f m",D);
H=Hw+2*Hy;
fprintf(fp,"\nHeight of the frame is %.3f m",H);
W=2*D+Dy;
fprintf(fp,"\nWidth of the frame is  %.3f m",W);
Df=Dy;
fprintf(fp,"\nDepth of the frame is  %.3f m",Df);
clrscr();
printf("\n\n\n*** LOW VOLTAGE DESIGN*** \n\n\n");
fprintf(fp,"\n\n\n *** LOW VOLTAGE WINDING CALCULATION OF TRANSFORMER *** \n\n\n");
printf("\nEnter seconday line voltage(V):");
scanf("%f",&Vls);
fprintf(fp,"\s Secondary Line voltage is %.2f V",Vls);
printf("\n Enter the connection type\n 1-Star \n 2-Delta \n:");
scanf("%d",&c1);
switch(c1)
{
case 1:
fprintf(fp,"\nConnection type is Star");
Vsp=Vls/sqrt(3);
fprintf(fp,"\n Phase voltage is %.3f V",Vsp);
break;
case 2:
fprintf(fp,"\nconnection type is delta");
Vsp=Vls;
fprintf(fp,"\n Phase voltage is %.3f V",Vsp);
break;
}
Ts=int(Vsp/Et);
fprintf(fp,"\n Turn per phase is %0.0f",Ts);
Isp=(KVA*1000)/(3*Vsp);
fprintf(fp,"\n Secondary current per phase is %0.3f",Isp);
printf("\n Distribution Transformer current density is 1.1 to 2.3 A/mm^2 \n Power transformer\n (i)self oil cooled type or air blast - current density is 2.2 to 3.2 A/mm^2 \n (ii) Forced circulation of oil with water cooling - current density is 5.4 to 6.2 A/mm^2 \n \n Enter current density (A/mm^2):\n");
scanf("%f",&delta);
fprintf(fp,"\n Current density in secondary phase is %.2f A/mm^2",delta);
as=Isp/delta;
fprintf(fp,"\nTotal area of secondary conductor is %.3f mm^2",as);
printf("\nTotal area of secondary conductor is %.3f mm^2",as);
printf("\n Enter number of strips: ");
scanf("%f",&st);
printf("\n Area of each conductor is %.3f mm^2 \n",(as/st));
fprintf(fp,"\nTo provide %.f mm^2 area,the number of conductor is %.f",as,st);
printf("\nUse the proper conductor(23.1//IS:1897-1962//)and Enter the dimension (mm):");
scanf("%f%f",&x,&y);
fprintf(fp,"\n Dimension of the conductor is %.3f * %.3f",x,y);
as1=st*x*y;
fprintf(fp,"\n Modified area of secondary conductor is %.3fmm^2",as1);
delta1=Isp/as1;
fprintf(fp,"\n modified current density in secondary phase is %.2f A/mm^2 ",delta1);
printf("\n Enter the proper value covering(mm):");
scanf("%f",&z);
fprintf(fp,"\n Covering of the conductor is %.3f mm",z);
x1=x+z;
y1=y+z;
fprintf(fp,"\n Dimension of the conductor with covering is %.3f * %.3f",x1,y1);
printf("\n The turn per phase is %d. \n",int(Ts));
printf("\n Enter the number of layers to be used:");
scanf("%f",&lay);
fprintf(fp,"\n Number of layers used is %.0f",lay);
printf("\n Using hellical winding space to be provided %.3f turns along the axis \n ",(Ts/lay)+1);
fprintf(fp,"\n Using hellical winding space to be provided %.3f along the axis \n",(Ts/lay)+1);
Ts1=int((Ts/lay)+1);
fprintf(fp,"\n Turns along the axial depth is %.f",Ts1);
Lcs=Ts1*x1;
printf("\n Axial depth of LV winding is %.3f mm \n",Lcs);
fprintf(fp,"\n Axial depth of LV winding is %.3f mm \n",Lcs);
cls=(Hw*1000-Lcs)/2;
fprintf(fp,"\n Clearance is %.3f mm",cls);
if(cls<6)
{
printf("\n The calculation does not satisfy(6) minimum clearance. Recalculate. ");
fprintf(fp,"\n The calculation does not satisfy(6) minimum clearance. Recalculate. ");
}
printf("\n Enter the thickness of pressboard cylinders (mm): ");
scanf("%f",&cly);
fprintf(fp,"\n thickness of pressboard cylinders is %.3f mm ",cly);
bs=lay*y1+2*cly;
fprintf(fp,"\n Radial depth of LV winding is %.3f mm",bs);
printf("\n Enter the insulation for the circumscribing circle 0.5 mm)");
scanf("%f",&di);
fprintf(fp,"\n Insulation for the circumscribing circle is %.3f mm",di);
printf("\n Enter the insulation between LV winding and core (1.5 mm) ");
scanf("%f",&lvi);
fprintf(fp,"\n Insulation between LV winding and core is %.3f mm",lvi);
dc=d+(di/100);
fprintf(fp,"\n Diameter of the circumscribing circle is %.3f mm",dc);
Id=dc*1000+2*lvi;
fprintf(fp,"\n Inside diameter is %.3f mm",Id);
Od=Id+ 2*bs;
fprintf(fp,"\n Outside diameter is %.3f mm",Od);
clrscr();
printf("\n\n\n*** HIGH VOLTAGE WINDING DESIGN ***\n\n\n");
fprintf(fp,"\n\n\n***HIGH VOLTAGE WINDING DESIGN OF TRANSFORMER *** \n\n\n");
printf("\n Enter the Primary Line voltage (V): \n");
scanf("%f",&Vlp);
fprintf(fp,"\n The primary line voltage is %.2f V",Vlp);
connection:
printf("\n Enter connection Type \n 1-star \n 2-delta \n");
scanf("%d",&c);
if(c==1||c==2)
{
switch(c)
{
case 1:
fprintf(fp,"\n Connection type is star");
Vpp=Vlp/sqrt(3);
break;
case 2:
fprintf(fp,"\n Connection type is Delta");
Vpp=Vlp;
break;
}
}
else
goto connection;
fprintf(fp,"\n Primary phase voltage is %.3f V",Vpp);
Tp=int((Ts*Vpp)/Vsp);
fprintf(fp,"\n Primary turn per phase is %.0f",Tp);
tapping:
printf("\n Press 1 for no tapping \n Press 2 for tapping \n");
int t;
scanf("%d",&t);
if(t==2)
{
printf("\n Enter % tapping \n");
scanf("%f",&tp);
fprintf(fp,"\n Tapping is considered here. Percentage of tapping is %.3f %",tp);
Tp1=int(((tp/100)+1)*Tp);
fprintf(fp,"\n Primary turns per phase with %.3 f tapping is %.0f",tp,Tp1);
}
else
if(t==1)
{
fprintf(fp,"\n There is no tapping. ");
Tp1=Tp;
}
else
goto tapping;
NOC:
printf("\n Actual number of turns per phase is %.0f \n",Tp1);
fprintf(fp,"\n Crossover winding is used here. \n");
printf("\n Crossover winding is used here. \n Enter voltage per coil: ");
scanf("%f",&Vc);
fprintf(fp,"\n The value of voltage per coil is %.3f V",Vc);
Nc=int(Vlp/Vc);
fprintf(fp,"\n Number of coils is %.0f",Nc);
printf("\n The calculated number of coil is %.0f. \n Enter the new value (>%.0f). \n ",Nc,Nc);
scanf("%f",&Nc);
fprintf(fp,"\n Modified Number of coil is %.0f",Nc);
Vc1=Vpp/Nc;
fprintf(fp,"\n Modified value of voltage per coil is %.3f V",Vc1);
tc=Tp1/Nc;
fprintf(fp,"\n Turns per coil is %.0f",tc);
printf("\n Total number of coil is %.0f ",Nc);
printf("\n Enter number of normal coil: ");
scanf("%f",&Ncn);
printf("\n Enter number of turns of normal coil. ");
scanf("%f",&Nct);
fprintf(fp,"\n Number of turns of normal coil is %.0f \n Reinforced turns in remaining %.0f coil is %.0f.",Nct,(Nc-Ncn),(Tp1-(Ncn*Nct)));
Tp2=(Ncn*Nct)+((Nc-Ncn)*(Tp1-(Ncn*Nct)));
printf("\n Total turns is %.0f \n\n Enter number of layers:\n",Tp1);
scanf("%f",Ncl);
fprintf(fp,"\n Number of layers is %.0f",Ncl);
Tncl=Nct/Ncl;
fprintf(fp,"\n Turns per layer is %.0f",Tncl);
if(2*Ncl*Et > 300)
{
printf("\n WARNING !! Further calculation may cause some error. The value of 2*Ncl*Et exceeds 300. \n Change the value of voltage per coil or turns per coil.");
fprintf(fp,"\n WARNING !! Further calculation may cause some error. The value of 2*Ncl*Et exceeds 300. \n Change the value of voltage per coil or turns per coil.");
goto NOC;
}


     Ipp=(KVA*1000)/(3*Vpp);
     fprintf(fp,"\nPrimary current per phase is %0.3f A",Ipp);
     if(Ipp<=20)
{
              printf("\ncurrent is below 20A.Cross Over winding is use here.\n");
              fprintf(fp,"\ncurrent is below 20A .Cross over winding is used here ");
 }
printf("\nEnter the current density in primary conductor (A/mm^2).");
scanf("%f",&delta);
fprintf(fp,"\ncurrent density in the primary conductor is%0.3fA/mm^2",delta );
ap=Ipp/delta;    //Area of the primary conductor
printf("\nEnter the type of conductor .\n1-Round conductor.\n2-Rectangular conductor\n");
scanf("%f",&con);
if(con==1)   
{
fprintf(fp,"\nArea of the primary conductoris %0.3f mm^2",ap);
dp=sqrt((4*ap)/pi);         //Diameter of the primary conductor
fprintf(fp,"\n Diameter of the primary conductor is %0.3f mm",dp);
printf("\n Calculated value of the diamater of primary conductor is %0.3f mm.\n",dp);
printf("\nEnter the nearest standard value of the diameter(mm).");
scanf("%f",&dp1);
printf("\nEnter the nearest standard value of the diameter proper insulation(mm).");
fprintf(fp,"\nStandard value of the diameter proper insulation is%0.3f mm",dp2);
ap1=((pi*dp1*dp1)/4);          //Modified diameter of primary conductor
fprintf(fp,"\nModified area of primary conductor is %0.3 mm^2",ap1);     
}
if(con==2)
{      
printf("\nArea of  primary conductor is%0.3f mm^2 \n",ap);
fprintf(fp,"\nArea of primary conductor is %o.3f mm^2\n",ap);
printf("\nEnter the number of strips:");
scanf("%f",&stp);
fprintf(fp,"\nNumber of strips is %0.0f",stp);
printf("\nEnter the diamension of the conductor in mm:");
scanf("%f%f",&dp1,&dp2);
fprintf(fp,"\nThe dimension of the conductor in mm is %0.3f * %0.3f",dp1,dp2);
printf("\nEnter the number coil in axial:");
scanf("%f",&ca);
fprintf(fp,"\nNumber of coil in axial is %0.0f",ca);
printf("\nEnter the number of coil in radial:");
scanf("%f",&cr);
fprintf(fp,"\nNumber of coil in radial is %0.3f ",cr);
printf("\nEnter the proper value insulation (in mm): ");
scanf("%f",&dp3);
fprintf(fp,"\nDimension of the insulated conductor is %0.3f * %0.3f in mm",(dp1+dp3),(dp2+dp3));
ap1=stp*(dp1+dp3)*(dp2+dp3);
fprintf(fp,"\nModified area of the conductor is %0.3f mm ^2",ap1);
}
delta=(Ipp/ap1);                      //Current density in the primary conductor
fprintf(fp,"\nModified current density in the primary conductor is %.3f A/mm^2",delta1);
if(con==2)
           Hlp=ca*dp2;
Hlp=Tncl*dp2;                                      //Axial depth of the coil
fprintf(fp,"\nAxial depth of one coil is %0.3f mm",Hlp);
printf("\nEnter the space between adjacent coil(mm)");
scanf("%f",&dbc);
fprintf(fp,"\nSpace between adjacent coil is %0.1f mm",dbc);
Lcp=(Nc*Hlp)+(Nc+dbc);                           //Axial Length of the coil
fprintf(fp,"\nAxial Length of the coil is %0.3f mm",Lcp);
clc=(Hw*1000-Lcp)/2;                              //Clearence
fprintf(fp,"\nClearence is %0.3f mm",clc);
printf("\nEnter the thickness of insulation between the layers(mm)");
scanf("%f",&ti);
fprintf(fp,"\nThickness of insulation between the layers is %0.3f mm",ti);
if(con==2)
      bp=cr*dp2;
bp=(Ncl*dp2)+(Ncl-1)*ti;           //Radial depth of the coil
fprintf(fp,"\nRadial depth of the coil is %0.3f mm",bp);
T=5+((0.9*Vlp)/1000);                //Thickness of insulation b/w LV & HV
fprintf(fp,"\nThickness of insulation b/w LV & HV is 0.3f mm",T);
IDhv=Od+2*T;                           //Inside diameter of HV
fprintf(fp,"\nInside diameter of the HV is %0.3f mm",IDhv);
ODhv=IDhv+2*bp;                  //Outside diameter pf HV
fprintf(fp,"\nOutside diameter of the HV %0.3f mm",ODhv);
clrscr();
printf ("*** \n\n\n RESISTANCE CALCULATION ****\n");
fprintf(fp,"\n\n\n ***RESISTANCE DESIGN OF THE TRANSFOEMER *** \n\n");
Dpm=(IDhv+ODhv)/2;   
fprintf(fp,"Mean diameter of HV winding is % 0.3f mm",Dpm);
Lmtp=(pi*Dpm)/1000;    
fprintf(fp,"\nLenth of mean turn in HV winding is %0.3f",Lmtp);
printf("\nEnter the Resistivity of the material of high voltage winding (0.021-default)");
scanf("%f",&rop);
fprintf(fp,"\nResistivity of the material is %0.4f",rop);
Rp=(Tp*Lmtp*rop)/ap1;                      
fprintf(fp,"\nResistivity of the material is %0.4f",Rp);
Dsm=(Id+Od)/2;       
fprintf(fp,"\nLength of mean turn in LV winding is %0.3f mm",Dsm);
Lmts=(pi*Dsm)/1000;    
fprintf(fp,"\nLength of mean turn in LV winding is %0.3f mm",Lmts);
printf("\nEnter the Resistivity of the material of low voltage winding (0.21-default)");
scanf("%f",&ros);
fprintf(fp,"\nResistivity of the material is %0.4f",ros);
Rs=(Ts*Lmts*ros)/as1;
fprintf(fp,"\nResistance in LV side is %.4f Ohm",Rs);
Ref=Rp+(((Tp*Tp)/(Ts*Ts))*Rs);     
fprintf(fp,"\nResistance reffered to primary side is %0.4f ohm",Ref);
ep=(Ipp*Ref)/Vlp;       
fprintf(fp,"\nPer unit resistance is %0.4f",ep);
clrscr();
printf("\n\n\n*** LEAKAGE REACTANCE ***\n\n\n");
fprintf(fp,"\n\n\n***CALCULATION OF LEAKAGE REACTANCE OF THE TRANSFORMER***\n\n\n ");
Dm=(IDhv+ODhv)/2;
fprintf(fp,"\n Mean diameter of winding is %.3f mm",Dm);
Lmt=(pi*Dm)/1000;
fprintf(fp,"\n Length of mean turn of winding is %.3f m",Lmt);
Lc=(Lcp+Lcs)/2;
fprintf(fp,"\n Mean axial length of winding is %.3f mm",Lc);
Xp=(2*pi*f*muo*Tp*Tp*Lmt*(T+(bp+bs)/3))/Lc;
fprintf(fp,"\n Leakage reactance reffered to primary side is %.3f Ohm",Xp);
epx=(Ipp*Xp)/Vpp;
fprintf(fp,"\n Per unit leakage reactance is %.3f ",epx);
epi=sqrt((ep*ep)+(epx*epx));
fprintf(fp,"\n Per unit impedence is %.3f ",epi);
clrscr();
	printf("\n\n\n ***LOSS CALCULATION *** \n");
	Li2r=3*Ipp*Ipp*Ref;
	fprintf(fp,"I^2R Loss is %.3 f W",Li2r);
	printf("\nCopper loss is %.3f W\n",Li2r);
	printf("\nEnter percentage stray Loss(5 to 25% of copper loss:\n");
	scanf("%f",&Ls);
	fprintf(fp,"\n Percentage stray loss is %.3f",Ls);
	Pi2r=(1+Ls/100)*Li2r;
	fprintf(fp,"\nI^2R Loss including stray loss is %3f W ",Pi2r);
printf("\nEnter the density of lamination");
scanf("%f",&y);
fprintf(fp,"\nDensity of lamination is %.3f kg/m^2",y);
printf("Enter the no of limbs");
scanf("%f",&Nl);
Wl=Nl*Hw*Ai*y;
fprintf(fp,"\nWeight of the %.0f limbs is % .3 f Kg",Nl,Wl);
printf("\nEnter specific core loss(W/kg) according to Flux density in the limbs(%.3f Wm/m^2)",Bm);
scanf("%f",&z);
fprintf(fp,"\nSpecific core loss is %.3f W/kg",z);
Lcl=Wl*z;
fprintf(fp,"\nCore loss in limbs is %.3f W",Lcl);
printf("\nEnter number of yokes:");
scanf("%f",&Ny);
printf("\nEnter the density of laminations(7.6e3 Kg/m^2)");
scanf("%f",&y);
fprintf(fp,"\nDensity of laminations is %.3f kg/m^2",y);
Wy=Ny*W*Ay*y;
fprintf(fp,"\nWeight of the yokes is  %.3f Kg",Wy);
printf("\nEnter the specific core loss according to flux density in the yoke:",FDy);
scanf("%f",&z);
fprintf(fp,"\nSpecific core loss is %.3f W/kg",z);
Lyl=Wy*z;
fprintf(fp,"\ncore loss in the yoke is % .3f W",Lyl);
Pi=Lcl+Lyl;
fprintf(fp,"\nTotal core loss is % .3f W ",Pi);
clrscr();
printf("\n\n\n*** EFFICIENCY *** \n\n\n");
fprintf(fp,"\n\n\n***EFFICIENCY OF TRANSFORMER***\n\n\nn");
Lt=Pi+Pi2r;
fprintf(fp,"\n Total loss is %.3f W",Lt);
eff=(KVA*1000/((KVA*1000)+Lt))*100;
fprintf(fp,"\n Efficiency of transformer is %.2f",eff);
x=sqrt(Pi/Pi2r);
fprintf(fp,"\nCondition for maximum efficiency is %.3f",x);
fclose(fp);
}
void main()
{
design();
getch();
}