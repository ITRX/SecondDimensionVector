#include "SDV.h"
#include <cmath>

using namespace std;

SDV::SDV(){
    X = 0;
    Y = 0;
}

SDV::SDV(double n) {
    X = n;
    Y = n;
}

SDV::SDV(double x, double y) {
    X = x;
    Y = y;
}

SDV::SDV(const SDV &v) {
    *this = v;
}

SDV& SDV::operator = (const SDV &v) {
    this->X = v.X;
    this->Y = v.Y;
    return *this;
}

SDV& SDV::operator += (const SDV &v) {
    this->X += v.X;
    this->Y += v.Y;
    return *this;
}

SDV& SDV::operator -= (const SDV &v) {
    this->X -= v.X;
    this->Y -= v.Y;
    return *this;
}

SDV& SDV::operator = (const double &n) {
    this->X = n;
    this->Y = n;
    return *this;
}

SDV& SDV::operator += (const double &n) {
    this->X += n;
    this->Y += n;
    return *this;
}

SDV& SDV::operator -= (const double &n) {
    this->X -= n;
    this->Y -= n;
    return *this;
}

SDV& SDV::operator *= (const double &n) {
    this->X *= n;
    this->Y *= n;
    return *this;
}

SDV& SDV::operator /= (const double &n) {
    this->X /= n;
    this->Y /= n;
    return *this;
}

SDV& SDV::operator = (const SDVI &vi){
    this->X = vi.X;
    this->Y = vi.Y;
    return *this;
}

SDV operator + (const SDV &v1, const SDV &v2) {
    return SDV(v1.X + v2.X, v1.Y + v2.Y);
}

SDV operator - (const SDV &v1, const SDV &v2) {
    return SDV(v1.X - v2.X, v1.Y - v2.Y);
}

double operator * (const SDV &v1, const SDV &v2) {
    return v1.X * v2.X + v1.Y * v2.Y;
}

double operator / (const SDV &v1, const SDV &v2) {
    return v1.X * v2.Y - v2.X * v1.Y;
}

SDV operator + (const SDV &v, const double &n) {
    return SDV(v.X + n, v.Y + n);
}

SDV operator - (const SDV &v, const double &n) {
    return SDV(v.X - n, v.Y - n);
}

SDV operator * (const SDV &v, const double &n) {
    return SDV(v.X * n, v.Y * n);
}

SDV operator * (const double &n, const SDV &v) {
    return SDV(v.X * n, v.Y * n);
}

SDV operator / (const SDV &v, const double &n) {
    return SDV(v.X / n, v.Y / n);
}


bool SDV::operator == (const SDV &v) const {
    return this->X == v.X && this->Y == v.Y;
}

bool SDV::operator != (const SDV &v) const {
    return !(this->X == v.X && this->Y == v.Y);
}

bool SDV::operator > (const SDV &v) const {
    return this->X > v.X && this->Y > v.Y;
}

bool SDV::operator < (const SDV &v) const {
    return this->X < v.X && this->Y < v.Y;
}

bool SDV::operator >= (const SDV &v) const {
    return this->X >= v.X && this->Y >= v.Y;
}

bool SDV::operator <= (const SDV &v) const {
    return this->X <= v.X && this->Y <= v.Y;
}

SDV SDV::operator + () const {
    SDV r(+this->X, +this->Y);
    return r;
}

SDV SDV::operator - () const {
    SDV r(-this->X, -this->Y);
    return r;
}

SDV& SDV::operator ++ () {
    this->X += 1;
    this->Y += 1;
    return *this;
}

SDV& SDV::operator -- () {
    this->X -= 1;
    this->Y -= 1;
    return *this;
}

SDV& SDV::operator ++ (int) {
    this->X += 1;
    this->Y += 1;
    return *this;
}

SDV& SDV::operator -- (int) {
    this->X -= 1;
    this->Y -= 1;
    return *this;
}


istream& operator >> (istream &in, SDV &v){
    in >> v.X >> v.Y;
    return in;
}

ostream& operator << (ostream &out, const SDV &v){
    out << v.X << " " << v.Y;
    return out;
}


void SDV::Set(double n){
    this->X = n;
    this->Y = n;
}

void SDV::Set(double x, double y) {
    this->X = x;
    this->Y = y;
}

double SDV::Norlm() const {
    return sqrt(pow(this->X, 2) + pow(this->Y, 2));
}

SDV SDV::Rot(const SDV &c, double A) const {
    SDV rot;
    rot.X = cos(A) * (this->X - c.X) - sin(A) * (this->Y - c.Y) + c.X;
    rot.Y = sin(A) * (this->X - c.X) + cos(A) * (this->Y - c.Y) + c.Y;
    return rot;
}

double SDV::BetAngle(const SDV &other) const {
    if (this->Norlm() == 0 || other.Norlm() == 0)
        return acos(0);
    else
        return acos(((*this) * other) / (this->Norlm() * other.Norlm()));
}


SDVI::SDVI(){
    X = 0;
    Y = 0;
}

SDVI::SDVI(int n) {
    X = n;
    Y = n;
}

SDVI::SDVI(int x, int y) {
    X = x;
    Y = y;
}

SDVI::SDVI(const SDVI &v) {
    *this = v;
}


SDVI& SDVI::operator = (const SDVI &v) {
    this->X = v.X;
    this->Y = v.Y;
    return *this;
}

SDVI& SDVI::operator += (const SDVI &v) {
    this->X += v.X;
    this->Y += v.Y;
    return *this;
}

SDVI& SDVI::operator -= (const SDVI &v) {
    this->X -= v.X;
    this->Y -= v.Y;
    return *this;
}

SDVI& SDVI::operator = (const int &n) {
    this->X = n;
    this->Y = n;
    return *this;
}

SDVI& SDVI::operator += (const int &n) {
    this->X += n;
    this->Y += n;
    return *this;
}

SDVI& SDVI::operator -= (const int &n) {
    this->X -= n;
    this->Y -= n;
    return *this;
}

SDVI& SDVI::operator *= (const int &n) {
    this->X *= n;
    this->Y *= n;
    return *this;
}

SDVI& SDVI::operator /= (const int &n) {
    this->X /= n;
    this->Y /= n;
    return *this;
}

SDVI& SDVI::operator = (const SDV &vf){
    this->X = vf.X;
    this->Y = vf.Y;
    return *this;
}

SDVI operator + (const SDVI &v1, const SDVI &v2) {
    return SDVI(v1.X + v2.X, v1.Y + v2.Y);
}

SDVI operator - (const SDVI &v1, const SDVI &v2) {
    return SDVI(v1.X - v2.X, v1.Y - v2.Y);
}

int operator * (const SDVI &v1, const SDVI &v2) {
    return v1.X * v2.X + v1.Y * v2.Y;
}

int operator / (const SDVI &v1, const SDVI &v2) {
    return v1.X * v2.Y - v2.X * v1.Y;
}

SDVI operator + (const SDVI &v, const int &n) {
    return SDVI(v.X + n, v.Y + n);
}

SDVI operator - (const SDVI &v, const int &n) {
    return SDVI(v.X - n, v.Y - n);
}

SDVI operator * (const SDVI &v, const int &n) {
    return SDVI(v.X * n, v.Y * n);
}

SDVI operator * (const int &n, const SDVI &v) {
    return SDVI(v.X * n, v.Y * n);
}

SDVI operator / (const SDVI &v, const int &n) {
    return SDVI(v.X / n, v.Y / n);
}


bool SDVI::operator == (const SDVI &v) const {
    return this->X == v.X && this->Y == v.Y;
}

bool SDVI::operator != (const SDVI &v) const {
    return !(this->X == v.X && this->Y == v.Y);
}

bool SDVI::operator > (const SDVI &v) const {
    return this->X > v.X && this->Y > v.Y;
}

bool SDVI::operator < (const SDVI &v) const {
    return this->X < v.X && this->Y < v.Y;
}

bool SDVI::operator >= (const SDVI &v) const {
    return this->X >= v.X && this->Y >= v.Y;
}

bool SDVI::operator <= (const SDVI &v) const {
    return this->X <= v.X && this->Y <= v.Y;
}

SDVI SDVI::operator + () const {
    SDVI r(+this->X, +this->Y);
    return r;
}

SDVI SDVI::operator - () const {
    SDVI r(-this->X, -this->Y);
    return r;
}

SDVI& SDVI::operator ++ () {
    this->X += 1;
    this->Y += 1;
    return *this;
}

SDVI& SDVI::operator -- () {
    this->X -= 1;
    this->Y -= 1;
    return *this;
}

SDVI& SDVI::operator ++ (int) {
    this->X += 1;
    this->Y += 1;
    return *this;
}

SDVI& SDVI::operator -- (int) {
    this->X -= 1;
    this->Y -= 1;
    return *this;
}


istream& operator >> (istream &in, SDVI &v){
    in >> v.X >> v.Y;
    return in;
}

ostream& operator << (ostream &out, const SDVI &v){
    out << v.X << " " << v.Y;
    return out;
}


void SDVI::Set(int n){
    this->X = n;
    this->Y = n;
}

void SDVI::Set(int x, int y) {
    this->X = x;
    this->Y = y;
}

double SDVI::Norlm() const {
    return sqrt(pow(this->X, 2) + pow(this->Y, 2));
}

SDV SDVI::Rot(const SDVI &c, double A) const {
    SDV rot;
    rot.X = cos(A) * (this->X - c.X) - sin(A) * (this->Y - c.Y) + c.X;
    rot.Y = sin(A) * (this->X - c.X) + cos(A) * (this->Y - c.Y) + c.Y;
    return rot;
}

double SDVI::BetAngle(const SDVI &other) const {
    if (this->Norlm() == 0 || other.Norlm() == 0)
        return acos(0);
    else
        return acos(((*this) * other) / (this->Norlm() * other.Norlm()));
}
