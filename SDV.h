#include <iostream>

#ifndef _SDV_LIB_H_
#define _SDV_LIB_H_

class SDV;
class SDVI;

class SDV {
public:
    double X;
    double Y;
    
    SDV();
    SDV(double n);
    SDV(double x, double y);
    SDV(const SDV &v);
    
    SDV& operator = (const SDV &v);
    SDV& operator += (const SDV &v);
    SDV& operator -= (const SDV &v);
    SDV& operator = (const double &n);
    SDV& operator += (const double &n);
    SDV& operator -= (const double &n);
    SDV& operator *= (const double &n);
    SDV& operator /= (const double &n);
    SDV& operator = (const SDVI &vi);
    
    bool operator == (const SDV &v) const;
    bool operator != (const SDV &v) const;
    bool operator > (const SDV &v) const;
    bool operator < (const SDV &v) const;
    bool operator >= (const SDV &v) const;
    bool operator <= (const SDV &v) const;
    
    SDV operator + () const;
    SDV operator - () const;
    SDV& operator ++ ();
    SDV& operator -- ();
    SDV& operator ++ (int);
    SDV& operator -- (int);
    
    void Set(double n);
    void Set(double x, double y);
    double Norlm() const;
    SDV Rot(const SDV &c, double A) const;
    double BetAngle(const SDV &other) const;
};

class SDVI{
public:
    int X;
    int Y;
    
    SDVI();
    SDVI(int n);
    SDVI(int x, int y);
    SDVI(const SDVI &v);
    
    SDVI& operator = (const SDVI &v);
    SDVI& operator += (const SDVI &v);
    SDVI& operator -= (const SDVI &v);
    SDVI& operator = (const int &n);
    SDVI& operator += (const int &n);
    SDVI& operator -= (const int &n);
    SDVI& operator *= (const int &n);
    SDVI& operator /= (const int &n);
    SDVI& operator = (const SDV &vf);
    
    bool operator == (const SDVI &v) const;
    bool operator != (const SDVI &v) const;
    bool operator > (const SDVI &v) const;
    bool operator < (const SDVI &v) const;
    bool operator >= (const SDVI &v) const;
    bool operator <= (const SDVI &v) const;
    
    SDVI operator + () const;
    SDVI operator - () const;
    SDVI& operator ++ ();
    SDVI& operator -- ();
    SDVI& operator ++ (int);
    SDVI& operator -- (int);
    
    void Set(int n);
    void Set(int x, int y);
    double Norlm() const;
    SDV Rot(const SDVI &c, double A) const;
    double BetAngle(const SDVI &other) const;
};

SDV operator + (const SDV &v1, const SDV &v2);
SDV operator - (const SDV &v1, const SDV &v2);
double operator * (const SDV &v1, const SDV &v2);
double operator / (const SDV &v1, const SDV &v2);
SDV operator + (const SDV &v, const double &n);
SDV operator - (const SDV &v, const double &n);
SDV operator * (const SDV &v, const double &n);
SDV operator * (const double &n, const SDV &v);
SDV operator / (const SDV &v, const double &n);

std::istream& operator >> (std::istream &in, SDV &v);
std::ostream& operator << (std::ostream &out, const SDV &v);

SDVI operator + (const SDVI &v1, const SDVI &v2);
SDVI operator - (const SDVI &v1, const SDVI &v2);
int operator * (const SDVI &v1, const SDVI &v2);
int operator / (const SDVI &v1, const SDVI &v2);
SDVI operator + (const SDVI &v, const int &n);
SDVI operator - (const SDVI &v, const int &n);
SDVI operator * (const SDVI &v, const int &n);
SDVI operator * (const int &n, const SDVI &v);
SDVI operator / (const SDVI &v, const int &n);

std::istream& operator >> (std::istream &in, SDVI &v);
std::ostream& operator << (std::ostream &out, const SDVI &v);

#endif
