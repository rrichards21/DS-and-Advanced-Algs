#ifndef SUFFIX_ARRAY
#define SUFFIX_ARRAY
using namespace std;

class suffixArray {
 private:
  char *_text;
  int *_arr;
 public:
  suffixArray(string &text);
  ~suffixArray();
  int search(const string &pattern)const;
  int patternMatching(const string &pattern)const;
};
#endif