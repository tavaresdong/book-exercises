#include "TextQuery.h"
#include <sstream>

using namespace std;

TextQuery::TextQuery(ifstream& infile) 
       : lines(new vector<string>())
{
    string text;
    while (getline(infile, text)) {
        lines->push_back(text);
        int n = lines->size() - 1;
        istringstream line(text);
        string word;
        while (line >> word) {
            auto &wls = wordToLines[word];
            if (!wls) {
                wls.reset(new set<lineno>());
            }
            wls->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string& qr) const
{
    static shared_ptr<set<lineno>> nodata(new set<lineno>);
    auto iter = wordToLines.find(qr);
    if (iter == wordToLines.end()) {
        return QueryResult(qr, nodata, lines);
    } else {
        return QueryResult(qr, iter->second, lines);
    }
}

ostream& print(ostream& out, const QueryResult& result) {
    out << result.sought << " occurs " <<
           result.linenos->size() << " times" << endl;
    for (auto num : *result.linenos) {
        out << result.lines->at(num) << endl;
    }
    return out;
}
