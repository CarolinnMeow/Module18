#include <iostream>
#include <string>

using namespace std;

class Player 
{
public:
    string name;
    int score;

    Player() : name(" "), score(0)
    {}

    Player(string _name, int _score) : name(_name), score(_score)
    {}

    void Show()
    {
        cout << "Player's name: " << name << "\t" << "Score: " << score << "\n";
    }
};

int main()
{
    int size;
    cout << "How many players?\n";
    cin >> size;
    Player* Players = new Player[size];
    for (int counter = 0; counter < size; counter++)
    {
        cout << "Enter player's " << counter + 1 << " name:\n";
        cin >> Players[counter].name;
        cout << "Enter player's " << counter + 1 << " score:\n";
        cin >> Players[counter].score;
    }
    cout << endl;

    // Сортировка 
    for (int i = 0; i < size; i++)
    {
        for (int j = size -1; j > i; j--)
        {
            if (Players[j].score > Players[j-1].score)
            {
                swap(Players[j].score, Players[j - 1].score);
            }
        }
    }

    // Вывод отсортированного массива
    for (int i = 0; i < size; i++)
    {
        Players[i].Show();
    }

    // Освобождаем память
    delete[] Players;

    return 0;
}
