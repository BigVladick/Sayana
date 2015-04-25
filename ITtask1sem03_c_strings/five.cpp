#include <iostream>
#include <string>

using namespace std;
// общее количество символов
int const amountSymbols = 42;

/*
Вводимый с клавиатуры текст перевести в последовательность точек и тире с помощью
азбуки Морзе (преобразовывать без различия строчных и прописных букв).

*/


/*
	Функция инициализирует массив входных символов.
*/
void initInputs(char inputs[])
{
	int amountInputs = 0;
	// обрати внимание, что можно не только int использовать в for как индекс.
	// этот цикл добавит в массив все буквы от A до Z
	for (char i = 'A'; i <= 'Z'; i++)
	{
		inputs[amountInputs++] = i;
	}
	// этот цикл добавит в массив все цифры от 1 до 9
	for (char i = '1'; i <= '9'; i++)
	{
		inputs[amountInputs++] = i;
	}
	// добавим все остальное
	inputs[amountInputs++] = '0';
	inputs[amountInputs++] = '.';
	inputs[amountInputs++] = ',';
	inputs[amountInputs++] = ':';
	inputs[amountInputs++] = '?';
	inputs[amountInputs++] = '-';
	inputs[amountInputs++] = '/';
}

/*
Функция инициализирует массив выходных символов.
сократить ее размер мне не удалось :(
*/
void initOutputs(string outputs[])
{
	int amountOutputs = 0;
	outputs[amountOutputs++] = ".-";
	outputs[amountOutputs++] = "-...";
	outputs[amountOutputs++] = "-.-.";
	outputs[amountOutputs++] = "-..";
	outputs[amountOutputs++] = ".";
	outputs[amountOutputs++] = "..-.";
	outputs[amountOutputs++] = "--.";
	outputs[amountOutputs++] = "....";
	outputs[amountOutputs++] = "..";
	outputs[amountOutputs++] = ".---";
	outputs[amountOutputs++] = "-.-";
	outputs[amountOutputs++] = ".-..";
	outputs[amountOutputs++] = "--";
	outputs[amountOutputs++] = "-.";
	outputs[amountOutputs++] = "---";
	outputs[amountOutputs++] = ".--.";
	outputs[amountOutputs++] = "--.-";
	outputs[amountOutputs++] = ".-.";
	outputs[amountOutputs++] = "...";
	outputs[amountOutputs++] = "-";
	outputs[amountOutputs++] = "..-";
	outputs[amountOutputs++] = "...-";
	outputs[amountOutputs++] = ".--";
	outputs[amountOutputs++] = "-..-";
	outputs[amountOutputs++] = "-.--";
	outputs[amountOutputs++] = "--..";
	outputs[amountOutputs++] = ".----";
	outputs[amountOutputs++] = "..---";
	outputs[amountOutputs++] = "…--";
	outputs[amountOutputs++] = "….-";
	outputs[amountOutputs++] = "…..";
	outputs[amountOutputs++] = "-….";
	outputs[amountOutputs++] = "--…";
	outputs[amountOutputs++] = "---..";
	outputs[amountOutputs++] = "----.";
	outputs[amountOutputs++] = "-----";
	outputs[amountOutputs++] = ".-.-.-";
	outputs[amountOutputs++] = "--..--";
	outputs[amountOutputs++] = "---…";
	outputs[amountOutputs++] = "..--..";
	outputs[amountOutputs++] = "-….-";
	outputs[amountOutputs++] = "--..-.";
}

// Функция принимает массив символов и символ и возращает позицию символа в массиве (индекс) иначе -1
int getIndexSymbol(char symbols[], char a)
{
	for (int i = 0; i < amountSymbols; i++)
	{
		if (symbols[i] == a)
			return i;
	}
	return -1;
}

// Функция преобразовывает буквы в верхний регистр
// с вопросиками и двоеточиями, как ты любишь :)
char toUpper(char a)
{
	// если символ - большая буква, то его же и возвращаем, иначе прибавляем к его коду разность маленькой и большой буквы
	return a >= 'A' && a <= 'Z' ? a : (char)((int)a + (int)('A' - 'a'));
}

// Функция принимает строку и кодирует ее
string getMorze(string input)
{
	// создали массивы входных и выходных символов и пронициализировали их.
	char* inputs = new char[amountSymbols];
	string* outputs = new string[amountSymbols];
	initInputs(inputs);
	initOutputs(outputs);


	int len = input.size();
	string result = "";
	for (int i = 0; i < len; i++)
	{
		/*
			Смотри, у нас с тобой биекция выходных символов и входных символом. 
			Помнишь, что это значит?)
			То, что входному символу соотвестует выходной и при этом однозначно.
			Мы получили позицию символа(индекс) в массиве входных символов она 
			же будет и позицией в массиве выходных символов.
		*/
		result += outputs[getIndexSymbol(inputs, toUpper(input[i]))];
	}

	// У хороших девушек чисто не только дома, но и в коде :)
	// Поэтому память чистим за собой.
	delete[] inputs;
	delete[] outputs;
	return result;
}

int main()
{
	cout << "enter text\n";
	string text = "";
	getline(cin, text);
	cout << getMorze(text) << endl;
	return 0;
}