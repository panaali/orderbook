/*
 * Copyright 2018 Aliakbar Panahi
 *
 */

#ifndef PRICER_ORDER_H
#define PRICER_ORDER_H

#include <string>
namespace orderbook {

enum OrderSide { buy, sell };
enum OrderType { add, reduce };

// Market Order
struct Order {

  typedef std::string Id;               // Unique Order Id
  typedef unsigned int Timestamp;       // Milliseconds from midnight
  typedef unsigned long int Price;      // Price in cents
  typedef unsigned long int Size;       // Size

  Timestamp timestamp;
  OrderType type;
  Id id;
  OrderSide side;
  Price price;
  Size size;
};
} // orderbook namespace

#endif //PRICER_ORDER_H
