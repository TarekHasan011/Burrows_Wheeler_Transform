#include<bits/stdc++.h>
using namespace std;
void to_lower(string &str)
{
    for(char &c : str)
    {
        if(c>='a' && c<='z')
            continue;
        c-='A';
        c+='a';
    }
    return;
}
string itos(int x)
{
    string str = "";
    while(x)
    {
        str+=((x%10)+'0');
        x/=10;
    }
    reverse(str.begin(),str.end());
    return str;
}
string encode(string str)
{
    string temp = str;
    vector< string > strings;
    for(int i=0;i<str.size();i++)
    {
        char c = temp[0];
        temp = temp.substr(1);
        temp+=c;
        strings.push_back(temp);
    }
    sort(strings.begin(),strings.end());
    string encoded_string = "";
    for(string s : strings)
        encoded_string+=s.back();

    stack< pair< char , int > > st;
    for(char c : encoded_string)
    {
        if(st.empty()) st.push({c,1});
        else
        {
            if(st.top().first==c)
                st.top().second+=1;
            else
                st.push({c,1});
        }
    }
    string final_encoded_string = "";

    while(!st.empty())
    {
        auto x = st.top();
        st.pop();
        final_encoded_string = (x.second>1 ? itos(x.second) : "") + x.first + final_encoded_string;
    }
    cout << "Run Length : " << final_encoded_string.length() << "\n";
    return encoded_string;
}

string decode(string str)
{
    string last_column = str;
    string first_column = str;
    sort(first_column.begin(),first_column.end());

    map< char , int > mp;
    vector< pair< char , int > > _last_column;
    for(char c : last_column) _last_column.push_back({c,mp[c]++});
    mp.clear();
    map< pair< char , int > , int > first_column_index;
    for(int i=0;i<first_column.size();i++)
    {
        first_column_index[{first_column[i], mp[first_column[i]]++}] = i;
    }
    mp.clear();

    string decoded_string = "";

    pair< char , int > temp{'$',0};

    while(_last_column[first_column_index[temp]].first!='$')
    {
        decoded_string+=temp.first;
        temp = _last_column[first_column_index[temp]];
    }
    decoded_string+=temp.first;

    reverse(decoded_string.begin(),decoded_string.end());
    return decoded_string;

}

int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
    #endif // TarekHasan
    string str; cin >> str;
    to_lower(str);
    str+='$';

    cout << "Original String : " << str << "\n";

    string encoded_string = encode(str);
    cout << "Encoded String : " << encoded_string << "\n";

    string decoded_string = decode(encoded_string);
    cout << "Decoded String : " << decoded_string << "\n";

    if(str==decoded_string)
        cout << "Matched!!\n";
    else
        cout << "Mismatched\n";

    return 0;
}
