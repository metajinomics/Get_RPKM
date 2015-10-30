//This script Get normalization by using RPKM
// usage:  g++ Get_RPKM.cpp -o Get_RPKM
// ./Get_RPKM input output
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <dirent.h>
#include <vector>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
  int checkFile(ifstream &input); 
  int fileToDataTap (string filenameDIR,vector <vector <string> > &data);
  void printMatrix(vector <vector <string> > &dad);


  if (argc!=3){
    cout<<"usage: ./GetNorRPKM input output"<< endl <<flush;
    return 1;
  }
  cout<<"running"<<endl<<flush;
  //open file
  string filename = argv[1];
  vector <vector <string> > data;
  fileToDataTap(filename,data);
  //printMatrix(data);

  //get Double table
  vector <vector <double> > Ddata;
  for (int i=1;i<data.size();i++){
    vector <double> Dtemp;
    for (int j=3;j<data[i].size();j++){
      Dtemp.push_back(atof(data[i][j].c_str()));
    }
    Ddata.push_back(Dtemp);
  }

  //get length
  vector <double> length;
  for(int i=1;i<data.size();i++){
    length.push_back(atof(data[i][1].c_str()));
  }

  //for(int i=0;i<length.size();i++){
  //cout<<length[i]<<endl<<flush;
  //}

  //get total
  vector <double> sum;
  for(int i=0; i<Ddata[0].size();i++){
    double total = 0;
    for (int j=0;j<Ddata.size();j++){
      total = total + Ddata[j][i];
    }
    sum.push_back(total);
  }
  //cout<<sum.size()<<endl<<flush;
  //cout<<Ddata[0].size()<<endl<<flush;
  //18
  //cout<<Ddata.size()<<endl<<flush;
  //3236
  for (int i=0;i<Ddata.size();i++){
    for (int j=0;j<Ddata[i].size();j++){
      //step 1: multiply 10^9
      Ddata[i][j] = Ddata[i][j]*1000000000;
      //cout<<Ddata[i][j]<<endl<<flush;
      //step 2 div total mapped read
      double div = sum[j];
      if(div==0){div=1;}
      Ddata[i][j] = Ddata[i][j]/div;
      //cout<<Ddata[i][j]<<endl<<flush;
      //step 3 div exon length
      double divl = length[i];
      if(divl==0){divl=1;}
      Ddata[i][j] = Ddata[i][j]/divl;
      //cout<<Ddata[i][j]<<endl<<flush;
      //cout<<Ddata[i].size()<<endl<<flush;
    }
  }
  /*
    cout<<endl<<flush;
for(int i=0;i<Ddata[3234].size();i++){
cout<<Ddata[3234][i]<<endl<<flush;
}
cout<<endl<<flush;
for(int i=0;i<Ddata[3235].size();i++){
cout<<Ddata[3235][i]<<endl<<flush;
}
  */
  //file for result
  ofstream myfile;
  myfile.open (argv[2]);

  //cout<<Ddata[0][0]<<endl<<flush;
  string ss;
  for (int i=0;i<data[0].size();i++){
    myfile << data[0][i] + "\t";
  }
  myfile <<  "\n";

  for (int i=0;i<Ddata.size();i++){
    for (int k=0;k<3;k++){
      myfile << data[i+1][k] + "\t";
    }
    for (int j=0;j<Ddata[i].size();j++){
      myfile << Ddata[i][j];
      myfile << "\t";
    }
    myfile << "\n";
  }
  /*
//double into string
for (int i=1;i<data.size();i++){
for (int j=3;j<data[i].size();j++){
data[i][j]=to_string(Ddata[i-1][j-3]);
}
}

//write file
for (int i=0;i<data.size();i++){
for (int j=0;j<data[i].size();j++){
myfile << data[i][j] + "\t" ;
}
myfile << "\n";
}
  */

  cout<<"done"<<endl<<flush;
  return 0;
}
//this is end of main

// check openfile
int checkFile(ifstream &input)
{
  if(input.fail()){                           //    Check open
    cerr << "Can't open file\n";
    exit(EXIT_FAILURE);
    //return 1;
  }else{return 0;}
}

//file contents to data-vector
int fileToDataTap (string filenameDIR,vector <vector <string> > &data){
  char const* fin = filenameDIR.c_str();
  ifstream input;
  string s;
  input.open(fin);
  checkFile(input);
  while(getline(input,s))
    {
      istringstream ss (s);
      //this add data into the column (second number)
      vector <string> record;
      while (ss)
	{
	  string s1;
	  if(!getline(ss,s1,'')) break;
	  if(s1!=""){
	    record.push_back(s1);
	  }
	}
      //this add data into the row (first number)
      data.push_back(record);
    }//while
  input.close();
  return 0;
}

//print matrix
void printMatrix(vector <vector <string> > &dad){
  for (int i=0;i<dad.size();i++){
    for (int j=0;j<dad[i].size();j++){
      cout<<dad[i][j]+" "<<flush;
    }
    cout<<endl<<flush;
  }
}
