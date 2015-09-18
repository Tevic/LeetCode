#include "stdafx.h"
#include "DataStructure.h"
//#include "LeetCodeV1.cpp"
//#include "LeetCodeV2.cpp"
#include "LeetCodeV3.cpp"

class String
{
public:
	String() :data(new char[1]{ '\0' }) {};
	String(const char* data)
	{
		if (!data)
		{
			this->data = new char[1]{ '\0' };
		}
		else
		{
			int len = strlen(data);
			this->data = new char[len + 1]{'\0'};
			strcpy(this->data, data);
		}
	};
	String(const String& str)
	{
		int len = str.Size();
		this->data = new char[len + 1]{ '\0' };
		strcpy(this->data, str.data);
	};

	//String& operator = (const String& str)
	//{
	//	if (this!=&str)
	//	{
	//		int len = str.Size();
	//		delete[] data;
	//		data = new char[len + 1];
	//		strcpy(data, str.data);
	//	}
	//	return *this;
	//};

	String& operator = (String str)
	{
		swap(data,str.data);
		return *this;
	};

	~String()
	{
		delete[] data;
	};

	int Size() const
	{
		return strlen(data);
	}

	char& operator[] (int index) const
	{
		int len = strlen(data);
		if (index<=len)
		{
			return data[index];
		}
		else
		{
			return data[len];
		}
	}
	
	friend istream& operator >> (istream& is, String& str);

	friend ostream& operator << (ostream& os, const String& str);
private:
	char* data;
};

ostream& operator << (ostream& os, const String& str)
{
	os << str.data;
	return os;
}

istream& operator >> (istream& is, String& str)
{
	char tmp;
	int len = str.Size();
	if (len==0)
	{
		str.data = new char[2]{ '\0' };
		len = 1;
	}
	is.get(tmp);
	int index = 0;
	while (tmp!='\n')
	{
		if (index>=len)
		{
			char* newData = new char[len * 2 + 1]{'\0'};
			len *= 2;
			strcpy(newData, str.data);
			delete[] str.data;
			str.data = newData;
		}
		str[index] = tmp;
		index++;
		is.get(tmp);
	}
	return is;
}



int _tmain(int argc, _TCHAR* argv[])
{
	//Solution264 SU264;
	//SU264.nthUglyNumber(6);
	//cout << sizeof(A) << endl;
	String st11("11121211");
	String ST2;
	ST2 = st11;
	cout << ST2 << endl;
}



