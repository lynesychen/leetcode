class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<char>> record(board);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if( dfs(board,i,j,word,0,record) == true){
                    return true;
                }
            }
        }

        return false;
    }
    
    bool dfs(vector<vector<char>>& board, int posi, int posj, string& word, int index, vector<vector<char>>& record){
        if(index == word.length()){
            return true;
        }
        
        int m = board.size();
        int n = board[0].size();
        
        if(posi < 0 || posi >= m || posj < 0 || posj >=n){
            return false;
        }

        if(record[posi][posj] == '*'){
            return false;
        }
        
        if(word[index] == board[posi][posj]){
            record[posi][posj] = '*';
            if (dfs(board, posi-1, posj, word, index+1,record) == true){
                record[posi][posj] = '-';
                return true;
            };
            if (dfs(board, posi+1, posj, word, index+1,record) == true){
                record[posi][posj] = '-';
                return true;
            };
            if (dfs(board, posi, posj-1, word, index+1,record) == true){
                record[posi][posj] = '-';
                return true;
            };
            if (dfs(board, posi, posj+1, word, index+1,record) == true){
                record[posi][posj] = '-';
                return true;
            };
            record[posi][posj] = '-';
            return false;
        }else{
            return false;
        }
    }
};