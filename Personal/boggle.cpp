#include <iostream>
#include <vector>

using namespace std;

char arr[5][5] = {
                    {'U', 'R', 'L', 'P', 'M'},
                    {'X', 'P', 'R', 'E', 'T'},
                    {'G', 'I', 'A', 'E', 'T'},
                    {'X', 'T', 'N', 'Z', 'Y'},
                    {'X', 'O', 'Q', 'R', 'S'}
                };
int xArr[8] = {-1, 0, 1, 1, 0, 0, -1, -1};
int yArr[8] = {0, 1, 0, 0, -1, -1, 0, 0};

bool hasWord(int x, int y, const string& word)
{
    cout << word;
    if(x<0 || x>5 || y<0 || y>5) return false;
    if(arr[x][y] != word[0]) return false;
    if(word.size() == 1) return true;
    cout << "arr:[" << x << "][: "<< y << "]: " << arr[x][y] << "\n";
    
    /*
        send the word finding to next function using word.substr()
        so, every eight times find for matching next word.
    */
    for(int i=0; i<8; i++)
    {   
        if(hasWord(x+(xArr[i]), y+(yArr[i]), word.substr(1)))
        {
            cout << "once";
            return true;
        }
    }
    return false;
}

int main()
{
    string word = "PRETTY";

    if(hasWord(1, 1, word))
        cout << "[" << word << "]찾기 성공";
    else
        cout << "[" << word << "]찾기 실패";

    return 0;
}