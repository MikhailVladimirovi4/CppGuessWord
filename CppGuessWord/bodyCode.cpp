#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;
char GetGuess(string);
string Check(string,string, char);
int wrong = 0;

int main()
{
	const int MAX_WRONG = 8;
	vector<string> words;
	char guess;

	words.push_back("guess");
	words.push_back("hangman");
	words.push_back("difficult");

	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());

	const string THE_WORD = words[0];
	string soFar(THE_WORD.size(), '-');
	string used = "";
	cout << "Welcome to Hangman. Good Luck!\n";

	// основной цикл
	while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
	{
		cout << "\n\nYou have " << (MAX_WRONG - wrong) << " incorrect guessess left.\n";
		cout << "\nYou've used the following letters:\n" << used << endl;

		guess = GetGuess(used);
		cout << "\nGuess: " << guess;
		used += guess;
		soFar = Check(THE_WORD, soFar, guess);

		cout << "\n soFar: " << soFar << endl;
	}

	if (wrong == MAX_WRONG)
	{
		cout << "\nYou loss!";
	}
	else
	{
		cout << "\nYou win!";
	}

	cout << "\n\n The word was " << THE_WORD << endl;

	return 0;
}

char GetGuess(string used)
{
	char f = ' ';

	while (used.find(f) != string::npos)
	{
		cout << "\nYou've already guessed " << f << endl;
		cout << "Enter your guess : ";
		cin >> f;
		f = tolower(f);
	}

	return f;
}

string Check(string THE_WORD, string soFar, char guess)
{
	if (THE_WORD.find(guess) != string::npos)
	{
		cout << "that's right1 " << guess << " is in the word.\n";

		for (int i = 0; i < THE_WORD.length(); ++i)
		{
			if (THE_WORD[i] == guess)
				soFar[i] = guess;
		}
	}
	else
	{
		cout << "Sorry. " << guess << " isn't in the word.\n";
		++wrong;
	}

	return soFar;
}
