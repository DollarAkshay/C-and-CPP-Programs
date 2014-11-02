
//http://www.hackerearth.com/iitkgpheoct14/algorithm/the-punishment-3/

x = input();
while x>0:
	n, k = map(int, raw_input().split())
	p1 = 10 * *(n - k);
	p1 -= 1;
	p2 = 10 * *k
	p2 -= 1;
	print p1*p2
	x -= 1

//Solved using Python,couldnt handle big numbers in C/C++