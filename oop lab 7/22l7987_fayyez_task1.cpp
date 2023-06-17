//#include<iostream>
//using namespace std;
//class rationalNo
//{
//	int num;
//	int den;
//public:
//	rationalNo(int n=1,int d=1)
//	{
//		num=n;
//		if(d==0||d<0) d=1;
//		den=d;
//		this->simplify();
//	}
//	void simplify()
//	{
//		for(int i=2;i<=abs(num)&&i<=den;i++)
//		{
//			if(num%i==0 && den%i==0)
//			{
//				num/=i;
//				den/=i;
//				simplify();
//			}
//		}
//	}
//	rationalNo operator + (rationalNo& obj)
//	{
//		rationalNo temp;
//		if(obj.den==den)
//		{
//			temp.num = num + obj.num;
//			temp.den=den;
//		}
//		else{
//			temp.den=den*obj.den;
//			temp.num= den*obj.num + obj.den*num;
//		}
//		temp.simplify();
//		return temp;
//	}
//	rationalNo operator - (rationalNo& obj)
//	{
//		rationalNo temp;
//		if(obj.den==den)
//		{
//			temp.num = num - obj.num;
//			temp.den=den;
//		}
//		else{
//			temp.den=den*obj.den;
//			temp.num= den*obj.num - obj.den*num;
//		}
//		temp.simplify();
//		return temp;
//	}
//	bool operator == (rationalNo& obj)
//	{
//		if(obj.num==num&&obj.den==den) return true;
//		else return false;
//	}
//	rationalNo& operator++()
//	{
//		num+=1;den+=1;
//		simplify();
//		return *this;
//	}
//	rationalNo& operator -- (int dummy)
//	{
//		rationalNo temp = *this;
//		num-=1;den-=1;
//		if(den<=0)den=1;
//		simplify();
//		return temp;
//	}
//	friend istream& operator >> (istream&, rationalNo &);
//	friend ostream&  operator << (ostream&, rationalNo &);
//
//};
//istream& operator >> (istream& input, rationalNo& obj)
//{
//	cout<<"enter num : ";
//	input >> obj.num;
//	do 
//	{
//		cout<<"enter den : ";
//		cin>>obj.den;
//
//	}while(obj.den<=0);
//	obj.simplify();
//	return input;
//}
//ostream& operator << (ostream& output, rationalNo & obj)
// {
//	 output << obj.num<<"/"<<obj.den;
//	 return output;
// }
//int main()
//{
//	rationalNo r1(2,8), r2;
//	cin>>r2;
//	cout<<"r3 = "<<r2<<endl;
//	rationalNo r3= r1+r2;
//	cout<< "r3 = " << r3 <<endl;
//	rationalNo r4= r1-r2;
//	cout<<"r4 = " <<r4<<endl;
//	if(r1==r2) cout << "r1 == r2\n";
//	else cout<< "r1 != r2\n";
//	cout<<"after prefix increment, r3 = ";
//	cout << ++r3 << endl;
//	cout<< "after postfix decrement, r2 = ";
//	r3--;
//	cout<< r3 <<endl;
//	cout<<endl<<endl;
//	system("pause");
//	return 0;
//}