int main()
{
    unsigned int arr_sz = 2;
    int *arr = new int[arr_sz];
    for (unsigned int i = 0; i < arr_sz; ++i)
        arr[i] = i;
    /* does something interesting */
    delete [] arr;

    return 0;
}