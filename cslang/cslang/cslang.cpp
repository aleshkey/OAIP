// cslang.cpp: определяет точку входа для приложения.
//

#include "cslang.h"
#include <string>
#include <typeinfo>

using namespace std;

class var {

private:
	void* ptr = nullptr;
	string typeName = "";

public:

	string getType() { return typeName; }

	template<typename T>
	T get() { return *(T*)ptr; }

	template<typename T>
	void set(T value) {
		typeName = typeid(value).name();
		if (ptr) free(ptr);
		ptr = malloc(sizeof(T));
		*(T*)ptr = value;
	}

	template<typename T>
	T operator+(T other) {
		return get<T>() + other;
	}

	template<typename T>
	friend T operator+(T other, var dyn) {
		return dyn.get<T>() + other;
	}

	template<typename T>
	T operator-(T other) {
		return get<T>() - other;
	}

	template<typename T>
	friend T operator-(T other, var dyn) {
		return other - dyn.get<T>();
	}

	template<typename T>
	void operator=(T value) {
		set<T>(value);
	}

	template<typename T>
	operator T() { return get<T>(); }

};

int main()
{
	
	var test;

	test = 19;
	cout << test.getType() << ": " << (int)test << endl;

	test = 19.343;
	cout << test.getType() << ": " << test + 12.9 << endl;

	cout << test.getType() << ": " << 12.9 + test << endl;

	test = true;
	cout << test.getType() << ": " << (bool)test << endl;

	test = nullptr;
	cout << test.getType() << ": " << (void*)test << endl;

	test = &test;
	cout << test.getType() << ": " << (void*)test << endl;

	test = "hello, world!";
	cout << test.getType() << ": " << (char*)test << endl;
 
	system("pause");

	return 0;
}
