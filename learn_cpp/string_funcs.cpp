#include <iostream>
#include <string>

void seperate_key_value(std::string &input, std::string &key, std::string &value){
  size_t mid = input.find("=");
  key = input.substr(0, mid);
  value = input.substr(mid + 1, input.size() - mid);
}


int main ()
{
  std::string str0 ("This is an example ignore_dbm=yes sentence.");
  std::cout << str0 << '\n';
                                           // "This is an example sentence."
  std::string input = "ignore_dbm=yes";
  std::string key;
  std::string value;
  seperate_key_value(input, key, value);
  std::cout << key << "    " << value << '\n';

  std::size_t found = str0.find(key);
  str0.erase (found, key.size() + value.size() + 2);                        //            ^^^^^^^^
  std::cout << str0 << '\n';
/*
  std::string str ("There are two needles in this haystack with needles.");
  std::string str2 ("needle");

  //different member versions of find in the same order as above:
  std::size_t found = str.find(str2);
  if (found!=std::string::npos)
      std::cout << "first 'needle' found at: " << found << '\n';

  found=str.find("needles are small",found+1,6);
  if (found!=std::string::npos)
      std::cout << "second 'needle' found at: " << found << '\n';

  found=str.find("haystack");
    if (found!=std::string::npos)
      std::cout << "'haystack' also found at: " << found << '\n';

  found=str.find('.');
  if (found!=std::string::npos)
    std::cout << "Period found at: " << found << '\n';

  // let's replace the first needle:
  str.replace(str.find(str2),str2.length(),"preposition");
    std::cout << str << '\n';
*/

  return 0;
}
