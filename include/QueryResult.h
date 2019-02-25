#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <set>

class QueryResult
{
    friend std::ostream& print(std::ostream &, const QueryResult &);

public:
    using line_no_t = std::vector<std::string>::size_type;
    using line_it_t = std::set<line_no_t>::const_iterator;

    QueryResult(std::string s, std::shared_ptr<std::set<line_no_t>> ln, std::shared_ptr<std::vector<std::string>> f)
        : sought(s), line_nos(ln), file(f) {}
    std::set<line_no_t>::size_type size() const { return line_nos->size(); }
    line_it_t begin() const { return line_nos->begin(); }
    line_it_t end() const { return line_nos->end(); }
private:
    std::string sought;
    std::shared_ptr<std::set<line_no_t>> line_nos;
    std::shared_ptr<std::vector<std::string>> file;
};

std::ostream& print(std::ostream &, const QueryResult &);

#endif // QUERYRESULT_H
