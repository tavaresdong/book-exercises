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
    virtual void debug() const
    { std::cout << "base Quote " << "bookNo: " << bookNo << std::endl; }
private:
    std::string bookNo;
protected:
    // let derived classes to use
    double price = 0.0;
};

class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string& book, double price,
               std::size_t qty, double disc) : Quote(book, price), 
               quantity(qty), discount(disc) { }
    double net_price(std::size_t n) const = 0;
protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string&, double, std::size_t, double);
    double net_price(std::size_t) const override;
    void debug() const
    { std::cout << "Bulk_quote" << " Min_qty: " << quantity <<
                "discount: " << discount << std::endl; }
};


double print_total(std::ostream &os,
                   const Quote &item, size_t n);

#endif
