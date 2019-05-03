/**
 * Minimalist example of a contract that intercepts a 'transfer' action from 
 *   the 'acornaccount' contract.
 */
#pragma once

#include <eosio/asset.hpp>
#include <eosio/eosio.hpp>
#include <eosio/transaction.hpp>

#include <string>

namespace eosiosystem {
   class system_contract;
}

namespace eosio {

   using std::string;

   class [[eosio::contract("betacorn")]] dice : public contract {
      public:
         using contract::contract;

         [[eosio::action]]
         void hello( );

   	 void private_function( name from, name to, asset quantity, string memo );

      private:
	 
   };

} /// namespace eosio
