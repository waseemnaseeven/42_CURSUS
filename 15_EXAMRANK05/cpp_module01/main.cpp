#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"

int main()
{
      Warlock richard("Richard", "the Titled");
      // ASpell  *kapt;

      // kapt->getName();

      Dummy bob;
      Fwoosh* fwoosh = new Fwoosh();


      richard.learnSpell(fwoosh);

      richard.introduce();
      richard.launchSpell("Fwoosh", bob);

      Fwoosh*  fwoosh2 = new Fwoosh();
      
      richard.learnSpell(fwoosh2);
      richard.forgetSpell("Fwoosh");
      richard.launchSpell("Fwoosh", bob);

}
