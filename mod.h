void mod(u64 *x, u64 div){
	u64 n=*x,c=1,mask,rem,num,coeff;
	msu32 hbit;
	_BitScanReverse64(&hbit,div);
	hbit+=1;
	mask=(1<<hbit)-1;
	coeff=mask+1-div;
	if(n<(2*div)){c=0;}
	while(c!=0){
		rem=n&mask;
		num=n>>hbit;
		n=(coeff*num)+rem;
		if(n<(2*div)){c=0;}
	}
	if(n>div){n-=div;}
	if(n==div){n=0;}
	
	*x=n;
}

void qmod(u64 *x, u64 div){
	u64 n=*x,c=1,mask,rem,num,coeff;
	msu32 hbit;
	_BitScanReverse64(&hbit,div);
	hbit+=1;
	mask=(1<<hbit)-1;
	rem=n&mask;
	num=(1<<hbit)-div;
	n>>=hbit;
	while(c!=0){
		rem+=num&(0-(n&1));
		n>>=1;
		num<<=1;
		if(num>=div){num-=div;}
		if(n==0 && rem>=div){
			n=rem;
			rem=n&mask;
			n>>=hbit;
			num=(1<<hbit)-div;}
		c=n;
	}
	if(rem>=div){rem-=div;}
	*x=rem;
}
