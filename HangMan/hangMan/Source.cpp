#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<conio.h>
#include<time.h>
#include<windows.h>

class Hangman
{
private:
	int guessCount;
	bool gameOver;
	std::string guessWord;
	std::string wordToGuess;

public:
	Hangman()
	{
		guessCount = 0;
		gameOver = true;
		guessWord = "";
		wordToGuess = "";
	}
	void PrintMessage(std::string message, bool printTop = true, bool printBottom = true)
	{
		if (printTop)
		{
			std::cout << "+__________________________________________" << std::endl;
			std::cout << "|";
		}
		else
			std::cout << "|";
		bool flag = true;
		for (int i = message.length(); i < 36; i++)
		{
			if (flag)
				message = message + " ";
			else if (!flag)
				message = " " + message;
			flag = !flag;
		}
		std::cout << message;

		if (printBottom)
		{
			std::cout << "|" << std::endl;
			std::cout << "+__________________________________________" << std::endl;
		}
		else
			std::cout << "|" << std::endl;
	}
	void DrawHangman()
	{
		if (guessCount >= 1)
			PrintMessage("!", 0, 0);
		else
			PrintMessage("", 0, 0);

		if (guessCount >= 2)
			PrintMessage("!", 0, 0);
		else
			PrintMessage("", 0, 0);

		if (guessCount == 10)
			PrintMessage("@", 0, 0);
		else if (guessCount >= 3)
			PrintMessage("O", 0, 0);
		else
			PrintMessage("", 0, 0);

		if (guessCount == 4)
			PrintMessage("|", 0, 0);
		else if (guessCount == 5)
			PrintMessage("\\|", 0, 0);

		if (guessCount >= 6)
			PrintMessage("\\|", 0, 0);
		else
			PrintMessage("", 0, 0);

		if (guessCount >= 7)
			PrintMessage("|", 0, 0);
		else
			PrintMessage("|", 0, 0);

		if (guessCount == 8)
			PrintMessage("/ ", 0, 0);

		if (guessCount >= 9)
			PrintMessage("/ \\", 0, 0);
		else
			PrintMessage("", 0, 0);
	}

	void RandomWord(std::string path = "words.txt")
	{
		srand(time(0)); // set seed
		std::vector <std::string>v;
		std::ifstream file(path);

		if (file.is_open())
			while (std::getline(file, wordToGuess))
				v.push_back(wordToGuess);
		else
			std::cout << "Unable to open file" << std::endl;
		file.close();
		wordToGuess = v.at(rand() % v.size());

	}

	void PrintLetters(char from, char to)
		{
		std::string S;
		for (char i = from; i <= to; i++)
		{
			if (guessWord.find(i) == std::string::npos)
			{
				S += i;
				S += "";
			}
			else
			{
				S += " ";
			}
		}
		PrintMessage(S, 0, 0);
	}

	void RemainingLetters()
	{
		PrintMessage("REMAINING LETTERS");
		PrintLetters('a', 'n');
		PrintLetters('n', 'z');
	}

	void PrintWord()
	{
		PrintMessage("GUESS THE WORD");
		std::string S;
		for (int i = 0; i < wordToGuess.length(); i++)
		{
			if (guessWord.find(wordToGuess[i]) == std::string::npos)
			{
				gameOver = false;
				S += "_ ";
			}
			else
			{
				S += wordToGuess[i];
				S += " ";
			}
		}
		PrintMessage(S, 0);
	}

	void CountGuess(std::string newGuess)
	{
		for (int i = 0; i < newGuess.length(); i++)
			if (wordToGuess.find(newGuess[i]) == std::string::npos)
				guessCount++;
	}

	void Setup()
	{
		RandomWord();
		do
		{
			system("cls");
			PrintMessage("MADE BY ASHISH");
			DrawHangman();
			RemainingLetters();
			PrintWord();

			std::string ch;
			std::cout << ">"; 
			std::cin >> ch;
			if (guessWord.find(ch) == std::string::npos)
			{
				guessWord += ch;
				CountGuess(ch);
			}
			if (gameOver)
				break;
			if (_kbhit())
			{
				char ch = _getch();
				if (ch == '0')
					break;
			}
		}while (guessCount < 10);

			if (gameOver)
			{
				std::cout << "You Win" << std::endl;
			}

			std::cout << "WORD: " << wordToGuess << std::endl;
			std::cout << "Game Over" << std::endl;
	}
};

int main()
{
	Hangman h;
	h.Setup();
	return 0;
}
