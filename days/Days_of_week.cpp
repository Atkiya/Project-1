/*Input format-
 Month date,year
 Or,
 MM/DD/YYYY
 For example-
 July 14,2019
 07/14/2019
*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    string s;
    int m, d, y;
    getline(cin,s);
    string week[7] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    if (s[0] > 47 && s[0] < 58)
    {
        if (s[0] == '0')
        {
            m = s[1] - 48;
            if (s[3] == 0)
            {
                d = s[4] - 48;
            }
            else
            {
                d = (s[3] - 48) * 10 + (s[4] - 48);
            }
        }
        else
        {
            m = (s[0] - 48) * 10 + (s[1] - 48);
            if (s[3] == 0)
            {
                d = s[4] - 48;
            }
            else
            {
                d = (s[3] - 48) * 10 + (s[4] - 48);
            }
        }
        y = (s[6] - 48) * 1000 + (s[7] - 48) * 100 + (s[8] - 48) * 10 + (s[9] - 48);
    }
    else
    {
        if (s[0] == 'J' && s[1] == 'a')
        {
            m = 1;
        }
        else if (s[0] == 'F')
        {
            m = 2;
        }
        else if (s[0] == 'M' && s[2] == 'r')
        {
            m = 3;
        }
        else if (s[0] == 'A' && s[1] == 'p')
        {
            m = 4;
        }
        else if (s[0] == 'M' && s[2] == 'y')
        {
            m = 5;
        }
        else if (s[0] == 'J' && s[2] == 'n')
        {
            m = 6;
        }
        else if (s[0] == 'J' && s[2] == 'l')
        {
            m = 7;
        }
        else if (s[0] == 'A' && s[1] == 'u')
        {
            m = 8;
        }
        else if (s[0] == 'S')
        {
            m = 9;
        }
        else if (s[0] == 'O')
        {
            m = 10;
        }
        else if (s[0] == 'N')
        {
            m = 11;
        }
        else
        {
            m = 12;
        }
        string dt;
        int comma;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                dt += s[i];
            }
            else if (s[i] == ',')
            {
                comma = i;
                break;
            }
        }
        if (dt[0] == 0)
        {
            d = (dt[1] - 48);
        }
        else if (dt.length() == 1)
        {
            d = dt[0] - 48;
        }
        else
        {
            d = (dt[0] - 48) * 10 + (dt[1] - 48);
        }
        string yr;
        for (int i = comma; i < s.length(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                yr += s[i];
            }
        }
        y = (yr[0] - 48) * 1000 + (yr[1] - 48) * 100 + (yr[2] - 48) * 10 + (yr[3] - 48);
    }
    int mon;
    if (m > 2)
    {
        mon = m;
    }
    else
    {
        mon = (12 + m);
        y--;
    }
    int Y = y % 100;
    int C = y / 100;
    int w = (d + floor((13 * (mon + 1)) / 5) + Y + floor(Y / 4) + floor(C / 4) + (5 * C));
    w = w % 7;
    cout << week[w];
}
