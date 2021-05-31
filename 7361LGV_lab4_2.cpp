#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <unistd.h>
#include <signal.h>
#include <cstdlib>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
using namespace std;
int main()
{
	pid_t v;
	int j=0,k=0,t=-1;
	const char *from,*progname="/Lab4/A",*to, *forcom,*forobh;
	string s,b,c,p,g,z,w,q="/",m;
	cout<<"Enter the name of the sender folder:";
	cin>>b;
	cout<<"Enter the name of the recipient folder:";
	cin>>p;
	forcom=b.c_str();
	w="ls "+q+b+">1.txt";
	forobh=w.c_str();
	system(forobh);
	ifstream file ("/Lab4/1.txt");
	ifstream file1 ("/Lab4/1.txt");
	cout<<"\tList of files in directory "<<b<<" is:"<<endl;
	cout<<"\t*****************************************"<<endl;
	while (getline(file,s))
	{
		cout<<"\t*\t\t"<<s<<"\t\t\t*"<<endl;
		sleep(1);
		j++;
	}
	cout<<"\t*****************************************"<<endl;
	file.close();
	s.clear();
	while (getline(file1,s))
	{
		g=b+q+s;
		z=p+q+s;
		from=g.c_str();
		to=z.c_str();
		cout<<"\tThe file "<<s<<" is copying from: "<<b<<" to: "<<p<<endl;
		v=fork();
		switch(v)
		{
			case -1:
				cout<<"\tError!"<<endl;
			case 0:
				cout<<"\tThe PID of Child is: "<<getpid()<<endl;
				sleep(5);
				execl("A",progname,from,to,NULL);
				sleep(5);
				exit(0);
			default:
				cout<<"\tThe PID of Parent is: "<<getpid()<<endl;
				wait(&t);
				if (WEXITSTATUS(t)==0)
				{
					k++;
				}								}
	}
	file1.close();
	return 0;
}

