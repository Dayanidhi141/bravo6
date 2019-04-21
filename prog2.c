1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
#include <iostream>
#include <atomic>
#include <thread>
using namespace std;
 
const int COUNT = 10;
 
int main(int argc, char** argv)
{
	atomic_bool f1{false}, f2{false};
 
	auto proc1 = [&]() {
		for(int i = 0; i < COUNT;)
		{
			f1.store(true);
			if(f2.load() == false)
			{
				cout << "T1 in critical section" << endl;
				++i;
			}
			
			f1.store(false);
		}
	};
 
	auto proc2 = [&]() {
		for(int i = 0; i < COUNT;)
		{
			f2.store(true);
			if(f1.load() == false)
			{
				cout << "T2 in critical section" << endl;
				++i;
			}
			
			f2.store(false);
		}
	};
 
	thread t1(proc1);
	thread t2(proc2);
 
	t1.join();
	t2.join();
 
	return 1;
