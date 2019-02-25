#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <fstream>
#include <memory>
#include <vector>
#include <string>
#include <map>
#include <set>

#include "./QueryResult.h"
class QueryResult;

class TextQuery
{
public:
    using line_no_t = std::vector<std::string>::size_type;

    TextQuery(std::ifstream &);
    QueryResult query(const std::string &) const;
private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string,
             std::shared_ptr<std::set<line_no_t>>> word_map;

    static std::string tidy_str(const std::string &);
};

#endif // TEXTQUERY_H
