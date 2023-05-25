#include <cstddef>
#include <string>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b)
	{
		string res;
		size_t a_len = a.length();
		size_t b_len = b.length();

		if (a_len > b_len) {
			b = string(a_len - b_len, '0') + b;
		} else if (b_len > a_len) {
			a = string(b_len - a_len, '0') + a;
		}
		bool pre_carry = false;
		for (int i = a.length() - 1; i >= 0; --i) {
			int tmp = a[i] + b[i];
			char cur = '0';
			bool next_carry = false;
		ADD:
			if (tmp == 98) {
				next_carry = true;
				cur = '0';
			} else if (tmp == 97) {
				cur = '1';
			} else {
				cur = '0';
			}
			if (pre_carry) {
				tmp = cur + '1';
				pre_carry = false;
				goto ADD;
			}
			pre_carry = next_carry;
			res += cur;
		}
		if (pre_carry) {
			res.append("1");
		}
		return string(res.rbegin(), res.rend());
	}
};
