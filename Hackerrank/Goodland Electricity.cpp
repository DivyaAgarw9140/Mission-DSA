

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'pylons' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY arr
 */

int pylons(int k, vector<int> arr) {
    k = k - 1;
    int start = 0, end = k;
    bool flag = false, check = false;
    int g = 0, count; count = 0;
    while(end < arr.size()){
        flag = false;
        for (int h = end; h >= start; h--)
            {if (arr[h] == 1){g = h;flag = true;count++;break;}}
        if (g + k >= arr.size() - 1){check = true;break;}
        if (flag == false)
        {  
            bool flg = false;
            for (int l = start; l >= start - k; l--){
                if (arr[l] == 1){count++; g = l; flg = true; break;}
            }        
            if (flg == false){break;}
        }
        end = g + (2*k+1);
        start = g + k + 1;
    }
    if (flag == true){
        if (check == false){
            bool flg = false;
            for (int i = arr.size(); i >= arr.size()-k; i--)
                {if (arr[i] == 1){count++;flg = true; break;}}
            if (flg == false){count = -1;}
        }
    } else {count = -1;}
    return count;   
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = pylons(k, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}


