# sample_eosio_dispatcher
Sample EOSIO custom dispatcher that intercepts 'transfer' actions from an 'acornaccount' account

This is just a minimalist EOSIO smart contract skeleton that has a custom dispatcher. It allows the contract to listen to a transfer action from another contract (in this case, from the "acornaccount" account/contract). 

This was done with EOSIO CDT 1.6 or so, and tested with EOSIO 1.7 nodeos, I think.
