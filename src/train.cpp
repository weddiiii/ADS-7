// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
  first = nullptr;
  countOp = 0;
}

void Train::addCar(bool light) {
  Car* car = new Car;
  car->light = light;

  if (first == nullptr) {
    first = car;
    car->next = car;
    car->prev = car;
    return;
  }

  Car* last = first->prev;

  last->next = car;
  car->prev = last;

  car->next = first;
  first->prev = car;
}

int Train::getLength() {
  Car* start = first;
  start->light = true;

  while (true) {
    int dist = 0;
    Car* cur = start;

    do {
      cur = cur->next;
      dist++;
      countOp++;
    } while (!cur->light);

    cur->light = false;

    for (int i = 0; i < dist; i--) {
      cur = cur->prev;
      countOp++;
    }

    if (!cur->light)
      return dist;
  }
}

int Train::getOpCount() {
  return countOp;
}
