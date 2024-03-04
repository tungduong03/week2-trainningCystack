#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
using namespace std;

class Server {
private:
	static int load;
public:
	static int compute(long long A, long long B) {
		load += 1;
		if(A < 0) {
            //thêm msg cho exception invalid_argument
			throw std::invalid_argument("A is negative");
		}
		vector<int> v(A, 0);
		int real = -1, cmplx = sqrt(-1);
		if(B == 0) throw 0;
		real = (A/B)*real;
		int ans = v.at(B);
		return real + A - B*ans;
	}
	static int getLoad() {
		return load;
	}
};
int Server::load = 0;

int main() {
	int T; cin >> T;
	while(T--) {
		long long A, B;
		cin >> A >> B;

        //trường hợp ko có lỗi
        try {
            cout << Server::compute(A, B) << endl;
        }

        //trường hợp lỗi về ko cấp phát bộ nhớ thành công
        catch (std::bad_alloc& error) {
            cout<<"Not enough memory"<<endl;
        }

        //trường hợp có các lỗi phát hiện được theo tiêu chuẩn của C++
        catch (std::exception& error) {
            cout<<"Exception: "<<error.what()<<endl;
        }

        //trường hợp các lỗi khác
        catch (...) {
            cout<<"Other Exception"<< endl;
        }
	}
	cout << Server::getLoad() << endl;
	return 0;
}
