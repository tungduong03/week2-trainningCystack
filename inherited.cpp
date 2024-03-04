#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

//tạo class exception
class BadLengthException {
    private:
        int n;
    public:
        BadLengthException(int errornumber) {
            n = errornumber;
        }

        int what(){
            return n;
        }
};

//check username
bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if(n < 5) {
        //nếu n<5 thì ném lỗi
		throw BadLengthException(n);
	}
	for(int i = 0; i < n-1; i++) {
		if(username[i] == 'w' && username[i+1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int main() {
	int T; cin >> T;
	while(T--) {
		string username;
		cin >> username;
		try {
			bool isValid = checkUsername(username);
			if(isValid) {
				cout << "Valid" << '\n';
			} else {
				cout << "Invalid" << '\n';
			}
		} catch (BadLengthException e) {
			cout << "Too short: " << e.what() << '\n';
		}
	}
	return 0;
}
