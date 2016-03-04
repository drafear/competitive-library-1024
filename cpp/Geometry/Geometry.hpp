#pragma once

#include "../util.hpp"

using ld = long double;
using Point = complex<ld>;
using Polygon = vector<Point>;

const ld eps = 1e-9;

ld dot(Point a, Point b) { return real(conj(a) * b); }
ld cross(Point a, Point b) { return imag(conj(a) * b); }

struct Line {
  Point a, b;
  Line (Point p, Point q) : a(p), b(q) {;}
};

struct Segment {
  Point a, b;
  Segment (Point p, Point q) : a(p), b(q) {;}
};

struct Circle {
  Point p; ld r;
  Circle (Point a, ld b) : p(a), r(b) {;}
};

Line to_line(Segment s) { return Line(s.a, s.b); }
Segment to_segment(Line l) { return Segment(l.a, l.b); }

// counter clockwise
int ccw (Point a, Point b, Point c) {
  b -= a; c -= a;
  if (cross(b, c) > eps) return 1;   // counter clockwise
  if (cross(b, c) < -eps) return -1; // clockwise
  if (dot(b, c) < 0) return 2;       // c--a--b on line
  if (norm(b) < norm(c)) return -2;  // a--b--c on line
  return 0;
}
