#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include<ctime>
#include<cstdlib>

using namespace std;

class QuickSort{
	vector<int>numList;
	
public:
	void fnGenRandArray(int);
	void fnQuickSort(int , int);
	void fnDispArray();
	int fnPartition(int ,int);
	void fnSwap(int &,int &);
};

int main(){
	srand(time(NULL));
	
	FILE *gnuplot=nullptr;
	
	struct timespec tv;
	int iChoice,i,iNum;
	double dStart,dEnd;
	QuickSort myListObj;
	ofstream fout("QuickPlot.dat",ios::out);
	
	while(true){
		cout<<"\n1.Plot the graph\n2.Quick Sort\n3.Exit";
		cout<<"\nEnter your choice:";
		cin>>iChoice;
		
		switch(iChoice){
			case 1:
				for(i=5;i<=5;i+=5){
					myListObj.fnGenRandArray(i);
					clock_gettime(CLOCK_REALTIME,&tv);
					dStart=tv.tv_sec+tv.tv_nsec/1e9;
					myListObj.fnQuickSort(0,i-1);
					clock_gettime(CLOCK_REALTIME,&tv);
					dEnd=tv.tv_sec+tv.tv_nsec/1e9;
					
					fout<<i<<"\t"<<setprecision(10)<<dEnd-dStart<<endl;
				}
				cout<<"\nData file generated QuickPlot.dat. Use a plotting utility\n";
				
				gnuplot=popen("gnuplot -persist","w");
				if(!gnuplot){
					cerr<<"Error opening Gnuplot!"<<endl;
					return 1;
				}
				fprintf(gnuplot,"plot 'QuickPlot.dat' using 1:2 lines with title 'Time Complexity'\n");
				pclose(gnuplot);
				break;
				
			case 2:
				cout<<"\nEnter number of elements to sort:";
				cin>>iNum;
				myListObj.fnGenRandArray(iNum);
				
				cout<<"\nUnsorted Array:\n";
				myListObj.fnDispArray();
				
				myListObj.fnQuickSort(0,iNum-1);
				
				cout<<"\nSorted Array:\n";
				myListObj.fnDispArray();
				break;
				
			case 3:
				fout.close();
				return 0;
				
			default:
				cout<<"\nInvalid choice! Try again.\n";
		}
	}
}

int QuickSort::fnPartition(int l,int r){
	int pivot = numList[l], i=l+1,j=r;
	
	while(i<= j){
		while(i<=r && numList[i] < pivot) i++;
		while(numList[j] > pivot) j--;
	
		if(i<j){
			fnSwap(numList[i],numList[j]);
		}
	}
	fnSwap(numList[l],numList[j]);
	return j;
}

void QuickSort::fnQuickSort(int l,int r){
	if(l < r){
		int s = fnPartition(l,r);
		fnQuickSort(l,s-1);
		fnQuickSort(s+1,r);
	}
}

void QuickSort::fnGenRandArray(int n){
	numList.clear();
	for(int i=0;i<n;i++){
		numList.push_back(rand()%10000);
	}
}

void QuickSort::fnDispArray(){
	for(int val:numList){
	cout<<setw(8)<<val<<endl;
	}
}

void QuickSort::fnSwap(int &a,int &b){
	int temp = a;
	a = b;
	b = temp;
}
