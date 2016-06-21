#ifndef UTIL_H
#define UTIL_H
#include <string>
#include <iomanip>
#include <sstream>  

template <typename T>
class Util {
	public:
		
		static std::string to_string_with_precision(const T , const int);

};

template <typename T>
std::string Util<T>::to_string_with_precision(const T a_value, const int n = 6) {
	std::ostringstream out;
	out << std::setprecision(n) << a_value;
	return out.str();
}
#endif
