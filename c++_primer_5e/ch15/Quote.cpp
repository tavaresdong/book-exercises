#include "Quote.h"

Bulk_quote::Bulk_quote(const std::string& book, double p,
                       std::size_t qty, double disc) :
                       Quote(book, p), min_qty(qty), discount(disc) { }

double Bulk_quote::net_price(std::size_t cnt) const
{
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

Limited_bulk_quote::Limited_bulk_quote(const std::string& book, double p,
                                       std::size_t qty, double disc,
                                       std::size_t lmt) :
                                       Bulk_quote(book, p, qty, disc),
                                       limit(lmt) { }

double Limited_bulk_quote::net_price(std::size_t cnt) const
{
    if (cnt >= min_qty && limit >= cnt)
        return cnt * (1 - discount) * price;
    else if (cnt > limit)
        return limit * (1 - discount) * price + (cnt - limit) * price;
    else
        return cnt * price;
}

double print_total(std::ostream &os,
                   const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
       << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}
