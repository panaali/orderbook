/*
 * Copyright 2018 Aliakbar Panahi
 *
 */

#ifndef PRICER_E
#define PRICER_EXCEPTION_H

namespace orderbook {

// Main Exception
class Exception {
};

// Parsing exception
class ParseException : public Exception {
};

// Parsing exception
class updateBooksException : public Exception {
};


// executeOrder exception
class executeOrderException : public Exception {
};


}  // orderbook namespace

#endif //PRICER_EXCEPTION_H
