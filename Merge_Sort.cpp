#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include<ctime>
#include<cstdlib>

using namespace std;

class MergeSort{
	vector<int>numList;
	
public:
	void fnGenRandArray(int);
	void fnSortArray();
	void fnDispArray();
	void fnMergeSort(int ,int);
	void fnMerge(int ,int ,int);
};

int main(){
	struct timespec tv;
	int iChoice,i,iNum;
	double dStart,dEnd;
	MergeSort myListObj;
	ofstream fout("MergePlot.dat",ios::out);
	
	srand(time(NULL));
	
	FILE *gnuplot=nullptr;
	
	do{
		cout<<"\n1.plot the graph\n2.MergeSort\n3.exit";
		cout<<"\n enter your choice:";
		cin>>iChoice;
		
		switch(iChoice){
			case 1:
				for(i=100;i<10000;i+=100){
					myListObj.fnGenRandArray(i);
					clock_gettime(CLOCK_REALTIME,&tv);
					dStart=tv.tv_sec+tv.tv_nsec/1e9;
					myListObj.fnSortArray();
					clock_gettime(CLOCK_REALTIME,&tv);
					dEnd=tv.tv_sec+tv.tv_nsec/1e9;
					fout<<i<<"\t"<<setprecision(10)<<dEnd-dStart<<endl;
					}
					cout<<"\ndata file generated and stored in file<MergePlot.dat>\n";
					gnuplot=popen("gnuplot -persist","w");
					if(!gnuplot){
						cerr<<"error opening gnuplot!"<<endl;
						return 1;
					}
					fprintf(gnuplot,"plot 'MergePlot.dat'using 1:2 with lines title 'Time Complexity '\n");
					pclose(gnuplot);
					break;
			case 2:
				cout<<"\nenter number of elements to sort:";
				cin>>iNum;
				myListObj.fnGenRandArray(iNum);
				cout<<"\nunsorted array:\n";
				myListObj.fnDispArray();
				myListObj.fnSortArray();
				cout<<"\nsorted array:\n";
				myListObj.fnDispArray();
				break;
			case 3:
				fout.close();
				exit(0);
				
			default:
				cout<<"\ninvalid choice! please enter 1,2,or3.\n";
				}
			}while(true);
			return 0;
		}
			
void MergeSort::fnGenRandArray(int n){
	numList.clear();
	for(int i=0;i<n;i++){
		numList.push_back(rand()%10000);
	}
}

void MergeSort::fnDispArray(){
	for(int num:numList){
	cout<<num<<" ";
	}
	cout<<endl;
}

void MergeSort::fnSortArray(){
	if(!numList.empty()){
		fnMergeSort(0, numList.size()-1);
	}
}
		
void MergeSort::fnMergeSort(int left,int right){
	if(left<right){
		int mid=left+(right-left)/2;
		fnMergeSort(left,mid);
		fnMergeSort(mid+1,right);
		fnMerge(left,mid,right);
	}
}

void MergeSort::fnMerge(int left, int mid, int right){
	vector<int>temp;
	int i=left,j=mid+1;
	
	while(i<=mid&&j<=right){
		if(numList[i]<=numList[j]){
			temp.push_back(numList[i]);
			i++;
		}else{
			temp.push_back(numList[j]);
			j++;
		}
	}
	
	while(i<=mid){
		temp.push_back(numList[i]);
		i++;
	}
	
	while(j<=right){
		temp.push_back(numList[j]);
		j++;
	}
	
	for(size_t i=0;i<temp.size();i++){
		numList[left+i]=temp[i];
	}
}
