#pragma once

#include <cstddef>
#include <iostream>

namespace ARylova {
	class Text final {
		private:
			static const char END = '\0';
			
			char* value;
			std::size_t size = 0;
		public:
			// Конструктор по умолчанию
			Text();
			// Конструктор с параметрами
			Text(const char* const str);
			// Конструктор копирования (lvalue)
			Text(const Text& x);
			// Конструктор перемещения (rvalue)
			Text(Text&& x) noexcept;
			// Деструктор
			~Text();

			Text& operator = (const char* const str);
			// Оператор присвоения копирования (lvalue)
			Text& operator = (const Text& x);
			// Оператор присвоения перемещения (rvalue)
			Text& operator = (Text&& x) noexcept;
			
			// Перегрузка операторов
			char& operator [] (const std::size_t i) { return value[i]; }
			bool operator == (const Text& x) const;
			bool operator != (const Text& x) const;
			Text operator + (const Text& x) const;
			
			/*
				at(std::size_t i) в отличие от перегруженного оператора []
				должна проверять на выход за пределы массива. 
				И если такое происходит, то надо выбрасывать ошибку 
				std::out_of_range из библиотеки <stdexcept>.
			*/
			char& at(std::size_t i);
			const char* get_str() const noexcept { return value; }
			void push_back(const char c);
			void push_back(const char* const str);
			// Вспомни идиому remove-erase
			void remove_all(const char c);
			std::size_t get_size() const noexcept { return size; }
			
			friend std::ostream& operator << (std::ostream& os, const Text& x);
			
		private:
			std::size_t get_length(const char* const str);
	};
}
