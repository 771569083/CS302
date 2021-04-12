#include <stdio.h>
int main(){
	int i,N,temp,num=1,max=0;
	scanf("%d",&N);
	int a[N],b[N];
	for(i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<N;i++){
		b[i]=0;
	}
	
	for(i=0;i<N;i++){
		temp=i;
		if(a[i]<=a[i+1])num++;
		else{
			if(max<=num){
				max=num;
				printf("%d\n",num);
				num=1;
				for(int j=0;j<max;j++){
					b[j] = a[i-max+1+j];
			}}
			else num=1;
		
	}
	}
	for(i=0;i<max;i++){
		printf("%d ",b[i]);
	}

}
