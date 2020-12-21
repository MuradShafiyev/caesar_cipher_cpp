#include <iostream>
#include <cstdlib>
using namespace std;

string encrypt(string s, int key);
string decrypt(string s, int key);

int main()
{
    string s; int key, type;

    cout << "---    Sezar şifri     ---" << endl
         << "Tətbiq etmək istədiyiniz prosesi seçin..." << endl 
         << "Şifrləmə üçün '1'\nDeşifrləmə üçün '2' daxil edin" << endl
         << "\t(1/2) => ";
    cin >> type;
    
    if(type == 1)
    {
        cout << "###    Şifrləmə    ###" << endl
            << "Açarı daxil edin:" << endl;
        cin >> key;
        cout << "Şifrlənəcək mesajı daxil edin" << endl;
        cin >> s;
        cout << endl << "Şifrlənmiş mesaj:" << endl << encrypt(s, key) << endl;
    }
    if(type == 2)
    {
        cout << "###    Deşifrləmə    ###" << endl
            << "Açarı daxil edin:" << endl;
        cin >> key;
        cout << "Deşifrlənəcək mesajı daxil edin" << endl;
        cin >> s;
        cout << endl << "Deşifrlənmiş mesaj:" << endl << decrypt(s, key) << endl;
    }

    return 0;
}

string encrypt(string s, int key)
{
    string cipher = "";
    for (int i = 0; i < s.length(); ++i)
    {
        // Böyük hərf simvolları üçün
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            cipher += (char) (s[i] - 'A' + key) % ('Z' - 'A') + 'A';
            continue;
        }

        // Kiçik hərf simvolları üçün
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            cipher += (char) (s[i] - 'a' + key) % ('z' - 'a') + 'a';
            continue;
        }

        // Digər simvollar üçün
        cipher += s[i];
    }
    return cipher;
}

string decrypt(string s, int key)
{
    string plain = "";
    for (int i = 0; i < s.length(); ++i)
    {
        // Böyük hərf simvolları üçün
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            plain += (char) (s[i] - 'A' - key + ('Z' - 'A')) % ('Z' - 'A') + 'A';
            continue;
        }

        // Kiçik hərf simvolları üçün
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            plain += (char) (s[i] - 'a' - key + ('z' - 'a')) % ('z' - 'a') + 'a';
            continue;
        }

        // Digər simvollar üçün
        plain += s[i];
    }
    return plain;
}