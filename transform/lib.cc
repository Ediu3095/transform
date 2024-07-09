#include <iostream>

#include "transform/vec/vec1.h"
#include "transform/vec/vec2.h"


void PrintVec1(tf::Vec1<tf::i32> const& vec) {
  std::cout << "{ " << vec.x() << " }";
}

void PrintVec2(tf::Vec2<tf::i32> const& vec) {
  std::cout << "{ " << vec.x() << ", " << vec.y() << " }";
}

int main() {
  tf::Vec1<tf::i32> vec1(2);
  tf::Vec1<tf::i32> vec2(4);

  PrintVec1(vec1);
  std::cout << " + ";
  PrintVec1(vec2);
  std::cout << " = ";
  PrintVec1(vec1 + vec2);
  std::cout << std::endl;

  tf::Vec2<tf::i32> vec3(2, -4);
  tf::Vec2<tf::i32> vec4(0, -1);

  PrintVec2(vec3);
  std::cout << " * ";
  PrintVec2(vec4);
  std::cout << " = ";
  PrintVec2(vec3 * vec4);
  std::cout << std::endl;

  return 0;
}
