#include <iostream>
#include <string>
using namespace std;

class CurrencyConversion {
	public:
		double aedPerUsd = 3.67;
		double aedPerEur = 4.19;
		int notes = 250;
		string name = "Moses";
};


int main() {
	CurrencyConversion item;
	double euros = item.notes / item.aedPerEur;
	double dollars = item.notes / item.aedPerUsd;
	double eurosTrunc = (static_cast<int> ((euros) * 100.0)) / 100.0;
	double dollarsTrunc = (static_cast<int> ((dollars) * 100.0)) / 100.0;
	cout << item.name << " is carrying " << eurosTrunc << " Euros and " << dollarsTrunc << " Dollars!" << endl;

	return 0;
}