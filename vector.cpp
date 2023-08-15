//Author: sjp
//vector
#include <iostream>
using namespace std;

template<typename T>
class Vector {
private:
	int Size;
	int Max;
	T *buf;
public:
	Vector() {
		Size = 0; Max = 2; buf = new T[2];
	}
	~Vector() {
		delete[] buf;
	}
	Vector(Vector& x) {
		Size = x.Size;
		Max = x.Max;
		buf = new T[Max];
		for (int i = 0; i < Size; i++) {
			buf[i] = x.buf[i];
		}
	}
	T& operator[](int i) {
		return buf[i];
	}
	Vector& operator=(Vector x) {
		Size = x.Size;
		Max = x.Max;
		buf = new T[Max];
		for (int i = 0; i < Size; i++) {
			buf[i] = x.buf[i];
		}
		return *this;
	}
	bool operator==(Vector& x) {
		if (Size != x.Size)
			return false;
		for (int i = 0; i < Size; i++)
			if (buf[i] != x.buf[i])
				return false;
		return true;
	}
	void push_back(T x) {
		if (Size >= Max) {
			Max *= 2;
			T *buf2 = new T[Max];
			for (int i = 0; i < Size; i++) {
				buf2[i] = buf[i];
			}
			buf2[Size] = x;
			delete[] buf;
			buf = buf2;

		}
		else {
			buf[Size] = x;
		}
		Size++;

	}
	void pop_back() {
		Size--;
	}

	void insert(int it, T x) {
		Size++;
		if (Size >= Max) {
			Max *= 2;	
		}

		T *buf2 = new T[Max];
		for (int i = 0; i < it; i++) {
			buf2[i] = buf[i];
		}
		buf2[it] = x;
		for (int i = it + 1; i < Size; i++) {
			buf2[i] = buf[i-1];
		}
			
		delete[] buf;
		buf = buf2;
		

	}
	void erase(int it) {
		Size--;
		for (int i = it; i < Size; i++) {
			buf[i] = buf[i+1];
		}
	}
	T front() {
		T temp = buf[0];
		Size--;
		for (int i = 0; i < Size; i++)
			buf[i] = buf[i+1];
		return temp;

	}
	T back() {
		Size--;
		return buf[Size];
	}
	int begin() {
		return int(buf);
	}
	int end() {
		return int(buf)+Size-1;
	}
	int size() {
		return Size;
	}
	int max() {
		return Max;
	}
	bool empty() {
		return Size == 0;
	}
	void print() {
		for (int i = 0; i < Size; i++) {
			cout << buf[i];
		}
	}
};
int main()
{
	Vector<char> vec;
	char s = 's';
	vec.push_back('a');
	cout << "size:" << vec.size() <<" ";
	vec.print();
	vec.push_back('b');
	cout << "\nsize:" << vec.size() << " ";
	vec.print();
	vec.push_back('c');
	cout << "\nsize:" << vec.size() << " ";
	vec.print();
	vec.push_back('d');
	cout << "\nsize:" << vec.size() << " ";
	vec.print();
	vec.push_back('e');
	vec.push_back('f');
	cout << "\nsize:" << vec.size() << " ";
	vec.print();

	vec.pop_back();
	cout << "\n pop_back size:" << vec.size() << " ";
	vec.print();

	vec.erase(1);
	cout << "\n erase    size:" << vec.size() << " ";
	vec.print();

	vec.insert(1, 'b');
	cout << "\n insert   size:" << vec.size() << " ";

	vec.print();

	cout << "\n begin:"<<vec.begin()<<" ";

	cout << "\n end:  "<<vec.end()<<" ";
	cout << "\n front:"<<vec.front() << endl;
	cout << " back:"<<vec.back() << endl;
	cout << "vec: ";
	vec.print();

	Vector<char> vec2(vec);
	cout << "\nvec2:";
	vec2.print();s


	Vector<char> vec3;
	if (vec3.empty())
		cout << "\nvec3为空" << endl;
	else
		cout << "\nvec3不为空" << endl;
	vec3 = vec;
	cout << "vec3:";
	vec2.print();
	if (vec3.empty())
		cout << "\nvec3为空" << endl;
	else
		cout << "\nvec3不为空" << endl;
	if (vec == vec2)
		cout << "vec与vec1相同" << endl;
	else
		cout << "vec与vec1不同" << endl;

}