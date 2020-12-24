#include "complexDB.h"

using namespace std;
int main() {
    complexDB c;
    c.readinfo();
    c.sort();
    c.to_file();
    c.recursive_sort(c.get_size());
    c.to_file_extra_credit();
    return 0;
}