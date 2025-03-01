#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include<ctime>
#include<cstdlib>

using namespace std;

class SelectionSort{
	vector<int>numList;
	
public:
	void fnGenRandArray(int);
	void fnSortArray();
	void fnDispArray();
  void fnSwap(int &,int &);
};

int main(){
	struct timespec tv;
	int iChoice,i,iNum;
	double dStart,dEnd;
	MergeSort myListObj;
	ofstream fout("SelectPlot.dat",ios::out);
	
	srand(time(NULL));
	
	FILE *gnuplot=nullptr;
	
	do{
		cout<<"\n1.plot the graph\n2.Selection Sort\n3.exit";
		cout<<"\n enter your choice:";
		cin>>iChoice;
		
		switch(iChoice){
			case 1:
				for(i=100;i<10000;i+=100){
					myListObj.fnGenRandArray(i);
					clock_gettime(CLOCK_REALTIME,&tv);
					dStart=tv.tv_sec+tv.tv_nsec/1000000000.0;
					myListObj.fnSortArray();
					clock_gettime(CLOCK_REALTIME,&tv);
					dEnd=tv.tv_sec+tv.tv_nsec/100000000.0;
					fout<<i<<"\t"<<setprecision(10)<<dEnd-dStart<<endl;
					}
					cout<<"\ndata file generated and stored in file<SelectPlot.dat>\n";
					gnuplot=popen("gnuplot -persist","w");
					if(!gnuplot){
						cerr<<"error opening gnuplot!"<<endl;
						return 1;
					}
					fprintf(gnuplot,"plot 'SelectPlot.dat'using 1:2 with lines title 'Time Complexity '\n");
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
			
void SelectionSort::fnGenRandArray(int n){
	numList.clear();
	for(int i=0;i<n;i++){
		numList.push_back(rand()%10000);
	}
}

void SelectionSort::fnDispArray(){
  int n=numList.size();
	for(int num:numList){
	cout<<setw(8)<<num<<endl;
  }
}

void SelectionSort::fnSortArray(){
  int n= numList.size();
  for(int i=0;i<n-1;i++) {
    int min_idx = i;
    for (int j=i+1; j<n;j++) {
      if(numList[j]<numList[min_idx])
      {
        min_idx=j;
      }
      if(i!= min_idx)
        fnSwap(numList[i],numList[min_idx]);
	}
}
		
void SelectionSort::fnSwap(int &a,int &b){
  int temp=a;
  a=b;
  b=temp;
}
