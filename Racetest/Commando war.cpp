#include<vector>
#include<cstdio>
#include<algorithm>


using namespace std;
class Job{
	public:
		int j,b;
		bool operator < (const Job& x)const{
			return j<x.j;		
		}
		Job(int a,int y){
			j=a;
			b=y;
		}
};

int main(){
	int n ,b,j;
	while(scanf("%d",&n) == 1 &&n){
		printf("u input number:%d\n",n);
		vector<Job> array;
		for(int i=0; i<n; i++){
			scanf("%d%d",&j,&b);
			array.push_back(Job(j,b));
			printf("j=:%d\tb=%d\n",array.at(i).j,array.at(i).b);
		}
//		printf("%d",array.begin());
		sort(array.begin(),array.end());
			for(int i=0; i<n; i++){
			printf("j=:%d\tb=%d\n",array.at(i).j,array.at(i).b);
		}
		int ans=0;
		int s=0;
		
		for(int i=0; i<n; i++){
			s+= array[i].b;
			ans = max(ans,s+array[i].j);
		}
		printf("ans:%d",ans);
		return 0;
}
	
	
}
