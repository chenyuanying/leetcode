// Regular Expression Matching
// Using Dynamic Table

class Solution{
    public:
        bool isMatch(string s, string p){
            int m = s.size(), n = p.size();
            vector<vector<bool>> f(m+1, vector<bool>(n + 1, false));

            // f[i][j]: if s[0..i-1] matches p[0..j-1]
            // f[0][0]: s = NULL, p = NULL
            f[0][0] = true;
            for(int i = 1; i <= m; ++i){
                f[i][0] = false;
            }
            for(int j = 1; j <= n; ++j){
                f[0][j] = j > 1 && '*' == p[j - 1] && f[0][j - 2];
            }
            // DP table
            for(int i = 1; i <= m; ++i){
                for (int j = 1; j <= n; ++j){
                    if('*' == p[j - 1]){
                        f[i][j] = f[i][j - 2] || (f[i - 1][j] && (p[j - 2] == s[i - 1] || p[j - 2] == '.'));
                    }else{
                        f[i][j] = f[i - 1][j - 1] && (p[j - 1] == s[i - 1] || '.' == p[j - 1]);
                    }
                }
            }
            return f[m][n];
        }
};


