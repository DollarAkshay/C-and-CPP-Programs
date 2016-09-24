#include <stdio.h>
#include <stdlib.h>

int main(void){

	int arr[] = { 1, 1, 2 };
	int t = 1;
	int n = 3;
	for (int i = 0; i<n; ++i){
		int newIndex = arr[i];

		/* if this position is >=n, it means it has already been referred to multiple times */
		if (newIndex>=n)
			newIndex -= n;
		                                
		/* if this position is <0 , it means we have referred to this element exactly once */
		else if (newIndex < 0)
			newIndex += n;

		/* if element is occuring for the second time  */
		if (arr[newIndex]<0)
		{
			printf("%d ", newIndex);
			arr[newIndex] += 2*n;
		}
		/*if the element newIndex refers to is occuring for the first time */
		else if (arr[newIndex]<n)
		{
			arr[newIndex] -= n;
		}

	}

	printf("\n");
	system("pause");

	return 0;

}