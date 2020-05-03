#include "variabels.h"
char* read(const char* filename); // функци€, читающа€ текст из файла.
void separateText(char* text, SeparatedText* sent); // функци€, раздел€юща€ текст на предложени€.
void analyseSentenses(SeparatedText* sep);// функци€, вычисл€юща€ сложность предложени€.
double calculateAverageComplexity(SeparatedText* sep);// функци€, вычисл€юща€ среднюю сложность теста.
Sentences* findSentenceWithMaxComplexity(SeparatedText* sep);// функци€ назод€ща€ предложение с максимальной сложностью
void print(const char* OUT, char* text, double averageComplexity, Sentences* sentenceWithMaxComplexity); // функци€, вывод€щ€€ ответ в файл.
void setrus(); // побочна€ функци€, устанвка необзодимых пораметров.