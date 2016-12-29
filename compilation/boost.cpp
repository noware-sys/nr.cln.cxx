#include <iostream>
#include <sstream>
#include <list>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/access.hpp>
#include <boost/version.hpp>
#include <boost/serialization/list.hpp>
//#include <boost/serialization/slist.hpp>

struct Foo {
   std::list <unsigned long long int> bar;

   template<class Archive>
   void serialize(Archive& ar, const unsigned int & /*version*/) {
      ar & bar;
   }
};

std::ostream& operator<<(std::ostream& os, /*const */Foo/*&*/ foo) {
   os << foo.bar.front () << ", ";
   foo.bar.pop_front ();
   os << foo.bar.front () << ", ";
   foo.bar.pop_front ();
   os << foo.bar.front () << std::endl;
   foo.bar.pop_front ();
   
   return os;   
}

int main()
{
   std::cout << "Boost version " << BOOST_LIB_VERSION << '\n';

   Foo before;
   before.bar.push_back (110);
   before.bar.push_back (220);
   before.bar.push_back (330);

   std::cout << "before: " << before << std::endl;

   std::ostringstream os;
   {
      boost::archive::text_oarchive oa(os);
      oa << before;
   }

   Foo after;
   {
      std::istringstream is(os.str());
      boost::archive::text_iarchive ia(is);
      ia >> after;
   }

   std::cout << "after: " << after << std::endl;
}
