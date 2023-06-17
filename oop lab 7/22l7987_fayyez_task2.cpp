//#include<iostream>
//using namespace std;
//
//class set
//{
//	int * data;
//	int capacity;
//	int noOfElements;
//	static int count;
//public:
//	set(int cap = 0)
//	{
//		capacity = cap;
//		data = new int[capacity];
//		noOfElements = 0;
//		count++;
//	}
//	set(const set& ref)
//	{
//		capacity = ref.capacity;
//		data = new int[capacity];
//		noOfElements = ref.noOfElements;
//		count++;
//		for (int i = 0; i < capacity; i++)
//		{
//			data[i] = ref.data[i];
//		}
//	}
//	void reSize(int newCap)
//	{
//		int* arr = new int[newCap];
//		for (int i = 0; i < newCap; i++)
//		{
//			arr[i] = data[i];
//		}
//		delete[]data;
//		data = arr;
//		capacity = newCap;
//	}
//	static int getObjCount()//cant be kept const as not applicable to static int data type
//	{
//		return count;
//	}
//	~set()
//	{
//		delete[]data;
//		data = nullptr;
//	}
//	void insert(int element)
//	{
//		//increase capacity in case array is full
//		if (noOfElements == capacity ) reSize(capacity + 1);
//		data[capacity - 1] = element;
//		noOfElements++;
//	}
//	int operator [] (int index)
//	{
//		while (!(index >= 0 && index < noOfElements))
//		{//index is not out of bound/make sure 
//			cout << "***index is out of bound of array***\nEnter index : ";
//			cin >> index;
//		}
//		return data[index];
//	}
//	set operator + (int nToAdd) 
//	{
//		set temp;
//		for (int i = 0; i < noOfElements; i++)
//		{
//			temp.insert(data[i] + nToAdd);
//		}
//		return temp;
//	}
//	set& operator ++ ()
//	{
//		for (int i = 0; i < noOfElements; i++)
//		{
//			data[i] += 1;
//		}return *this;
//	}
//	set& operator ++ (int)
//	{
//		for (int i = 0; i < noOfElements; i++)
//		{
//			data[i] += 1;
//		}return *this;
//	}
//	set& operator -- ()
//	{
//		for (int i = 0; i < noOfElements; i++)
//		{
//			data[i] -= 1;
//		}return *this;
//	}
//	set& operator -- (int)
//	{
//		for (int i = 0; i < noOfElements; i++)
//		{
//			data[i] -= 1;
//		}return *this;
//	}
//};
//int set::count = 0;//to initialize static int (count)
//int main()
//{
//	set s1; int valToInsert = 0, n = 0;
//	int size = 0;
//	for (int i = 0; i < 5; i++)//takes 5 inputs in set 1
//	{
//		cout << "enter value to insert : ";
//		cin >> valToInsert;
//		s1.insert(valToInsert);
//		size++;
//	}
//	cout << "s1 = ";
//	for (int i = 0; i < size; i++) cout << s1[i]<<" ";
//	cout << endl;
//	cout << "enter n : ";
//	cin >> n;
//	set s2 = s1 + n;
//	cout << "After incrementing all values by "<<n<<", s2 = ";
//	for (int i = 0; i < size; i++) cout << s2[i] << " ";
//	cout << endl;
//	s1++;
//	cout << "s1 after post increment = ";
//	for (int i = 0; i < size; i++) cout << s1[i] << " ";
//	cout << endl;
//	s1--;
//	cout << "s1 after post decrement = ";
//	for (int i = 0; i < size; i++) cout << s1[i] << " ";
//	cout << endl;
//
//	cout << endl;
//	system("pause");
//	return 0;
//}