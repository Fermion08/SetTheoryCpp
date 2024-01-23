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
	void elementRemover(int i);
	int checkDuplicateValues();
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

void Set::elementRemover(int i ) {
	for (; i < Set::index; ++i) {
		Set::elements[i] = Set::elements[i+1];
	}
	--Set::index;
}

int Set::checkDuplicateValues() {
	int index = Set::index;
	for(int i = 0; i < Set::index; ++i) {
		for (int j = i+1; j < Set::index; ++j) {
			if(Set::elements[i] == Set::elements[j]) {
				Set::elementRemover(j);
				
			}
		}
	}
	return index-Set::index;
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
	set.elementSetter(9);
	//set.elementSetter(1);
	//set.elementSetter(1);
	set.elementSetter(10);
	//set.elementRemover(1);
	printf("%d\n", set.checkDuplicateValues());
	for(int i = 0; i < set.lenGetter(); ++i) {
		printf("%d ", set.elementGetter(i));
	}
	printf("%d\n", set.n());
	return 0;
}