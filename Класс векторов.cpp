#include <iostream>
#include <vector>
using namespace std;
class Array {
private:
		int size1;
		vector<vector<int>>ar;
		int size2;
public:
		Array() {
			size1 = 0;
			size2 = 0;
		}
		Array(int size1, int size2) {
			this->size1 = size1;
			this->size2 = size2;
			ar.resize(size1);
			for (int i = 0; i < size1; i++) {
				ar[i].resize(size2);
				for (int j = 0; j < size2; j++) {
					ar[i][j] = rand() % 15;
				}
			}
		}
		~Array() {}
		void print() {
			for (int i = 0; i < size1; i++) {
				for (int j = 0; j < size2; j++) {
					cout << ar[i][j] << "\t";
				}
				cout << endl;
			}
		}
		Array(const Array& other) :Array(other.size1, other.size2) {
			for(int i=0;i<size1;i++){
				for (int j = 0; j < size2; j++) {
					this->ar[i][j] = other.ar[i][j];
				}
		}
}
		bool operator==(const Array& other) {
		return this->size1 == other.size1&&this->size2 ==other.size2;
	}
		Array operator+(const Array& other) {
			Array result;
			result.size1 = this->size1;
			result.size2 = this->size2;
			vector<vector<int>>ar;
			ar.resize(result.size1);
			for (int i = 0; i < result.size1; i++) {
				ar[i].resize(result.size2);
				for (int j = 0; j < result.size2; j++) {
					result.ar[i][j] = this->ar[i][j] + other.ar[i][j];
				}
			}
			return result;
	}



};
int main() {
	Array ar(3, 3);
	ar.print();
	cout << endl;
	Array ar2(3, 3);
	ar2.print();
	cout << endl;
	Array result;
	result = ar + ar2;
	result.print();
}