/*
 * Copyright 2018 Aliakbar Panahi
 *
 */

#ifndef PRICER_H_
#define PRICER_H_

#include <string>
#include <unordered_map>
#include <map>
#include <functional>
#include "order.h"

namespace orderbook {

// Literals for parsing the input and printing the output
const std::string kBuyLiteral = "B";
const std::string kSellLiteral = "S";
const std::string kAddOrderIdentifier = "A";
const std::string kReduceOrderIdentifier = "R";

/**
 * Pricer class
 */
class Pricer {

 public:
  Pricer(): orders_locator_(), bids_(), asks_() {}
  void processOrder(const std::string &input);
  void setTargetSize(Order::Size targetSize);


 private:
  void updateBooks(Order &order);
  void addToBooks(Order &order);
  void reduceFromBooks(Order &order);
  Order::Price executeOrder(Order &order);
  void printOutput(Order &order, Order::Price &totalPrice);

  struct orderLocator {
    orderbook::OrderSide side;
    std::multimap<Order::Price, Order::Size>::iterator order_it;
  };

  // An ordered map for bids in descending order,
  std::multimap<Order::Price, Order::Size, std::greater<>> bids_;

  // An ordered map for asks in ascending order
  std::multimap<Order::Price, Order::Size> asks_;

  // A hash map for locating order in the bids or asks map by it's order-id
  std::unordered_map<std::string, orderLocator> orders_locator_;

  Order::Size target_size = 0;
  Order::Price buy_previous_trade_total = 0;
  Order::Price sell_previous_trade_total = 0;


};

} // orderbook namespace

#endif  // PRICER_H_
