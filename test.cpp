#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <cmath>

using namespace std;

int stream_to_int(stringstream & input)
{
	double param, fractpart, intpart;
	input >> param;
	if (input.fail()) throw invalid_argument("expected integer argument");
	else
	{
		fractpart = modf (param , &intpart);
		if (fractpart != 0) throw invalid_argument("expected integer argument");
		else return (int) intpart;
	}
	return 10000;
}

int main()
{
	stringstream input;
	input.str("1 2.3 4.12345678 20 -1 aaa");
	for (int i = 0; i < 6; i++)
	{
		try {
			cout << stream_to_int(input) << endl;
		}
		catch (exception& e) {
			// If you use exceptions, make sure the line number is printed here
			cout << "Error on line ?: " << e.what() << endl;
		}
	}
		
	return 0;
}
