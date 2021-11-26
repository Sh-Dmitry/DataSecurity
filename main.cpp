#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#define c32 69
#define c33 116
#define c34 114
#define c35 112
#define c36 115
#define c37 119
#define c38 100
#define c39 16
#define C40 89


std::string generate_key(std::string login){
    int len_of_login = login.length();
    int sum = 0;

    L2:
    std::string half_str_1;
    std::string half_str_2;
    std::string buf;
    int seed = sum;
    int j = len_of_login;
    uint64_t hash=0;
    std::string hash_str = std::to_string(hash);
    int len_of_hash = hash_str.length();
    int l;
    int k = 0;
    goto L9;

    if (len_of_login % 2 != 0){
        goto L5;
    }
    L1:
    goto L2;

    L9:
        for (int i = 0; i < len_of_login / 2 ; i++){
            half_str_1 += login[i];
            half_str_2 += login[int(login.length())-1-i];
            sum += int(login[i]) + int(login[int(login.length())-1-i]);
        }
    goto L11;

    L7:
        seed = sum;
        j = len_of_login;
        hash=0;
        for (int i = 0; i < len_of_login; ++i){
            hash = hash*seed + j;
        }

        hash_str = std::to_string(hash);
        len_of_hash = hash_str.length();

        if (len_of_hash % 3 == 2){
            hash_str = hash_str + '0';

        }else if (len_of_hash % 3 == 1){
            hash_str = hash_str + "00";

        }


        l = int(hash_str.length()) / 3;
        k = 0;
            for (int i=0; i < l ; ++i){
                std::string s1,s2,s3, s;
                s1 = hash_str[k];  s2 = hash_str[k+1]; s3 = hash_str[k+2];
                k += 3;
                s = s1 +s2+s3;

                int h1 = std::stoi(s);
                int h2;
                h2 = h1 % 128;
                if (h2 < 32){
                    h2 +=32;
                }
                buf+= char(h2);
            }

        std::cout << buf;
        return buf;

        L5:
        login = login + '0';
        len_of_login += 1;
        goto L1;
        L11:
            for (int i = 0; i < len_of_login / 2 ; i++){
                int tmp;
                tmp = ((int(half_str_1[i]) + (int(half_str_1[i]) xor int(half_str_2[i])) )% 128 );
                if (tmp < 32){
                    tmp +=32;
                }
                buf += char(tmp);

            }
        goto L7;
}

void output(int i){
    std::string x1 = "\x45""n\164e\x72"" \154o\x67""i\156:""\x0A""";
    char x2[16] = {char(c32), char(c38 + 10), char(c33) , char(c38 + c33 - c36) ,
                   char(c34) , char(32), char(c35), char(97), char(c36), char(c36),
                   char(c37), char(c35-1), char(c34), char(c38), char(c32-11), char(10)};
    std::string x3 ="Error";
    std::string x4 = "egUUWee";
    switch (i){
    case 1:
        std::cout << x1;
        break;

    case 3:
        std::cout << x3;
        break;
    case 4:
        std::string new_str;
        for (int i = 0; i < int(x4.length()); i++){
                new_str += char(x4[i]-c39-2);
            }
        std::cout << "\n" << new_str;
        break;
    }
}
int main()
{
    std::string a412, pass;
    output(1);
    std::cin >> a412;
    std::cout << char(c32)<< char(c38 + 10)<< char(c33) << char(c38 + c33 - c36) <<
            char(c34) << char(32)<< char(c35)<< char(97)<< char(c36)<< char(c36)<<
            char(c37)<< char(c35-1)<< char(c34)<< char(c38)<< char(c32-11)<< char(10);

    std::cin >> pass;
    if (pass == generate_key(a412)){
         output(4);
         std::cout<<'\n';
    }else{
    output(3);
    std::cout<<'\n';
    }


    return 0;
}

