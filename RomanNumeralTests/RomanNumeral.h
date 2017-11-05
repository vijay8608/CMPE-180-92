#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_
#include<string>
#include <cstring>

using namespace std;

class RomanNumeral
{
public:
    RomanNumeral();
    RomanNumeral(int d);
    RomanNumeral(string r);

    string get_roman() const;
    int get_decimal() const;

    void set_roman( string r);
    void set_decimal( int d);

    friend int operator + (const RomanNumeral& r1, const RomanNumeral& r2);
    friend int operator - (const RomanNumeral& r1, const RomanNumeral& r2);
    friend int operator * (const RomanNumeral& r1, const RomanNumeral& r2);
    friend int operator / (const RomanNumeral& r1, const RomanNumeral& r2);
    friend bool operator == (const RomanNumeral& r1, const RomanNumeral& r2);
    friend bool operator != (const RomanNumeral& r1, const RomanNumeral& r2);
    friend ostream& operator << ( ostream& outs, RomanNumeral& rom);
    friend istream& operator >> ( istream& in, RomanNumeral& rom);



private:
    string roman;
    int decimal;
    void to_decimal(string r);
    void to_roman(int d);
};




#endif /* ROMANNUMERAL_H_ */
