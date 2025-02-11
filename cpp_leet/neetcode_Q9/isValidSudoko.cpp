#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i {0} ; i<9 ;i++)
        {
            unordered_set<char> set;
            for(int j {0} ; j<9;j++)
            {
                if(board[i][j] != '.')
                {
                    if (set.count(board[i][j]))
                    {
                        return false;
                    }
                    set.insert(board[i][j]);
                }
            }
        }

        for(int i {0} ; i<9 ;i++)
        {
            unordered_set<char> set;
            for(int j {0} ; j<9;j++)
            {
                if(board[i][j] != '.')
                {
                    if (set.count(board[i][j]))
                    {
                        return false;
                    }
                    set.insert(board[i][j]);
                }
            }
        }

        for(int square = 0 ;square<9;square++)
        {
            unordered_set<char> set;
            for(int i = 0;i<3;i++)
            {
                for( int j {0} ; j<3 ; j++)
                {
                    int row = (square/3)* 3 +i;
                    int col = (square%3)* 3 +j;
                    if(board[row][col]!='.')
                    {
                        if(set.count(board[row][col]))
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<string>> ques = {{"1","2",".",".","3",".",".",".","."},
                               {"4",".",".","5",".",".",".",".","."},
                               {".","9","8",".",".",".",".",".","3"},
                               {"5",".",".",".","6",".",".",".","4"},
                               {".",".",".","8",".","3",".",".","5"},
                               {"7",".",".",".","2",".",".",".","6"},
                               {".",".",".",".",".",".","2",".","."},
                               {".",".",".","4","1","9",".",".","8"},
                               {".",".",".",".","8",".",".","7","9"}};

    Solution Sol;
}

