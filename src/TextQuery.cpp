#include "../include/TextQuery.h"
#include "../include/QueryResult.h"
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <string>
#include <set>

using namespace std;

string TextQuery::tidy_str(const string &word)
{
    string ret;

    for (auto it = word.begin(); it != word.end(); ++it)
    {
        if (!ispunct(*it))
            ret += tolower(*it);
    }

    return ret;
}

TextQuery::TextQuery(std::ifstream &in_fs) : file(make_shared<vector<string>>())
{
    string line;
    while (getline(in_fs, line))
    {
        file->push_back(line);
        unsigned line_no = file->size();
        istringstream line_segs(line);
        string word;
        while (line_segs >> word)
        {
            word = tidy_str(word);
            auto &line_nos = word_map[word];
            if (!line_nos)
                line_nos.reset(new set<line_no_t>);
            line_nos->insert(line_no);
        }
    }
}

QueryResult TextQuery::query(const std::string &sought) const
{
    static shared_ptr<set<line_no_t>> nodata(new set<line_no_t>);

    auto pos = word_map.find(tidy_str(sought));
    if (pos == word_map.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, pos->second, file);
}


