#ifndef _QUOTE_H_
#define _QUOTE_H_
#include <string>
#include <iostream>

class Quote {
public:
    Quote() = default;
    Quote(const std::string& book, double sales_price) :
            bookNo(book), price(sales_price) { }

    std::string isbn() const { return bookNo; }

    virtual double net_price(std::size_t n) const
    { return n * price; }

    virtual ~Quote() = default;
private:
    std::string bookNo;
protected:
    // let derived classes to use
    double price = 0.0;
};

class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string&, double, std::size_t, double);
    virtual double net_price(std::size_t) const override;
protected:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

class Limited_bulk_quote : public Bulk_quote {
public:
    Limited_bulk_quote() = default;
    Limited_bulk_quote(const std::string&, double, std::size_t, double, std::size_t);
    double net_price(std::size_t) const override;
private:
    std::size_t limit;
};

double print_total(std::ostream &os,
                   const Quote &item, size_t n);

#endif
