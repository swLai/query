#include "QueryResult.h"
#include <iostream>

using namespace std;

ostream& print(ostream &out, const QueryResult &qr)
{
    out << qr.sought << " occurs " << qr.line_nos->size() << " times" << endl;

    for (auto no : *qr.line_nos)
        out << "\t(line " << no << ") " << *(qr.file->begin() + (no-1)) << endl;
    out << endl;

    return out;
}
