#include <iostream>
#include <string>

using namespace std;
char decompressed[20][20];

void decompress(string::iterator& it, int y, int x, int size)
{
    // move iterator forward on every call
    char head = *(it++);
    // base case: the first word is 'b' or 'w'
    if(head == 'b' || head == 'w')
    {
        for(int dy=0; dy<size; dy++)
            for(int dx=0; dx<size; dx++)
                decompressed[y+dy][x+dx] = head;
    }
    else 
    {
        // decompress each parts
        int half = size/2;
        decompress(it, y, x, half);
        decompress(it, y, x+half, half);
        decompress(it, y+half, x, half);
        decompress(it, y+half, x+half, half);
    }
}

string reverse(string::iterator& it)
{
    char head = *(it++);
    
    if(head == 'b' || head == 'w')
        return string(1, head); // change datatype
    
    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);
    
    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main()
{
    string tree = "xbwxwbbwb";
    string::iterator it = tree.begin();

    decompress(it, 0, 0, tree.size());
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
            cout << decompressed[i][j] << ' ';
        cout << endl;
    }
    cout << "================" << endl;
    
    it = tree.begin();
    cout << reverse(it) << endl;

    return 0;    
}