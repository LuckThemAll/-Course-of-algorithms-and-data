#include <vector>
#include <iostream>
#include <string>

using namespace std;

bool found = false;

bool check(string &s);
int readTag(int c, string &s, vector<string> &openTags);

int main() {
    freopen("xml.in", "r", stdin);
    freopen("xml.out", "w", stdout);
    string s, sTest;
    cin >> s;
    sTest = s;
    string alph = "qwertyuiopasdfghjklzxcvbnm<>/";
    for (int i = 0; i < sTest.size(); i++){
        for (int j = 0; j < alph.size(); j++){
            sTest[i] = alph[j];
            if (check(sTest)){
                cout << sTest;
                found = true;
                break;
            }
        }
        sTest = s;
        if (found) break;

    }
}

bool check(string &s){
    int i = 0;
    vector<string> Tags;
    bool endS = false;
    while (!endS){
        if (s[i] == '<' && s[i+1] == '/'){
            string tagName = "<";
            i += 2;
            while (s[i] != '>'){
                if (s[i] == '/' || s[i] == '<' && s[i+2] != '/' && s[i+2] != '<' && s[i+2] != '>')
                    return false;
                tagName += s[i++];
            }
            tagName += s[i++];
            if (!Tags.empty() && Tags[Tags.size() - 1] == tagName)
                Tags.pop_back();
            else
                return false;
        } else if (s[i] == '<' && s[i+1] != '/' && s[i+1] != '<' && s[i+1] != '>'){
            string tagName = "<";
            i++;
            while (s[i] != '>'){
                if (s[i] == '/' || s[i] == '<')
                    return false;
                tagName += s[i++];
            }
            tagName += s[i++];
            Tags.push_back(tagName);
        } else return false;

    if (i == s.size()) endS = true;
    }
    if (Tags.empty()) return true;
    else return false;
}
