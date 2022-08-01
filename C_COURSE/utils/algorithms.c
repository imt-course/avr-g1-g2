
/*
	Function Name: bubble_sort
	Parameters In: 
		- arr: array to sort
		- arr_size: size of the array
	Parameters Out: 
		- None
	Return value: 
		- None
*/
void bubble_sort(int arr[], int arr_size) {
	int i, j;
	for (i = arr_size-1; i>=0; i--) {
		char swapped = 0;
		for (j=0; j<i; j++) {
			if (arr[j] > arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				swapped = 1;
			}
		}
		if (swapped == 0){
			break;
		}
	}
	
}

/*
	Function Name: linear_search
	Parameters In: 
		- arr: array to search in
		- arr_size: size of the array
		- number: number to search
	Parameters Out: 
		- None
	Return value: 
		- index of the number if the numbe is found,
		else the return value = arr_size
*/
int linear_search (int arr[], int arr_size, int number) {
	int i, index = arr_size;
	for (i=0; i<arr_size; i++) {
		if (arr[i] == number) {
			index = i;
			break;
		}
	}
	return index;
}

/*
	Function Name: binary_search
	Parameters In: 
		- arr: array to search in
		- arr_size: size of the array
		- number: number to search
	Parameters Out: 
		- None
	Return value: 
		- index of the number if the numbe is found,
		else the return value = arr_size
*/

int binary_search (int arr[], int arr_size, int number) {
	int start = 0;
	int end = arr_size-1;
	int mid;
	int index = arr_size;
	
	while (start <= end) {
		mid = start + ((end-start) / 2);
		if (arr[mid] == number) {
			index = mid;
			break;
		}
		else if (number > arr[mid]) {
			start = mid+1;
		}
		else {
			end = mid-1;
		}
	}
	return index;

}