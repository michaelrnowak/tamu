const unsigned int NOROWS = 2;
const unsigned int NOCOLS = 3;

int main()
{

	int *(*arr) = new int*[NOROWS];
	for (unsigned int i = 0; i < NOROWS; ++i)
		arr[i] = new int[NOCOLS];

	for (unsigned int i = 0; i < NOROWS; ++i)
		delete [] arr[i];
	delete [] arr;

	return 0;
}