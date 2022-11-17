#include <iostream>
#include <cstdio>

using namespace std;
int rs[10][101]={};

void backtraking(int n,int k ,int D[],int D2[],int l,int c){
	// caso de semi-parada
	// se o numero de colunas for maior que n
	if(c>n){
        backtraking(n,k,D,D2,l+1,1);	// começa o algoritimo de uma nova fileira
        return;
    }
    // caso de parada
    // se o numero de linhas é maior que n
    if(l>n){
    	return;	// encerra esta execução
	}
	// configuração do backtraking
	if(!D[l+c] && !D2[n-l+c]){
        rs[n][k]++;
        D[l+c]=D2[n-l+c]=1;
        backtraking(n,k+1,D,D2,l,c+1);
        D[l+c]=D2[n-l+c]=0;
    }
    backtraking(n,k,D,D2,l,c+1);
}
int main(){
	int n,k;
	// calcula casos bases
	for(int n=1; n<=8; n++){
            int D[32]={},D2[32]={};
            backtraking(n,1,D,D2,1,1);
    }
    
    scanf("%d %d",&n,&k);
    getchar();
    while(n != 0){
    	if(k==0)
    		printf("1\n");
    	else
    		printf("%d\n",rs[n][k]);
    	scanf("%d %d",&n,&k);
    	getchar();
	}
}
