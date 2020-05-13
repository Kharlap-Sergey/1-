const int NL = 100; // text length is in lines
const int NUMW = 100; // lines length is in words
const int NW = 200; // word lenght
const int TextMaxLen = NL * NUMW * NW+10;
const int LineMaxLen = NUMW * NW + 10;
const char IN[] = "input.txt";
const char OUT[] = "output.txt";

struct Sentences {
	int len = 0; // длинна предложения
	int complexity = 0; // сложность предложения
	char *value; // указатель на само предложение
};

struct SeparatedText {
	Sentences sentences[NL]; // массив структур для предложений
	int sentencesNumber = 0; // колличество предложений в тексте
};
