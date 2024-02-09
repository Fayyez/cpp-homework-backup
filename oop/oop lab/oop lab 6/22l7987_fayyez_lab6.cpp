#include<iostream>
#include<windows.h>
using namespace std;

class set
{
	int* data, capacity, noOfElements;
	static int count;
public:
	set(int cap = 0)
	{
		capacity = cap;
		data = new int[capacity];
		noOfElements = 0;
		count++;
	}
	set(const set& ref)
	{
		capacity = ref.capacity;
		data = new int[capacity];
		noOfElements = ref.noOfElements;
		count++;
		for (int i = 0; i < capacity; i++)
		{
			data[i] = ref.data[i];
		}
	}
	void reSize(int newCap)
	{
		int* arr = new int[newCap];
		for (int i = 0; i < newCap; i++)
		{
			arr[i] = data[i];
		}
		delete[]data;
		data = arr;
		capacity = newCap;
	}
	static int getObjCount()//cant be kept const as not applicable to static int data type
	{
		return count;
	}
	void insert(int element)
	{
		bool present = false;
		for (int i = 0; i < capacity; i++)
		{
			if (element == data[i]) present = true;
		}//increase capacity in case array is full
		if (noOfElements == capacity && !present) reSize(capacity + 1);
		if (!present)
		{
			data[capacity - 1] = element;
			noOfElements++;
		}
	}
	void remove(int element)
	{
		for (int i = 0; i < capacity; i++)
		{
			if (element == data[i])
			{
				data[i] = data[capacity - 1];
				data[capacity - 1] = -1;
				reSize(capacity - 1);
			}
		}
	}
	int getCardinality() const
	{
		return noOfElements;
	}
	set calUnion(const set& obj) const
	{
		set s(0);
		for (int i = 0; i < capacity; i++) s.insert(data[i]);
		for (int i = 0; i < obj.capacity; i++) s.insert(obj.data[i]);
		return s;
	}
	bool isMember(int val)
	{
		for (int i = 0; i < noOfElements; i++)
		{
			if (data[i] == val) return true;
		} return false;
	}
	set calcDifference(const set& obj)
	{
		set s(0);
		for (int i = 0; i < obj.capacity; i++)
		{
			if (isMember(obj.data[i])) s.insert(obj.data[i]);
		} return s;

	}
	set calcSymmetricDifference(const set& obj)
	{
		set unionSet = calUnion(obj), differenceSet = calcDifference(obj);
		for (int i = 0; i < unionSet.capacity; i++)
		{
			if (differenceSet.isMember(unionSet.data[i]))
				unionSet.remove(unionSet.data[i--]);
		}return unionSet;
	}
	int isSubSet(const set& obj)
	{
		bool flag = true;
		for (int i = 0; i < obj.capacity; i++)
		{
			if (!isMember(obj.data[i])) flag = false;
		}
		if (flag && capacity == obj.capacity) return 2;
		else if (flag) return 1;
		else if (!flag) return 0;
	}
	void print()
	{
		cout << "set is :\n";
		for (int i = 0; i < capacity; i++)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	}
	~set()
	{
		delete[]data;
		data = nullptr;
	}
};
int set::count = 0;//to initialize static int (count)
int main()
{
	//system("color 84");
	set s1(0);
	int valToInsert = 0, temp = 0;
	for (int i = 0; i < 5; i++)//takes 5 inputs in set 1
	{
		cout << "enter value to insert : ";
		cin >> valToInsert;
		if (s1.isMember(valToInsert)) cout << "element already exists, so not added.\n";
		s1.insert(valToInsert);
	}
	cout << "no. of elements in s1 = " << s1.getCardinality() << endl;
	s1.print();
	cout << "enter value to check Presence in set 1 : ";
	cin >> temp;
	if (s1.isMember(temp)) cout << "found\n";
	else cout << "not found.\n";
	set s2(0);//s2 is mirror image of s1
	for (int i = 0; i < 5; i++)//takes 5 inputs in set 1
	{
		cout << "enter value to insert : ";
		cin >> valToInsert;
		if (s2.isMember(valToInsert)) cout << "element already exists, so not added.\n";
		s2.insert(valToInsert);
	}
	s2.print();
	set s3 = s1.calUnion(s2);//getting union of s1 and s2
	cout << "union ";  s3.print();
	set s4 = s1.calcDifference(s2);//getting union of s1 and s2
	cout << "intersection "; s4.print();
	set s5 = s1.calcSymmetricDifference(s2);//getting symmetric difference of s1 and s2
	cout << "symmetric difference "; s5.print();
	if (s1.isSubSet(s2) == 2) cout << "s2 is improper subset of s1.\n";//check if s2 is a subset of s1
	else if (s1.isSubSet(s2) == 1) cout << "s2 is proper subset of s1.\n";
	else if (s1.isSubSet(s2) == 0) cout << "s2 is not a subset of s1.\n";
	cout << "no. of construction calls = " << s1.getObjCount() << "\n\n\n\n";
	system("pause");
	return 0;
}