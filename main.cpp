#include "iostream"
#include "string"
#include "vector"
#include "algorithm"

using namespace std;
int n,m;
struct symbol{
    int addCost;
    int deleteCost;
};

int main(){
    cin >> n >> m;
    string str = "";
    cin >> str;
    vector<symbol> v(26);
    for(int i = 0; i < n; i++){
        char temp;
        cin >> temp;
        cin >> v[temp - 'a'].addCost >> v[temp - 'a'].deleteCost;
    }

    vector<vector<int>> dp(m,vector<int>(m, INT_MAX));
    for(int i = 0; i < m; i++) {
        dp[i][i] = 0;
        if(i != 0) dp[i][i-1] = 0;
    }

    for(int length = 1; length < m; length++){
        for(int i = 0, j = i+length; i < m && j < m; i++,j = i+length){
            if(str[i] == str[j]){
                dp[i][j] = dp[i+1][j-1];
            }else{
                dp[i][j] = min(
                        i+1 < m ? (dp[i+1][j] + min(v[str[i] - 'a'].addCost,v[str[i] - 'a'].deleteCost )): INT_MAX,
                        dp[i][j-1] + min(v[str[j] - 'a'].addCost,v[str[j] - 'a'].deleteCost)
                        );
            }

        }
    }

    cout << dp[0][m-1] << endl;

    return 0;
}