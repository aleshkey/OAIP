#include "Check.h"
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include "devide_set.h"
#include <sstream>
#include <numeric>
using namespace std;
vector<string> Check(vector<string> arr)
{
	
		vector<string> buffer;
		vector<string> rez;
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i][0] == '{') {
				buffer = divide_set(arr[i]);
				sort(buffer.begin(), buffer.end());
				buffer[0] = "{" + buffer[0];
				int last = buffer.size();
				buffer[last - 1] = buffer[last - 1] + "}";
				for (int i = 0; i < buffer.size(); i++) {
					if (i < buffer.size()-1) {
						buffer[i] = buffer[i] + " ";
					}
				}
				ostringstream stream;
				copy(buffer.begin(), buffer.end(), std::ostream_iterator<string>(stream));
				string s = stream.str();
				rez.push_back(s);
			}
			else {
				rez.push_back(arr[i]);
			}
		}
		return rez;
}
