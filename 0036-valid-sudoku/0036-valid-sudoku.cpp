class Solution {
public:

bool issafe(vector<vector<char>> &board, int sr, int sc, int er, int ec){
    unordered_set<char> st;
    for(int i = sr; i<=er; i++){
        
        for(int j = sc; j<=ec; j++){
            char digit = board[i][j];
            if(digit == '.') continue;
            if(st.find(digit) != st.end()) return false;
            st.insert(digit);
        }
    }
    return true;
}
    bool isValidSudoku(vector<vector<char>>& board) {
        //row;
        
        for(int r = 0; r<9; r++){
            unordered_set<char> st;
            for(int c = 0; c<9; c++){
                char digit = board[r][c];
                if(digit == '.') continue;
                if(st.find(digit) != st.end()) return false;
                st.insert(digit);
            }
        }

        //col
        for(int c = 0; c<9; c++){
            unordered_set<char> st;
            for(int r = 0; r<9; r++){
                char digit = board[r][c];
                if(digit == '.') continue;
                if(st.find(digit) != st.end()) return false;
                st.insert(digit);
            }
        }

        // 3*3
        for(int sr = 0; sr<9; sr+=3){
            int er = sr+2;
            for(int sc = 0; sc<9; sc += 3){
                int ec= sc+2;
                if(!issafe(board, sr,sc,er,ec)) return false;
            }
        }
        return true;

    }
};