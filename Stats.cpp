#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <fstream>
using namespace std;
// Integer Data
//linear distribution of population
int* p; //population (pointer)( to be global)
void generatePopulation(int* p,int size)
{
	p = new int [size]	;
	// genearte a linear sampling population
	for(int i = 0;i<size;i++)
	{
		p[i]= i ;
	}
}
bool ifExists(int * data,int size,int val)
{
	for (int i=0;i<size;i++)
	{
		if(data[i]==val)return true;
	}
	return false;
}
void getSample(int sampleSize,int* samples/*assuming of desired sampleSize*/,int populationSize)
{
	// Randomly select m samples from population
	int m =sampleSize, samplesSelected=0;
	//Array to store Sample Data; ( 1xm )
	
	int * selectedDataIndex = new int [m];
	for(int i=0;i<m;i++)selectedDataIndex[i] = -1;// stores which data points were selected  ( by default  -1)
	while(samplesSelected!=m)
	{
		//generate  a random number between 0 & np ( including ends)
		//make sure random number doesn't occurs twice
		//take the samples & store in an array
		int n = rand()%populationSize;
		if(!ifExists(selectedDataIndex,populationSize,n))
		{
			samples[samplesSelected] = p[n];
			selectedDataIndex[samplesSelected]=n;
			samplesSelected++;
		}
	}
}
int main()
{
	generatePopulation(p,30);
	//size of array
	int np=sizeof(p)/sizeof(p[0]);
	
	//population mean
	float u=0;
	for ( int i = 0;i<np;i++)
	{
		u +=p[i];
	}
	u/=np;
	// population Varience 
	float pVar=0;
	for (int i = 0;i<np;i++)
	{
		pVar+=(p[i]-u)*(p[i]-u);	// assuming each data is equally likely
	}
	pVar/=np;
	cout<<"Population ->";
	for(int i=0;i<np;i++)
	{
		cout<<p[i]<<":";
	}
	cout<<endl;
	cout<<"population Size : "<<np<<endl;
	cout<<"Population Mean : "<<u<<endl;
	cout<<"Population Varience : "<<pVar<<endl;
	cout<<"press any key to continue...";
	char a ;
	cin>>a;
	cout<<endl;
	//sample Data
	int m = 1;	//sampling size
	int * s = new int [12];
	fstream file("data.csv");
	// Repeat the  sampling process  number of times
	for(int k = 0 ;k<1000;k++)
	{
		
		getSample(m,s,np);
		
		// store all respective parameters in an csv file
		
		
		// calculate mean of selected Data
		float sampleMean=0;
		for (int i=0;i<m;i++)
		{
			sampleMean+=s[i];
		}
		sampleMean/=m;
		//calculate varience of sampled data
		float sampleVar=0;
		for(int i=0;i<m;i++)
		{
			sampleVar+=(s[i]-sampleMean)*(s[i]-sampleMean);
		}
		sampleVar/=m;
		
			// print selected Data
		cout<<"selected Data ->";
		for(int i=0;i<m;i++)
		{
			cout<<s[i]<<":";
		}
		cout<<endl;
		cout<<"Sample Size : "<<m<<endl;
		file<<sampleMean<<","<<sampleVar<<endl;
		cout<<"Sample Mean : "<<sampleMean<<endl;
		cout<<"Sample Varience : "<< sampleVar<<endl;
	}
	file.close();
}
