#include <iostream>
#include <list>
//..............................................................................
//..............................................................................
template <typename Type> struct Point {

  Type x;
  Type y;
};
template <typename U> struct Triangle {

  Point <U> pts[3];

  U double_square () {

    U square = pts[0].x * (pts[1].y - pts[2].y) +
               pts[1].x * (pts[2].y - pts[0].y) +
               pts[2].x * (pts[0].y - pts[1].y);

    return (square > 0) ? square : -square;
  }
};
//..............................................................................
//..............................................................................
int main () {

  Triangle <int>    Triangle_I = { {0} };
  Triangle <double> Triangle_D = { {0} };

  std::list <int> List;

  List.push_back(2);
  List.push_back(1);
  List.push_back(3);

  std::cin >> m >> n;

  std::cout << List.back() << "\n";

  Triangle_I.pts[0].x = 0;
  Triangle_I.pts[0].y = 0;
  Triangle_I.pts[1].x = 0;
  Triangle_I.pts[1].y = 5;
  Triangle_I.pts[2].x = 5;
  Triangle_I.pts[2].y = 0;

  Triangle_D.pts[0].x = 0.0;
  Triangle_D.pts[0].y = 0.0;
  Triangle_D.pts[1].x = 0.0;
  Triangle_D.pts[1].y = 1.4;
  Triangle_D.pts[2].x = 1.4;
  Triangle_D.pts[2].y = 0.0;

  std::cout << Triangle_I.double_square() << '\n';
  std::cout << Triangle_D.double_square() << '\n';
}
