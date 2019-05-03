#include <betacorn.hpp>

namespace eosio {

void dice::hello() {
  // this dummy action is here just as a placeholder for the dispatch helper macro
  check( false, "You tried to call Hello.");
}
  
void dice::private_function( name from, name to, asset quantity, string memo ) {
  string s;

  s.append("Incoming Transfer: ");
  s.append(from.to_string());
  s.append(", ");
  s.append(to.to_string());
  s.append(", ");
  s.append(quantity.to_string());
  s.append(", '");
  s.append(memo);
  s.append("'");
  
  print(s);
  
  check( false, "An incoming transfer action from the acornaccount::transfer() contract/action." );
}

extern "C" {
  void apply(uint64_t receiver, uint64_t code, uint64_t action) {
    if (code == "acornaccount"_n.value && action == "transfer"_n.value) {
      eosio::execute_action(eosio::name(receiver), eosio::name(code), &dice::private_function);
    } else if (code == receiver) {
      switch (action) { EOSIO_DISPATCH_HELPER(dice, (hello)) }
    }
    eosio_exit(0);
  }
}

} /// namespace eosio
