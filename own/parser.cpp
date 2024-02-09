#include<string>
#include<iostream>
#include<ostream>
enum Token {
	tok_eof = -1,
	tok_def = -2,
	tok_identifier = -3,
	tok_number = -4
};

static std::string Identifier;
static int Value;

bool is_space(int ch) {
	return ch == ' ' || ch == '\n' || ch == '\t';
}

bool is_alpha_num(int ch) {
	return (ch<='z' && ch>='a') || (ch<='Z' && ch>='A') || (ch<='9' && ch>='0');
}

bool is_alpha(int ch) {
	return (ch<='z' && ch>='a') || (ch<='Z' && ch>='A'); 
}

bool is_num(int ch) {
	return (ch<='9' && ch>='0');
}

static int get_token() {
	static int LastChar = ' ';
	while(is_space(LastChar)) LastChar = getchar();
	
	// candidates for first character being alphabets are variable/function names(Identifier), or def
	if (is_alpha(LastChar)) {
		Identifier=LastChar;
		// [a-zA-Z][a-zA-Z0-9]*
		while(is_alpha_num(LastChar = getchar())) {
			Identifier+=LastChar;
		}

		if (Identifier == "def") {
			return tok_def;
		}
		return tok_identifier;
	}
	
	// number [0-9]+
	if (is_num(LastChar)) {
		std::string number;
		number+=LastChar;
		while (is_num(LastChar = getchar())) {
			number+=LastChar;
		}
		Value = strtod(number.c_str(), 0);
		return tok_number;
	}
	if (LastChar == EOF) {
		return tok_eof;
	}
}


int main() {
	int current_token;
	while((current_token = get_token()) != tok_eof) {
		if (current_token == tok_identifier) {
			std::cout << "IDENTIFIER : " << Identifier << std::endl;
		} else if (current_token == tok_number) {
			std::cout << "NNUMBER : " << Value << std::endl;
		} else if (current_token == tok_def) {
			std::cout << "DEF\n";
		}
	}
}
