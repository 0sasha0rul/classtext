#include "text.hpp"

#include <cstring>
#include <stdexcept>

using ARylova::Text;

Text::Text() {
	value = nullptr;
    size = 0;
}

Text::Text(const char* const str) {
	size = get_length(str);
    value = new char[size+1];
	for (int i = 0; i < size ; i++) {
		value[i] = str[i];
	}
	value[size] = '\0';
}

Text::Text(const Text& x) {
	size = x.size;
	value = new char[x.size];
	for (int i = 0; i < x.size ; i++) {
		value[i] = x.value[i];
	}
}

Text::Text(Text&& x) noexcept {
	size = x.size;
    value = x.value;
    x.value = nullptr;
    x.size = 0;
}

Text::~Text() {
	delete[] value;
}

Text& Text::operator = (const char* const str) {
	std::cout << "Text::operator = (const char* const str) was used!" << std::endl;
	size = strlen(str);
	value = new char[size];
	for (int i = 0; i < size ; i++) {
		value[i] = str[i];
	}
	return *this;
}

Text& Text::operator = (const Text& x) {
	std::cout << "Text::operator = (const Text& x) was used!" << std::endl;
	size = x.size + 1;
	if (value != nullptr) {
		delete[] value;
	}
	value = new char[size];
	
	for (int i = 0; i < size - 1 ; i++) {
		value[i] = x.value[i];
	}
	value[size - 1] = '\0';

	return *this;
}

Text& Text::operator = (Text&& x) noexcept {
	std::cout << "Text::operator = (Text&& x) was used!" << std::endl;
	if ( value != nullptr) delete[] value;
	size = x.size;
	value = x.value;
	x.value = nullptr;
	return *this;
}

bool Text::operator == (const Text& x) const  {
	if (size == x.size){
		for (int i = 0; i < x.size ; i++) {
			if (value[i] != x.value[i])
				return false;
		}
	} else {
		return false;
	}
	return true;
}

bool Text::operator != (const Text& x) const {
	bool equals = true;
	if (size == x.size) {
		for (int i = 0; i < x.size ; i++) {
			if (value[i] != x.value[i])
				equals = false;
		}
	} else {
		equals = false;
	}
	return !equals;
}

Text Text::operator + (const Text& x) const {
	Text temp;
	temp.size = size + x.size + 1;
	temp.value = new char[temp.size];
	for (int i = 0; i < size ; i++) {
		temp.value[i] = value[i];
	}
	
	int n = 0;
	for (int i = size; i < temp.size - 1 ; i++) {
		temp.value[i] = x.value[n];
		n += 1;
	}
	temp.value[temp.size - 1] = '\0';
	
	return temp;
}

char& Text::at(std::size_t i) {
	std::cout << "You are in Text::at(std::size_t i)" << std::endl;
	if (i > size - 1) {
		std::cout << "hsjdfhsjdhs";
		throw std::out_of_range("You enter invalid value");
	}
	return value[i];
}

void Text::push_back(const char c) {
	// TODO
	std::cout << "push_back(const char c)" << std::endl;
}

void Text::push_back(const char* const str) {
	std::cout << "push_back(const char* const str)" << std::endl;
	
	char* new_value = new char[size + strlen(str) + 1];

	for (int i = 0; i < size ; i++) {	
		new_value[i] = value[i];
	}

	int n = 0;
	for (int i = size; i < size + strlen(str) ; i++) {
		new_value[i] = str[n];
		n++;
	}

	size = size + strlen(str) + 1;
	new_value[size - 1] = '\0';
	value = new_value;
	
	delete new_value;
}

void Text::remove_all(const char c) {
	// TODO
}			

namespace ARylova {
	std::ostream& operator << (std::ostream& os, const Text& x) {
		os << x.value;
		return os;
	}
}

//-----------------------------------------------------------------------------
// PRIVATE
//-----------------------------------------------------------------------------
std::size_t Text::get_length(const char* const str) {
	
	return strlen(str);
}
