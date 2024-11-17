#include <iostream> 
#include <string>

using namespace std;

bool allLowerCase(string);

int main(){
	string word;
	cin >> word;
	allLowerCase(word);
	return 0;
}

bool allLowerCase(string s) {	
	for (int i = 0; i < s.length(); i++) {

		if (isupper(s[i])) {
			cout << "false" << endl;
			return false;
		}
	}
	    cout << "true" << endl;
		return true;
}
	
