#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

/*
█▀▄▀█ █▀▀█ █▀▀ █▀▀ █▀▀ ─█▀▀█ █▀▀▄ █▀▀ █───█ █▀▀█ █── █──█ 
█░█░█ █──█ ▀▀█ █▀▀ ▀▀█ ░█▄▄█ █──█ █▀▀ █▄█▄█ █──█ █── █──█ 
█──░█ ▀▀▀▀ ▀▀▀ ▀▀▀ ▀▀▀ ░█─░█ ▀▀▀─ ▀▀▀ ─▀─▀─ ▀▀▀▀ ▀▀▀ ─▀▀▀
*/

class ArrayList {
	private:
		int* backing_arr;
		int size;
		const int INITIAL_CAPACITY = 9;

	public:
		ArrayList() {
			this.size = 0;
		};

		void addToFront() {
			
		}

		void add(int index) {

		}

		bool isEmpty() {
			return size == 0;
		}
		
		void clear() {
			for (int i = 0; i < size; ++i) {
				backing_arr[i] = nullptr;
			}

			size = 0;
		}

		int* getBackingArray() {
			return backing_arr;
		}

		int getSize() {
			return size;
		}
};

int main() {

	return 0;
}