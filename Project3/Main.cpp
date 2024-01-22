#include<iostream>
#include<cstring>

using namespace std;


class Set {
private:
	unsigned int* elements;
	int len = 10;
	int index = 0;
public:
	Set();
	void elementSetter(unsigned int e);
	unsigned int elementGetter(int i);
	void elementsSetter(unsigned int* elements);
	unsigned int* elementsGetter();
	int lenGetter() const;
	int n();
};

Set::Set() {

}

void Set::elementsSetter(unsigned int* elements) {
	Set::elements = elements;
}

unsigned int* Set::elementsGetter() {
	return Set::elements;
}

void Set::elementSetter(unsigned int e) {
	if (e == 0xFFFFFFFF) {
		Set::elements[index--] == 0xFFFFFFFF;
		return;
	}
	Set::elements[index++] = e;
}

unsigned int Set::elementGetter(int i) {
	return Set::elements[i];
}

int Set::lenGetter() const {
	return Set::len;
}

int Set::n() {
	int n = 0;
	for (; Set::elementGetter(n) != 0xFFFFFFFF; ++n) {}
	return n;
}

int main()
{
	Set set;
	set.elementsSetter((unsigned int*)calloc(set.lenGetter(), sizeof(int)));
	if (set.elementsGetter() != NULL) {
		memset(set.elementsGetter(), 0xFF, set.lenGetter() * sizeof(int));
	}
	set.elementSetter(9);
	set.elementSetter(10);
	set.elementSetter(2);
	set.elementSetter(-1);
	set.elementSetter(99);
	printf("%d", set.n());
	return 0;
}