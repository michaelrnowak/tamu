void resize(int *&, unsigned int &);

int main()
{
    unsigned int cap = 1;
    unsigned int sz = 0;
    int *arr = new int[cap];
    for (unsigned int i = 0; i < 2; ++i) {
        if (cap == sz)
            resize(arr, cap);
        arr[sz] = i; sz += 1;
    }
    return 0;
}

void resize(int *&array, unsigned int &capacity)
{
    unsigned int newCapacity = capacity * 2;
    int *temp = new int[capacity * 2];
    for (unsigned int i = 0; i < capacity; ++i)
        temp[i] = array[i];
    delete [] array;
    capacity = newCapacity;
    array = temp;
}