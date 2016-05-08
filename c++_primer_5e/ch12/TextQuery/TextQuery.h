#ifndef _TEXTQUERY_H_
#define _TEXTQUERY_H_
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <fstream>
#include <iostream>

class QueryResult;
class TextQuery {
public:
    using lineno = std::vector<std::string>::size_type;
    TextQuery(std::ifstream& infile);
    QueryResult query(const std::string& s) const;

private:
    std::shared_ptr<std::vector<std::string>> lines;
    std::map<std::string, std::shared_ptr<std::set<lineno>>> wordToLines;
};

class QueryResult {
   friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    using lineno = TextQuery::lineno;
    QueryResult(std::string st, std::shared_ptr<std::set<lineno>> lns,
                std::shared_ptr<std::vector<std::string>> ls) : 
            sought(st), linenos(lns), lines(ls) { }
private:
    std::string sought;
    std::shared_ptr<std::set<lineno>> linenos;
    std::shared_ptr<std::vector<std::string>> lines;
};

#endif
