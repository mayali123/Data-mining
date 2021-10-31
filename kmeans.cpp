#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int INF =  0x3f3f3f3;
// k代表簇数 n代表坐标的个数 
const int k=2,n=8,zz=2;
// 簇所包含的点
int point[k][n+10];
int last[k][n+10];
// 检查和之前是否一致 
int check()
{
	// 簇 
	for(int i=0;i<k;i++)
	{
		int z = point[i][0];
		for(int j=1;j<=z;j++)
		{
			int flag = 0;
			int z1 = last[i][0];
			for(int dd=1;dd<=z1;dd++)
			{
				if(last[i][dd]==point[i][j])
				{
					flag = 1;
					break; 
				}
			}
			if(!flag)
				return 0;
		}
	}
	return 1;
}
int main()
{
//	//	// 坐标 
//	double x[zz][n] = {{0,1,3,8,9,10},{0,2,1,8,10,7}};
//
// 	// 簇的中心坐标 
// 	double cx[zz][k] = {{0,1},{0,2}}; 
	
	// 坐标 
	double x[zz][n] = {{3,3,4,4,1,1,2,2},{1,2,1,2,3,4,3,4}};

 	// 簇的中心坐标 
 	double cx[zz][k] = {{0,3},{4,3}}; 
	
//	//	// 坐标 
//	double x[zz][n] = {{2,2,8,5,7,6,1,4},{10,5,4,8,5,4,2,9}};
//
// 	// 簇的中心坐标 
// 	double cx[zz][k] = {{2,5,1},{10,8,2}}; 
	
	
	// 第一次 
	int flag = -1;
	
	// 距离 
	double dist[k][n]={0};
	 
	while(flag<1||!check())
	{
		flag ++;  
		// 将point 复制到 last point
		for(int i=0;i<k;i++)
		{
			int z = point[i][0];
			last[i][0] = z;
			for(int j=1;j<=z;j++)
			{
				last[i][j] = point[i][j]; 
			} 
		}
		
		
		memset(point,0,sizeof(point));
		// 对于每一个点 
		for(int i=0;i<n;i++)
		{
			double Min = INF;
			int indx = 0;
			//对每一簇 求距离 
			for(int j=0;j<k;j++)
			{
				double he = 0;
				for(int dd=0;dd<zz;dd++)
					he += (x[dd][i] - cx[dd][j]) * (x[dd][i] - cx[dd][j]); 
				dist[j][i] = sqrt(he);
				if(Min>he)
				{
					Min = he;
					indx = j;
				} 
			}	
			int len = ++point[indx][0];
			point[indx][len] = i;
		} 
		
		// debug 输出距离
		cout<<flag<<":\n";
		for(int j=0;j<n;j++)
		{
			cout<<"第"<<j+1<<"点："; 
			for(int i=0;i<k;i++)
			{
				printf("%.2lf ",dist[i][j]);		
			}
			cout<<"\n";
		} 
		cout<<"\n\n";
		// debug 输出簇里的元素
		cout<<"\n";
		for(int i=0;i<k;i++)
		{
			int z = point[i][0];
			cout<<"第"<<i+1<<"簇包含:\n";
			for(int j=1;j<=z;j++)
			{
				cout<<point[i][j]+1<<" ";		
			}
			cout<<"\n";
		} 
		
		
		// 更新
		// 簇 
		for(int i=0;i<k;i++)
		{
			int z = point[i][0];
			// x y  
			for(int dd=0;dd<zz;dd++)
			{
				double he = 0;
				// 簇内 
				for(int j=1;j<=z;j++)
				{
					he += x[dd][point[i][j]]; 
				}
				cx[dd][i] = he/z; 
			}
		} 

	
//		// 更新簇
//		for(int i=0;i<k;i++)
//		{
//			double Min =INF ;
//			int z = point[i][0]; 
//			int indx = 1;
//			// 对于簇中的每一个点 
//			for(int j=1;j<=z;j++)
//			{
//				int now_point = point[i][j];
//				double he = 0;
//				// 其他点 
//				for(int dd = 1;dd<=z;dd++) 
//				{
//					double he1 = 0;
//					int other_point = point[i][dd];
//					// 维数 
//					for(int ff=0;ff<zz;ff++)
//					{
//						he1 += (x[ff][now_point] - x[ff][other_point])*(x[ff][now_point] - x[ff][other_point]);
//					}
//					he += sqrt(he1);
//				}
//				if(Min>he)
//				{
//					Min = he;
//					indx = now_point;
//				}
//				cout<<"第"<<now_point<<"点到其他点的距离"<<he<<"\n"; 
//			} 
//			// 维数 
//			for(int j=0;j<zz;j++) 
//				cx[j][i] = x[j][indx]; 
//		} 

		cout<<"簇的坐标:\n";
		for(int i=0;i<k;i++)
		{
			for(int j=0;j<zz;j++) 
				cout<<cx[j][i]<<" ";
			cout<<"\n";
		}
		cout<<"\n\n";
	}
		
	// 输出结果
	for(int i=0;i<k;i++)
	{
		int z = point[i][0];
		cout<<"第"<<i+1<<"簇包含:"; 
		for(int j =1;j<=z;j++)
			cout<<point[i][j]+1<<" ";
		cout<<"\n";	
	} 
	
	 
	return 0;
}
