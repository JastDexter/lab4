#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<string> text;
vector<int> lengths;

void input_text() {
    cout << "Input text:" << endl;
    string temp_text;
    do {
        cin >> temp_text;
        text.push_back(temp_text);
    } while (cin.get() != '\n');
}

int find_simillar_words() {
    int cnt = 0;
    for (string elem : text) {
        if (elem[0] == elem[elem.length() - 1]) cnt++;
    }
    cout << "Number of words with simillar first and last symbol: " << cnt << endl;
    return cnt;
}

void init_lengths() {
    lengths.clear();
    cout << "Inited lengths:" << endl;
    for (int i = 0; i < text.size(); i++) {
        lengths.push_back(text[i].length());
        cout << lengths[lengths.size() - 1] << " ";
    }
    cout << endl;
}

int find_words_starting_with(char symbol) {
    int cnt = 0;
    for (string elem : text) {
        if (elem[0] == symbol) cnt++;
    }
    cout << "Number of words starting with <" << symbol << "> : " << cnt << endl;
    return cnt;
}

void read_text_from_file() {
    ifstream fin("input.txt", ios::in);
    cout << "Reading from file input.txt" << endl;
    while (!fin.eof()) {
        string word;
        fin >> word;
        text.push_back(word);
    }
    fin.close();
    cout << "Added to text:" << endl;
    for (string elem : text) cout << elem << " ";
    cout << endl;
}

void write_to_file() {
    ofstream fout("output.txt", ios::out);
    cout << "Writing to file output.txt" << endl;
    for (string elem : text) fout << elem << " ";
    fout.close();
}

void print_to_screen() {
    cout << "Printing text to console: " << endl;
    for (string elem : text) cout << elem << " ";
    cout << endl;
}

int main() {
    int user_choose = 0;
    do {
        cout << "Choose action:" << endl
             << "1. Input text" << endl
             << "2. Count the number of words in which the first and last characters are the same" << endl
             << "3. Form an array containing word lengths" << endl
             << "4. Count the number of words starting with a given character" << endl
             << "5. Save text to file" << endl
             << "6. Read text from file" << endl
             << "7. Display text on screen" << endl
             << "0. Finish" << endl;
        cin >> user_choose;
        system("cls");
        switch (user_choose) {
            case 1:
                input_text();
                break;
            case 2:
                find_simillar_words();
                break;
            case 3:
                init_lengths();
                break;
            case 4:
                cout << "Input symbol:" << endl;
                char user_symbol;
                cin >> user_symbol;
                find_words_starting_with(user_symbol);
                break;
            case 5:
                write_to_file();
                break;
            case 6:
                read_text_from_file();
                break;
            case 7:
                print_to_screen();
                break;
            case 0:
                break;
            default:
                cout << "Wrong input! Input number from 0 to 7." << endl;
        }
        system("pause");
        system("cls");
    } while (user_choose != 0);
    return 0;
}

