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
string encode(string &str)
{
    to_lower(str);
    str+='$';
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

    /*cout << "Encoded String : " << encoded_string << "\n";
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
        final_encoded_string = x.first + itos(x.second) + final_encoded_string;
    }
    return final_encoded_string;*/
    return encoded_string;
}


int main()
{
    #ifdef TarekHasan
        freopen("temp.txt","r",stdin);
    #endif // TarekHasan
    string str; cin >> str;
    string encoded_string = encode(str);
    cout << "Original String : " << str << "\n";
    cout << "Encoded String : " << encoded_string << "\n";

    return 0;
}
