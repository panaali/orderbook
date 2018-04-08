/*
 * Copyright 2018 Aliakbar Panahi
 *
 */

#ifndef PRICER_PARSER_H
#define PRICER_PARSER_H

#include <string>
#include <sstream>
#include <array>
#include "order.h"
#include "exception.h"
#include "pricer.h"

namespace orderbook {

class Parser {
 public:
  // Basic Market Order Parser
  static orderbook::Order parse(const std::string &input);
};

} // orderbook namespace

#endif //PRICER_PARSER_H

inline orderbook::Order orderbook::Parser::parse(const std::string &input) {
  // Split the line into different tokens
  std::istringstream input_string_stream(input);
  std::array<std::string, 6> tokens;
  std::copy(std::istream_iterator<std::string>(input_string_stream),
            std::istream_iterator<std::string>(),
            tokens.begin());

  Order order;

  // timestamp
  auto timestamp = tokens[0];
  order.timestamp = (Order::Timestamp) std::stoul(timestamp);

  // identifier
  auto order_identifier = tokens[1];
  if (order_identifier.compare(kAddOrderIdentifier) == 0)
    order.type = add;
  else if (order_identifier.compare(kReduceOrderIdentifier) == 0)
    order.type = reduce;
  else
    throw ParseException();

  // order-id
  auto order_id = tokens[2];
  order.id = order_id;

  if (order.type == add) { // Add Order

    // side
    auto sideLiteral = tokens[3];
    if (sideLiteral == kBuyLiteral)
      order.side = buy;
    else if (sideLiteral == kSellLiteral)
      order.side = sell;
    else
      throw ParseException();

    // price (in cents)
    order.price = static_cast<Order::Price>(100 * std::stof(tokens[4]));

    // size
    order.size = std::stoul(tokens[5]);

  } else if (order.type == reduce) { // Reduce Order
    // size
    order.size = std::stoul(tokens[3]);

  } else {
    throw ParseException();
  }
  return order;
}
