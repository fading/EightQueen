#include<stdio.h>
// 按照所在列遍历所有行的可能性
void EQ(int play[][9],int *sol,int num);
int cross(int play[][9],int *sol,int indexr,int indexc);
int rowe(int play[][9],int *sol,int indexr,int indexc);
int main()
{
	int play[9][9]={{0},{0},{0},{0},{0},{0},{0},{0},{0}};
	int sol[9]={0};
	EQ(play,sol,1);//从第一列开始
}

//判定当前位置所在行是否有已填值
int rowe(int play[][9],int indexr)
{
	int i=1;
	for(;i<9;i++)
		if(play[indexr][i]==1)
			return 0;
	return 1;
}

//判定当前位置的斜向十字是否已填
int cross(int play[][9],int indexr,int indexc)
{
	int i,j;
	i = indexr;
	j=indexc;
	for(;i>=1&&j>=1;i--,j--){
		if(play[i][j]==1)
			return 0;
	}
	i = indexr;
	j=indexc;
	for(;i<=8&&j<=8;i++,j++){
		if(play[i][j]==1)
			return 0;
	}
	i = indexr;
	j=indexc;
	for(;i>=1&&j<=8;i--,j++){
		if(play[i][j]==1)
			return 0;
	}
	i = indexr;
	j=indexc;
	for(;i<=8&&j>=1;i++,j--){
		if(play[i][j]==1)
			return 0;
	}
	return 1;
}


void EQ(int play[][9],int *sol,int num)
{
	int i=1;
	if(num==9){
		int k=1;
		for(;k<=8;k++)
			printf("%d  ",sol[k]);
		printf("\n");
	}
	else if(num < 9)
	{
		for(;i<=8;i++){
			if(cross(play,sol,i,num)&&rowe(play,sol,i,num)){

				play[i][num]=1;
				sol[num]=i;
				EQ(play,sol,num+1);
				play[i][num]=0;
			}	
		}
	}
}
