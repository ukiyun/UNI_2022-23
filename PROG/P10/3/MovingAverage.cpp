#include <iostream>
#include <vector>
#include <string>
#include "MovingAverage.h"
using namespace std;	


void MovingAverage::update(double value) {
  values_.push_back(value);
  if (values_.size() > n_) {
    values_.pop_front();
  }
}

double MovingAverage::get() const {
  double sum = 0;
  for (auto value : values_) {
    sum += value;
  }
  return sum / values_.size();
}

MovingAverage::MovingAverage(std::size_t n) : n_(n) {
}